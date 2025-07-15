int __cdecl png_handle_gAMA(_DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned __int8 v4[260]; // [esp+0h] [ebp-110h] BYREF
  unsigned __int8 buf[4]; // [esp+108h] [ebp-8h] BYREF
  int v6; // [esp+10Ch] [ebp-4h]

  if ( (a1[27] & 1) == 0 )
    png_error((int)a1, (int)"Missing IHDR before gAMA");
  if ( (a1[27] & 4) != 0 )
  {
    png_warning((int)a1, "Invalid gAMA after IDAT");
    return png_crc_finish((int)a1, a3);
  }
  else
  {
    if ( (a1[27] & 2) != 0 )
      png_warning((int)a1, "Out of place gAMA chunk");
    if ( a2 && (*(_DWORD *)(a2 + 8) & 1) != 0 && (*(_DWORD *)(a2 + 8) & 0x800) == 0 )
    {
      png_warning((int)a1, "Duplicate gAMA chunk");
      return png_crc_finish((int)a1, a3);
    }
    else if ( a3 == 4 )
    {
      png_crc_read(a1, buf, 4);
      result = png_crc_finish((int)a1, 0);
      if ( !result )
      {
        v6 = sub_471D20(0, buf);
        if ( v6 > 0 )
        {
          if ( a2 && (*(_DWORD *)(a2 + 8) & 0x800) != 0 && (v6 < 45000 || v6 > 46000) )
          {
            png_warning_parameter_signed((int)v4, 1, 5, v6);
            return png_formatted_warning((int)a1, (int)v4, "Ignoring incorrect gAMA value @1 when sRGB is also present");
          }
          else
          {
            a1[94] = v6;
            return png_set_gAMA_fixed((int)a1, a2, v6);
          }
        }
        else
        {
          return png_warning((int)a1, "Ignoring gAMA chunk with out of range gamma");
        }
      }
    }
    else
    {
      png_warning((int)a1, "Incorrect gAMA chunk length");
      return png_crc_finish((int)a1, a3);
    }
  }
  return result;
}
