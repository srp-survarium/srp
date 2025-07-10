void __cdecl _tr_align(internal_state *s)
{
  int dummy; // ecx
  int v2; // edx
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // eax

  dummy = s[1455].dummy;
  LOWORD(s[1454].dummy) |= 2 << dummy;
  if ( dummy <= 13 )
  {
    s[1455].dummy = dummy + 3;
  }
  else
  {
    *(_BYTE *)(s[2].dummy + s[5].dummy++) = s[1454].dummy;
    *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
    v2 = s[1455].dummy;
    ++s[5].dummy;
    s[1455].dummy = v2 - 13;
    LOWORD(s[1454].dummy) = 2u >> (16 - v2);
  }
  v3 = s[1455].dummy;
  LOWORD(s[1454].dummy) = s[1454].dummy;
  if ( v3 <= 9 )
  {
    s[1455].dummy = v3 + 7;
  }
  else
  {
    *(_BYTE *)(s[2].dummy + s[5].dummy++) = s[1454].dummy;
    *(_BYTE *)(s[5].dummy + s[2].dummy) = BYTE1(s[1454].dummy);
    v4 = s[1455].dummy;
    ++s[5].dummy;
    s[1455].dummy = v4 - 9;
    LOWORD(s[1454].dummy) = 0;
  }
  bi_flush(s);
  v6 = *(_DWORD *)(v5 + 5820);
  if ( *(_DWORD *)(v5 + 5812) - v6 + 11 < 9 )
  {
    *(_WORD *)(v5 + 5816) |= 2 << v6;
    if ( v6 <= 13 )
    {
      *(_DWORD *)(v5 + 5820) = v6 + 3;
    }
    else
    {
      *(_BYTE *)(*(_DWORD *)(v5 + 8) + (*(_DWORD *)(v5 + 20))++) = *(_BYTE *)(v5 + 5816);
      *(_BYTE *)(*(_DWORD *)(v5 + 20) + *(_DWORD *)(v5 + 8)) = *(_BYTE *)(v5 + 5817);
      v7 = *(_DWORD *)(v5 + 5820);
      ++*(_DWORD *)(v5 + 20);
      *(_DWORD *)(v5 + 5820) = v7 - 13;
      *(_WORD *)(v5 + 5816) = 2u >> (16 - v7);
    }
    v8 = *(_DWORD *)(v5 + 5820);
    *(_WORD *)(v5 + 5816) = *(_WORD *)(v5 + 5816);
    if ( v8 > 9 )
    {
      *(_BYTE *)(*(_DWORD *)(v5 + 8) + (*(_DWORD *)(v5 + 20))++) = *(_BYTE *)(v5 + 5816);
      *(_BYTE *)(*(_DWORD *)(v5 + 20) + *(_DWORD *)(v5 + 8)) = *(_BYTE *)(v5 + 5817);
      v9 = *(_DWORD *)(v5 + 5820);
      ++*(_DWORD *)(v5 + 20);
      *(_DWORD *)(v5 + 5820) = v9 - 9;
      *(_WORD *)(v5 + 5816) = 0;
      bi_flush((internal_state *)v5);
      *(_DWORD *)(v10 + 5812) = 7;
      return;
    }
    *(_DWORD *)(v5 + 5820) = v8 + 7;
    bi_flush((internal_state *)v5);
  }
  *(_DWORD *)(v5 + 5812) = 7;
}
