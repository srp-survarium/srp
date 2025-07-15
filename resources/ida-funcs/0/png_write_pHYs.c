int __cdecl png_write_pHYs(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned __int8 buf[4]; // [esp+0h] [ebp-10h] BYREF
  _BYTE v6[8]; // [esp+4h] [ebp-Ch] BYREF

  if ( a4 >= 2 )
    png_warning((int)a1, "Unrecognized unit type for pHYs chunk");
  png_save_uint_32(buf, a2);
  png_save_uint_32(v6, a3);
  v6[4] = a4;
  return sub_477B80(a1, 1883789683, buf, 9);
}
