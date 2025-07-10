void __thiscall Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
        Scaleform::Render::Matrix3x4<float> *this,
        const Scaleform::Render::Matrix3x4<float> *m1,
        const Scaleform::Render::Matrix2x4<float> *m2)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm4
  __m128 v6; // xmm5
  __m128 v7; // xmm3

  v3 = *(__m128 *)&m1->M[1][0];
  v4 = *(__m128 *)&m1->M[2][0];
  v5 = *(__m128 *)&m2->M[0][0];
  v6 = *(__m128 *)&m2->M[1][0];
  v7 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>'::`2'::v;
  *(__m128 *)&this->M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 85), v6),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 0),
                                    *(__m128 *)&m2->M[0][0])),
                                _mm_and_ps(
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,4294967295,4294967295>'::`2'::v,
                                  *(__m128 *)&m1->M[0][0]));
  *(__m128 *)&this->M[1][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), v6),
                                  _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), v5)),
                                _mm_and_ps(v7, v3));
  *(__m128 *)&this->M[2][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), v6),
                                  _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), v5)),
                                _mm_and_ps(v7, v4));
}
