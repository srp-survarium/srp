; SPDX-License-Identifier: GPL-3.0-or-later
; rip = 0x7aff90


%macro nops 1
  %rep %1
    nop
  %endrep
%endmacro

bits 32

nops  11h

