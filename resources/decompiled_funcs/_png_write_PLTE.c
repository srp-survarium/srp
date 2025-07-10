int __cdecl png_write_PLTE(int a1, unsigned __int8 *a2, unsigned int a3)
{
  int result; // eax
  unsigned __int8 buf[4]; // [esp+0h] [ebp-Ch] BYREF
  unsigned int v5; // [esp+4h] [ebp-8h]
  unsigned __int8 *v6; // [esp+8h] [ebp-4h]

  if ( ((*(_DWORD *)(a1 + 600) & 1) != 0 || a3) && a3 <= 0x100 )
  {
    if ( (*(_BYTE *)(a1 + 315) & 2) != 0 )
    {
      *(_WORD *)(a1 + 300) = a3;
      sub_36AD20((_DWORD *)a1, 1347179589, 3 * a3);
      v5 = 0;
      v6 = a2;
      while ( v5 < a3 )
      {
        buf[0] = *v6;
        buf[1] = v6[1];
        buf[2] = v6[2];
        png_write_chunk_data((_DWORD *)a1, buf, 3);
        ++v5;
        v6 += 3;
      }
      png_write_chunk_end(a1);
      result = *(_DWORD *)(a1 + 108) | 2;
      *(_DWORD *)(a1 + 108) = result;
    }
    else
    {
      return png_warning(a1, "Ignoring request to write a PLTE chunk in grayscale PNG");
    }
  }
  else
  {
    if ( *(_BYTE *)(a1 + 315) == 3 )
      png_error(a1, (int)"Invalid number of colors in palette");
    return png_warning(a1, "Invalid number of colors in palette");
  }
  return result;
}
