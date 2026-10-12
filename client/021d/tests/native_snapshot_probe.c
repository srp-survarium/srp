// SPDX-License-Identifier: GPL-3.0-or-later
// Executes the verified retail serializer on synthetic, SDK-free history data.
// No game entry point, rendering, server, session, or live-world pointer.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../dll/native_match.h"
#include "../dll/native_tree.h"
#include "../dll/native_snapshot.h"
#include "../dll/native_recovery.h"

_Static_assert(sizeof(void *) == 4, "x86 only");
void *native_history_ctor, *native_history_serialize;

static void __attribute__((naked)) history_ctor(void *item __attribute__((unused)))
{
    __asm__("push %esi\nmov 8(%esp),%esi\ncall *_native_history_ctor\npop %esi\nret\n");
}
static void __attribute__((naked)) history_serialize(
    void *item __attribute__((unused)), void *writer __attribute__((unused)),
    uint32_t mask __attribute__((unused)))
{
    // EAX=item; stack=(writer,mask); ret 8. Preserve our caller's frame.
    __asm__("push %ebp\nmov %esp,%ebp\nmov 8(%ebp),%eax\n"
            "push 16(%ebp)\npush 12(%ebp)\ncall *_native_history_serialize\n"
            "leave\nret\n");
}
struct mutable_buffer { void *allocator; unsigned char *data; uint32_t capacity, size; };
struct writer { uint32_t list[4]; uint32_t player_id; struct mutable_buffer *buffer; };
struct reader { const unsigned char *begin, *current; uint32_t size; };
typedef uint32_t (__attribute__((stdcall)) *deserialize_fn)(void *, struct reader *);
_Static_assert(sizeof(struct writer) == 0x18, "writer layout");
_Static_assert(sizeof(struct mutable_buffer) == 0x10, "buffer layout");

#define CHECK(test) do { if (!(test)) { fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#test); return 1; } } while (0)
static LONG CALLBACK fault(EXCEPTION_POINTERS *info)
{
    fprintf(stderr, "native probe fault %08lx at %08lx; stack return %08lx\n",
        info->ExceptionRecord->ExceptionCode, info->ContextRecord->Eip,
        *(DWORD *)(uintptr_t)info->ContextRecord->Esp);
    ExitProcess(2);
}
static void set_blob(unsigned char *item, unsigned start, unsigned capacity, const char *text)
{
    struct mutable_buffer *buffer = (void *)(item + start + capacity);
    // The original constructor must provide the expected embedded storage.
    if (buffer->data != item + start || buffer->capacity != capacity || buffer->allocator) abort();
    buffer->size = (uint32_t)strlen(text);
    memcpy(buffer->data, text, buffer->size);
}

