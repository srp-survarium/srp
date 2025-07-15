int __cdecl sub_464CB0(int a1, int a2)
{
  double v3; // [esp+8h] [ebp-8h]

  v3 = floor((double)a2 * ((double)a1 * 0.00001) + 0.5);
  if ( v3 > 2147483647.0 || v3 < -2147483648.0 )
    return 0;
  else
    return (int)v3;
}
