double __cdecl _floor_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128i v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  double v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  __int64 v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = _mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32(v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns, (__m128i)_mm_and_pd((__m128d)v2, *(__m128d *)&S));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = *(_OWORD *)&_mm_cmplt_pd(v9, v8);
    if ( v3 < 3071 )
    {
      a1.m128i_i64[0] = (*(_OWORD *)&_mm_cmplt_pd(v9, *(__m128d *)&NegZero) | NegZero) & NegOne;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 3122 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] - COERCE_DOUBLE(v10 & One);
      return *(double *)a1.m128i_i64;
    }
  }
  else
  {
    if ( v3 >= 1023 )
    {
      *(_QWORD *)&v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 1074 )
      {
        *(double *)a1.m128i_i64 = v6;
        return v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return 0.0;
  }
}
