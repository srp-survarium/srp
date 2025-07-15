int __cdecl png_check_cHRM_fixed(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v10; // [esp+0h] [ebp-14h] BYREF
  int v11; // [esp+4h] [ebp-10h] BYREF
  int v12; // [esp+8h] [ebp-Ch] BYREF
  int v13; // [esp+Ch] [ebp-8h]
  int v14; // [esp+10h] [ebp-4h] BYREF

  v13 = 1;
  if ( !a1 )
    return 0;
  if ( a2 < 0 || a3 <= 0 || a4 < 0 || a5 < 0 || a6 < 0 || a7 < 0 || a8 < 0 || a9 < 0 )
  {
    png_warning(a1, "Ignoring attempt to set negative chromaticity value");
    v13 = 0;
  }
  if ( a2 > (int)&loc_186A0 - a3 )
  {
    png_warning(a1, "Invalid cHRM white point");
    v13 = 0;
  }
  if ( a4 > (int)&loc_186A0 - a5 )
  {
    png_warning(a1, "Invalid cHRM red point");
    v13 = 0;
  }
  if ( a6 > (int)&loc_186A0 - a7 )
  {
    png_warning(a1, "Invalid cHRM green point");
    v13 = 0;
  }
  if ( a8 > (int)&loc_186A0 - a9 )
  {
    png_warning(a1, "Invalid cHRM blue point");
    v13 = 0;
  }
  png_64bit_product(a6 - a4, a9 - a5, &v14, &v12);
  png_64bit_product(a7 - a5, a8 - a4, &v10, &v11);
  if ( v14 == v10 && v12 == v11 )
  {
    png_warning(a1, "Ignoring attempt to set cHRM RGB triangle with zero area");
    return 0;
  }
  return v13;
}
