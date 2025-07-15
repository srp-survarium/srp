void __cdecl vorbis_lsp_to_curve(float *curve, int *map, int n, int ln, float *lsp, int m, float amp, float ampoffset)
{
  int v8; // esi
  long double v9; // st7
  int v10; // edi
  int j; // eax
  int v12; // esi
  int v13; // ebp
  long double v14; // st6
  int v15; // eax
  double i; // st6
  double v17; // st5
  double v18; // st7
  float p; // [esp+4h] [ebp-18h]
  float pa; // [esp+4h] [ebp-18h]
  float w; // [esp+8h] [ebp-14h]
  float wdel; // [esp+14h] [ebp-8h]
  float q; // [esp+2Ch] [ebp+10h]
  float qb; // [esp+2Ch] [ebp+10h]
  float qc; // [esp+2Ch] [ebp+10h]
  float qa; // [esp+2Ch] [ebp+10h]

  v8 = 0;
  for ( wdel = 3.141592741012573 / (double)ln; v8 < m; lsp[v8 - 1] = v9 + v9 )
    v9 = cos(lsp[v8++]);
  v10 = 0;
  if ( n > 0 )
  {
    j = *map;
    v12 = 0;
    do
    {
      v13 = j;
      p = 0.5;
      q = 0.5;
      v14 = cos((double)j * wdel) * 2.0;
      v15 = 1;
      w = v14;
      for ( i = w; v15 < m; p = (i - lsp[v15 - 2]) * p )
      {
        v17 = i - lsp[v15 - 1];
        v15 += 2;
        q = v17 * q;
      }
      if ( v15 == m )
      {
        qb = (i - lsp[v15 - 1]) * q;
        pa = (4.0 - i * i) * p * p;
        v18 = qb * qb;
      }
      else
      {
        pa = (2.0 - i) * p * p;
        v18 = (i + 2.0) * q * q;
      }
      qc = v18;
      qa = exp((amp / sqrt(qc + pa) - ampoffset) * 0.1151292473077774);
      ++v10;
      curve[v12] = curve[v12] * qa;
      v12 = v10;
      for ( j = map[v10]; j == v13; j = map[v10] )
      {
        ++v10;
        curve[v12] = curve[v12] * qa;
        v12 = v10;
      }
    }
    while ( v10 < n );
  }
}
