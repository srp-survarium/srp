void __usercall vorbis_lsp_to_curve(
        int a1@<edi>,
        int a2@<esi>,
        __int128 a3@<xmm2>,
        float *curve,
        int *map,
        int n,
        int ln,
        float *lsp,
        int m,
        float amp,
        float ampoffset)
{
  int v11; // esi
  float v12; // xmm0_4
  float *v13; // edi
  double v14; // xmm0_8
  int v15; // esi
  int v16; // edi
  int v17; // eax
  double v18; // xmm0_8
  int i; // eax
  int v20; // eax
  __int128 v21; // xmm0
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float *v25; // eax
  float v26; // xmm1_4
  long double v27; // [esp-Ch] [ebp-18h]
  long double v28; // [esp-Ch] [ebp-18h]
  int v29; // [esp+0h] [ebp-Ch]
  float v30; // [esp+4h] [ebp-8h]
  float v31; // [esp+8h] [ebp-4h]
  float v32; // [esp+20h] [ebp+14h]

  HIDWORD(v27) = a2;
  v11 = 0;
  v12 = 3.1415927 / (float)ln;
  LODWORD(v27) = a1;
  v30 = v12;
  if ( m > 0 )
  {
    do
    {
      v13 = &lsp[v11];
      v14 = *v13;
      __libm_sse2_cos(v27);
      ++v11;
      *(float *)&v14 = v14 * 2.0;
      *v13 = *(float *)&v14;
    }
    while ( v11 < m );
    v12 = 3.1415927 / (float)ln;
  }
  v15 = 0;
  v16 = 0;
  if ( n > 0 )
  {
    v17 = *map;
    while ( 1 )
    {
      v32 = c_anim_center;
      v31 = c_anim_center;
      v29 = v17;
      v18 = (float)((float)v17 * v12);
      __libm_sse2_cos(v27);
      *(float *)&a3 = v18 * 2.0;
      for ( i = 0; ; i = v20 + 1 )
      {
        v20 = i + 1;
        if ( v20 >= m )
          break;
        v31 = (float)(*(float *)&a3 - lsp[v20 - 1]) * v31;
        v32 = (float)(*(float *)&a3 - lsp[v20]) * v32;
      }
      if ( v20 == m )
      {
        v21 = a3;
        *(float *)&v21 = (float)(*(float *)&a3 - lsp[v20 - 1]) * v31;
        v22 = *(float *)&a3 * *(float *)&a3;
        a3 = v21;
        v23 = 4.0 - v22;
        *(float *)&a3 = *(float *)&v21 * *(float *)&v21;
      }
      else
      {
        v23 = 2.0 - *(float *)&a3;
        *(float *)&a3 = (float)((float)(*(float *)&a3 + 2.0) * v31) * v31;
      }
      __libm_sse2_exp(v28);
      v24 = (amp / sqrt((float)(*(float *)&a3 + (float)((float)(v23 * v32) * v32))) - ampoffset) * 0.1151292473077774;
      do
      {
        v25 = &curve[v15];
        v26 = curve[v15];
        v15 = ++v16;
        *v25 = v26 * v24;
        v17 = map[v16];
      }
      while ( v17 == v29 );
      if ( v16 >= n )
        break;
      v12 = v30;
    }
  }
}
