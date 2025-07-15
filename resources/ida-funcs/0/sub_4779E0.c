_DWORD *__cdecl sub_4779E0(_DWORD *a1, int a2, int a3)
{
  _DWORD *result; // eax
  _BYTE v4[4]; // [esp+0h] [ebp-Ch] BYREF
  unsigned __int8 buf[4]; // [esp+4h] [ebp-8h] BYREF

  if ( a1 )
  {
    a1[171] = 34;
    png_save_uint_32(v4, a3);
    png_save_uint_32(buf, a2);
    png_write_data((int)a1, (int)v4, 8);
    a1[64] = a2;
    png_reset_crc((int)a1);
    png_calculate_crc(a1, buf, 4u);
    result = a1;
    a1[171] = 66;
  }
  return result;
}
