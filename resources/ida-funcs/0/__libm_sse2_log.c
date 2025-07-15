void __usercall __libm_sse2_log(__m128d a1@<xmm0>)
{
  __m128i v1; // xmm5
  __m128d v2; // xmm0
  int v3; // eax
  __m128d v4; // xmm6
  unsigned int v5; // ecx
  __m128d v6; // xmm0
  double i; // [esp+4h] [ebp-8h]

  for ( i = a1.m128d_f64[0]; ; a1.m128d_f64[0] = i * *(double *)Two52_0 )
  {
    v1 = (__m128i)a1;
    v2 = _mm_or_pd(_mm_and_pd(_mm_unpacklo_pd(a1, a1), *(__m128d *)emask_1), *(__m128d *)One_1);
    v3 = _mm_extract_epi16((__m128i)_mm_add_pd(*(__m128d *)Magic_0, v2), 0) & 0x7F0;
    v4 = _mm_and_pd(*(__m128d *)hi_mask_0, v2);
    a1 = _mm_add_pd(
           _mm_mul_pd(_mm_sub_pd(v2, v4), *(__m128d *)((char *)B_Tbl_0 + v3)),
           _mm_sub_pd(_mm_mul_pd(v4, *(__m128d *)((char *)B_Tbl_0 + v3)), *(__m128d *)One_1));
    v5 = (_mm_extract_epi16(_mm_srli_epi64(v1, 0x34u), 0) & 0xFFF) - 1;
    if ( v5 <= 0x7FD )
      break;
    v6.m128d_f64[0] = i;
    if ( _mm_extract_epi16((__m128i)_mm_cmpeq_sd(*(__m128d *)Zero_0, v6), 0) || v5 != -1 )
      break;
  }
}
