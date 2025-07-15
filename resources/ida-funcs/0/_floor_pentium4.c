double __cdecl _floor_pentium4(__m128i arg0)
{
  __m128i v2; // xmm7
  __m128i v3; // xmm0
  int v4; // eax
  __m128i v5; // xmm2
  __m128i v6; // xmm1
  double v7; // xmm1_8
  __m128d v9; // xmm1
  __m128d v10; // xmm3
  __int64 v11; // xmm0_8

  v2 = _mm_loadl_epi64(&arg0);
  v3 = _mm_srli_epi64(v2, 0x34u);
  v4 = _mm_cvtsi128_si32(v3);
  v5 = _mm_sub_epi32(*(__m128i *)&Bns, (__m128i)_mm_and_pd((__m128d)v3, *(__m128d *)&S));
  v6 = _mm_srl_epi64(v2, v5);
  if ( (v4 & 0x800) != 0 )
  {
    v9 = (__m128d)_mm_sll_epi64(v6, v5);
    v10 = (__m128d)_mm_loadl_epi64(&arg0);
    v11 = *(_OWORD *)&_mm_cmplt_pd(v10, v9);
    if ( v4 < 3071 )
    {
      arg0.m128i_i64[0] = (*(_OWORD *)&_mm_cmplt_pd(v10, *(__m128d *)&NegZero) | NegZero) & NegOne;
      return *(double *)arg0.m128i_i64;
    }
    else
    {
      if ( v4 > 3122 )
        return *(double *)arg0.m128i_i64;
      *(double *)arg0.m128i_i64 = v9.m128d_f64[0] - COERCE_DOUBLE(v11 & One);
      return *(double *)arg0.m128i_i64;
    }
  }
  else
  {
    if ( v4 >= 1023 )
    {
      *(_QWORD *)&v7 = v6.m128i_i64[0] << v5.m128i_i8[0];
      if ( v4 <= 1074 )
      {
        *(double *)arg0.m128i_i64 = v7;
        return v7;
      }
      return *(double *)arg0.m128i_i64;
    }
    return 0.0;
  }
}
