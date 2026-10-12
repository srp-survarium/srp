// SPDX-License-Identifier: GPL-3.0-or-later
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "native_snapshot.h"
#include "native_tree.h"
#include "native_match.h"
#include "native_roundtrip.h"

_Static_assert(sizeof(void *) == 4, "retail 0.21d x86 layout");
struct mutable_buffer { void *allocator; unsigned char *data; uint32_t capacity, size; };
struct player { struct mutable_buffer state; void *tree; };
static int read_at(const void *base, unsigned offset, void *output, unsigned size)
{
    uintptr_t address = (uintptr_t)base;
    SIZE_T read;
    if (!address || address > UINTPTR_MAX - offset ||
        address + offset > UINTPTR_MAX - size) return 0;
    return ReadProcessMemory(GetCurrentProcess(), (void *)(address + offset), output, size, &read)
        && read == size;
}

static int inline_buffer(const void *item, unsigned offset, unsigned capacity,
                          struct mutable_buffer *out)
{
    return read_at(item, offset + capacity, out, sizeof(*out)) && !out->allocator &&
        out->data == (unsigned char *)item + offset && out->capacity == capacity &&
        out->size <= capacity;
}

unsigned srp_snapshot_serialize(unsigned char *module, const void *item, uint32_t mask,
                                unsigned char *output, unsigned capacity)
{
    unsigned char debug[2];
    if (!output || mask & ~0xfffffu ||
        !read_at(module, 0x1cf80f0, debug, sizeof(debug)) || debug[0] || debug[1]) return 0;
    // Stock dynamic state adds a four-byte time to the complete message.
    if (capacity > SRP_SNAPSHOT_LIMIT - 4) capacity = SRP_SNAPSHOT_LIMIT - 4;
    if ((uintptr_t)output > UINTPTR_MAX - capacity) return 0;
    struct player players[20] = {0};
    struct mutable_buffer world[4];
    static const unsigned starts[] = {0xb4690, 0xb6ab8, 0xb7908, 0xb76e0};
    static const unsigned limits[] = {0x2400, 0xc00, 0x2000, 0x200};
    unsigned minimum = 4 + 4 * 2;
    for (unsigned slot = 0; slot < 20; slot++) {
        if (!(mask & (1u << slot))) continue;
        if (!inline_buffer(item, slot * 0x9054, 0x800, &players[slot].state) ||
            !read_at(item, slot * 0x9054 + 0x1050, &players[slot].tree, sizeof(void *))) return 0;
        minimum += 3 + players[slot].state.size;
    }
    for (unsigned i = 0; i < 4; i++) {
        if (!inline_buffer(item, starts[i], limits[i], &world[i])) return 0;
        minimum += world[i].size;
    }
    if (minimum > capacity) return 0;
    memcpy(output, &mask, 4);
    unsigned used = 4, remaining = minimum - 4;
    for (unsigned slot = 0; slot < 20; slot++) {
        if (!(mask & (1u << slot))) continue;
        const struct player *player = players + slot;
        uint16_t size = (uint16_t)player->state.size;
        memcpy(output + used, &size, 2);
        if (!read_at(player->state.data, 0, output + used + 2, size)) return 0;
        used += size + 2;
        // Retail buffer_writer encodes true as 0xff, not C's integer 1.
        output[used++] = player->tree ? 0xff : 0;
        remaining -= size + 3;
        if (player->tree) {
            unsigned tree_size;
            // Reserve all remaining state/world bytes before invoking native
            // tree code. Its guarded bit writer also needs its trailing clear.
            if (!srp_tree_serialize(player->tree, output + used,
                                    capacity - used - remaining, &tree_size)) return 0;
            used += tree_size;
        }
    }
    for (unsigned i = 0; i < 4; i++) {
        uint16_t size = (uint16_t)world[i].size;
        memcpy(output + used, &size, 2);
        if (!read_at(world[i].data, 0, output + used + 2, size)) return 0;
        used += size + 2;
    }
    return used;
}

void *srp_capture_original_send;
static unsigned char *capture_module;
static void (*capture_log)(const char *);
static unsigned capture_stage;

