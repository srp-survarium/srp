int __cdecl png_get_gAMA(int a1, int a2, double *a3)
{
  int v4; // [esp+0h] [ebp-8h] BYREF
  int gAMA_fixed; // [esp+4h] [ebp-4h]

  gAMA_fixed = png_get_gAMA_fixed(a1, a2, &v4);
  if ( gAMA_fixed )
    *a3 = (double)v4 * 0.00001;
  return gAMA_fixed;
}
