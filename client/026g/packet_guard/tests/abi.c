// SPDX-License-Identifier: GPL-3.0-or-later

/* C linkage test only. All parsing and decompression lives in Rust. */
#define _GNU_SOURCE
#include "guard.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(__unix__)
#include <sys/mman.h>
#include <unistd.h>
#endif
void *pg_host_alloc(size_t size, size_t alignment) {
    void *p = NULL;
    if (alignment < sizeof(void *)) alignment = sizeof(void *);
    if (posix_memalign(&p, alignment, size) != 0) return NULL;
    return p;
}
void pg_host_free(void *p, size_t size, size_t alignment) { (void)size; (void)alignment; free(p); }
void pg_host_abort(void) { abort(); }
static int32_t reject(void *context, uint32_t op, const uint8_t *p, uint32_t n) {
    (void)context; (void)op; (void)p; (void)n; return 12345;
}
int main(void) {
    const uint8_t login[] = {8,1,0,0,0,127,0,0,1,210,4};
    const uint8_t packet[] = {0,0,0,0xe3,1,0,2,0};
    const uint8_t compressed[] = {1,0,2,'a','b','c',0};
    struct pg_frame frames[2], complete;
    struct pg_frame first = {0xe8,7,0,2,(const uint8_t *)"abc",3};
    struct pg_frame second = {0xe8,7,1,0,(const uint8_t *)"def",3};
    struct pg_callbacks callbacks = {0};
    uint32_t n = 99, consumed = 0, response_size = 0;
    const uint8_t *response = NULL;
    uint8_t output[32];
    void *stream = pg_host_alloc(pg_login_size(), pg_login_align());
    void *assembly = pg_host_alloc(pg_reassembly_size(), pg_reassembly_align());
    assert(stream && assembly);
    assert(pg_login(PG_LOGIN_PASSWORD_REPLY, login, sizeof(login)) == PG_OK);
    assert(pg_login(999, login, sizeof(login)) == PG_INVALID);
    assert(pg_login(PG_LOGIN_PASSWORD_REPLY, NULL, 1) == PG_INVALID);
    assert(pg_login_init(stream, pg_login_size()) == PG_OK);
    assert(pg_login_feed(stream, pg_login_size(), PG_LOGIN_PASSWORD_REPLY, login, 3,
                         &consumed, &response, &response_size) == PG_MORE);
    assert(consumed == 3 && response_size == 0 && response == NULL);
    assert(pg_login_feed(stream, pg_login_size(), PG_LOGIN_PASSWORD_REPLY, login + 3, sizeof(login) - 3,
                         &consumed, &response, &response_size) == PG_OK);
    assert(consumed == 8 && response_size == sizeof(login) && !memcmp(response, login, sizeof(login)));
    assert(pg_udp(PG_MATCH, 2, packet, sizeof(packet), frames, 2, &n) == PG_OK);
    assert(n == 1 && frames[0].opcode == 0xe3 && frames[0].size == 4 && frames[0].body == packet + 4);
    assert(frames[0].index == PG_ABSENT && frames[0].delivery == PG_ABSENT);
    assert(pg_udp(PG_MATCH, 2, packet, sizeof(packet) - 1, frames, 2, &n) != PG_OK && n == 0);
    assert(pg_udp(999, 2, packet, sizeof(packet), frames, 2, &n) != PG_OK && n == 0);
    assert(pg_reassembly_init(assembly, pg_reassembly_size()) == PG_OK);
    assert(pg_reassemble(assembly, pg_reassembly_size(), PG_MATCH, &first, 0, &complete) == PG_FRAGMENT_PENDING);
    assert(pg_reassemble(assembly, pg_reassembly_size(), PG_MATCH, &second, 1, &complete) == PG_OK);
    assert(complete.size == 6 && !memcmp(complete.body, "abcdef", 6));
    callbacks.lobby_schema = reject;
    assert(pg_lobby(0x81, packet, 1, &callbacks) == PG_UNSUPPORTED);
    assert(pg_lobby(0x81, packet, 1, NULL) == PG_UNSUPPORTED);
    assert(pg_lobby(0x80, packet, 2, NULL) == PG_OK);
    assert(pg_decode(compressed, sizeof(compressed), output, sizeof(output), &n) == PG_OK);
    assert(n == 3 && !memcmp(output, "abc", 3));
    assert(pg_decode(compressed, sizeof(compressed), output, 2, &n) != PG_OK && n == 0);
#if defined(__unix__)
    {
        long page = sysconf(_SC_PAGESIZE);
        uint8_t *memory;
        uint32_t size;
        assert(page >= 4096);
        memory = mmap(NULL, (size_t)page * 2, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        assert(memory != MAP_FAILED);
        assert(mprotect(memory + page, (size_t)page, PROT_NONE) == 0);
        for (size = 0; size <= 1024; ++size) {
            const uint8_t *p = memory + page - size;
            (void)pg_login(PG_LOGIN_PASSWORD_REPLY, p, size);
            (void)pg_udp(PG_MATCH, 2, p, size, frames, 2, &n);
            (void)pg_state_envelope(p, size, 2);
            (void)pg_options(p, size, NULL, &n);
            (void)pg_decode(p, size, output, sizeof(output), &n);
        }
        assert(munmap(memory, (size_t)page * 2) == 0);
    }
#endif
    free(stream); free(assembly);
    puts("PASS: C ABI, contexts, callbacks, Rust decoder, null/enum rejection, guard-page boundaries");
    return 0;
}
