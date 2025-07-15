int __cdecl png_handle_sBIT(int a1, int a2, unsigned int a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-8h]
  unsigned __int8 buf; // [esp+4h] [ebp-4h] BYREF
  char v6; // [esp+5h] [ebp-3h]
  char v7; // [esp+6h] [ebp-2h]
  char v8; // [esp+7h] [ebp-1h]

  v8 = 0;
  v7 = 0;
  v6 = 0;
  buf = 0;
  if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
    png_error(a1, (int)"Missing IHDR before sBIT");
  if ( (*(_DWORD *)(a1 + 108) & 4) != 0 )
  {
    png_warning(a1, "Invalid sBIT after IDAT");
    return png_crc_finish(a1, a3);
  }
  else
  {
    if ( (*(_DWORD *)(a1 + 108) & 2) != 0 )
      png_warning(a1, "Out of place sBIT chunk");
    if ( a2 && (*(_DWORD *)(a2 + 8) & 2) != 0 )
    {
      png_warning(a1, "Duplicate sBIT chunk");
      return png_crc_finish(a1, a3);
    }
    else
    {
      if ( *(_BYTE *)(a1 + 315) == 3 )
        v4 = 3;
      else
        v4 = *(unsigned __int8 *)(a1 + 319);
      if ( a3 == v4 && a3 <= 4 )
      {
        png_crc_read((_DWORD *)a1, &buf, v4);
        result = png_crc_finish(a1, 0);
        if ( !result )
        {
          if ( (*(_BYTE *)(a1 + 315) & 2) != 0 )
          {
            *(_BYTE *)(a1 + 408) = buf;
            *(_BYTE *)(a1 + 409) = v6;
            *(_BYTE *)(a1 + 410) = v7;
            *(_BYTE *)(a1 + 412) = v8;
          }
          else
          {
            *(_BYTE *)(a1 + 411) = buf;
            *(_BYTE *)(a1 + 408) = buf;
            *(_BYTE *)(a1 + 409) = buf;
            *(_BYTE *)(a1 + 410) = buf;
            *(_BYTE *)(a1 + 412) = v6;
          }
          return png_set_sBIT(a1, a2, (const __m128i *)(a1 + 408));
        }
      }
      else
      {
        png_warning(a1, "Incorrect sBIT chunk length");
        return png_crc_finish(a1, a3);
      }
    }
  }
  return result;
}
