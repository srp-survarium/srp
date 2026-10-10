// SPDX-License-Identifier: GPL-3.0-or-later
// Script for WinDbg to print all console commands

"use strict";

function invokeScript()
{
    let name;

    let tail = 0x04BB2A54;
    let ptr = host.memory.readMemoryValues(tail, 4);
    tail = ptr[0x0] | (ptr[0x1] << 8) | (ptr[0x2] << 16) | (ptr[0x3] << 24);

    while (tail != 0) {
        ptr = host.memory.readMemoryValues(tail, 8 + 4 + 4 + 4);
                                            // vt + next + prev + name

        tail = ptr[0x0C] | (ptr[0x0D] << 8) | (ptr[0x0E] << 16) | (ptr[0x0F] << 24);
        name = ptr[0x10] | (ptr[0x11] << 8) | (ptr[0x12] << 16) | (ptr[0x13] << 24);

        name = host.memory.readString(name);
        host.diagnostics.debugLog("name: " + name + "\n");
    }
}
