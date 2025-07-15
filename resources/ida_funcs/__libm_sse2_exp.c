double __usercall __libm_sse2_exp@<st0>(__m128d a1@<xmm0>)
{
  __m128i v1; // xmm0
  int v2; // eax
  __m128i v3; // xmm7
  __m128d v4; // xmm1
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  __m128d v8; // xmm0
  __m128d v9; // xmm2
  __m128d v10; // xmm4
  __m128d v11; // xmm0
  __m128d v12; // xmm0
  __m128i v13; // xmm2
  double v14; // xmm0_8
  int v15; // edx
  int v16; // eax
  double result; // st7
  double v18; // [esp+8h] [ebp-16h]

  v1 = (__m128i)_mm_unpacklo_pd(a1, a1);
  v2 = _mm_extract_epi16(v1, 3) & 0x7FFF;
  if ( ((v2 - 15504) | (unsigned int)(16527 - v2)) < 0x80000000 )
  {
    v3 = (__m128i)_mm_add_pd(
                    _mm_mul_pd(*(__m128d *)&stru_984D24.m_working_macro_list.m_buffer[10].m_store[476], (__m128d)v1),
                    *(__m128d *)&stru_984D24.m_working_macro_list.m_buffer[10].m_store[460]);
    v4 = _mm_sub_pd((__m128d)v3, *(__m128d *)&stru_984D24.m_working_macro_list.m_buffer[10].m_store[460]);
    v5 = _mm_cvtsi128_si32(v3);
    v6 = 16 * (v5 & 0x3F);
    v7 = v5 >> 6;
    v8 = _mm_sub_pd(
           _mm_sub_pd(
             (__m128d)v1,
             _mm_mul_pd(*(__m128d *)&stru_984D24.m_working_macro_list.m_buffer[10].m_store[492], v4)),
           _mm_mul_pd(*(__m128d *)&stru_984D24.m_working_macro_list.m_buffer[10].m_store[508], v4));
    v9 = *(__m128d *)&stru_984D24.m_working_macro_list.m_buffer[11].m_store[v6 + 12];
    v10 = _mm_mul_pd(*(__m128d *)&stru_984D24.m_working_macro_list.m_buffer[10].m_store[524], v8);
    v4.m128d_f64[0] = v8.m128d_f64[0];
    v11 = _mm_mul_pd(v8, v8);
    v11.m128d_f64[0] = v11.m128d_f64[0] * v11.m128d_f64[0];
    v12 = _mm_mul_pd(v11, _mm_add_pd(*(__m128d *)&stru_984D24.m_working_macro_list.m_buffer[10].m_store[540], v10));
    v4.m128d_f64[0] = v4.m128d_f64[0] + v9.m128d_f64[0] + v12.m128d_f64[0];
    v13 = (__m128i)_mm_or_pd(
                     _mm_unpackhi_pd(v9, v9),
                     (__m128d)_mm_slli_epi64(
                                _mm_add_epi64(
                                  _mm_and_si128(
                                    v3,
                                    _mm_load_si128((const __m128i *)&stru_984D24.m_working_macro_list.m_buffer[10].m_store[428])),
                                  _mm_load_si128((const __m128i *)&stru_984D24.m_working_macro_list.m_buffer[10].m_store[444])),
                                0x2Eu));
    v14 = _mm_unpackhi_pd(v12, v12).m128d_f64[0] + v4.m128d_f64[0];
    if ( (unsigned int)(v7 + 894) > 0x77C )
    {
      v15 = v7;
      v16 = v7 >> 1;
      *(_QWORD *)&v18 = _mm_andnot_si128(
                          _mm_load_si128((const __m128i *)&stru_984D24.m_working_macro_list.m_buffer[10].m_store[412]),
                          v13).m128i_u64[0]
                      | (_mm_cvtsi32_si128(v16 + 1023).m128i_u64[0] << 52);
      return (v14 * v18 + v18) * COERCE_DOUBLE(_mm_cvtsi32_si128(v15 - v16 + 1023).m128i_u64[0] << 52);
    }
  }
  return result;
}
