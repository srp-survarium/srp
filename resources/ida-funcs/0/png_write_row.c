int __cdecl png_write_row(int a1, const __m128i *src)
{
  int result; // eax
  int v3; // [esp+0h] [ebp-14h]
  _DWORD v4[2]; // [esp+8h] [ebp-Ch] BYREF
  char v5; // [esp+10h] [ebp-4h]
  char v6; // [esp+11h] [ebp-3h]
  char v7; // [esp+12h] [ebp-2h]
  unsigned __int8 v8; // [esp+13h] [ebp-1h]

  if ( a1 )
  {
    if ( !*(_DWORD *)(a1 + 252) && !*(_BYTE *)(a1 + 313) )
    {
      if ( (*(_DWORD *)(a1 + 108) & 0x400) == 0 )
        png_error(a1, (int)"png_write_info was never called before png_write_row");
      png_write_start_row(a1);
    }
    if ( *(_BYTE *)(a1 + 312) && (*(_DWORD *)(a1 + 116) & 2) != 0 )
    {
      switch ( *(_BYTE *)(a1 + 313) )
      {
        case 0:
          if ( (*(_DWORD *)(a1 + 252) & 7) == 0 )
            goto LABEL_31;
          break;
        case 1:
          if ( (*(_DWORD *)(a1 + 252) & 7) == 0 && *(_DWORD *)(a1 + 228) >= 5u )
            goto LABEL_31;
          break;
        case 2:
          if ( (*(_DWORD *)(a1 + 252) & 7) == 4 )
            goto LABEL_31;
          break;
        case 3:
          if ( (*(_DWORD *)(a1 + 252) & 3) == 0 && *(_DWORD *)(a1 + 228) >= 3u )
            goto LABEL_31;
          break;
        case 4:
          if ( (*(_DWORD *)(a1 + 252) & 3) == 2 )
            goto LABEL_31;
          break;
        case 5:
          if ( (*(_DWORD *)(a1 + 252) & 1) == 0 && *(_DWORD *)(a1 + 228) >= 2u )
            goto LABEL_31;
          break;
        case 6:
          if ( (*(_DWORD *)(a1 + 252) & 1) != 0 )
            goto LABEL_31;
          break;
        default:
          goto LABEL_31;
      }
      return png_write_finish_row(a1);
    }
    else
    {
LABEL_31:
      v5 = *(_BYTE *)(a1 + 315);
      v4[0] = *(_DWORD *)(a1 + 240);
      v7 = *(_BYTE *)(a1 + 320);
      v6 = *(_BYTE *)(a1 + 317);
      v8 = v7 * v6;
      if ( (unsigned __int8)(v7 * v6) < 8u )
        v3 = (v4[0] * (unsigned int)v8 + 7) >> 3;
      else
        v3 = v4[0] * (v8 >> 3);
      v4[1] = v3;
      memcpy(*(_DWORD *)(a1 + 264) + 1, src, v3);
      if ( *(_BYTE *)(a1 + 312)
        && *(unsigned __int8 *)(a1 + 313) < 6u
        && (*(_DWORD *)(a1 + 116) & 2) != 0
        && (png_do_write_interlace(v4, *(_DWORD *)(a1 + 264) + 1, *(unsigned __int8 *)(a1 + 313)), !v4[0]) )
      {
        return png_write_finish_row(a1);
      }
      else
      {
        if ( *(_DWORD *)(a1 + 116) )
          png_do_write_transformations(a1, v4);
        if ( v8 != *(unsigned __int8 *)(a1 + 318) || v8 != *(unsigned __int8 *)(a1 + 323) )
          png_error(a1, (int)"internal write transform logic error");
        if ( (*(_DWORD *)(a1 + 600) & 4) != 0 && *(_BYTE *)(a1 + 604) == 64 )
          png_do_write_intrapixel(v4, *(_DWORD *)(a1 + 264) + 1);
        if ( v5 == 3 && *(int *)(a1 + 304) >= 0 )
          png_do_check_palette_indexes(a1, v4);
        result = png_write_find_filter(a1, v4);
        if ( *(_DWORD *)(a1 + 440) )
          return (*(int (__cdecl **)(int, _DWORD, _DWORD))(a1 + 440))(
                   a1,
                   *(_DWORD *)(a1 + 252),
                   *(unsigned __int8 *)(a1 + 313));
      }
    }
  }
  return result;
}
