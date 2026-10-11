// SPDX-License-Identifier: GPL-3.0-or-later
// Retail 0.21d build 2010. No Scaleform SDK dependency.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "menu_http.h"
#include "native_session.h"
#include "native_match.h"
#include "native_snapshot.h"
#include "native_roundtrip.h"
#include "native_recovery.h"

_Static_assert(sizeof(void *) == 4, "Build this DLL for x86");

typedef void (__attribute__((thiscall)) *callback_fn)(
    void *, void *, const char *, const void *, unsigned);
typedef void *(__attribute__((thiscall)) *get_user_data_fn)(void *);

static callback_fn original_callback;
static unsigned probe_count;
static int initialized;
static int menu_preview;
void *srp_native_set_variable;

static void log_line(const char *text)
{
    char path[MAX_PATH];
    if (!GetModuleFileNameA(NULL, path, sizeof(path))) return;
    char *end = strrchr(path, '\\');
    if (!end || (size_t)(end - path) + 24 >= sizeof(path)) return;
    strcpy(end + 1, "srp-client.log");
    HANDLE file = CreateFileA(path, FILE_APPEND_DATA, FILE_SHARE_READ | FILE_SHARE_WRITE,
                              NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) return;
    DWORD written;
    WriteFile(file, text, (DWORD)strlen(text), &written, NULL);
    WriteFile(file, "\r\n", 2, &written, NULL);
    CloseHandle(file);
}

// LTO ABI at RVA 0x1a573a: EAX=value, stack=(movie,path), callee pops 8.
// This cdecl shim isolates that convention from the C compiler.
void __attribute__((naked)) srp_set_movie_string(
    void *movie __attribute__((unused)), const char *path __attribute__((unused)),
    const char *value __attribute__((unused)))
{
    __asm__("push %ebp\n"
            "mov %esp, %ebp\n"
            "mov 16(%ebp), %eax\n"
            "push 12(%ebp)\n"
            "push 8(%ebp)\n"
            "call *_srp_native_set_variable\n"
            "leave\n"
            "ret\n");
}

static void __attribute__((fastcall)) callback_hook(
    void *self, void *unused __attribute__((unused)), void *gfx_movie,
    const char *method, const void *args, unsigned count)
{
    if (method && !strncmp(method, "srp_", 4) && count == 0) {
        char reply[32832];
        srp_http_set_identity(menu_preview, menu_preview ? 0 :
            srp_native_lobby_session(GetModuleHandleA(NULL), self));
        if (srp_http_command(method, reply, sizeof(reply))) {
            if (reply[0]) {
                void **vtable = *(void ***)gfx_movie;
                void *movie = ((get_user_data_fn)vtable[0x98 / 4])(gfx_movie);
                if (movie) srp_set_movie_string(movie, "root.srpMenu.wireResponse", reply);
            }
            return;
        }
    }
    if (method && strcmp(method, "srp_probe_ack") == 0 && count == 0) {
        log_line("AS3 observed the native probe response");
        return;
    }
    if (method && strcmp(method, "srp_probe") == 0) {
        // Verified virtual GetUserData slot used by the original callback.
        void **vtable = *(void ***)gfx_movie;
        void *movie = ((get_user_data_fn)vtable[0x98 / 4])(gfx_movie);
        if (!movie || count) {
            log_line("probe rejected: unexpected movie or arguments");
            return;
        }
        char message[128];
        snprintf(message, sizeof(message), "SRP DLL connected: response %u", ++probe_count);
        srp_set_movie_string(movie, "root.srpMenu.response.text", message);
        log_line(message);
        return;
    }
    // Preview loads the lobby movie in the login scene. Its original commands
    // must not reach that scene's unrelated login handler.
    if (!menu_preview) original_callback(self, gfx_movie, method, args, count);
}

