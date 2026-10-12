// SPDX-License-Identifier: GPL-3.0-or-later
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <string.h>
#include "native_tree.h"

_Static_assert(sizeof(void *) == 4, "retail 0.21d x86 layout");
struct mutable_buffer { void *allocator; unsigned char *data; uint32_t capacity, size; };
struct writer { uint32_t list[4], player_id; struct mutable_buffer *buffer; };
struct output_guard { uintptr_t begin, end; int failed; };
typedef void (__attribute__((stdcall)) *append_fn)(void *, uint32_t, unsigned);
typedef void (__attribute__((cdecl)) *serialize_fn)(void **, struct writer *);
static append_fn original_append;
static serialize_fn serialize_tree;
static DWORD guard_tls = TLS_OUT_OF_INDEXES;
static unsigned char *tree_module;

static void __attribute__((stdcall)) append_hook(void *self, uint32_t value, unsigned bits)
{
    struct output_guard *guard = TlsGetValue(guard_tls);
    if (guard) {
        if (guard->failed) return;
        uintptr_t cursor = *(uintptr_t *)((unsigned char *)self + 0x2024);
        unsigned bit = *(unsigned *)((unsigned char *)self + 0x202c);
        // The retail loop clears the following byte even when the last bit
        // exactly fills a byte. Account for that write, not just payload size.
        if (bit > 7 || bits > 32 || cursor < guard->begin || cursor >= guard->end ||
            (7 - bit + bits) / 8 >= guard->end - cursor ||
            (bits < 32 && (value >> bits))) {
            guard->failed = 1;
            return;
        }
    }
    original_append(self, value, bits);
}

static void jump(unsigned char *out, const void *from, const void *to)
{
    out[0] = 0xe9;
    uint32_t relative = (uint32_t)(uintptr_t)to - (uint32_t)(uintptr_t)from - 5;
    memcpy(out + 1, &relative, 4);
}

int srp_tree_initialize(unsigned char *module)
{
    if (tree_module) {
        unsigned char installed[9] = {0,0,0,0,0,0x90,0x90,0x90,0x90};
        jump(installed, tree_module + 0x23d52a, append_hook);
        return module == tree_module && !memcmp(module + 0x23d52a, installed, sizeof(installed));
    }
    // Whole instructions, no relative operands: push ebp; mov ebp,esp;
    // and esp,-8; sub esp,0x24. The aligned native frame stays in its trampoline.
    static const unsigned char prologue[] = {0x55,0x8b,0xec,0x83,0xe4,0xf8,0x83,0xec,0x24};
    if (guard_tls != TLS_OUT_OF_INDEXES ||
        memcmp(module + 0x23d52a, prologue, sizeof(prologue)) ||
        memcmp(module + 0x23d2bb, "\x55\x8b\xec\xb8\x34\x20\0\0", 8)) return 0;
    unsigned char *entry = module + 0x23d52a;
    unsigned char *trampoline = VirtualAlloc(NULL, 14, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!trampoline) return 0;
    memcpy(trampoline, prologue, sizeof(prologue));
    jump(trampoline + 9, trampoline + 9, entry + 9);
    DWORD old, ignored;
    if (!VirtualProtect(trampoline, 14, PAGE_EXECUTE_READ, &old)) {
        VirtualFree(trampoline, 0, MEM_RELEASE);
        return 0;
    }
    guard_tls = TlsAlloc();
    if (guard_tls == TLS_OUT_OF_INDEXES) {
        VirtualFree(trampoline, 0, MEM_RELEASE);
        return 0;
    }
    unsigned char patch[9] = {0,0,0,0,0,0x90,0x90,0x90,0x90};
    jump(patch, entry, append_hook);
    if (!VirtualProtect(entry, sizeof(patch), PAGE_EXECUTE_READWRITE, &old)) {
        TlsFree(guard_tls);
        guard_tls = TLS_OUT_OF_INDEXES;
        VirtualFree(trampoline, 0, MEM_RELEASE);
        return 0;
    }
    original_append = (append_fn)trampoline;
    serialize_tree = (serialize_fn)(module + 0x23d2bb);
    memcpy(entry, patch, sizeof(patch));
    if (!VirtualProtect(entry, sizeof(patch), old, &ignored)) return 0;
    FlushInstructionCache(GetCurrentProcess(), trampoline, 14);
    FlushInstructionCache(GetCurrentProcess(), entry, sizeof(patch));
    tree_module = module;
    return 1;
}

int srp_tree_serialize(void *tree, unsigned char *output, unsigned capacity, unsigned *written)
{
    if (written) *written = 0;
    // The constructor clears output[0] and later reads/updates output[2]
    // directly while filling the 16-bit length prefix. Reserve both upfront.
    if (!tree || !output || !written || capacity < 3 ||
        (uintptr_t)output > UINTPTR_MAX - capacity ||
        guard_tls == TLS_OUT_OF_INDEXES || TlsGetValue(guard_tls)) return 0;
    struct output_guard guard = {(uintptr_t)output, (uintptr_t)output + capacity, 0};
    struct mutable_buffer buffer = {NULL, output, capacity, 0};
    struct writer writer = {{0}, 0xff, &buffer};
    if (!TlsSetValue(guard_tls, &guard)) return 0;
    serialize_tree(&tree, &writer);
    TlsSetValue(guard_tls, NULL);
    if (guard.failed || buffer.size > capacity) return 0;
    *written = buffer.size;
    return 1;
}
