void __cdecl png_set_cHRM_fixed(int a1, _DWORD *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  if ( a1 && a2 )
  {
    if ( png_check_cHRM_fixed(a1, a3, a4, a5, a6, a7, a8, a9, a10) )
    {
      a2[32] = a3;
      a2[33] = a4;
      a2[34] = a5;
      a2[35] = a6;
      a2[36] = a7;
      a2[37] = a8;
      a2[38] = a9;
      a2[39] = a10;
      a2[2] |= 4u;
    }
  }
}