static int enable_menu_preview(unsigned char *base)
{
    char enabled[8];
    DWORD length = GetEnvironmentVariableA("SRP_MENU_PREVIEW", enabled, sizeof(enabled));
    if (length != 1 || enabled[0] != '1') return 1;
    static const char original[] = "resources/flash_movies/login_menu.swf";
    static const char replacement[] = "resources/flash_movies/lobby_menu.swf";
    char *path = (char *)base + 0x7fd8c0;
    if (memcmp(path, original, sizeof(original))) return 0;
    DWORD old_protect, ignored;
    if (!VirtualProtect(path, sizeof(original), PAGE_READWRITE, &old_protect)) return 0;
    memcpy(path, replacement, sizeof(replacement));
    if (!VirtualProtect(path, sizeof(original), old_protect, &ignored)) return 0;
    menu_preview = 1;
    log_line("development menu preview enabled; original callbacks suppressed");
    return 1;
}

static void relative_jump(unsigned char *out, const void *from, const void *to)
{
    out[0] = 0xe9;
    uint32_t relative = (uint32_t)(uintptr_t)to - (uint32_t)(uintptr_t)from - 5;
    memcpy(out + 1, &relative, 4);
}

static int wine_vram_floor(unsigned char *base)
{
    char enabled[8];
    DWORD length = GetEnvironmentVariableA("SRP_WINE_VRAM_FLOOR", enabled, sizeof(enabled));
    if (length != 1 || enabled[0] != '1') return 1;
    if (!GetProcAddress(GetModuleHandleA("ntdll.dll"), "wine_get_version")) return 0;
    unsigned char expected[] = {0x68,0x00,0x01,0x00,0x00,0x68,0,0,0,0,
                               0xe8,0x68,0x91,0x00,0x00};
    uint32_t text = (uint32_t)(uintptr_t)(base + 0x7e9208);
    memcpy(expected + 6, &text, 4); // Account for the loader's relocation.
    unsigned char *entry = base + 0xb9371;
    if (memcmp(entry, expected, sizeof(expected))) return 0;
    // At the too-small-memory branch, EDI holds the minimum. Return it in
    // EDX:EAX and use the existing epilogue. Only this failure branch changes.
    unsigned char replacement[15] = {0x8b,0xc7,0x33,0xd2,0xeb,0x0d,
                                     0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90};
    DWORD old_protect, ignored;
    if (!VirtualProtect(entry, 15, PAGE_EXECUTE_READWRITE, &old_protect)) return 0;
    memcpy(entry, replacement, sizeof(replacement));
    if (!VirtualProtect(entry, 15, old_protect, &ignored)) return 0;
    FlushInstructionCache(GetCurrentProcess(), entry, 15);
    log_line("optional Wine VRAM floor enabled");
    return 1;
}

