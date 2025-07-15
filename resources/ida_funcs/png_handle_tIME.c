int __cdecl png_handle_tIME(_DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned __int8 buf[8]; // [esp+0h] [ebp-14h] BYREF
  unsigned __int8 src[2]; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int8 v6; // [esp+Eh] [ebp-6h]
  unsigned __int8 v7; // [esp+Fh] [ebp-5h]
  unsigned __int8 v8; // [esp+10h] [ebp-4h]
  unsigned __int8 v9; // [esp+11h] [ebp-3h]
  unsigned __int8 v10; // [esp+12h] [ebp-2h]

  if ( (a1[27] & 1) == 0 )
    png_error((int)a1, (int)"Out of place tIME chunk");
  if ( a2 && (*(_DWORD *)(a2 + 8) & 0x200) != 0 )
  {
    png_warning((int)a1, "Duplicate tIME chunk");
    return png_crc_finish((int)a1, a3);
  }
  else
  {
    if ( (a1[27] & 4) != 0 )
      a1[27] |= 8u;
    if ( a3 == 7 )
    {
      png_crc_read(a1, buf, 7);
      result = png_crc_finish((int)a1, 0);
      if ( !result )
      {
        v10 = buf[6];
        v9 = buf[5];
        v8 = buf[4];
        v7 = buf[3];
        v6 = buf[2];
        *(_WORD *)src = buf[1] + (buf[0] << 8);
        return png_set_tIME((int)a1, a2, src);
      }
    }
    else
    {
      png_warning((int)a1, "Incorrect tIME chunk length");
      return png_crc_finish((int)a1, a3);
    }
  }
  return result;
}
