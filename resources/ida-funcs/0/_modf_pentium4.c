double __cdecl _modf_pentium4(__m128i a1)
{
  __m128i v2; // xmm6
  __m128i v3; // xmm0
  unsigned __int64 v4; // xmm4_8
  int v5; // eax
  unsigned __int8 v6; // xmm2_1
  double v7; // xmm1_8
  int v8; // edx
  double result; // st7
  __m128d v10; // xmm0
  long double v11; // xmm1_8
  __m128i v12; // xmm0
  int epi16; // eax
  double v14; // xmm0_8
  void *arg1; // [esp+0h] [ebp-1Ch] BYREF
  double retval; // [esp+10h] [ebp-Ch] BYREF

  v2 = _mm_loadl_epi64(&a1);
  v3 = _mm_srli_epi64(_mm_slli_epi64(v2, 1u), 0x35u);
  v4 = v2.m128i_i64[0] & Sign;
  v5 = _mm_cvtsi128_si32(v3);
  v6 = _mm_sub_epi32(*(__m128i *)&Bns_1, v3).m128i_u8[0];
  *(_QWORD *)&v7 = (unsigned __int64)v2.m128i_i64[0] >> v6 << v6;
  v8 = _mm_cvtsi128_si32(_mm_srli_epi64(v2, 0x34u));
  if ( v5 < 1023 )
  {
    *(_QWORD *)a1.m128i_i32[2] = v4;
    return *(double *)a1.m128i_i64;
  }
  else if ( v5 > 1074 )
  {
    v10 = (__m128d)_mm_loadl_epi64(&a1);
    if ( v5 == 2047 )
    {
      v11 = v10.m128d_f64[0];
      v10.m128d_f64[0] = v10.m128d_f64[0] + v10.m128d_f64[0];
      *(long double *)a1.m128i_i32[2] = v10.m128d_f64[0];
      v12 = (__m128i)_mm_cmpneq_pd(_mm_and_pd(v10, *(__m128d *)&Mantissa), *(__m128d *)&Zero_0);
      epi16 = _mm_extract_epi16(v12, 0);
      *(_QWORD *)&v14 = v12.m128i_i64[0] & *(_QWORD *)&v11 | v4;
      if ( epi16 )
      {
        retval = v14;
        __libm_error_support((double *)&arg1 + 4, (double *)&a1.m128i_i64[1], &retval, 1007);
        return retval;
      }
      else
      {
        *(double *)a1.m128i_i64 = v14;
        return v14;
      }
    }
    else
    {
      *(long double *)a1.m128i_i32[2] = v10.m128d_f64[0];
      result = 0.0;
      if ( v8 >= 2048 )
        return -0.0;
    }
  }
  else
  {
    *(double *)a1.m128i_i32[2] = v7;
    a1.m128i_i64[0] = COERCE_UNSIGNED_INT64(*(double *)v2.m128i_i64 - v7) | v4;
    return *(double *)a1.m128i_i64;
  }
  return result;
}
