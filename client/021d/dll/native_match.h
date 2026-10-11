// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef SRP_NATIVE_MATCH_H
#define SRP_NATIVE_MATCH_H
#include <stdint.h>

#define SRP_SNAPSHOT_OPCODE 0x48
#define SRP_SNAPSHOT_LIMIT 32768

// Called before game threads start. Failure is fatal to patch initialization.
int srp_match_initialize(unsigned char *module, void (*log)(const char *));
// Optional diagnostic: stock CRC notifications at every 50 ms simulation step.
int srp_match_hash_every_step(unsigned char *module);
// Simulation-thread only. Limited deliberately to time 50, with no active players.
unsigned srp_match_bootstrap(unsigned char *module, const void *core,
                             unsigned char *output, unsigned capacity, uint32_t *time);
int srp_match_upload(void *network);
// Send a fully bounded, timestamp-free SRP snapshot body on the owning thread.
int srp_match_send_snapshot(void *network, const unsigned char *bytes, unsigned size, uint32_t time);
#endif
