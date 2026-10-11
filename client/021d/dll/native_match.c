// SPDX-License-Identifier: GPL-3.0-or-later
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "native_match.h"

_Static_assert(sizeof(void *) == 4, "retail 0.21d x86 layout");
struct mutable_buffer { void *allocator; unsigned char *data; uint32_t capacity, size; };
struct writer { uint32_t list[4], player_id; struct mutable_buffer *buffer; };
struct sending_info { uint16_t resend; unsigned char deviation, flags; };
typedef void (__attribute__((thiscall)) *ready_fn)(void *, void *);
typedef void *(__attribute__((thiscall)) *info_fn)(void *, struct sending_info *, unsigned);
typedef void *(__attribute__((thiscall)) *new_packet_fn)(void *, unsigned);
typedef void (__attribute__((thiscall)) *enqueue_fn)(void *, void *);
typedef void (__attribute__((stdcall)) *write_fn)(void *, const void *, unsigned);
static ready_fn original_ready;
static info_fn original_info;
static unsigned char *game_module;
static void (*match_log)(const char *);

static int read_at(uintptr_t address, unsigned offset, void *value, SIZE_T size)
{
    SIZE_T read = 0;
    if (!address || address > UINTPTR_MAX - offset ||
        address + offset > UINTPTR_MAX - size) return 0;
    return ReadProcessMemory(GetCurrentProcess(), (void *)(address + offset),
                             value, size, &read) && read == size;
}
#define READ(address, offset, value) read_at((uintptr_t)(address), offset, &(value), sizeof(value))

// LTO: EAX=item, stack=(writer,mask), ret 8. Pass the function explicitly so
// the isolated probe can use a separately mapped retail module.
static void __attribute__((naked)) serialize(
    void *function __attribute__((unused)), void *item __attribute__((unused)),
    void *writer __attribute__((unused)))
{
    __asm__("push %ebp\nmov %esp,%ebp\nmov 12(%ebp),%eax\n"
            "push $0\npush 16(%ebp)\ncall *8(%ebp)\nleave\nret\n");
}

unsigned srp_match_bootstrap(unsigned char *module, const void *core,
                             unsigned char *output, unsigned capacity, uint32_t *time)
{
    uintptr_t item, membership;
    uint32_t stamp, mask, node[4];
    unsigned char debug[2];
    // No present-animation-tree branch is reachable with this initial mask.
    // Native objects stay on their owning simulation thread throughout export.
    if (!output || !time || !READ(module, 0x1cf80f0, debug) || debug[0] || debug[1] ||
        !READ(core, 0xc808, mask) || mask || !READ(core, 0x2678, item) ||
        !READ(item, 0xb9938, stamp) || stamp != 50 ||
        !READ(core, 0x5ed8, membership)) return 0;
    unsigned visited;
    for (visited = 0; visited < 40; visited++) {
        if (!READ(membership, 0, node)) return 0;
        if (node[3] <= stamp) break;
        membership = node[1]; // previous membership, not today's mask
    }
    if (visited == 40 || node[2]) return 0;

    static const unsigned starts[] = {0xb4690, 0xb6ab8, 0xb7908, 0xb76e0};
    static const unsigned capacities[] = {0x2400, 0xc00, 0x2000, 0x200};
    unsigned required = 4 + 4 * 2;
    for (unsigned i = 0; i < 4; i++) {
        struct mutable_buffer buffer;
        if (!READ(item, starts[i] + capacities[i], buffer) || buffer.allocator ||
            buffer.data != (unsigned char *)item + starts[i] ||
            buffer.capacity != capacities[i] || buffer.size > buffer.capacity) return 0;
        required += buffer.size;
    }
    if (required > capacity || required > SRP_SNAPSHOT_LIMIT) return 0;
    struct mutable_buffer buffer = {NULL, output, capacity, 0};
    struct writer writer = {{0}, 0xff, &buffer};
    serialize(module + 0x1ede3e, (void *)item, &writer);
    if (buffer.size != required) return 0;
    *time = stamp;
    return buffer.size;
}

static void * __attribute__((fastcall)) info_hook(
    void *self, void *unused __attribute__((unused)), struct sending_info *out, unsigned opcode)
{
    if (opcode != SRP_SNAPSHOT_OPCODE) return original_info(self, out, opcode);
    out->resend = 500;
    out->deviation = 200;
    out->flags = 0x7f; // reliable, unordered, channel 63
    return out;
}

