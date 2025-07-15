void __usercall mdct_init(int n@<eax>, mdct_lookup *lookup)
{
  int v3; // ebx
  float *v4; // edi
  double v5; // xmm1_8
  __m128d v6; // xmm2
  __m128i v7; // xmm0
  float v8; // xmm1_4
  __m128 v9; // xmm0
  float *v10; // eax
  int v11; // ebx
  float *v12; // esi
  int v13; // edi
  float v14; // xmm0_4
  int v15; // eax
  int i; // esi
  char v17; // cl
  int v18; // edi
  long double v19; // [esp+0h] [ebp-40h]
  long double v20; // [esp+0h] [ebp-40h]
  long double v21; // [esp+0h] [ebp-40h]
  long double v22; // [esp+0h] [ebp-40h]
  int v23; // [esp+10h] [ebp-30h]
  float *v24; // [esp+14h] [ebp-2Ch]
  int v25; // [esp+14h] [ebp-2Ch]
  int v26; // [esp+18h] [ebp-28h]
  int v27; // [esp+1Ch] [ebp-24h]
  int v28; // [esp+1Ch] [ebp-24h]
  float v29; // [esp+20h] [ebp-20h]
  float v30; // [esp+24h] [ebp-1Ch]
  int v31; // [esp+28h] [ebp-18h]
  int *v32; // [esp+2Ch] [ebp-14h]
  float v33; // [esp+34h] [ebp-Ch]
  float v34; // [esp+38h] [ebp-8h]

  v3 = n / 4;
  v32 = (int *)ogg_malloc_impl(4 * (n / 4));
  v4 = (float *)ogg_malloc_impl(4 * (v3 + n));
  v30 = (float)n;
  __libm_sse2_log(v19);
  __libm_sse2_log(v20);
  v23 = 0;
  v5 = (float)n / 2.0 + 0.5;
  *(_QWORD *)&v6.m128d_f64[0] = *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v5;
  v7 = (__m128i)LODWORD(pi_23);
  v31 = (int)(v5
            + COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v5)
            - COERCE_DOUBLE(*(_QWORD *)&DOUBLE_4_503599627370496e15 | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v5)
            - COERCE_DOUBLE(
                *(_OWORD *)&_mm_cmpgt_sd(
                              (__m128d)COERCE_UNSIGNED_INT64(
                                         v5
                                       + COERCE_DOUBLE(
                                           *(_QWORD *)&DOUBLE_4_503599627370496e15
                                         | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v5)
                                       - COERCE_DOUBLE(
                                           *(_QWORD *)&DOUBLE_4_503599627370496e15
                                         | *(_QWORD *)&DOUBLE_N0_0 & *(_QWORD *)&v5)
                                       - v5),
                              v6)
              & *(_QWORD *)&DOUBLE_1_0));
  lookup->log2n = v31;
  lookup->n = n;
  lookup->trig = v4;
  lookup->bitrev = v32;
  if ( v3 > 0 )
  {
    v26 = 0;
    v8 = 3.1415927 / v30;
    v33 = 3.1415927 / (float)(2 * n);
    v27 = 1;
    v24 = &v4[n >> 1];
    while ( 1 )
    {
      __libm_sse2_cos(v21);
      *(float *)v7.m128i_i32 = (float)v26 * v8;
      v4[2 * v23] = *(float *)v7.m128i_i32;
      *(double *)v7.m128i_i64 = *(float *)v7.m128i_i32;
      __libm_sse2_sin(v7);
      *(double *)v7.m128i_i64 = -*(double *)v7.m128i_i64;
      *(double *)&v7.m128i_i64[1] = -*(double *)&v7.m128i_i64[1];
      v9 = _mm_cvtpd_ps((__m128d)v7);
      v4[2 * v23 + 1] = v9.m128_f32[0];
      v9.m128_f32[0] = (float)v27 * v33;
      v7 = (__m128i)_mm_cvtps_pd(v9);
      __libm_sse2_cos(v22);
      *(float *)v7.m128i_i32 = *(double *)v7.m128i_i64;
      *v24 = *(float *)v7.m128i_i32;
      *(double *)v7.m128i_i64 = (float)((float)v27 * v33);
      __libm_sse2_sin(v7);
      v10 = v24;
      ++v23;
      v26 += 4;
      v24 += 2;
      v27 += 2;
      *(float *)v7.m128i_i32 = *(double *)v7.m128i_i64;
      v10[1] = *(float *)v7.m128i_i32;
      if ( v23 >= v3 )
        break;
      v8 = 3.1415927 / v30;
    }
    v7 = (__m128i)LODWORD(pi_23);
  }
  v11 = n / 8;
  if ( n / 8 > 0 )
  {
    v12 = &v4[n];
    v29 = *(float *)v7.m128i_i32 / v30;
    v28 = 2;
    v13 = v11;
    do
    {
      v34 = (float)v28 * v29;
      __libm_sse2_cos(v21);
      *(float *)v7.m128i_i32 = v34 * 0.5;
      *v12 = *(float *)v7.m128i_i32;
      *(double *)v7.m128i_i64 = v34;
      __libm_sse2_sin(v7);
      v28 += 4;
      v14 = v34 * -0.5;
      v12[1] = v14;
      v12 += 2;
      --v13;
    }
    while ( v13 );
  }
  v15 = 1 << (v31 - 2);
  for ( i = 0; i < v11; ++i )
  {
    v17 = 0;
    v25 = 0;
    if ( v15 )
    {
      v18 = 1 << (v31 - 2);
      do
      {
        if ( (v18 & i) != 0 )
          v25 |= 1 << v17;
        v18 = v15 >> ++v17;
      }
      while ( v15 >> v17 );
    }
    v32[2 * i] = (((1 << (v31 - 1)) - 1) & ~v25) - 1;
    v32[2 * i + 1] = v25;
  }
  lookup->scale = 4.0 / v30;
}
