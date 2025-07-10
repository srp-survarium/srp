__m128 __usercall btSimdDot3@<xmm0>(__m128 vec0@<xmm0>, __m128 vec1@<xmm1>)
{
  __m128 v2; // xmm1

  v2 = _mm_mul_ps(vec0, vec1);
  return _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v2, v2, 170), _mm_shuffle_ps(v2, v2, 85)), _mm_shuffle_ps(v2, v2, 0));
}
