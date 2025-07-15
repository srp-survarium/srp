int __cdecl png_muldiv(_DWORD *a1, int a2, int a3, int a4)
{
  double v5; // [esp+8h] [ebp-8h]

  if ( !a4 )
    return 0;
  if ( !a2 || !a3 )
  {
    *a1 = 0;
    return 1;
  }
  v5 = floor((double)a3 * (double)a2 / (double)a4 + 0.5);
  if ( v5 > 2147483647.0 || v5 < -2147483648.0 )
    return 0;
  *a1 = (int)v5;
  return 1;
}
