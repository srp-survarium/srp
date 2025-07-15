int __cdecl png_write_sRGB(_DWORD *a1, int a2)
{
  int v2; // ecx
  unsigned __int8 buf; // [esp+1h] [ebp-1h] BYREF

  buf = HIBYTE(v2);
  if ( a2 >= 4 )
    png_warning((int)a1, "Invalid sRGB rendering intent specified");
  buf = a2;
  return sub_477B80(a1, 1934772034, &buf, 1);
}
