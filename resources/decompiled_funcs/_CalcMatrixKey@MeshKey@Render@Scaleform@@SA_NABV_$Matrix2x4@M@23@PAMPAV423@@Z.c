char __cdecl Scaleform::Render::MeshKey::CalcMatrixKey(
        const Scaleform::Render::Matrix2x4<float> *m,
        float *key,
        Scaleform::Render::Matrix2x4<float> *m2)
{
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm5
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm1
  __m128 si128; // xmm6
  __m128 v11; // xmm5
  __m128 v12; // xmm0
  __m128 v13; // xmm3
  __m128 v14; // xmm4
  __m128 v15; // xmm2

  if ( m2 )
    return Scaleform::Render::MeshKey::CalcMatrixKey_NonOpt(m, key, m2);
  v4 = *(__m128 *)&m->M[1][0];
  v5 = _mm_shuffle_ps(*(__m128 *)&m->M[0][0], v4, 85);
  v6 = _mm_shuffle_ps(*(__m128 *)&m->M[0][0], v4, 0);
  v7 = _mm_mul_ps(_mm_shuffle_ps(v4, *(__m128 *)&m->M[0][0], 0), _mm_sub_ps(v5, v6));
  v8 = _mm_mul_ps(v5, v6);
  v9 = _mm_add_ps(_mm_mul_ps(v4, v4), _mm_mul_ps(*(__m128 *)&m->M[0][0], *(__m128 *)&m->M[0][0]));
  si128 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v);
  v11 = _mm_rsqrt_ps(v9);
  v12 = _mm_mul_ps(
          _mm_unpacklo_ps(
            _mm_and_ps(
              _mm_sub_ps(_mm_shuffle_ps(v7, v7, 10), v7),
              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<2147483647,2147483647,2147483647,2147483647>'::`2'::v),
            _mm_add_ps(_mm_shuffle_ps(v8, v8, 10), v8)),
          _mm_shuffle_ps(v11, v11, 0));
  v13 = _mm_shuffle_ps(v12, v12, 207);
  v14 = _mm_rcp_ps(
          _mm_shuffle_ps(
            _mm_sub_ps(
              v12,
              _mm_and_ps(v13, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,0,0,0>'::`2'::v)),
            v11,
            72));
  v15 = _mm_add_ps(_mm_mul_ps(v14, v12), c0100);
  *(__m128 *)key = _mm_shuffle_ps(
                     v14,
                     _mm_xor_ps(
                       _mm_and_ps(_mm_xor_ps(_mm_shuffle_ps(v15, v15, 225), v15), _mm_cmple_ps(si128, v13)),
                       v15),
                     14);
  return (_mm_movemask_ps(_mm_cmpneq_ps(_mm_shuffle_ps(v9, v12, 4), si128)) & 0xF) == 15;
}
