Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::Append(
        Scaleform::Render::Matrix2x4<float> *this,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  __m128 v2; // xmm3
  Scaleform::Render::Matrix2x4<float> *result; // eax
  __m128 v4; // xmm5
  __m128 v5; // xmm0

  v2 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v;
  result = this;
  v4 = *(__m128 *)&this->M[1][0];
  v5 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m->M[1][0], *(__m128 *)&m->M[1][0], 85), v4),
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m->M[1][0], *(__m128 *)&m->M[1][0], 0), *(__m128 *)&this->M[0][0])),
         _mm_and_ps(
           *(__m128 *)&m->M[1][0],
           (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
  *(__m128 *)&this->M[0][0] = _mm_and_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m->M[0][0], *(__m128 *)&m->M[0][0], 85), v4),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&m->M[0][0], *(__m128 *)&m->M[0][0], 0),
                                      *(__m128 *)&this->M[0][0])),
                                  _mm_and_ps(
                                    *(__m128 *)&m->M[0][0],
                                    (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v)),
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v);
  *(__m128 *)&this->M[1][0] = _mm_and_ps(v5, v2);
  return result;
}
