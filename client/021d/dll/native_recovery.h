// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// Install the explicit SRP request handler, before game threads start.
int srp_recovery_initialize(unsigned char *module, void (*log)(const char *));
