int __cdecl png_write_gAMA_fixed(_DWORD *a1, int a2)
{
  int v2; // ecx
  int buf; // [esp+0h] [ebp-4h] BYREF

  buf = v2;
  png_save_uint_32(&buf, a2);
  return sub_36AEC0(a1, 1732332865, (unsigned __int8 *)&buf, 4);
}
