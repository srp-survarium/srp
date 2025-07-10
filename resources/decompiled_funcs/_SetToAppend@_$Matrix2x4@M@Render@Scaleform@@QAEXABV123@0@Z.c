void __thiscall Scaleform::Render::Matrix2x4<float>::SetToAppend(
        Scaleform::Render::Matrix2x4<float> *this,
        const Scaleform::Render::Matrix2x4<float> *m0,
        const Scaleform::Render::Matrix2x4<float> *m1)
{
  __m128 v3; // xmm5
  __m128 v4; // xmm3
  __m128 v5; // xmm0

  v3 = *(__m128 *)&m0->M[1][0];
  v4 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v;
  v5 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[1][0], *(__m128 *)&m1->M[1][0], 85), v3),
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[1][0], *(__m128 *)&m1->M[1][0], 0), *(__m128 *)&m0->M[0][0])),
         _mm_and_ps(
           *(__m128 *)&m1->M[1][0],
           (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
  *(__m128 *)&this->M[0][0] = _mm_and_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 85), v3),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 0),
                                      *(__m128 *)&m0->M[0][0])),
                                  _mm_and_ps(
                                    *(__m128 *)&m1->M[0][0],
                                    (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v)),
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v);
  *(__m128 *)&this->M[1][0] = _mm_and_ps(v5, v4);
}
