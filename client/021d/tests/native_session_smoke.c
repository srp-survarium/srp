// SPDX-License-Identifier: GPL-3.0-or-later
// Synthetic object graph tests for rejecting stale/wrong native owners.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../dll/native_session.h"
static unsigned char callback[16], lobby[0x6b0], game[0x3700];
static unsigned char network[0x7a28], login[0x5d0];
static uintptr_t owner_vtable[2], network_vtable[22];
#define PUT(object, offset, value) do { uintptr_t word = (uintptr_t)(value); memcpy(object + offset, &word, 4); } while (0)
#define CHECK(test) do { if (!(test)) { fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#test); return 1; } } while (0)
int main(void)
{
    void *base = (void *)0x10000000;
    CHECK(!srp_native_lobby_session(base, NULL));
    CHECK(!srp_native_lobby_session(base, (void *)1));
    PUT(callback, 0xc, lobby + 0xf4);
    PUT(lobby, 0xf4, owner_vtable);
    owner_vtable[1] = (uintptr_t)base + 0x1615c8;
    PUT(lobby, 0xa0, game);
    PUT(game, 0x3638, lobby);
    PUT(game, 0x3684, network);
    PUT(network, 0, network_vtable);
    network_vtable[21] = (uintptr_t)base + 0x1923b8;
    PUT(network, 0x18, game);
    PUT(network, 0x160, 1);
    network[0x3ec] = 1;
    PUT(network, 0x27c, 0x12345678);
    PUT(network, 0x15c, login);
    PUT(login, 0x188, 0x12345678);
    CHECK(srp_native_lobby_session(base, callback) == 0x12345678);
    owner_vtable[1]++;
    CHECK(!srp_native_lobby_session(base, callback));
    owner_vtable[1]--;
    PUT(game, 0x3638, lobby + 4);
    CHECK(!srp_native_lobby_session(base, callback));
    PUT(game, 0x3638, lobby);
    network_vtable[21]++;
    CHECK(!srp_native_lobby_session(base, callback));
    network_vtable[21]--;
    PUT(network, 0x160, 0);
    CHECK(!srp_native_lobby_session(base, callback));
    PUT(network, 0x160, 1);
    network[0x3ec] = 0;
    CHECK(!srp_native_lobby_session(base, callback));
    network[0x3ec] = 1;
    PUT(login, 0x188, 99);
    CHECK(!srp_native_lobby_session(base, callback));
    PUT(login, 0x188, 0x12345678);
    PUT(network, 0x15c, 1);
    CHECK(!srp_native_lobby_session(base, callback));
    PUT(network, 0x15c, login);
    CHECK(srp_native_lobby_session(base, callback) == 0x12345678);
    puts("PASS: session layout, owner/lifetime guards, sign-out, disconnected lobby, mismatched session");
    return 0;
}
