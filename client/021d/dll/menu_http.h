// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once
#include <stdint.h>
int srp_http_initialize(void);
// Set only after the native protocol hooks pass initialization, never by AS3.
void srp_http_enable_match_protocol(void);
void srp_http_enable_match_recovery(void);
// Default is unavailable. Only the explicit preview mode may use fixture
// identity. Native session values stay in the DLL, never in ActionScript.
void srp_http_set_identity(int preview, uint32_t native_session);
// Commands contain ASCII form data, never pointers or Scaleform-owned values.
// Returns 1 when recognized. reply is populated only by a matching poll.
int srp_http_command(const char *command, char *reply, unsigned capacity);
