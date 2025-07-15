int __cdecl png_handle_oFFs(_DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned __int8 buf[8]; // [esp+Ch] [ebp-18h] BYREF
  unsigned __int8 v5; // [esp+14h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-8h]
  int v7; // [esp+20h] [ebp-4h]

  if ( (a1[27] & 1) == 0 )
    png_error((int)a1, (int)"Missing IHDR before oFFs");
  if ( (a1[27] & 4) != 0 )
  {
    png_warning((int)a1, "Invalid oFFs after IDAT");
    return png_crc_finish((int)a1, a3);
  }
  else if ( a2 && (*(_DWORD *)(a2 + 8) & 0x100) != 0 )
  {
    png_warning((int)a1, "Duplicate oFFs chunk");
    return png_crc_finish((int)a1, a3);
  }
  else if ( a3 == 9 )
  {
    png_crc_read(a1, buf, 9);
    result = png_crc_finish((int)a1, 0);
    if ( !result )
    {
      v6 = buf[3] + (buf[2] << 8) + (buf[1] << 16) + (buf[0] << 24);
      v7 = v5;
      return png_set_oFFs((int)a1, a2, v6, buf[7] + (buf[6] << 8) + (buf[5] << 16) + (buf[4] << 24), v5);
    }
  }
  else
  {
    png_warning((int)a1, "Incorrect oFFs chunk length");
    return png_crc_finish((int)a1, a3);
  }
  return result;
}