static unsigned char *upload_expected;
static unsigned upload_size, upload_offset, upload_packets, upload_errors, upload_time = 50;
static void probe_log(const char *message) { puts(message); }
static unsigned char packet_storage[0x2ac];
static void * __attribute__((fastcall)) make_packet(
    void *self __attribute__((unused)), void *unused __attribute__((unused)), unsigned opcode)
{
    if (opcode != SRP_SNAPSHOT_OPCODE) upload_errors++;
    memset(packet_storage, 0, sizeof(packet_storage));
    struct mutable_buffer *buffer = (void *)(packet_storage + 0x284);
    *buffer = (struct mutable_buffer){NULL, packet_storage + 0x7b, 520, 1};
    struct writer *writer = (void *)(packet_storage + 0x294);
    writer->player_id = 0xff;
    writer->buffer = buffer;
    buffer->data[0] = (unsigned char)opcode;
    return packet_storage;
}
static void __attribute__((fastcall)) enqueue_packet(
    void *self __attribute__((unused)), void *unused __attribute__((unused)), void *packet)
{
    struct mutable_buffer *buffer = (void *)((unsigned char *)packet + 0x284);
    const unsigned char *data = buffer->data;
    unsigned count = upload_size - upload_offset;
    if (count > 480) count = 480;
    uint32_t time;
    uint16_t offset, total;
    memcpy(&time, data + 5, 4);
    memcpy(&offset, data + 9, 2);
    memcpy(&total, data + 11, 2);
    if (buffer->size != count + 13 || data[0] != SRP_SNAPSHOT_OPCODE ||
        memcmp(data + 1, "SRP1", 4) || time != upload_time || offset != upload_offset ||
        total != upload_size || memcmp(data + 13, upload_expected + upload_offset, count)) upload_errors++;
    upload_offset += count;
    upload_packets++;
}
int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    AddVectoredExceptionHandler(1, fault);
    CHECK(argc == 2);
    HMODULE module = LoadLibraryExA(argv[1], NULL, DONT_RESOLVE_DLL_REFERENCES);
    CHECK(module);
    unsigned char *base = (void *)module;
    printf("Mapped retail at %p\n", base);
    IMAGE_DOS_HEADER *dos = (void *)base;
    IMAGE_NT_HEADERS32 *pe = (void *)(base + dos->e_lfanew);
    CHECK(pe->FileHeader.TimeDateStamp == 0x53596ad3);
    // Windows/Wine can map an EXE with DONT_RESOLVE_DLL_REFERENCES without
    // relocating it. Apply only its declared HIGHLOW relocations in this
    // isolated harness; the game entry point and its imports stay untouched.
    uintptr_t actual = (uintptr_t)base;
    uint32_t operand = *(uint32_t *)(base + 0x1ede3e + 15);
    if (operand == 0x1d080f0 && actual != 0x10000) {
        IMAGE_DATA_DIRECTORY dir = pe->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC];
        CHECK(dir.Size && dir.VirtualAddress);
        for (DWORD offset = 0; offset < dir.Size;) {
            IMAGE_BASE_RELOCATION *block = (void *)(base + dir.VirtualAddress + offset);
            CHECK(block->SizeOfBlock >= 8 && block->SizeOfBlock <= dir.Size - offset);
            WORD *entries = (void *)(block + 1);
            for (DWORD j=0; j<(block->SizeOfBlock-8)/2; j++) {
                WORD type = entries[j] >> 12;
                if (!type) continue;
                CHECK(type == IMAGE_REL_BASED_HIGHLOW);
                DWORD *target = (void *)(base + block->VirtualAddress + (entries[j]&4095));
                DWORD previous, ignored;
                CHECK(VirtualProtect(target, 4, PAGE_EXECUTE_READWRITE, &previous));
                *target += (DWORD)actual - 0x10000;
                CHECK(VirtualProtect(target, 4, previous, &ignored));
            }
            offset += block->SizeOfBlock;
        }
        FlushInstructionCache(GetCurrentProcess(), base, pe->OptionalHeader.SizeOfImage);
    }
    CHECK(*(uint32_t *)(base + 0x1ede3e + 15) == (uint32_t)actual + 0x1cf80f0);
    CHECK(!memcmp(base + 0x1edb18, "\x53\x57\x6a\x13\x8b\xfe\x5b", 7));
    CHECK(!memcmp(base + 0x1ede3e, "\x55\x8b\xec\x51\x53\x8b\x5d\x08", 8));
    CHECK(base[0x1cf80f0] == 0 && base[0x1cf80f1] == 0); // debug allocators must stay unused
    native_history_ctor = base + 0x1edb18;
    native_history_serialize = base + 0x1ede3e;
    unsigned char *item = calloc(1, 0xb9954), *restored = calloc(1, 0xb9954);
    CHECK(item && restored);
    puts("Constructing synthetic history items");
    history_ctor(item); history_ctor(restored);
    set_blob(item, 0xb4690, 0x2400, "bul");
    set_blob(item, 0xb6ab8, 0xc00, "stat");
    set_blob(item, 0xb7908, 0x2000, "obj");
    set_blob(item, 0xb76e0, 0x200, "rule");
    unsigned char bytes[4096] = {0};
    struct mutable_buffer buffer = {NULL, bytes, sizeof(bytes), 0};
    struct writer writer = {{0}, 0xff, &buffer};
    set_blob(item, 0, 0x800, "first");
    set_blob(item, 19 * 0x9054, 0x800, "last");
    set_blob(item, 0x828, 0x800, "private-first");
    set_blob(item, 19 * 0x9054 + 0x828, 0x800, "private-last");
    static const unsigned char world[] = {
        3,0,'b','u','l', 4,0,'s','t','a','t',
        3,0,'o','b','j', 4,0,'r','u','l','e'};
    deserialize_fn deserialize = (deserialize_fn)(base + 0x1ee021);
    static const uint32_t masks[] = {0, 1, 0x80000, 0x80001, 0xfffff};
    for (unsigned test = 0; test < sizeof(masks)/sizeof(masks[0]); test++) {
        uint32_t mask = masks[test];
        unsigned char expected[4096] = {0}, incoming[4100] = {0x32,0,0,0};
        memcpy(expected, &mask, 4);
        unsigned size = 4;
        for (unsigned slot = 0; slot < 20; slot++) {
            if (!(mask & (1u << slot))) continue;
            const char *state = slot == 0 ? "first" : slot == 19 ? "last" : "";
            unsigned length = (unsigned)strlen(state);
            expected[size++] = (unsigned char)length;
            expected[size++] = 0;
            memcpy(expected + size, state, length);
            size += length;
            expected[size++] = 0; // absent animation tree
        }
        memcpy(expected + size, world, sizeof(world));
        size += sizeof(world);
        printf("Calling native serializer/deserializer, active mask %05lx\n", (unsigned long)mask);
        buffer.size = 0;
        history_serialize(item, &writer, mask);
        CHECK(buffer.size == size);
        CHECK(!memcmp(bytes, expected, size));
        unsigned char bounded[4096];
        CHECK(srp_snapshot_serialize(base, item, mask, bounded, sizeof(bounded)) == size);
        CHECK(!memcmp(bytes, bounded, size));
        // The stock receive form prefixes the history time; serialize omits it.
        memcpy(incoming + 4, bytes, size);
        struct reader reader = {incoming, incoming, size + 4};
        CHECK(deserialize(restored, &reader) == mask);
        CHECK(reader.current == incoming + size + 4);
        CHECK(*(uint32_t *)(restored + 0xb9938) == 50);
        CHECK(restored[0xb9941] == 1);
        if (mask & 1) CHECK(!memcmp(restored, "first", 5));
        if (mask & 0x80000) CHECK(!memcmp(restored + 19 * 0x9054, "last", 4));
        CHECK(*(uint32_t *)(restored + 0x828 + 0x80c) == 0);
        CHECK(*(uint32_t *)(restored + 19 * 0x9054 + 0x828 + 0x80c) == 0);
        CHECK(!memcmp(restored + 0xb4690, "bul", 3));
        CHECK(!memcmp(restored + 0xb6ab8, "stat", 4));
        CHECK(!memcmp(restored + 0xb7908, "obj", 3));
        CHECK(!memcmp(restored + 0xb76e0, "rule", 4));
    }
    puts("PASS: native LTO adapters, timestamp, active slots/order, omitted private state, four world buffers");

    // Exercise the actual production guard, native writer and patched orderer.
    unsigned char *core = calloc(1, 0xc820), *network = calloc(1, 0x7a20);
    unsigned char match[0x13c] = {0}, output[SRP_SNAPSHOT_LIMIT];
    uint32_t membership[4] = {0, 0, 0, 50}, time = 0;
    CHECK(core && network);
    *(void **)(core + 0x2678) = item;
    *(void **)(core + 0x5ed8) = membership;
    *(uint32_t *)(item + 0xb9938) = 50;
    CHECK(srp_match_bootstrap(base, core, output, sizeof(output), &time) == 26 && time == 50);
    membership[2] = 1;
    CHECK(!srp_match_bootstrap(base, core, output, sizeof(output), &time));
    membership[2] = 0;
    membership[3] = 100; // history newer than snapshot, with no previous node
    CHECK(!srp_match_bootstrap(base, core, output, sizeof(output), &time));
    membership[1] = (uint32_t)(uintptr_t)membership; // cyclic invalid history is bounded
    CHECK(!srp_match_bootstrap(base, core, output, sizeof(output), &time));
    membership[1] = 0;
    membership[3] = 50;
    *(uint32_t *)(core + 0xc808) = 1;
    CHECK(!srp_match_bootstrap(base, core, output, sizeof(output), &time));
    *(uint32_t *)(core + 0xc808) = 0;
    *(uint32_t *)(item + 0xb9938) = 100;
    CHECK(!srp_match_bootstrap(base, core, output, sizeof(output), &time));
    *(uint32_t *)(item + 0xb9938) = 50;
    CHECK(!srp_match_bootstrap(base, (void *)1, output, sizeof(output), &time));
    struct mutable_buffer *bullets = (void *)(item + 0xb6a90);
    bullets->size = bullets->capacity + 1;
    CHECK(!srp_match_bootstrap(base, core, output, sizeof(output), &time));
    static const unsigned starts[] = {0xb4690, 0xb6ab8, 0xb7908, 0xb76e0};
    static const unsigned capacities[] = {0x2400, 0xc00, 0x2000, 0x200};
    for (unsigned i = 0; i < 4; i++) {
        struct mutable_buffer *blob = (void *)(item + starts[i] + capacities[i]);
        blob->size = capacities[i];
        memset(blob->data, 0x31 + i, blob->size);
    }
    CHECK(!srp_match_bootstrap(base, core, output, 21003, &time));
    upload_size = srp_match_bootstrap(base, core, output, sizeof(output), &time);
    CHECK(upload_size == 21004);
    CHECK(srp_match_initialize(base, NULL));
    typedef void *(__attribute__((thiscall)) *info_fn)(void *, void *, unsigned);
    info_fn info = (info_fn)(base + 0x19144c);
    for (unsigned type = 0x40; type <= 0x48; type++) {
        unsigned char result[4] = {0};
        CHECK(info(NULL, result, type) == result);
        unsigned char expected_info[4] = {0xf4, 1, 0xc8, 0x7f};
        if (type == 0x44 || type == 0x46) memcpy(expected_info, "\xff\xff\xff\x3f", 4);
        if (type == 0x45) memcpy(expected_info, "\xc8\0\0\x7f", 4);
        CHECK(!memcmp(result, expected_info, 4));
    }
    void *vtable[8] = {0}, *client = vtable;
    vtable[6] = make_packet;
    vtable[7] = enqueue_packet;
    *(void **)(network + 0x7a00) = match;
    *(void **)(network + 0x7a08) = &client;
    *(void **)(match + 0x138) = core;
    upload_expected = output;
    CHECK(srp_match_upload(network));
    CHECK(upload_errors == 0 && upload_offset == upload_size && upload_packets == 44);
    puts("PASS: bootstrap rejection guards, maximum world buffers, stock orderer forwarding, SRP 0x48 and 44 native-written fragments");
    CHECK(!memcmp(base + 0x1931de, "\x83\xc0\x64\x3b\xc6", 5));
    CHECK(!memcmp(base + 0x193216, "\x83\xc1\x64\x3b\xce", 5));
    unsigned char *fake = calloc(1, 0x194000);
    CHECK(fake);
    memcpy(fake + 0x1931de, "\x83\xc0\x64\x3b\xc6", 5);
    CHECK(!srp_match_hash_every_step(fake)); // second guard fails: first remains intact
    CHECK(fake[0x1931e0] == 100);
    free(fake);
    CHECK(srp_match_hash_every_step(base));
    CHECK(!memcmp(base + 0x1931de, "\x83\xc0\x32\x3b\xc6", 5));
    CHECK(!memcmp(base + 0x193216, "\x83\xc1\x32\x3b\xce", 5));
    puts("PASS: opt-in hash pacing instruction guards and two exact constant edits");
    // A present tree with one identity-transformed object and no animation
    // nodes exercises its bit, time and compressed-float streams without SDKs.
    uint32_t tree[13] = {1};
    unsigned char object[0x88] = {0}, reference[4096], guarded[4096];
    for (unsigned i = 0; i < 4; i++) {
        *(float *)(object + i * 20) = 1.0f;
        *(float *)(object + 0x40 + i * 20) = 1.0f;
    }
    tree[6] = (uint32_t)(uintptr_t)object;
    tree[9] = 1;
    tree[11] = 12350;
    void *tree_ptr = tree;
    struct mutable_buffer tree_buffer = {NULL, reference, sizeof(reference), 0};
    struct writer tree_writer = {{0}, 0xff, &tree_buffer};
    typedef void (__attribute__((cdecl)) *tree_fn)(void **, struct writer *);
    tree_fn tree_serialize = (tree_fn)(base + 0x23d2bb);
    puts("Calling original present-tree serializer");
    tree_serialize(&tree_ptr, &tree_writer);
    CHECK(tree_buffer.size > 3 && tree_buffer.size < sizeof(reference));
    CHECK(tree[0] == 1);
    printf("Original present-tree payload: %lu bytes\n", (unsigned long)tree_buffer.size);
    CHECK(srp_tree_initialize(base));
    unsigned written;
    CHECK(srp_tree_serialize(tree, guarded, sizeof(guarded), &written));
    CHECK(written == tree_buffer.size && !memcmp(guarded, reference, written));
    CHECK(tree[0] == 1);
    // Put each tested output directly against a PAGE_NOACCESS boundary.
    // A failure must complete normally, preserve refcounts and discard output.
    unsigned char *pages = VirtualAlloc(NULL, 8192, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    DWORD page_old;
    CHECK(pages && VirtualProtect(pages + 4096, 4096, PAGE_NOACCESS, &page_old));
    for (unsigned capacity = 0; capacity <= tree_buffer.size + 1; capacity++) {
        unsigned char *small = pages + 4096 - capacity;
        int ok = srp_tree_serialize(tree, small, capacity, &written);
        CHECK(tree[0] == 1);
        if (capacity < tree_buffer.size) CHECK(!ok && written == 0);
        if (ok) CHECK(written == tree_buffer.size && !memcmp(small, reference, written));
        if (capacity == tree_buffer.size + 1) CHECK(ok);
    }
    VirtualFree(pages, 0, MEM_RELEASE);
    // Calls outside our scoped export keep their original bytes and semantics.
    tree_buffer.data = guarded; tree_buffer.size = 0;
    tree_serialize(&tree_ptr, &tree_writer);
    CHECK(tree_buffer.size == written && !memcmp(guarded, reference, written));
    puts("PASS: present-tree byte equivalence, protected output bounds, refcounts and stock forwarding");
    // Compare the complete bounded snapshot with the original history path,
    // including a present tree in both the first and last active player slots.
    for (unsigned i = 0; i < 4; i++) set_blob(item, starts[i], capacities[i], "world");
    *(void **)(item + 0x1050) = tree;
    *(void **)(item + 19 * 0x9054 + 0x1050) = tree;
    buffer.size = 0;
    history_serialize(item, &writer, 0x80001);
    unsigned snapshot_size = srp_snapshot_serialize(base, item, 0x80001, guarded, sizeof(guarded));
    printf("Populated snapshot: bounded=%u native=%lu\n", snapshot_size, (unsigned long)buffer.size);
    for (unsigned i = 0; i < snapshot_size && i < buffer.size; i++) {
        if (bytes[i] != guarded[i]) { printf("First differing byte: %u native=%02x bounded=%02x\n", i, bytes[i], guarded[i]); break; }
    }
    CHECK(snapshot_size == buffer.size && !memcmp(bytes, guarded, snapshot_size));
    CHECK(tree[0] == 1);
    // This synthetic zero-animation tree exercises serializer output only.
    // Retail deserialization assumes a nonempty animation-node list. A real
    // captured tree is required for the populated restore/round-trip test.
    CHECK(!srp_snapshot_serialize(base, item, 0x100000, guarded, sizeof(guarded)));
    pages = VirtualAlloc(NULL, 8192, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    CHECK(pages && VirtualProtect(pages + 4096, 4096, PAGE_NOACCESS, &page_old));
    for (unsigned capacity = 0; capacity <= snapshot_size + 1; capacity++) {
        unsigned char *small = pages + 4096 - capacity;
        unsigned size = srp_snapshot_serialize(base, item, 0x80001, small, capacity);
        if (capacity < snapshot_size) CHECK(!size);
        if (size) CHECK(size == snapshot_size && !memcmp(small, bytes, size));
        if (capacity == snapshot_size + 1) CHECK(size);
        CHECK(tree[0] == 1);
    }
    VirtualFree(pages, 0, MEM_RELEASE);
    // History and membership must both come from the event horizon, even
    // when newer entries and a different current mask exist.
    *(uint32_t *)(item + 0xb9938) = 200;
    *(uint32_t *)(restored + 0xb9938) = 250;
    *(void **)(restored + 0xb9930) = item;
    *(void **)(core + 0x2678) = restored;
    *(uint32_t *)(core + 0xc7f8) = 300;
    *(uint32_t *)(core + 0xc7ec) = 100;
    *(uint32_t *)(core + 0xc808) = 0xfffff;
    membership[2] = 0x80001; membership[3] = 100;
    uint32_t later_membership[4] = {0, (uint32_t)(uintptr_t)membership, 2, 250}, historical_mask;
    *(void **)(core + 0x5ed8) = later_membership;
    CHECK(srp_snapshot_current(base, core, guarded, sizeof(guarded), &time, &historical_mask) == snapshot_size);
    CHECK(time == 200 && historical_mask == 0x80001 && !memcmp(guarded, bytes, snapshot_size));
    *(void **)(restored + 0xb9930) = restored;
    CHECK(!srp_snapshot_current(base, core, guarded, sizeof(guarded), &time, &historical_mask));
    *(void **)(restored + 0xb9930) = item;
    later_membership[1] = (uint32_t)(uintptr_t)later_membership;
    CHECK(!srp_snapshot_current(base, core, guarded, sizeof(guarded), &time, &historical_mask));
    later_membership[1] = (uint32_t)(uintptr_t)membership;
    *(uint32_t *)(core + 0xc7ec) = 350;
    CHECK(!srp_snapshot_current(base, core, guarded, sizeof(guarded), &time, &historical_mask));
    puts("PASS: event-horizon history/membership selection, cycles and time underflow rejection");
    *(uint32_t *)(core + 0xc7ec) = 100;
    CHECK(srp_recovery_initialize(base, probe_log));
    typedef void (__attribute__((thiscall)) *receive_fn)(void *, unsigned, struct reader *);
    receive_fn receive = (receive_fn)(base + 0x191520);
    unsigned char command[5] = {'S','R','P','1',1};
    struct reader request = {command, command, sizeof(command)};
    upload_size = snapshot_size; upload_expected = bytes; upload_time = 200;
    upload_errors = upload_offset = upload_packets = 0;
    receive(network, 0x59, &request); // not yet in match stage 2
    CHECK(request.current == command + sizeof(command) && upload_packets == 0);
    *(uint32_t *)(network + 0x7a1c) = 2;
    command[4] = 9; request.current = command;
    receive(network, 0x59, &request);
    CHECK(request.current == command + sizeof(command) && upload_packets == 0);
    command[4] = 1; request.current = command;
    receive(network, 0x59, &request);
    CHECK(upload_errors == 0 && upload_offset == upload_size && upload_packets == 1);
    request.current = command;
    receive(network, 0x59, &request);
    CHECK(request.current == command + sizeof(command) && upload_packets == 1);
    puts("PASS: actual SRP request hook, stage/command guards, populated native upload and request throttling");
    for (unsigned slot = 0; slot < 20; slot++) {
        struct mutable_buffer *state = (void *)(item + slot * 0x9054 + 0x800);
        state->size = state->capacity;
    }
    CHECK(!srp_snapshot_serialize(base, item, 0xfffff, output, sizeof(output)));
    puts("PASS: complete populated snapshot equivalence, protected bounds and aggregate size rejection");
    free(core); free(network);
    free(item); free(restored); FreeLibrary(module);
    return 0;
}
