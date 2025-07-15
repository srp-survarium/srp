BOOL __cdecl png_crc_error(_DWORD *a1)
{
  BOOL v2; // [esp+0h] [ebp-Ch]
  _BYTE v3[4]; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h]

  if ( ((a1[64] >> 29) & 1) != 0 )
    v2 = (a1[28] & 0x300) != 768;
  else
    v2 = (a1[28] & 0x800) == 0;
  a1[171] = 129;
  png_read_data((int)a1, (int)v3, 4);
  if ( !v2 )
    return 0;
  v4 = v3[3] + (v3[2] << 8) + (v3[1] << 16) + (v3[0] << 24);
  return v4 != a1[73];
}
