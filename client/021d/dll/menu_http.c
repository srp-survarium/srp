// SPDX-License-Identifier: GPL-3.0-or-later
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winhttp.h>
#include <stdio.h>
#include <string.h>
#include "menu_http.h"

#define BODY_LIMIT 4096
#define REPLY_LIMIT 32768
static CRITICAL_SECTION lock;
static HANDLE wake;
static char generation[40], job_generation[40], job_id[24], body[BODY_LIMIT];
static char completed[REPLY_LIMIT + 64];
static char invalidated[160];
static int state; // 0 idle, 1 worker owns job, 2 completion waiting for UI
static int identity_preview;
static int identity_notice;
static uint32_t identity_session, job_session;
static uint64_t identity_epoch, job_epoch;
static volatile LONG match_protocol;

void srp_http_enable_match_protocol(void)
{
    InterlockedExchange(&match_protocol, 1);
}
void srp_http_enable_match_recovery(void)
{
    InterlockedExchange(&match_protocol, 2);
}

static DWORD request(const char *data, uint32_t native_session, char *output, DWORD capacity)
{
    WCHAR url[1024], host[256], path[768];
    DWORD length = GetEnvironmentVariableW(L"SRP_MENU_API", url, 1024);
    if (!length || length >= 1024) {
        strcpy(output, "Set SRP_MENU_API to the local menu fixture URL.");
        return 0;
    }
    URL_COMPONENTS parts = {0};
    parts.dwStructSize = sizeof(parts);
    parts.lpszHostName = host; parts.dwHostNameLength = 256;
    parts.lpszUrlPath = path; parts.dwUrlPathLength = 768;
    // Remote deployments await authenticated native-session integration.
    if (!WinHttpCrackUrl(url, 0, 0, &parts) || parts.nScheme != INTERNET_SCHEME_HTTP ||
        wcscmp(host, L"127.0.0.1") || wcscmp(path, L"/v1/menu")) {
        strcpy(output, "The development menu API must be http://127.0.0.1:PORT/v1/menu.");
        return 0;
    }
    DWORD status = 0, size = sizeof(status), used = 0;
    DWORD started = GetTickCount();
    HINTERNET session = WinHttpOpen(L"SRP-menu/1", WINHTTP_ACCESS_TYPE_NO_PROXY,
        WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    HINTERNET connection = NULL, req = NULL;
    if (!session) goto failure;
    WinHttpSetTimeouts(session, 2000, 2000, 3000, 3000);
    connection = WinHttpConnect(session, host, parts.nPort, 0);
    if (!connection) goto failure;
    req = WinHttpOpenRequest(connection, L"POST", path, NULL, WINHTTP_NO_REFERER,
        WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
    if (!req) goto failure;
    DWORD redirects = WINHTTP_OPTION_REDIRECT_POLICY_NEVER;
    if (!WinHttpSetOption(req, WINHTTP_OPTION_REDIRECT_POLICY, &redirects, sizeof(redirects)))
        goto failure;
    if (native_session) {
        WCHAR authorization[80];
        // Loopback integration contract; remote deployment needs an exchange
        // for a stronger API credential and TLS, not this legacy 32-bit token.
        swprintf(authorization, 80, L"Authorization: SRP-Native-021d %08lx\r\n",
                 (unsigned long)native_session);
        if (!WinHttpAddRequestHeaders(req, authorization, -1,
                                      WINHTTP_ADDREQ_FLAG_ADD | WINHTTP_ADDREQ_FLAG_REPLACE))
            goto failure;
        LONG protocol = InterlockedCompareExchange(&match_protocol, 0, 0);
        const WCHAR *capability = protocol == 2 ? L"X-SRP-Match-Protocol: SRP1-48-R1\r\n"
                                               : L"X-SRP-Match-Protocol: SRP1-48\r\n";
        if (protocol && !WinHttpAddRequestHeaders(req, capability, -1,
                                      WINHTTP_ADDREQ_FLAG_ADD | WINHTTP_ADDREQ_FLAG_REPLACE))
            goto failure;
    }
    if (!WinHttpSendRequest(req, L"Content-Type: application/x-www-form-urlencoded\r\n", -1,
        (void *)data, (DWORD)strlen(data), (DWORD)strlen(data), 0) ||
        !WinHttpReceiveResponse(req, NULL) ||
        !WinHttpQueryHeaders(req, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
            WINHTTP_HEADER_NAME_BY_INDEX, &status, &size, WINHTTP_NO_HEADER_INDEX)) goto failure;
    for (;;) {
        DWORD read = 0;
        if (GetTickCount() - started > 8000) goto failure;
        if (used == capacity - 1) goto failure;
        if (!WinHttpReadData(req, output + used, capacity - used - 1, &read)) goto failure;
        if (!read) break;
        if (memchr(output + used, 0, read)) goto failure;
        used += read;
    }
    output[used] = 0;
    goto cleanup;
failure:
    status = 0;
    strcpy(output, "Menu service unavailable, timed out, or returned an oversized response.");
cleanup:
    if (req) WinHttpCloseHandle(req);
    if (connection) WinHttpCloseHandle(connection);
    if (session) WinHttpCloseHandle(session);
    return status;
}

static DWORD WINAPI worker(void *unused)
{
    (void)unused;
    for (;;) {
        WaitForSingleObject(wake, INFINITE);
        char data[BODY_LIMIT], token[40], id[24], output[REPLY_LIMIT];
        EnterCriticalSection(&lock);
        strcpy(data, body); strcpy(token, job_generation); strcpy(id, job_id);
        uint32_t native_session = job_session;
        uint64_t epoch = job_epoch;
        LeaveCriticalSection(&lock);
        DWORD status = request(data, native_session, output, sizeof(output));
        EnterCriticalSection(&lock);
        if (epoch == identity_epoch && !strcmp(token, generation)) {
            snprintf(completed, sizeof(completed), "%s\n%lu\n%s", id, status, output);
            state = 2;
        } else state = 0;
        LeaveCriticalSection(&lock);
    }
    return 0;
}

int srp_http_initialize(void)
{
    InitializeCriticalSection(&lock);
    wake = CreateEventA(NULL, FALSE, FALSE, NULL);
    if (!wake) return 0;
    HANDLE thread = CreateThread(NULL, 0, worker, NULL, 0, NULL);
    if (!thread) { CloseHandle(wake); return 0; }
    CloseHandle(thread);
    return 1;
}

void srp_http_set_identity(int preview, uint32_t native_session)
{
    preview = !!preview;
    if (preview) native_session = 0;
    EnterCriticalSection(&lock);
    if (preview != identity_preview || native_session != identity_session) {
        if (generation[0]) identity_notice = 1;
        identity_preview = preview;
        identity_session = native_session;
        ++identity_epoch;
        if (state && !strcmp(job_generation, generation))
            snprintf(invalidated, sizeof(invalidated),
                     "%s\n401\nThe lobby session changed. Open Matches again.", job_id);
        if (state == 2) state = 0;
    }
    LeaveCriticalSection(&lock);
}

static int identifier(const char *start, unsigned length)
{
    if (!length) return 0;
    for (unsigned i = 0; i < length; i++)
        if (!((start[i] >= '0' && start[i] <= '9') ||
              (start[i] >= 'a' && start[i] <= 'z') || start[i] == '-')) return 0;
    return 1;
}

int srp_http_command(const char *command, char *reply, unsigned capacity)
{
    int attach = !strncmp(command, "srp_attach/", 11);
    int poll = !strncmp(command, "srp_poll/", 9);
    int submit = !strncmp(command, "srp_request/", 12);
    if (!attach && !poll && !submit) return 0;
    reply[0] = 0;
    const char *token = command + (attach ? 11 : poll ? 9 : 12);
    const char *end = submit ? strchr(token, '/') : token + strlen(token);
    if (!end || end - token >= 40 || !identifier(token, (unsigned)(end - token))) return 1;
    char local_token[40];
    memcpy(local_token, token, end - token); local_token[end - token] = 0;
    EnterCriticalSection(&lock);
    if (attach) {
        if (strcmp(local_token, generation)) {
            strcpy(generation, local_token);
            invalidated[0] = 0;
            identity_notice = 0;
            if (state == 2) state = 0;
        }
    } else if (!strcmp(local_token, generation)) {
        if (poll && invalidated[0]) {
            if (strlen(invalidated) < capacity) strcpy(reply, invalidated);
            invalidated[0] = 0;
            identity_notice = 0;
        } else if (poll && state == 2) {
            if (strlen(completed) < capacity) strcpy(reply, completed);
            state = 0;
        } else if (submit) {
            const char *id = end + 1, *payload = strchr(id, '/');
            if (payload && payload - id < 24 && identifier(id, (unsigned)(payload - id)) &&
                strlen(payload + 1) < BODY_LIMIT) {
                if (identity_notice) {
                    snprintf(reply, capacity, "%.*s\n401\nThe lobby session changed. Open Matches again.",
                        (int)(payload - id), id);
                    identity_notice = 0;
                } else if (!identity_preview && !identity_session) {
                    snprintf(reply, capacity, "%.*s\n401\nSign in to the lobby before using Matches.",
                        (int)(payload - id), id);
                } else if (state) {
                    snprintf(reply, capacity, "%.*s\n0\nAnother request is still finishing. Try again.",
                        (int)(payload - id), id);
                } else {
                    strcpy(job_generation, local_token);
                    job_session = identity_session; job_epoch = identity_epoch;
                    memcpy(job_id, id, payload - id); job_id[payload - id] = 0;
                    strcpy(body, payload + 1); state = 1; SetEvent(wake);
                }
            }
        }
    }
    LeaveCriticalSection(&lock);
    return 1;
}
