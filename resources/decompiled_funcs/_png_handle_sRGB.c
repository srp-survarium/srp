void __cdecl png_handle_sRGB(int a1, _DWORD *a2, unsigned int a3)
{
  unsigned __int8 v3[260]; // [esp+0h] [ebp-110h] BYREF
  unsigned __int8 buf; // [esp+10Bh] [ebp-5h] BYREF
  int v5; // [esp+10Ch] [ebp-4h]

  if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
    png_error(a1, (int)"Missing IHDR before sRGB");
  if ( (*(_DWORD *)(a1 + 108) & 4) != 0 )
  {
    png_warning(a1, "Invalid sRGB after IDAT");
    png_crc_finish(a1, a3);
  }
  else
  {
    if ( (*(_DWORD *)(a1 + 108) & 2) != 0 )
      png_warning(a1, "Out of place sRGB chunk");
    if ( a2 && (a2[2] & 0x800) != 0 )
    {
      png_warning(a1, "Duplicate sRGB chunk");
      png_crc_finish(a1, a3);
    }
    else if ( a3 == 1 )
    {
      png_crc_read((_DWORD *)a1, &buf, 1);
      if ( !png_crc_finish(a1, 0) )
      {
        v5 = buf;
        if ( buf < 4u )
        {
          if ( a2 && (a2[2] & 1) != 0 && ((int)a2[10] < 45000 || (int)a2[10] > 46000) )
          {
            png_warning_parameter_signed((int)v3, 1, 5, a2[10]);
            png_formatted_warning(a1, (int)v3, "Ignoring incorrect gAMA value @1 when sRGB is also present");
          }
          if ( a2
            && (a2[2] & 4) != 0
            && ((int)a2[32] < 30270
             || (int)a2[32] > 32270
             || (int)a2[33] < 31900
             || (int)a2[33] > 33900
             || (int)a2[34] < 63000
             || (int)a2[34] > 65000
             || (int)a2[35] < 32000
             || (int)a2[35] > 34000
             || (int)a2[36] < 29000
             || (int)a2[36] > 31000
             || (int)a2[37] < 59000
             || (int)a2[37] > 61000
             || (int)a2[38] < 14000
             || (int)a2[38] > 16000
             || (int)a2[39] < 5000
             || (int)a2[39] > 7000) )
          {
            png_warning(a1, "Ignoring incorrect cHRM value when sRGB is also present");
          }
          *(_BYTE *)(a1 + 592) = 1;
          if ( !*(_BYTE *)(a1 + 594) )
          {
            *(_WORD *)(a1 + 596) = 6968;
            *(_WORD *)(a1 + 598) = 23434;
            *(_BYTE *)(a1 + 594) = 1;
          }
          png_set_sRGB_gAMA_and_cHRM(a1, a2, v5);
        }
        else
        {
          png_warning(a1, "Unknown sRGB intent");
        }
      }
    }
    else
    {
      png_warning(a1, "Incorrect sRGB chunk length");
      png_crc_finish(a1, a3);
    }
  }
}
