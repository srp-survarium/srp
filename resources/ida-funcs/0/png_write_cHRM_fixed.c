int __cdecl png_write_cHRM_fixed(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int result; // eax
  unsigned __int8 buf[4]; // [esp+0h] [ebp-24h] BYREF
  _BYTE v11[4]; // [esp+4h] [ebp-20h] BYREF
  _BYTE v12[4]; // [esp+8h] [ebp-1Ch] BYREF
  _BYTE v13[4]; // [esp+Ch] [ebp-18h] BYREF
  _BYTE v14[4]; // [esp+10h] [ebp-14h] BYREF
  _BYTE v15[4]; // [esp+14h] [ebp-10h] BYREF
  _BYTE v16[4]; // [esp+18h] [ebp-Ch] BYREF
  _BYTE v17[4]; // [esp+1Ch] [ebp-8h] BYREF

  result = png_check_cHRM_fixed((int)a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    png_save_uint_32(buf, a2);
    png_save_uint_32(v11, a3);
    png_save_uint_32(v12, a4);
    png_save_uint_32(v13, a5);
    png_save_uint_32(v14, a6);
    png_save_uint_32(v15, a7);
    png_save_uint_32(v16, a8);
    png_save_uint_32(v17, a9);
    return sub_477B80(a1, 1665684045, buf, 32);
  }
  return result;
}
