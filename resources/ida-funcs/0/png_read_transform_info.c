int __cdecl png_read_transform_info(int a1, int a2)
{
  int result; // eax
  unsigned int v3; // [esp+0h] [ebp-4h]

  if ( (*(_DWORD *)(a1 + 116) & 0x1000) != 0 )
  {
    if ( *(_BYTE *)(a2 + 25) == 3 )
    {
      if ( *(_WORD *)(a1 + 308) )
        *(_BYTE *)(a2 + 25) = 6;
      else
        *(_BYTE *)(a2 + 25) = 2;
      *(_BYTE *)(a2 + 24) = 8;
      *(_WORD *)(a2 + 22) = 0;
    }
    else
    {
      if ( *(_WORD *)(a1 + 308) && (*(_DWORD *)(a1 + 116) & 0x2000000) != 0 )
        *(_BYTE *)(a2 + 25) |= 4u;
      if ( *(unsigned __int8 *)(a2 + 24) < 8u )
        *(_BYTE *)(a2 + 24) = 8;
      *(_WORD *)(a2 + 22) = 0;
    }
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x80) != 0 )
  {
    *(_DWORD *)(a2 + 90) = *(_DWORD *)(a1 + 340);
    *(_DWORD *)(a2 + 94) = *(_DWORD *)(a1 + 344);
    *(_WORD *)(a2 + 98) = *(_WORD *)(a1 + 348);
  }
  *(_DWORD *)(a2 + 40) = *(_DWORD *)(a1 + 376);
  if ( *(_BYTE *)(a2 + 24) == 16 )
  {
    if ( (*(_DWORD *)(a1 + 116) & 0x4000000) != 0 )
      *(_BYTE *)(a2 + 24) = 8;
    if ( (*(_DWORD *)(a1 + 116) & 0x400) != 0 )
      *(_BYTE *)(a2 + 24) = 8;
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x4000) != 0 )
    *(_BYTE *)(a2 + 25) |= 2u;
  if ( ((unsigned int)&loc_600000 & *(_DWORD *)(a1 + 116)) != 0 )
    *(_BYTE *)(a2 + 25) &= ~2u;
  if ( (*(_DWORD *)(a1 + 116) & 0x40) != 0
    && (*(_BYTE *)(a2 + 25) == 2 || *(_BYTE *)(a2 + 25) == 6)
    && *(_DWORD *)(a1 + 504)
    && *(_BYTE *)(a2 + 24) == 8 )
  {
    *(_BYTE *)(a2 + 25) = 3;
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x200) != 0 && *(_BYTE *)(a2 + 24) == 8 && *(_BYTE *)(a2 + 25) != 3 )
    *(_BYTE *)(a2 + 24) = 16;
  if ( (*(_DWORD *)(a1 + 116) & 4) != 0 && *(unsigned __int8 *)(a2 + 24) < 8u )
    *(_BYTE *)(a2 + 24) = 8;
  if ( *(_BYTE *)(a2 + 25) == 3 )
  {
    *(_BYTE *)(a2 + 29) = 1;
  }
  else if ( (*(_BYTE *)(a2 + 25) & 2) != 0 )
  {
    *(_BYTE *)(a2 + 29) = 3;
  }
  else
  {
    *(_BYTE *)(a2 + 29) = 1;
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x40000) != 0 )
  {
    *(_BYTE *)(a2 + 25) &= ~4u;
    *(_WORD *)(a2 + 22) = 0;
  }
  if ( (*(_BYTE *)(a2 + 25) & 4) != 0 )
    ++*(_BYTE *)(a2 + 29);
  if ( (*(_DWORD *)(a1 + 116) & 0x8000) != 0 && (*(_BYTE *)(a2 + 25) == 2 || !*(_BYTE *)(a2 + 25)) )
  {
    ++*(_BYTE *)(a2 + 29);
    if ( (*(_DWORD *)(a1 + 116) & 0x1000000) != 0 )
      *(_BYTE *)(a2 + 25) |= 4u;
  }
  if ( ((unsigned int)&loc_100000 & *(_DWORD *)(a1 + 116)) != 0 )
  {
    if ( *(unsigned __int8 *)(a2 + 24) < (int)*(unsigned __int8 *)(a1 + 104) )
      *(_BYTE *)(a2 + 24) = *(_BYTE *)(a1 + 104);
    if ( *(unsigned __int8 *)(a2 + 29) < (int)*(unsigned __int8 *)(a1 + 105) )
      *(_BYTE *)(a2 + 29) = *(_BYTE *)(a1 + 105);
  }
  *(_BYTE *)(a2 + 30) = *(_BYTE *)(a2 + 24) * *(_BYTE *)(a2 + 29);
  if ( *(unsigned __int8 *)(a2 + 30) < 8u )
    v3 = (*(_DWORD *)a2 * (unsigned int)*(unsigned __int8 *)(a2 + 30) + 7) >> 3;
  else
    v3 = *(_DWORD *)a2 * (*(unsigned __int8 *)(a2 + 30) >> 3);
  *(_DWORD *)(a2 + 12) = v3;
  result = a2;
  *(_DWORD *)(a1 + 284) = *(_DWORD *)(a2 + 12);
  return result;
}
