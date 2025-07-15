int __cdecl png_write_start_row(int a1)
{
  int result; // eax
  unsigned int v2; // [esp+0h] [ebp-Ch]
  int v3; // [esp+4h] [ebp-8h]

  v3 = *(unsigned __int8 *)(a1 + 317) * *(unsigned __int8 *)(a1 + 320);
  if ( v3 < 8 )
    v2 = (unsigned int)(v3 * *(_DWORD *)(a1 + 228) + 7) >> 3;
  else
    v2 = *(_DWORD *)(a1 + 228) * ((unsigned int)v3 >> 3);
  *(_BYTE *)(a1 + 323) = *(_BYTE *)(a1 + 318);
  *(_BYTE *)(a1 + 322) = v3;
  *(_DWORD *)(a1 + 264) = png_malloc(a1, v2 + 1);
  **(_BYTE **)(a1 + 264) = 0;
  if ( (*(_BYTE *)(a1 + 314) & 0x10) != 0 )
  {
    *(_DWORD *)(a1 + 268) = png_malloc(a1, *(_DWORD *)(a1 + 244) + 1);
    **(_BYTE **)(a1 + 268) = 1;
  }
  if ( (*(_BYTE *)(a1 + 314) & 0xE0) != 0 )
  {
    *(_DWORD *)(a1 + 260) = png_calloc(a1, v2 + 1);
    if ( (*(_BYTE *)(a1 + 314) & 0x20) != 0 )
    {
      *(_DWORD *)(a1 + 272) = png_malloc(a1, *(_DWORD *)(a1 + 244) + 1);
      **(_BYTE **)(a1 + 272) = 2;
    }
    if ( (*(_BYTE *)(a1 + 314) & 0x40) != 0 )
    {
      *(_DWORD *)(a1 + 276) = png_malloc(a1, *(_DWORD *)(a1 + 244) + 1);
      **(_BYTE **)(a1 + 276) = 3;
    }
    if ( (*(_BYTE *)(a1 + 314) & 0x80) != 0 )
    {
      *(_DWORD *)(a1 + 280) = png_malloc(a1, *(_DWORD *)(a1 + 244) + 1);
      **(_BYTE **)(a1 + 280) = 4;
    }
  }
  if ( *(_BYTE *)(a1 + 312) )
  {
    if ( (*(_DWORD *)(a1 + 116) & 2) != 0 )
    {
      *(_DWORD *)(a1 + 236) = *(_DWORD *)(a1 + 232);
      *(_DWORD *)(a1 + 240) = *(_DWORD *)(a1 + 228);
    }
    else
    {
      *(_DWORD *)(a1 + 236) = (*(_DWORD *)(a1 + 232) + 7) / 8u;
      *(_DWORD *)(a1 + 240) = (*(_DWORD *)(a1 + 228) + 7) / 8u;
    }
  }
  else
  {
    *(_DWORD *)(a1 + 236) = *(_DWORD *)(a1 + 232);
    *(_DWORD *)(a1 + 240) = *(_DWORD *)(a1 + 228);
  }
  sub_36BE00(a1, 1);
  *(_DWORD *)(a1 + 136) = *(_DWORD *)(a1 + 180);
  result = *(_DWORD *)(a1 + 176);
  *(_DWORD *)(a1 + 132) = result;
  return result;
}
