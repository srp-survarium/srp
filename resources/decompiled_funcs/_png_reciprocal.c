int __cdecl png_reciprocal(int a1)
{
  double v2; // [esp+8h] [ebp-8h]

  v2 = floor(1.0e10 / (double)a1 + 0.5);
  if ( v2 > 2147483647.0 || v2 < -2147483648.0 )
    return 0;
  else
    return (int)v2;
}
