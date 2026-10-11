// SPDX-License-Identifier: GPL-3.0-or-later
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "native_recovery.h"
#include "native_snapshot.h"
#include "native_match.h"
#include "native_tree.h"

struct reader { const unsigned char *begin, *current; uint32_t size; };
typedef void (__attribute__((thiscall)) *receive_fn)(void *, unsigned, struct reader *);
static receive_fn original_receive;
static unsigned char *game_module;
static void (*recovery_log)(const char *);
static uintptr_t last_network;
static DWORD last_upload_tick;
static int uploaded_once;

static int read_at(const void *base, unsigned offset, void *out, unsigned size)
{
    uintptr_t address = (uintptr_t)base;
    SIZE_T read;
    return address && address <= UINTPTR_MAX - offset &&
        address + offset <= UINTPTR_MAX - size &&
        ReadProcessMemory(GetCurrentProcess(), (void *)(address + offset), out, size, &read) && read == size;
}

static void __attribute__((fastcall)) receive_hook(
    void *network, void *unused __attribute__((unused)), unsigned opcode, struct reader *input)
{
    struct reader value;
    unsigned char command[5];
    if (opcode != 0x59 || !read_at(input, 0, &value, sizeof(value)) ||
        (uintptr_t)value.begin > UINTPTR_MAX - value.size ||
        (uintptr_t)value.current < (uintptr_t)value.begin ||
        (uintptr_t)value.current > (uintptr_t)value.begin + value.size ||
        (uintptr_t)value.begin + value.size - (uintptr_t)value.current != sizeof(command) ||
        !read_at(value.current, 0, command, sizeof(command)) || memcmp(command, "SRP1", 4)) {
        original_receive(network, opcode, input);
        return;
    }
    // SRP owns only this versioned envelope; ordinary stock debug traffic
    // still reaches the original handler. Never parse network-supplied state.
    input->current = value.begin + value.size;
    if (command[4] != 1) { recovery_log("SRP snapshot request rejected: command"); return; }
    uintptr_t match, core;
    uint32_t stage;
    if (!read_at(network, 0x7a1c, &stage, 4) || stage != 2 ||
        !read_at(network, 0x7a00, &match, 4) ||
        !read_at((void *)match, 0x138, &core, 4)) return;
    // The server asks every five seconds. Bound work if duplicate requests
    // arrive more rapidly; DWORD subtraction handles clock wraparound.
    DWORD now = GetTickCount();
    if (uploaded_once && last_network == (uintptr_t)network && now - last_upload_tick < 1000) return;
    uploaded_once = 1;
    last_network = (uintptr_t)network;
    last_upload_tick = now;
    unsigned char bytes[SRP_SNAPSHOT_LIMIT];
    uint32_t time, mask;
    unsigned size = srp_snapshot_current(game_module, (void *)core, bytes, sizeof(bytes), &time, &mask);
    if (!size || !mask || time <= 50 || !srp_match_send_snapshot(network, bytes, size, time)) {
        recovery_log("SRP requested snapshot not queued: history/output precondition"); return;
    }
    char message[128];
    snprintf(message, sizeof(message), "SRP requested snapshot queued: time=%lu mask=%05lx bytes=%u opcode=48",
             (unsigned long)time, (unsigned long)mask, size);
    recovery_log(message);
}

int srp_recovery_initialize(unsigned char *module, void (*log)(const char *))
{
    static const unsigned char prologue[] = {0x55,0x8b,0xec,0x83,0xec,0x6c,0x83,0x65,0xfc,0x00};
    if (!log || game_module || memcmp(module + 0x191520, prologue, sizeof(prologue)) ||
        !srp_tree_initialize(module)) return 0;
    unsigned char *entry = module + 0x191520;
    unsigned char *trampoline = VirtualAlloc(NULL, 15, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!trampoline) return 0;
    memcpy(trampoline, prologue, sizeof(prologue));
    trampoline[10] = 0xe9;
    uint32_t relative = (uint32_t)(uintptr_t)(entry + 10) - (uint32_t)(uintptr_t)(trampoline + 15);
    memcpy(trampoline + 11, &relative, 4);
    DWORD old, ignored;
    if (!VirtualProtect(trampoline, 15, PAGE_EXECUTE_READ, &old)) return 0;
    unsigned char patch[10] = {0xe9,0,0,0,0,0x90,0x90,0x90,0x90,0x90};
    relative = (uint32_t)(uintptr_t)receive_hook - (uint32_t)(uintptr_t)(entry + 5);
    memcpy(patch + 1, &relative, 4);
    if (!VirtualProtect(entry, sizeof(patch), PAGE_EXECUTE_READWRITE, &old)) return 0;
    original_receive = (receive_fn)trampoline;
    game_module = module;
    recovery_log = log;
    memcpy(entry, patch, sizeof(patch));
    if (!VirtualProtect(entry, sizeof(patch), old, &ignored)) return 0;
    FlushInstructionCache(GetCurrentProcess(), trampoline, 15);
    FlushInstructionCache(GetCurrentProcess(), entry, sizeof(patch));
    return 1;
}
