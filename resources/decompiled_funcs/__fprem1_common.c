unsigned int __usercall _fprem1_common@<eax>(char a1@<dl>, __int128 a2, int a3, int a4, __int128 a5)
{
  unsigned int result; // eax
  unsigned int v6; // eax
  int v7; // ecx
  double v8; // st7
  __int16 v9; // fps
  double v10; // st6
  bool v11; // c0
  char v12; // c2
  bool v13; // c3
  __int16 v14; // fps

  result = *(_DWORD *)((char *)&a2 + 6) ^ 0x700;
  if ( ((*(_DWORD *)((char *)&a2 + 6) ^ 0x700) & 0x700) == 0 )
  {
    result = (result >> 11) & 0xF;
    if ( fprem_risc_table[result] )
    {
      result = *(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000;
      if ( (*(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000) != 0x7FFF0000 )
      {
        result = *(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000;
        if ( (*(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000) != 0 && result != 2147418112 )
        {
          result = 2 * DWORD1(a5);
          if ( !(2 * DWORD1(a5)) )
          {
            result = 2 * DWORD1(a2);
            if ( !(2 * DWORD1(a2)) )
            {
              v6 = (WORD4(a2) & 0x7FFF) + 63;
              if ( (WORD4(a5) & 0x7FFFu) > v6 )
              {
                v7 = ((BYTE8(a5) - BYTE8(a2)) & 0x3F | 0x20) + 1;
                v8 = fabs(*(long double *)&a2);
                v10 = fabs(*(long double *)&a5);
                do
                {
                  v11 = v10 < v8;
                  v12 = 0;
                  v13 = v10 == v8;
                  result = v9 & 0x100;
                  if ( (v9 & 0x100) == 0 )
                    v10 = v10 - v8;
                  v8 = v8 * *(double *)&half;
                  --v7;
                }
                while ( v7 );
              }
              else
              {
                while ( 1 )
                {
                  result = (WORD4(a2) & 0x7FFF) + 10;
                  if ( (int)((WORD4(a5) & 0x7FFF) - result) < 0 )
                    break;
                  *(double *)&a5 = __FPREM__(*(long double *)&a5, *(long double *)&a2);
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (a1 & 3) != 0 )
  {
    result = v14 & 0x4300;
    __asm { fnstenv [esp+28h+var_28] }
    __asm { fldenv  [esp+28h+var_28] }
  }
  return result;
}
