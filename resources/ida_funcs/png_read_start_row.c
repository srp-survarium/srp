int __cdecl png_read_start_row(int a1)
{
  unsigned __int8 *v1; // eax
  int result; // eax
  unsigned int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+8h] [ebp-8h]
  unsigned int v5; // [esp+Ch] [ebp-4h]

  *(_DWORD *)(a1 + 124) = 0;
  png_init_read_transformations(a1);
  if ( *(_BYTE *)(a1 + 312) )
  {
    if ( (*(_DWORD *)(a1 + 116) & 2) != 0 )
      *(_DWORD *)(a1 + 236) = *(_DWORD *)(a1 + 232);
    else
      *(_DWORD *)(a1 + 236) = (*(_DWORD *)(a1 + 232) + 7) / 8u;
    *(_DWORD *)(a1 + 248) = (*(_DWORD *)(a1 + 228)
                           + (unsigned __int8)byte_85F3D4[*(unsigned __int8 *)(a1 + 313)]
                           - 1
                           - (unsigned int)(unsigned __int8)byte_85F3CC[*(unsigned __int8 *)(a1 + 313)])
                          / (unsigned __int8)byte_85F3D4[*(unsigned __int8 *)(a1 + 313)];
  }
  else
  {
    *(_DWORD *)(a1 + 236) = *(_DWORD *)(a1 + 232);
    *(_DWORD *)(a1 + 248) = *(_DWORD *)(a1 + 228);
  }
  v4 = *(unsigned __int8 *)(a1 + 318);
  if ( (*(_DWORD *)(a1 + 116) & 4) != 0 && *(unsigned __int8 *)(a1 + 316) < 8u )
    v4 = 8;
  if ( (*(_DWORD *)(a1 + 116) & 0x1000) != 0 )
  {
    if ( *(_BYTE *)(a1 + 315) == 3 )
    {
      if ( *(_WORD *)(a1 + 308) )
        v4 = 32;
      else
        v4 = 24;
    }
    else if ( *(_BYTE *)(a1 + 315) )
    {
      if ( *(_BYTE *)(a1 + 315) == 2 && *(_WORD *)(a1 + 308) )
        v4 = 4 * v4 / 3;
    }
    else
    {
      if ( v4 < 8 )
        v4 = 8;
      if ( *(_WORD *)(a1 + 308) )
        v4 *= 2;
    }
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x200) != 0 )
  {
    if ( (*(_DWORD *)(a1 + 116) & 0x1000) != 0 )
    {
      if ( *(unsigned __int8 *)(a1 + 316) < 0x10u )
        v4 *= 2;
    }
    else
    {
      *(_DWORD *)(a1 + 116) &= ~0x200u;
    }
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x8000) != 0 )
  {
    if ( *(_BYTE *)(a1 + 315) )
    {
      if ( *(_BYTE *)(a1 + 315) == 2 || *(_BYTE *)(a1 + 315) == 3 )
      {
        if ( v4 > 32 )
          v4 = 64;
        else
          v4 = 32;
      }
    }
    else if ( v4 > 8 )
    {
      v4 = 32;
    }
    else
    {
      v4 = 16;
    }
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x4000) != 0 )
  {
    if ( *(_WORD *)(a1 + 308) && (*(_DWORD *)(a1 + 116) & 0x1000) != 0
      || (*(_DWORD *)(a1 + 116) & 0x8000) != 0
      || *(_BYTE *)(a1 + 315) == 4 )
    {
      if ( v4 > 16 )
        v4 = 64;
      else
        v4 = 32;
    }
    else if ( v4 > 8 )
    {
      if ( *(_BYTE *)(a1 + 315) == 6 )
        v4 = 64;
      else
        v4 = 48;
    }
    else if ( *(_BYTE *)(a1 + 315) == 6 )
    {
      v4 = 32;
    }
    else
    {
      v4 = 24;
    }
  }
  if ( (*(_DWORD *)(a1 + 116) & 0x100000) != 0 && *(unsigned __int8 *)(a1 + 105) * *(unsigned __int8 *)(a1 + 104) > v4 )
    v4 = *(unsigned __int8 *)(a1 + 105) * *(unsigned __int8 *)(a1 + 104);
  *(_BYTE *)(a1 + 322) = v4;
  *(_BYTE *)(a1 + 323) = 0;
  v5 = (*(_DWORD *)(a1 + 228) + 7) & 0xFFFFFFF8;
  if ( v4 < 8 )
    v3 = (v4 * v5 + 7) >> 3;
  else
    v3 = v5 * ((unsigned int)v4 >> 3);
  if ( v3 + ((v4 + 7) >> 3) + 49 > *(_DWORD *)(a1 + 676) )
  {
    png_free(a1, *(void **)(a1 + 620));
    png_free(a1, *(void **)(a1 + 688));
    if ( *(_BYTE *)(a1 + 312) )
      v1 = png_calloc(a1, v3 + ((v4 + 7) >> 3) + 49);
    else
      v1 = (unsigned __int8 *)png_malloc(a1, v3 + ((v4 + 7) >> 3) + 49);
    *(_DWORD *)(a1 + 620) = v1;
    *(_DWORD *)(a1 + 688) = png_malloc(a1, v3 + ((v4 + 7) >> 3) + 49);
    *(_DWORD *)(a1 + 264) = *(_DWORD *)(a1 + 620) + 31;
    *(_DWORD *)(a1 + 260) = *(_DWORD *)(a1 + 688) + 31;
    *(_DWORD *)(a1 + 676) = v3 + ((v4 + 7) >> 3) + 49;
  }
  if ( *(_DWORD *)(a1 + 244) == -1 )
    png_error(a1, (int)"Row has too many bytes to allocate in memory");
  memset(*(_DWORD *)(a1 + 260), 0, *(_DWORD *)(a1 + 244) + 1);
  result = a1;
  *(_DWORD *)(a1 + 112) |= 0x40u;
  return result;
}
