int __cdecl sub_4669D0(int a1, double a2)
{
  double v3; // [esp+14h] [ebp+Ch]

  if ( a2 > 0.0 && a2 < 128.0 )
    a2 = a2 * 100000.0;
  v3 = floor(a2 + 0.5);
  if ( v3 > 2147483647.0 || v3 < -2147483647.0 )
    png_fixed_error(a1, (int)"gamma value");
  return (int)v3;
}
