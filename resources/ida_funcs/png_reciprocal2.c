int __cdecl png_reciprocal2(int a1, int a2)
{
  double v3; // [esp+8h] [ebp-8h]

  v3 = floor(1.0e15 / (double)a1 / (double)a2 + 0.5);
  if ( v3 > 2147483647.0 || v3 < -2147483648.0 )
    return 0;
  else
    return (int)v3;
}
