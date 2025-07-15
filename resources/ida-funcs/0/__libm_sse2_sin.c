double __usercall __libm_sse2_sin@<st0>(__m128i a1@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(a1, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(a1, 3) & 0x7FF0) != 0x7FF0 )
    return sin(*(double *)a1.m128i_i64);
  return result;
}
