// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once
#include <stdint.h>
// UI-thread only. Reads a session from the current retail lobby callback owner.
// Returns zero for preview/login/other scenes, disconnected or stale owners.
uint32_t srp_native_lobby_session(const void *module, const void *callback_self);
