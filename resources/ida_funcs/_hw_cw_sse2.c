unsigned int __fastcall _hw_cw_sse2(int a1, unsigned int abstr)
{
  unsigned int result; // eax
  unsigned int v3; // ecx
  unsigned __int8 *v4; // edx

  result = 0;
  if ( (abstr & 0x10) != 0 )
    result = 128;
  if ( (abstr & 8) != 0 )
    result |= 0x200u;
  if ( (abstr & 4) != 0 )
    result |= 0x400u;
  if ( (abstr & 2) != 0 )
    result |= 0x800u;
  if ( (abstr & 1) != 0 )
    result |= 0x1000u;
  if ( (abstr & 0x80000) != 0 )
    result |= 0x100u;
  v3 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v3 )
    {
      case 0x100u:
        result |= 0x2000u;
        break;
      case 0x200u:
        result |= 0x4000u;
        break;
      case 0x300u:
        result |= 0x6000u;
        break;
    }
  }
  v4 = (unsigned __int8 *)((unsigned int)&vostok::memory::s_CRT_arena[39128632] & abstr);
  if ( v4 == &vostok::memory::s_CRT_arena[5574200] )
  {
    result |= 0x8040u;
  }
  else if ( v4 == &vostok::memory::s_CRT_arena[22351416] )
  {
    result |= 0x40u;
  }
  else if ( v4 == &vostok::memory::s_CRT_arena[39128632] )
  {
    result |= 0x8000u;
  }
  return result;
}