unsigned srp_snapshot_current(unsigned char *module, const void *core,
                              unsigned char *output, unsigned capacity,
                              uint32_t *time, uint32_t *mask)
{
    uintptr_t item, membership;
    uint32_t maximum, interval, stamp, node[4];
    if (!time || !mask || !read_at(core, 0xc7f8, &maximum, 4) ||
        !read_at(core, 0xc7ec, &interval, 4) || maximum < interval ||
        !read_at(core, 0x2678, &item, 4)) return 0;
    int found = 0;
    for (unsigned i = 0; i < 256; i++) {
        if (!read_at((void *)item, 0xb9938, &stamp, 4)) break;
        if (stamp <= maximum - interval) { found = 1; break; }
        if (!read_at((void *)item, 0xb9930, &item, 4)) break;
    }
    if (!found || !read_at(core, 0x5ed8, &membership, 4)) return 0;
    found = 0;
    for (unsigned i = 0; i < 40; i++) {
        if (!read_at((void *)membership, 0, node, sizeof(node))) break;
        if (node[3] <= stamp) { found = 1; break; }
        membership = node[1];
    }
    if (!found || !stamp || stamp % 50) return 0;
    unsigned size = srp_snapshot_serialize(module, (void *)item, node[2], output, capacity);
    if (size) { *time = stamp; *mask = node[2]; }
    return size;
}

// Called by a naked adapter; keep externally visible to its assembler reference.
void srp_snapshot_capture_tick(void *network)
{
    static const uint32_t targets[] = {2000, 10000};
    uintptr_t match, core;
    uint32_t maximum, interval, time, mask;
    if (capture_stage >= 2 ||
        !read_at(network, 0x7a00, &match, 4) || !read_at((void *)match, 0x138, &core, 4) ||
        !read_at((void *)core, 0xc7f8, &maximum, 4) ||
        !read_at((void *)core, 0xc7ec, &interval, 4) || maximum < interval ||
        maximum - interval < targets[capture_stage]) return;
    unsigned target = targets[capture_stage++];
    unsigned char bytes[SRP_SNAPSHOT_LIMIT];
    unsigned size = srp_snapshot_current(capture_module, (void *)core,
                                        bytes + 4, sizeof(bytes) - 4, &time, &mask);
    char message[160], path[48];
    if (!size) {
        snprintf(message, sizeof(message), "snapshot capture rejected: target=%u", target);
        capture_log(message);
        return;
    }
    memcpy(bytes, &time, 4);
    snprintf(path, sizeof(path), "srp-snapshot-%u.bin", target);
    HANDLE file = CreateFileA(path, GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
    DWORD written = 0;
    int saved = file != INVALID_HANDLE_VALUE && WriteFile(file, bytes, size + 4, &written, NULL)
        && written == size + 4;
    if (file != INVALID_HANDLE_VALUE) CloseHandle(file);
    snprintf(message, sizeof(message), "snapshot capture %s: time=%lu mask=%05lx bytes=%u file=%s",
             saved ? "saved" : "write failed", (unsigned long)time, (unsigned long)mask, size + 4, path);
    capture_log(message);
    srp_roundtrip_check((void *)core, bytes, size + 4);
}

static void __attribute__((naked)) capture_hook(void)
{
    // try_send_all: EDI=network, stack=(time,can_send_hashes), ret 8.
    // Preserve its entire entry state and tail-call the original trampoline.
    __asm__("pushfl\npushal\npush %edi\ncall _srp_snapshot_capture_tick\n"
            "add $4,%esp\npopal\npopfl\njmp *_srp_capture_original_send\n");
}

static void capture_jump(unsigned char *out, const void *from, const void *to)
{
    out[0] = 0xe9;
    uint32_t relative = (uint32_t)(uintptr_t)to - (uint32_t)(uintptr_t)from - 5;
    memcpy(out + 1, &relative, 4);
}

int srp_snapshot_capture_initialize(unsigned char *module, void (*log)(const char *))
{
    static const unsigned char prologue[] = {0x55,0x8b,0xec,0x83,0xe4,0xf8,0x83,0xec,0x10};
    if (!log || capture_module || memcmp(module + 0x19310b, prologue, sizeof(prologue)) ||
        !srp_tree_initialize(module)) return 0;
    unsigned char *entry = module + 0x19310b;
    unsigned char *trampoline = VirtualAlloc(NULL, 14, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!trampoline) return 0;
    memcpy(trampoline, prologue, sizeof(prologue));
    capture_jump(trampoline + 9, trampoline + 9, entry + 9);
    DWORD old, ignored;
    if (!VirtualProtect(trampoline, 14, PAGE_EXECUTE_READ, &old)) return 0;
    unsigned char patch[9] = {0,0,0,0,0,0x90,0x90,0x90,0x90};
    capture_jump(patch, entry, capture_hook);
    if (!VirtualProtect(entry, sizeof(patch), PAGE_EXECUTE_READWRITE, &old)) return 0;
    srp_capture_original_send = trampoline;
    capture_module = module;
    capture_log = log;
    memcpy(entry, patch, sizeof(patch));
    if (!VirtualProtect(entry, sizeof(patch), old, &ignored)) return 0;
    FlushInstructionCache(GetCurrentProcess(), trampoline, 14);
    FlushInstructionCache(GetCurrentProcess(), entry, sizeof(patch));
    return 1;
}
