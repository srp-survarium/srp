int __usercall fit_line@<eax>(
        lsfit_acc *a@<eax>,
        int *y0@<esi>,
        int *y1@<edi>,
        __int128 a4@<xmm6>,
        int fits,
        vorbis_info_floor1 *info)
{
  int x0; // ecx
  int x1; // edx
  double v8; // xmm5_8
  double v9; // xmm3_8
  __int128 v10; // xmm1
  double v11; // xmm2_8
  int *p_xb; // eax
  int v13; // ecx
  int v14; // edx
  double v15; // xmm0_8
  bool v16; // zf
  int v17; // eax
  int v18; // eax
  double v19; // xmm6_8
  __m128d v20; // xmm5
  double v21; // xmm2_8
  __m128d v22; // xmm6
  int v23; // eax
  __m128d v24; // xmm3
  double v25; // xmm2_8
  __m128d v26; // xmm4
  int v27; // edx
  double v29; // [esp+4h] [ebp-18h]
  double v30; // [esp+4h] [ebp-18h]
  double v31; // [esp+Ch] [ebp-10h]
  int v32; // [esp+10h] [ebp-Ch]
  int v33; // [esp+14h] [ebp-8h]

  x0 = a->x0;
  x1 = a[fits - 1].x1;
  v8 = 0.0;
  v9 = 0.0;
  v10 = 0;
  v29 = 0.0;
  v11 = 0.0;
  v32 = a->x0;
  v33 = x1;
  if ( fits > 0 )
  {
    p_xb = &a->xb;
    do
    {
      v13 = *(p_xb - 1);
      v14 = p_xb[5];
      v15 = (float)((float)((float)((float)(v14 + v13) * info->twofitweight) / (float)(v13 + 1))
                  + s_bm_current_air_resistance);
      v8 = (double)*(p_xb - 6) * v15 + (double)*p_xb + v8;
      v9 = (double)*(p_xb - 5) * v15 + (double)p_xb[1] + v9;
      *(double *)&a4 = (double)*(p_xb - 4) * v15 + (double)p_xb[2] + *(double *)&v10;
      v10 = a4;
      v29 = (double)*(p_xb - 2) * v15 + (double)p_xb[4] + v29;
      p_xb += 14;
      v16 = fits-- == 1;
      v11 = (double)v13 * v15 + (double)v14 + v11;
    }
    while ( !v16 );
    x1 = v33;
    x0 = v32;
  }
  v17 = *y0;
  if ( *y0 >= 0 )
  {
    v8 = (double)x0 + v8;
    v9 = (double)v17 + v9;
    *(double *)&a4 = (double)(x0 * x0) + *(double *)&v10;
    v10 = a4;
    v29 = (double)(x0 * v17) + v29;
    v11 = v11 + 1.0;
  }
  v18 = *y1;
  if ( *y1 >= 0 )
  {
    v8 = (double)x1 + v8;
    v9 = (double)v18 + v9;
    *(double *)&a4 = (double)(x1 * x1) + *(double *)&v10;
    v10 = a4;
    v29 = (double)(x1 * v18) + v29;
    v11 = v11 + 1.0;
  }
  v19 = v11 * *(double *)&v10 - v8 * v8;
  if ( v19 <= 0.0 )
  {
    *y0 = 0;
    *y1 = 0;
    return 1;
  }
  else
  {
    v31 = (*(double *)&v10 * v9 - v29 * v8) * (1.0 / v19);
    v30 = (v11 * v29 - v9 * v8) * (1.0 / v19);
    *(double *)&v10 = (double)x0 * v30 + v31 + 0.5;
    *(_QWORD *)&v20.m128d_f64[0] = *(_QWORD *)&DOUBLE_N0_0 & v10;
    v21 = *(double *)&v10
        + COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&v20.m128d_f64[0])
        - COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&v20.m128d_f64[0]);
    v22.m128d_f64[1] = *((long double *)&v10 + 1);
    v22.m128d_f64[0] = v21 - *(double *)&v10;
    *(double *)&v10 = (double)x1 * v30 + v31 + 0.5;
    v23 = (int)(v21 - COERCE_DOUBLE(*(_OWORD *)&_mm_cmpgt_sd(v22, v20) & *(_QWORD *)&DOUBLE_1_0));
    *(_QWORD *)&v24.m128d_f64[0] = *(_QWORD *)&DOUBLE_N0_0 & v10;
    v25 = *(double *)&v10
        + COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&v24.m128d_f64[0])
        - COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&v24.m128d_f64[0]);
    v26.m128d_f64[1] = *((long double *)&v10 + 1);
    v26.m128d_f64[0] = v25 - *(double *)&v10;
    v27 = (int)(v25 - COERCE_DOUBLE(*(_OWORD *)&_mm_cmpgt_sd(v26, v24) & *(_QWORD *)&DOUBLE_1_0));
    *y0 = v23;
    *y1 = v27;
    if ( v23 > 1023 )
      *y0 = 1023;
    if ( v27 > 1023 )
      *y1 = 1023;
    if ( *y0 < 0 )
      *y0 = 0;
    if ( *y1 < 0 )
      *y1 = 0;
    return 0;
  }
}
