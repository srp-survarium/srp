int __cdecl png_handle_tEXt(int a1, int a2, unsigned int a3)
{
  int result; // eax
  _DWORD *pointer; // [esp+0h] [ebp-18h]
  int v5; // [esp+4h] [ebp-14h]
  const char *v6; // [esp+8h] [ebp-10h]
  LPCSTR lpString; // [esp+10h] [ebp-8h]

  if ( !*(_DWORD *)(a1 + 648) )
    goto LABEL_6;
  if ( *(_DWORD *)(a1 + 648) == 1 )
    return png_crc_finish(a1, a3);
  if ( --*(_DWORD *)(a1 + 648) == 1 )
  {
    png_warning(a1, "No space in chunk cache for tEXt");
    return png_crc_finish(a1, a3);
  }
  else
  {
LABEL_6:
    if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
      png_error(a1, (int)"Missing IHDR before tEXt");
    if ( (*(_DWORD *)(a1 + 108) & 4) != 0 )
      *(_DWORD *)(a1 + 108) |= 8u;
    png_free(a1, *(void **)(a1 + 680));
    *(_DWORD *)(a1 + 680) = png_malloc_warn(a1, a3 + 1);
    if ( *(_DWORD *)(a1 + 680) )
    {
      png_crc_read((_DWORD *)a1, *(unsigned __int8 **)(a1 + 680), a3);
      if ( png_crc_finish(a1, 0) )
      {
        result = png_free(a1, *(void **)(a1 + 680));
        *(_DWORD *)(a1 + 680) = 0;
      }
      else
      {
        v6 = *(const char **)(a1 + 680);
        v6[a3] = 0;
        for ( lpString = v6; *lpString; ++lpString )
          ;
        if ( lpString != &v6[a3] )
          ++lpString;
        pointer = (_DWORD *)png_malloc_warn(a1, 0x1Cu);
        if ( pointer )
        {
          *pointer = -1;
          pointer[1] = v6;
          pointer[5] = 0;
          pointer[6] = 0;
          pointer[4] = 0;
          pointer[2] = lpString;
          pointer[3] = lstrlenA(lpString);
          v5 = png_set_text_2(a1, a2, (int)pointer, 1);
          png_free(a1, *(void **)(a1 + 680));
          *(_DWORD *)(a1 + 680) = 0;
          result = png_free(a1, pointer);
          if ( v5 )
            return png_warning(a1, "Insufficient memory to process text chunk");
        }
        else
        {
          png_warning(a1, "Not enough memory to process text chunk");
          result = png_free(a1, *(void **)(a1 + 680));
          *(_DWORD *)(a1 + 680) = 0;
        }
      }
    }
    else
    {
      return png_warning(a1, "No memory to process text chunk");
    }
  }
  return result;
}
