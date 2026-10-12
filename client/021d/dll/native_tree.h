// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// Experimental populated-snapshot support. Installed only for capture diagnostics.
// Initialize once before native game threads start; failure is fatal to setup.
int srp_tree_initialize(unsigned char *module);
// A valid native tree, on its owning simulation thread. Failure leaves partial
// output which must be discarded. Capacity includes the native trailing clear.
int srp_tree_serialize(void *tree, unsigned char *output, unsigned capacity,
                       unsigned *written);
