// SPDX-License-Identifier: GPL-3.0-or-later
/* Explicit F6 rejoin for the local direct-match path; no automatic queueing. */
typedef unsigned int u32;
typedef struct RejoinState {
    void *game;
    u32 port, completed, key_down;
    char host[256];
} RejoinState;
_Static_assert(sizeof(RejoinState) <= 512, "rejoin state section is 512 bytes");
#define state ((RejoinState *)REJOIN_STATE)
typedef int (__attribute__((stdcall)) *Counter)(unsigned long long *);
typedef u32 (__attribute__((stdcall)) *Environment)(const char *, char *, u32);
typedef int (__attribute__((thiscall)) *Disconnected)(void *);
typedef void (__attribute__((thiscall)) *Connect)(void *, const char *, unsigned short, u32, u32);
#ifndef REJOIN_COUNTER
#define REJOIN_COUNTER ((Counter)*(void **)0x870158)
#define REJOIN_DISCONNECTED ((Disconnected)0x27a020)
#define REJOIN_CONNECT ((Connect)0x21beb0)
#endif
#ifndef REJOIN_ENVIRONMENT
#define REJOIN_ENVIRONMENT ((Environment)*(void **)0x8701b4)
#endif

/* Optional stable identity issued by the local server configuration. Invalid
 * explicit values fail closed; missing/empty values retain per-launch QPC. */
u32 rejoin_session(u32 previous) {
    char token[10];
    u32 length = REJOIN_ENVIRONMENT("SRP_MATCH_SESSION", token, sizeof(token));
    if (length) {
        if (length != 8) return 0;
        u32 session = 0;
        for (u32 i = 0; i < length; ++i) {
            unsigned char c = token[i];
            u32 digit;
            if (c >= '0' && c <= '9') digit = c - '0';
            else if (c >= 'a' && c <= 'f') digit = c - 'a' + 10;
            else if (c >= 'A' && c <= 'F') digit = c - 'A' + 10;
            else return 0;
            session = (session << 4) | digit;
        }
        return session;
    }
    unsigned long long clock;
    if (!REJOIN_COUNTER(&clock)) return 0;
    u32 session = ((u32)clock ^ (u32)(clock >> 32)) | 1;
    if (session == previous) session ^= 2;
    return session;
}

void rejoin_configure(void *game, const char *host, u32 port, u32 spectator) {
    state->game = 0;
    state->completed = state->key_down = 0;
    if (!game || !host || !port || port > 65535 || spectator) return;
    u32 length = 0;
    while (length < sizeof(state->host) && host[length]) ++length;
    if (!length || length == sizeof(state->host)) return;
    for (u32 i = 0; i <= length; ++i) state->host[i] = host[i];
    state->port = port;
    state->game = game;
}

void rejoin_completed(void *game) {
    if (state->game == game) {
        state->completed = 1;
        state->key_down = 0;
    }
}

int rejoin_initial_results(void *game) {
    return state->game != game || !state->completed;
}

int rejoin_keyboard(void *lobby, u32 key, u32 action) {
    void *game = *(void **)((char *)lobby + 0x9c);
    if (key != 0x40 || !state->completed || !state->game || state->game != game) return 0;
    if (action == 2) { state->key_down = 0; return 1; }
    if (action != 1 || state->key_down) return 1;
    state->key_down = 1;
    if (*(unsigned char *)((char *)lobby + 0x313a)) return 1;
    void *network = *(void **)((char *)game + 0x53ac);
    if (!network || *(void **)((char *)network + 0x1f1c40)) return 1;
    void *match = *(void **)((char *)network + 0x1f1c48);
    if (!match || !REJOIN_DISCONNECTED(match)) return 1;
    u32 *previous = (u32 *)((char *)network + 0x1ee7ec);
    u32 session = rejoin_session(*previous);
    if (!session) return 1;
    *previous = session;
    // Native connect skips equal IDs; E4 supplies the actual server match ID.
    u32 current = *(u32 *)((char *)match + 0x577bc);
    REJOIN_CONNECT(network, state->host, state->port, current + 1, session);
    return 1;
}
