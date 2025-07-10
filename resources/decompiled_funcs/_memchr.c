void __cdecl memchr(unsigned __int8 *buf, unsigned __int8 chr, unsigned int cnt)
{
  unsigned int v3; // eax
  unsigned __int8 *v4; // edx
  int v5; // ebx
  unsigned __int8 v6; // cl
  bool v7; // cf
  unsigned int v8; // eax
  unsigned int i; // eax
  unsigned __int8 v10; // cl
  int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // ecx

  v3 = cnt;
  if ( cnt )
  {
    v4 = buf;
    LOBYTE(v5) = chr;
    if ( ((unsigned __int8)buf & 3) != 0 )
    {
      while ( 1 )
      {
        v6 = *v4++;
        if ( chr == v6 )
          break;
        if ( !--v3 )
          break;
        if ( ((unsigned __int8)v4 & 3) == 0 )
          goto main_loop_start_0;
      }
    }
    else
    {
main_loop_start_0:
      v7 = v3 < 4;
      v8 = v3 - 4;
      if ( v7 )
      {
tail_less_then_4:
        for ( i = v8 + 4; i; --i )
        {
          v10 = *v4++;
          if ( (unsigned __int8)v5 == v10 )
            break;
        }
      }
      else
      {
        v5 = 16843009 * chr;
        while ( 1 )
        {
          v11 = v5 ^ *(_DWORD *)v4;
          v4 += 4;
          if ( (((v11 + 2130640639) ^ ~v11) & 0x81010100) != 0 )
          {
            v12 = *((_DWORD *)v4 - 1);
            LOBYTE(v12) = chr ^ v12;
            if ( !(_BYTE)v12 )
              break;
            BYTE1(v12) ^= chr;
            if ( !BYTE1(v12) )
              break;
            v13 = HIWORD(v12);
            if ( chr == (unsigned __int8)v13 || chr == BYTE1(v13) )
              break;
          }
          v7 = v8 < 4;
          v8 -= 4;
          if ( v7 )
            goto tail_less_then_4;
        }
      }
    }
  }
}
