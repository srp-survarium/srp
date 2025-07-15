unsigned int __cdecl sub_464D20(int a1, unsigned int *a2, int a3, int a4)
{
  unsigned int result; // eax
  double v5; // st7
  int v6; // [esp+10h] [ebp-4Ch]
  __int16 v7; // [esp+2Ch] [ebp-30h]
  unsigned int k; // [esp+30h] [ebp-2Ch]
  unsigned int j; // [esp+40h] [ebp-1Ch]
  int v10; // [esp+44h] [ebp-18h]
  unsigned int v11; // [esp+48h] [ebp-14h]
  unsigned int v12; // [esp+50h] [ebp-Ch]
  unsigned int i; // [esp+58h] [ebp-4h]

  v11 = (1 << (16 - a3)) - 1;
  *a2 = png_calloc(a1, 4 * (1 << (8 - a3)));
  result = *a2;
  v12 = *a2;
  for ( i = 0; i < 1 << (8 - a3); ++i )
  {
    *(_DWORD *)(v12 + 4 * i) = png_malloc(a1, 0x200u);
    v10 = *(_DWORD *)(v12 + 4 * i);
    result = png_gamma_significant(a4);
    if ( result )
    {
      for ( j = 0; j < 0x100; ++j )
      {
        v5 = pow((double)(i + (j << (8 - a3))) / (double)v11, (double)a4 * 0.00001);
        v6 = (int)floor(v5 * 65535.0 + 0.5);
        result = j;
        *(_WORD *)(v10 + 2 * j) = v6;
      }
    }
    else
    {
      for ( k = 0; k < 0x100; ++k )
      {
        result = i + (k << (8 - a3));
        v7 = result;
        if ( a3 )
        {
          result = ((1 << (15 - a3)) + 0xFFFF * result) / v11;
          v7 = result;
        }
        LOWORD(result) = v7;
        *(_WORD *)(v10 + 2 * k) = v7;
      }
    }
  }
  return result;
}
