int __cdecl png_read_chunk_header(_DWORD *a1)
{
  unsigned __int8 v2[4]; // [esp+0h] [ebp-10h] BYREF
  unsigned int buf; // [esp+4h] [ebp-Ch] BYREF
  int uint_31; // [esp+Ch] [ebp-4h]

  a1[171] = 33;
  png_read_data((int)a1, (int)v2, 8);
  uint_31 = png_get_uint_31((int)a1, v2);
  a1[64] = _byteswap_ulong(buf);
  png_reset_crc((int)a1);
  png_calculate_crc(a1, (unsigned __int8 *)&buf, 4u);
  png_check_chunk_name(a1, a1[64]);
  a1[171] = 65;
  return uint_31;
}
