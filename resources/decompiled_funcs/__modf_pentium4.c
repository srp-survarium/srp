double __cdecl _modf_pentium4(const __m128i arg2)
{
  __m128i v1; // xmm6
  __m128i v2; // xmm0
  unsigned __int64 v3; // xmm4_8
  int v4; // eax
  unsigned __int8 v5; // xmm2_1
  double v6; // xmm1_8
  int v7; // edx
  double result; // st7
  __m128d v9; // xmm0
  long double v10; // xmm1_8
  __m128i v11; // xmm0
  int epi16; // eax
  double v13; // xmm0_8
  void *arg1; // [esp+0h] [ebp-1Ch] BYREF
  double retval; // [esp+10h] [ebp-Ch] BYREF

  v1 = _mm_loadl_epi64(&arg2);
  v2 = _mm_srli_epi64(_mm_slli_epi64(v1, 1u), 0x35u);
  v3 = v1.m128i_i64[0] & Sign;
  v4 = _mm_cvtsi128_si32(v2);
  v5 = _mm_sub_epi32(*(__m128i *)&Bns_1, v2).m128i_u8[0];
  *(_QWORD *)&v6 = (unsigned __int64)v1.m128i_i64[0] >> v5 << v5;
  v7 = _mm_cvtsi128_si32(_mm_srli_epi64(v1, 0x34u));
  if ( v4 < 1023 )
  {
    *(_QWORD *)arg2.m128i_i32[2] = v3;
    return *(double *)arg2.m128i_i64;
  }
  else if ( v4 > 1074 )
  {
    v9 = (__m128d)_mm_loadl_epi64(&arg2);
    if ( v4 == 2047 )
    {
      v10 = v9.m128d_f64[0];
      v9.m128d_f64[0] = v9.m128d_f64[0] + v9.m128d_f64[0];
      *(long double *)arg2.m128i_i32[2] = v9.m128d_f64[0];
      v11 = (__m128i)_mm_cmpneq_pd(_mm_and_pd(v9, *(__m128d *)&Mantissa), *(__m128d *)&Zero_0);
      epi16 = _mm_extract_epi16(v11, 0);
      *(_QWORD *)&v13 = v11.m128i_i64[0] & *(_QWORD *)&v10 | v3;
      if ( epi16 )
      {
        retval = v13;
        __libm_error_support((long double *)&arg1 + 4, (long double *)&arg2.m128i_i64[1], &retval, modf_nan);
        return retval;
      }
      else
      {
        *(double *)arg2.m128i_i64 = v13;
        return v13;
      }
    }
    else
    {
      *(long double *)arg2.m128i_i32[2] = v9.m128d_f64[0];
      result = 0.0;
      if ( v7 >= 2048 )
        return -0.0;
    }
  }
  else
  {
    *(double *)arg2.m128i_i32[2] = v6;
    arg2.m128i_i64[0] = COERCE_UNSIGNED_INT64(*(double *)v1.m128i_i64 - v6) | v3;
    return *(double *)arg2.m128i_i64;
  }
  return result;
}
