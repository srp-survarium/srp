int __cdecl png_handle_pHYs(_DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned __int8 buf[8]; // [esp+0h] [ebp-1Ch] BYREF
  unsigned __int8 v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+10h] [ebp-Ch]
  int v7; // [esp+14h] [ebp-8h]
  int v8; // [esp+18h] [ebp-4h]

  if ( (a1[27] & 1) == 0 )
    png_error((int)a1, (int)"Missing IHDR before pHYs");
  if ( (a1[27] & 4) != 0 )
  {
    png_warning((int)a1, "Invalid pHYs after IDAT");
    return png_crc_finish((int)a1, a3);
  }
  else if ( a2 && (*(_DWORD *)(a2 + 8) & 0x80) != 0 )
  {
    png_warning((int)a1, "Duplicate pHYs chunk");
    return png_crc_finish((int)a1, a3);
  }
  else if ( a3 == 9 )
  {
    png_crc_read(a1, buf, 9);
    result = png_crc_finish((int)a1, 0);
    if ( !result )
    {
      v8 = buf[3] + (buf[2] << 8) + (buf[1] << 16) + (buf[0] << 24);
      v6 = buf[7] + (buf[6] << 8) + (buf[5] << 16) + (buf[4] << 24);
      v7 = v5;
      return png_set_pHYs((int)a1, a2, v8, v6, v5);
    }
  }
  else
  {
    png_warning((int)a1, "Incorrect pHYs chunk length");
    return png_crc_finish((int)a1, a3);
  }
  return result;
}
