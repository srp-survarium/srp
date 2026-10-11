// SPDX-License-Identifier: GPL-3.0-or-later
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include "native_session.h"

_Static_assert(sizeof(void *) == 4, "retail 0.21d x86 layout");

static int read_at(uintptr_t address, unsigned offset, void *value, SIZE_T size)
{
    SIZE_T read = 0;
    if (!address || address > UINTPTR_MAX - offset ||
        address + offset > UINTPTR_MAX - size) return 0;
    return ReadProcessMemory(GetCurrentProcess(), (void *)(address + offset),
                             value, size, &read) && read == size;
}
#define READ(address, offset, value) read_at(address, offset, &(value), sizeof(value))

uint32_t srp_native_lobby_session(const void *module, const void *callback_self)
{
    uintptr_t base = (uintptr_t)module, owner, vtable, callback, game, network;
    uintptr_t current_lobby, backref, close_match, login_impl;
    uint32_t state, session, login_session;
    unsigned char connected;
    // flash_external_handler_impl::owner; its virtual callback is slot 1.
    // The lobby callback receives the subobject at lobby_menu+0xf4.
    if (!READ((uintptr_t)callback_self, 0xc, owner) ||
        !READ(owner, 0, vtable) || !READ(vtable, 4, callback) ||
        callback != base + 0x1615c8 || owner < 0xf4) return 0;
    uintptr_t lobby = owner - 0xf4;
    if (!READ(lobby, 0xa0, game) || !READ(game, 0x3638, current_lobby) ||
        current_lobby != lobby || !READ(game, 0x3684, network) ||
        !READ(network, 0x18, backref) || backref != game ||
        !READ(network, 0, vtable) || !READ(vtable, 0x54, close_match) ||
        close_match != base + 0x1923b8) return 0;
    // Read no account name or password. Require both native session copies to
    // agree and the login/lobby connections to be usable at this callback.
    if (!READ(network, 0x20 + 0x140, state) || state != 1 ||
        !READ(network, 0x238 + 0x1b4, connected) || connected != 1 ||
        !READ(network, 0x238 + 0x44, session) || !session ||
        !READ(network, 0x20 + 0x13c, login_impl) ||
        !READ(login_impl, 0x188, login_session) || login_session != session) return 0;
    return session;
}