// Called by our entry-point loader before the game's entry point runs.
// All initialization is outside DllMain; no concurrent game code is patched.
__declspec(dllexport) int __cdecl srp_initialize(void)
{
    if (initialized) return 1;
    unsigned char *base = (unsigned char *)GetModuleHandleA(NULL);
    IMAGE_DOS_HEADER *dos = (IMAGE_DOS_HEADER *)base;
    IMAGE_NT_HEADERS32 *pe = (IMAGE_NT_HEADERS32 *)(base + dos->e_lfanew);
    if (dos->e_magic != IMAGE_DOS_SIGNATURE || pe->Signature != IMAGE_NT_SIGNATURE ||
        pe->FileHeader.Machine != IMAGE_FILE_MACHINE_I386 ||
        pe->FileHeader.TimeDateStamp != 0x53596ad3) {
        log_line("unsupported game build");
        return 0;
    }
    static const unsigned char expected[] = {0x56,0x8b,0xf1,0x8b,0x4c,0x24,0x08};
    static const unsigned char set_expected[] =
        {0x55,0x8b,0xec,0x83,0xec,0x18,0x83,0x65,0xe8,0x00,0x89,0x45,0xf0};
    unsigned char *entry = base + 0x1a576e;
    if (memcmp(entry, expected, sizeof(expected)) ||
        memcmp(base + 0x1a573a, set_expected, sizeof(set_expected))) {
        log_line("hook precondition mismatch");
        return 0;
    }
    if (!wine_vram_floor(base)) {
        log_line("Wine VRAM floor precondition failed");
        return 0;
    }
    if (!enable_menu_preview(base)) {
        log_line("menu preview precondition failed");
        return 0;
    }
    if (!srp_http_initialize()) return 0;
    unsigned char *trampoline = VirtualAlloc(NULL, 12, MEM_COMMIT | MEM_RESERVE,
                                             PAGE_READWRITE);
    if (!trampoline) return 0;
    memcpy(trampoline, entry, 7); // Complete instructions; none are PC-relative.
    relative_jump(trampoline + 7, trampoline + 7, entry + 7);
    DWORD old_protect;
    if (!VirtualProtect(trampoline, 12, PAGE_EXECUTE_READ, &old_protect)) {
        VirtualFree(trampoline, 0, MEM_RELEASE);
        return 0;
    }
    FlushInstructionCache(GetCurrentProcess(), trampoline, 12);
    original_callback = (callback_fn)trampoline;
    srp_native_set_variable = base + 0x1a573a;
    unsigned char patch[7] = {0,0,0,0,0,0x90,0x90};
    relative_jump(patch, entry, callback_hook);
    if (!VirtualProtect(entry, 7, PAGE_EXECUTE_READWRITE, &old_protect)) {
        VirtualFree(trampoline, 0, MEM_RELEASE);
        return 0;
    }
    memcpy(entry, patch, sizeof(patch));
    DWORD ignored;
    if (!VirtualProtect(entry, 7, old_protect, &ignored)) {
        // Initialization fails and the loader exits; the game cannot run half-patched.
        return 0;
    }
    FlushInstructionCache(GetCurrentProcess(), entry, 7);
    char match_enabled[8];
    DWORD match_length = GetEnvironmentVariableA("SRP_MATCH_PROTOCOL", match_enabled, sizeof(match_enabled));
    if (match_length == 1 && match_enabled[0] == '1') {
        if (!srp_match_initialize(base, log_line)) {
            log_line("SRP match hooks failed initialization");
            return 0;
        }
        log_line("experimental SRP match protocol enabled");
        if (!srp_recovery_initialize(base, log_line)) {
            log_line("SRP recovery request hook failed initialization");
            return 0;
        }
        log_line("SRP versioned snapshot requests enabled");
        char hash_step[8];
        DWORD hash_length = GetEnvironmentVariableA("SRP_MATCH_HASH_STEP", hash_step, sizeof(hash_step));
        if (hash_length == 1 && hash_step[0] == '1') {
            if (!srp_match_hash_every_step(base)) {
                log_line("SRP hash diagnostic precondition failed");
                return 0;
            }
            log_line("diagnostic hash pacing: every 50 ms simulation step");
        }
        srp_http_enable_match_recovery();
        char capture[8];
        DWORD capture_length = GetEnvironmentVariableA("SRP_MATCH_CAPTURE", capture, sizeof(capture));
        if (capture_length == 1 && capture[0] == '1') {
            char roundtrip[8];
            DWORD roundtrip_length = GetEnvironmentVariableA("SRP_MATCH_ROUNDTRIP", roundtrip, sizeof(roundtrip));
            if (roundtrip_length == 1 && roundtrip[0] == '1') {
                if (!srp_roundtrip_initialize(base, log_line)) {
                    log_line("SRP snapshot roundtrip precondition failed");
                    return 0;
                }
                log_line("diagnostic scratch snapshot roundtrip enabled");
            }
            if (!srp_snapshot_capture_initialize(base, log_line)) {
                log_line("SRP snapshot capture initialization failed");
                return 0;
            }
            log_line("diagnostic local snapshot capture enabled");
        }
    }
    initialized = 1;
    log_line("SRP 0.21d Scaleform bridge initialized");
    return 1;
}

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
    (void)reserved;
    if (reason == DLL_PROCESS_ATTACH) DisableThreadLibraryCalls(instance);
    return TRUE;
}
