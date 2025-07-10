int __cdecl FrustumCullsSphere_Detailed(int a1, float *a2, float a3)
{
  float v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v6 = 0;
  for ( i = 0; i < 6; ++i )
  {
    v4 = *(float *)(a1 + 16 * i) * *a2
       + *(float *)(a1 + 16 * i + 4) * a2[1]
       + *(float *)(a1 + 16 * i + 8) * a2[2]
       + *(float *)(a1 + 16 * i + 12);
    if ( v4 < -a3 )
      return 2;
    if ( a3 > (double)v4 )
      v6 = 1;
  }
  return v6;
}
