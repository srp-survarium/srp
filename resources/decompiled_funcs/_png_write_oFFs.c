int __cdecl png_write_oFFs(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned __int8 buf[4]; // [esp+0h] [ebp-10h] BYREF
  _BYTE v6[8]; // [esp+4h] [ebp-Ch] BYREF

  if ( a4 >= 2 )
    png_warning((int)a1, "Unrecognized unit type for oFFs chunk");
  png_save_int_32(buf, a2);
  png_save_int_32(v6, a3);
  v6[4] = a4;
  return sub_36AEC0(a1, 1866876531, buf, 9);
}
