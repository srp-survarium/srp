double __usercall __libm_sse2_tan@<st0>(__m128i X@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(X, 3) & 0x7FFF) - 14368) > 2216
    && COERCE_DOUBLE(*(_QWORD *)sign_mask_0 & X.m128i_i64[0] ^ X.m128i_i64[0]) != *(double *)INF_7 )
  {
    return tan(*(double *)X.m128i_i64);
  }
  return result;
}
