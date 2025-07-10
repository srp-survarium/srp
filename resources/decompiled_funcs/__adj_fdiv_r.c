// positive sp value has been detected, the output may be wrong!
void __usercall _adj_fdiv_r(char a1@<al>)
{
  _TBYTE v1; // [esp-2Ch] [ebp-58h]
  _TBYTE v2; // [esp-20h] [ebp-4Ch]
  _TBYTE v17; // [esp+0h] [ebp-2Ch]
  _TBYTE v18; // [esp+Ch] [ebp-20h]

  switch ( a1 & 0x3F )
  {
    case 0:
      __asm { fdiv    st, st; jumptable 001CE29D case 0 }
      return;
    case 1:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label2;
    case 2:
label2:
      __asm { fdivr   st, st; jumptable 001CE29D case 2 }
      return;
    case 3:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label4;
    case 4:
label4:
      __asm { fdiv    st, st; jumptable 001CE29D case 4 }
      return;
    case 5:
      __asm { fdivp   st, st; jumptable 001CE29D case 5 }
      return;
    case 6:
      __asm { fdivr   st, st; jumptable 001CE29D case 6 }
      return;
    case 7:
      __asm { fdivrp  st, st; jumptable 001CE29D case 7 }
      return;
    case 8:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 8
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(v1, v2);
      __asm
      {
        fld     [esp+2Ch+var_C]
        fxch    st(1)
      }
      return;
    case 9:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label10;
    case 0xA:
label10:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 001CE29D case 10
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(v17, v18);
      __asm
      {
        fld     [esp+arg_8]
        fxch    st(1)
      }
      return;
    case 0xB:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label12;
    case 0xC:
label12:
      __asm
      {
        fxch    st(1); jumptable 001CE29D case 12
        fstp    [esp+arg_8]; _TBYTE
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(v17, v18);
      __asm { fld     [esp+arg_1C] }
      return;
    case 0xD:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 001CE29D case 13
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      return;
    case 0xE:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 14
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm { fld     [esp+2Ch+var_20] }
      return;
    case 0xF:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 15
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      return;
    case 0x10:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 16
        fxch    st(1)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(v1, v2);
      __asm
      {
        fxch    st(1)
        fld     [esp+2Ch+var_C]
        fxch    st(2)
      }
      return;
    case 0x11:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label18;
    case 0x12:
label18:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 001CE29D case 18
        fxch    st(1)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(v17, v18);
      __asm
      {
        fxch    st(1)
        fld     [esp+arg_8]
        fxch    st(2)
      }
      return;
    case 0x13:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label20;
    case 0x14:
label20:
      __asm
      {
        fxch    st(2); jumptable 001CE29D case 20
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(1)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(v17, v18);
      __asm
      {
        fxch    st(1)
        fld     [esp+arg_1C]
      }
      return;
    case 0x15:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 001CE29D case 21
        fxch    st(1)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm { fxch    st(1) }
      return;
    case 0x16:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 22
        fxch    st(1)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm
      {
        fxch    st(1)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x17:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 23
        fxch    st(1)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm { fxch    st(1) }
      return;
    case 0x18:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 24
        fxch    st(2)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(v1, v2);
      __asm
      {
        fxch    st(2)
        fld     [esp+2Ch+var_C]
        fxch    st(3)
      }
      return;
    case 0x19:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label26;
    case 0x1A:
label26:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 001CE29D case 26
        fxch    st(2)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(v17, v18);
      __asm
      {
        fxch    st(2)
        fld     [esp+arg_8]
        fxch    st(3)
      }
      return;
    case 0x1B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label28;
    case 0x1C:
label28:
      __asm
      {
        fxch    st(3); jumptable 001CE29D case 28
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(2)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(v17, v18);
      __asm
      {
        fxch    st(2)
        fld     [esp+arg_1C]
      }
      return;
    case 0x1D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 001CE29D case 29
        fxch    st(2)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm { fxch    st(2) }
      return;
    case 0x1E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 30
        fxch    st(2)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm
      {
        fxch    st(2)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x1F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 31
        fxch    st(2)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm { fxch    st(2) }
      return;
    case 0x20:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 32
        fxch    st(3)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(v1, v2);
      __asm
      {
        fxch    st(3)
        fld     [esp+2Ch+var_C]
        fxch    st(4)
      }
      return;
    case 0x21:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label34;
    case 0x22:
label34:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 001CE29D case 34
        fxch    st(3)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(v17, v18);
      __asm
      {
        fxch    st(3)
        fld     [esp+arg_8]
        fxch    st(4)
      }
      return;
    case 0x23:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label36;
    case 0x24:
label36:
      __asm
      {
        fxch    st(4); jumptable 001CE29D case 36
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(3)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(v17, v18);
      __asm
      {
        fxch    st(3)
        fld     [esp+arg_1C]
      }
      return;
    case 0x25:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 001CE29D case 37
        fxch    st(3)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm { fxch    st(3) }
      return;
    case 0x26:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 38
        fxch    st(3)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm
      {
        fxch    st(3)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x27:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 39
        fxch    st(3)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm { fxch    st(3) }
      return;
    case 0x28:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 40
        fxch    st(4)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(v1, v2);
      __asm
      {
        fxch    st(4)
        fld     [esp+2Ch+var_C]
        fxch    st(5)
      }
      return;
    case 0x29:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label42;
    case 0x2A:
label42:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 001CE29D case 42
        fxch    st(4)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(v17, v18);
      __asm
      {
        fxch    st(4)
        fld     [esp+arg_8]
        fxch    st(5)
      }
      return;
    case 0x2B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label44;
    case 0x2C:
label44:
      __asm
      {
        fxch    st(5); jumptable 001CE29D case 44
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(4)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(v17, v18);
      __asm
      {
        fxch    st(4)
        fld     [esp+arg_1C]
      }
      return;
    case 0x2D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 001CE29D case 45
        fxch    st(4)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm { fxch    st(4) }
      return;
    case 0x2E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 46
        fxch    st(4)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm
      {
        fxch    st(4)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x2F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 47
        fxch    st(4)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm { fxch    st(4) }
      return;
    case 0x30:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 48
        fxch    st(5)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(v1, v2);
      __asm
      {
        fxch    st(5)
        fld     [esp+2Ch+var_C]
        fxch    st(6)
      }
      return;
    case 0x31:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label50;
    case 0x32:
label50:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 001CE29D case 50
        fxch    st(5)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(v17, v18);
      __asm
      {
        fxch    st(5)
        fld     [esp+arg_8]
        fxch    st(6)
      }
      return;
    case 0x33:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label52;
    case 0x34:
label52:
      __asm
      {
        fxch    st(6); jumptable 001CE29D case 52
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(5)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(v17, v18);
      __asm
      {
        fxch    st(5)
        fld     [esp+arg_1C]
      }
      return;
    case 0x35:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 001CE29D case 53
        fxch    st(5)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm { fxch    st(5) }
      return;
    case 0x36:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 54
        fxch    st(5)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm
      {
        fxch    st(5)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x37:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 55
        fxch    st(5)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm { fxch    st(5) }
      return;
    case 0x38:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 56
        fxch    st(6)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(v1, v2);
      __asm
      {
        fxch    st(6)
        fld     [esp+2Ch+var_C]
        fxch    st(7)
      }
      return;
    case 0x39:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label58;
    case 0x3A:
label58:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 001CE29D case 58
        fxch    st(6)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(v17, v18);
      __asm
      {
        fxch    st(6)
        fld     [esp+arg_8]
        fxch    st(7)
      }
      return;
    case 0x3B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label60;
    case 0x3C:
label60:
      __asm
      {
        fxch    st(7); jumptable 001CE29D case 60
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(6)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(v17, v18);
      __asm
      {
        fxch    st(6)
        fld     [esp+arg_1C]
      }
      break;
    case 0x3D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 001CE29D case 61
        fxch    st(6)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm { fxch    st(6) }
      break;
    case 0x3E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 62
        fxch    st(6)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm
      {
        fxch    st(6)
        fld     [esp+2Ch+var_20]
      }
      break;
    case 0x3F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 001CE29D case 63
        fxch    st(6)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(v1, v2);
      __asm { fxch    st(6) }
      break;
  }
}
