// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once
#include <stdint.h>

// Serialize a valid native history item using its HISTORICAL active mask, on
// the simulation thread. Tree support requires srp_tree_initialize first.
// Returns zero on failure; discard any partial output. Does not select history,
// prepend its timestamp, send packets, or authorize snapshot acceptance.
unsigned srp_snapshot_serialize(unsigned char *module, const void *item, uint32_t mask,
                                unsigned char *output, unsigned capacity);
// Select the latest history at or before the event horizon, with historical
// membership. Same owning-thread requirement; emits a body without timestamp.
unsigned srp_snapshot_current(unsigned char *module, const void *core,
                              unsigned char *output, unsigned capacity,
                              uint32_t *time, uint32_t *mask);
// Diagnostic only: save two current history snapshots locally on the native
// simulation thread. No packets are sent and no game state is restored.
int srp_snapshot_capture_initialize(unsigned char *module, void (*log)(const char *));
