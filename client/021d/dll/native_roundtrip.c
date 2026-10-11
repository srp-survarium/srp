// SPDX-License-Identifier: GPL-3.0-or-later
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "native_roundtrip.h"
#include "native_snapshot.h"
#include "native_match.h"

_Static_assert(sizeof(void *) == 4, "retail x86 only");
static unsigned char *module_base;
static void (*diagnostic_log)(const char *);
void *srp_roundtrip_ctor, *srp_roundtrip_resolve;
struct reader { const unsigned char *begin, *current; uint32_t size; };
typedef uint32_t (__attribute__((stdcall)) *decode_fn)(void *, struct reader *);
typedef void (__attribute__((stdcall)) *destroy_fn)(void *);

static void __attribute__((naked)) construct(void *item __attribute__((unused)))
{
    __asm__("push %esi\nmov 8(%esp),%esi\ncall *_srp_roundtrip_ctor\npop %esi\nret\n");
}
static void __attribute__((naked)) resolve(
    void *tree_ref __attribute__((unused)), void *player __attribute__((unused)))
{
    // EAX=&tree; stack=(animation_player); ret 4. The stock caller at
    // RVA 0x1c652e uses base_player + 0x350 for the animation player.
    __asm__("mov 4(%esp),%eax\npush 8(%esp)\ncall *_srp_roundtrip_resolve\nret\n");
}
static int read_memory(const void *at, void *out, unsigned size)
{
    SIZE_T read;
    return ReadProcessMemory(GetCurrentProcess(), at, out, size, &read) && read == size;
}

int srp_roundtrip_initialize(unsigned char *module, void (*log)(const char *))
{
    if (!log || module_base ||
        memcmp(module + 0x1edb18, "\x53\x57\x6a\x13\x8b\xfe\x5b", 7) ||
        memcmp(module + 0x1edcbc, "\x55\x8b\xec\x53\x8b\x5d\x08", 7) ||
        memcmp(module + 0x1ee021, "\x55\x8b\xec\x51\x53\x8b\x5d\x0c", 8) ||
        memcmp(module + 0x23cf99, "\x55\x8b\xec\x81\xec\x48\x01\x00\x00", 9)) return 0;
    module_base = module;
    diagnostic_log = log;
    srp_roundtrip_ctor = module + 0x1edb18;
    srp_roundtrip_resolve = module + 0x23cf99;
    return 1;
}

void srp_roundtrip_check(const void *core, const unsigned char *bytes, unsigned size)
{
    if (!module_base || !bytes || size < 16 || size > SRP_SNAPSHOT_LIMIT) return;
    uint32_t time, mask;
    memcpy(&time, bytes, 4); memcpy(&mask, bytes + 4, 4);
    if (!mask || (mask & ~0xfffffu)) return;
    uintptr_t vector[3], players[20] = {0};
    uintptr_t inline_begin = (uintptr_t)core + 0xc0b4;
    if (!read_memory((const unsigned char *)core + 0xc0a8, vector, sizeof(vector)) ||
        vector[0] != inline_begin || vector[1] < vector[0] ||
        vector[1] > inline_begin + 80 || (vector[1] - vector[0]) % 4) {
        diagnostic_log("snapshot roundtrip rejected: loaded player vector"); return;
    }
    unsigned count = (unsigned)(vector[1] - vector[0]) / 4;
    for (unsigned slot = 0; slot < 20; slot++) {
        if (!(mask & (1u << slot))) continue;
        unsigned char id;
        uintptr_t animation_resolver, object_resolver;
        if (slot >= count || !read_memory((void *)(vector[0] + slot * 4), players + slot, 4) ||
            !players[slot] || players[slot] > UINTPTR_MAX - 0x10410 ||
            !read_memory((void *)(players[slot] + 0x130), &id, 1) || id != slot ||
            !read_memory((void *)(players[slot] + 0x103b0), &animation_resolver, 4) ||
            !read_memory((void *)(players[slot] + 0x103f0), &object_resolver, 4) ||
            !animation_resolver || !object_resolver) {
            diagnostic_log("snapshot roundtrip rejected: loaded player resolver"); return;
        }
    }
    unsigned char *item = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 0xb9954);
    unsigned char *output = HeapAlloc(GetProcessHeap(), 0, SRP_SNAPSHOT_LIMIT);
    if (!item || !output) {
        if (item) HeapFree(GetProcessHeap(), 0, item);
        if (output) HeapFree(GetProcessHeap(), 0, output);
        diagnostic_log("snapshot roundtrip rejected: allocation"); return;
    }
    construct(item);
    struct reader input = {bytes, bytes, size};
    char message[192];
    snprintf(message, sizeof(message), "snapshot roundtrip decoding: time=%lu mask=%05lx bytes=%u",
             (unsigned long)time, (unsigned long)mask, size);
    diagnostic_log(message);
    uint32_t decoded = ((decode_fn)(module_base + 0x1ee021))(item, &input);
    uint32_t decoded_time;
    memcpy(&decoded_time, item + 0xb9938, 4);
    if (decoded != mask || decoded_time != time || input.current != bytes + size) {
        diagnostic_log("snapshot roundtrip rejected: decoder result"); goto cleanup;
    }
    for (unsigned slot = 0; slot < 20; slot++) {
        if (!(mask & (1u << slot))) continue;
        unsigned char *state = item + slot * 0x9054;
        uintptr_t tree;
        memcpy(&tree, state + 0x1050, 4);
        if (!tree) continue;
        if (tree < (uintptr_t)(state + 0x1054) || tree > (uintptr_t)(state + 0x9054 - 0x34)) {
            diagnostic_log("snapshot roundtrip rejected: decoded tree storage"); goto cleanup;
        }
        snprintf(message, sizeof(message), "snapshot roundtrip resolving: slot=%u", slot);
        diagnostic_log(message);
        resolve(state + 0x1050, (void *)(players[slot] + 0x350));
    }
    diagnostic_log("snapshot roundtrip reserializing resolved history");
    unsigned written = srp_snapshot_serialize(module_base, item, mask, output, SRP_SNAPSHOT_LIMIT);
    unsigned different = 0;
    while (different < written && different < size - 4 && output[different] == bytes[different + 4])
        different++;
    int equal = written == size - 4 && different == written;
    snprintf(message, sizeof(message), "snapshot roundtrip %s: time=%lu body=%u expected=%u first_difference=%u",
             equal ? "PASS" : "MISMATCH", (unsigned long)time, written, size - 4, different);
    diagnostic_log(message);
cleanup:
    ((destroy_fn)(module_base + 0x1edcbc))(item);
    HeapFree(GetProcessHeap(), 0, output);
    HeapFree(GetProcessHeap(), 0, item);
    diagnostic_log("snapshot roundtrip scratch history released");
}
