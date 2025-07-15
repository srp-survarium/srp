void __cdecl png_set_sRGB_gAMA_and_cHRM(int a1, _DWORD *a2, char a3)
{
  if ( a1 )
  {
    if ( a2 )
    {
      png_set_sRGB(a1, (int)a2, a3);
      png_set_gAMA_fixed(a1, (int)a2, 45455);
      png_set_cHRM_fixed(a1, a2, 31270, 32900, 64000, 33000, 30000, 60000, 15000, 6000);
    }
  }
}