int srp_match_send_snapshot(void *network, const unsigned char *bytes, unsigned size, uint32_t time)
{
    uintptr_t client, vtable, make, enqueue;
    if (!bytes || !size || size > SRP_SNAPSHOT_LIMIT || !game_module ||
        !READ(network, 0x7a08, client) || !READ(client, 0, vtable) ||
        !READ(vtable, 0x18, make) || !READ(vtable, 0x1c, enqueue) || !make || !enqueue) return 0;
    for (unsigned offset = 0; offset < size;) {
        unsigned count = size - offset;
        if (count > 480) count = 480;
        unsigned char fragment[492] = {'S', 'R', 'P', '1'};
        uint16_t start = (uint16_t)offset, total = (uint16_t)size;
        memcpy(fragment + 4, &time, 4);
        memcpy(fragment + 8, &start, 2);
        memcpy(fragment + 10, &total, 2);
        memcpy(fragment + 12, bytes + offset, count);
        unsigned char *packet = ((new_packet_fn)make)((void *)client, SRP_SNAPSHOT_OPCODE);
        if (!packet) return 0;
        // A complete application message fits the stock 520-byte packet buffer.
        ((write_fn)(game_module + 0x145ebe))(packet + 0x294, fragment, count + 12);
        ((enqueue_fn)enqueue)((void *)client, packet);
        offset += count;
    }
    return 1;
}

int srp_match_upload(void *network)
{
    uintptr_t match, core;
    if (!READ(network, 0x7a00, match) || !READ(match, 0x138, core)) return 0;
    unsigned char bytes[SRP_SNAPSHOT_LIMIT];
    uint32_t time;
    unsigned size = srp_match_bootstrap(game_module, (void *)core, bytes, sizeof(bytes), &time);
    if (!size || !srp_match_send_snapshot(network, bytes, size, time)) return 0;
    if (match_log) {
        char message[100];
        snprintf(message, sizeof(message), "SRP bootstrap queued: time=%lu bytes=%u opcode=48",
                 (unsigned long)time, size);
        match_log(message);
    }
    return 1;
}

static void __attribute__((fastcall)) ready_hook(
    void *self, void *unused __attribute__((unused)), void *result)
{
    original_ready(self, result); // Stock loading/binding and 0x42 readiness.
    if (!srp_match_upload(self) && match_log)
        match_log("SRP bootstrap not queued: initial snapshot preconditions failed");
}

static void jump(unsigned char *out, const void *from, const void *to)
{
    out[0] = 0xe9;
    uint32_t relative = (uint32_t)(uintptr_t)to - (uint32_t)(uintptr_t)from - 5;
    memcpy(out + 1, &relative, 4);
}

// These two seven-byte prologues contain complete non-PC-relative instructions.
static void *prepare(unsigned char *entry)
{
    unsigned char *trampoline = VirtualAlloc(NULL, 12, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!trampoline) return NULL;
    memcpy(trampoline, entry, 7);
    jump(trampoline + 7, trampoline + 7, entry + 7);
    DWORD old;
    if (!VirtualProtect(trampoline, 12, PAGE_EXECUTE_READ, &old)) {
        VirtualFree(trampoline, 0, MEM_RELEASE);
        return NULL;
    }
    FlushInstructionCache(GetCurrentProcess(), trampoline, 12);
    return trampoline;
}

static int install(unsigned char *entry, void *hook)
{
    unsigned char patch[7] = {0,0,0,0,0,0x90,0x90};
    jump(patch, entry, hook);
    DWORD old, ignored;
    if (!VirtualProtect(entry, 7, PAGE_EXECUTE_READWRITE, &old)) return 0;
    memcpy(entry, patch, 7);
    if (!VirtualProtect(entry, 7, old, &ignored)) return 0;
    FlushInstructionCache(GetCurrentProcess(), entry, 7);
    return 1;
}

int srp_match_initialize(unsigned char *module, void (*log)(const char *))
{
    if (memcmp(module + 0x1925cc, "\x55\x8b\xec\x51\x51\x53\x56", 7) ||
        memcmp(module + 0x19144c, "\x55\x8b\xec\x0f\xb6\x45\x0c", 7) ||
        memcmp(module + 0x1ede3e, "\x55\x8b\xec\x51\x53\x8b\x5d\x08", 8) ||
        memcmp(module + 0x145ebe, "\x55\x8b\xec\x8b\x45\x08\x53\x56", 8)) return 0;
    original_info = (info_fn)prepare(module + 0x19144c);
    original_ready = (ready_fn)prepare(module + 0x1925cc);
    if (!original_info || !original_ready) return 0;
    game_module = module;
    match_log = log;
    return install(module + 0x19144c, info_hook) && install(module + 0x1925cc, ready_hook);
}

int srp_match_hash_every_step(unsigned char *module)
{
    // try_send_all has an early-out check and the actual hash pacing check.
    // Change both constants only; keep stock hash selection and wire format.
    if (memcmp(module + 0x1931de, "\x83\xc0\x64\x3b\xc6", 5) ||
        memcmp(module + 0x193216, "\x83\xc1\x64\x3b\xce", 5)) return 0;
    const unsigned offsets[] = {0x1931e0, 0x193218};
    for (unsigned i = 0; i < 2; i++) {
        DWORD old, ignored;
        unsigned char *constant = module + offsets[i];
        if (!VirtualProtect(constant, 1, PAGE_EXECUTE_READWRITE, &old)) return 0;
        *constant = 50;
        if (!VirtualProtect(constant, 1, old, &ignored)) return 0;
        FlushInstructionCache(GetCurrentProcess(), constant, 1);
    }
    return 1;
}
