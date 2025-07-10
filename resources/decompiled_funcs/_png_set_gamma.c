void __cdecl png_set_gamma(int a1, double a2, double a3)
{
  int v3; // eax
  int v4; // [esp+8h] [ebp-4h]

  v4 = sub_359D10(a1, a3);
  v3 = sub_359D10(a1, a2);
  png_set_gamma_fixed(a1, v3, v4);
}
