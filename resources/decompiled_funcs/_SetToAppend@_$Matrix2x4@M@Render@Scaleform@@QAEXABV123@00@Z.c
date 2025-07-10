void __thiscall Scaleform::Render::Matrix2x4<float>::SetToAppend(
        Scaleform::Render::Matrix2x4<float> *this,
        const Scaleform::Render::Matrix2x4<float> *m0,
        const Scaleform::Render::Matrix2x4<float> *m1,
        const Scaleform::Render::Matrix2x4<float> *m2)
{
  __m128 v4; // xmm4
  __m128 v5; // xmm0
  __m128 v6; // xmm1
  __m128 v7; // xmm6
  __m128 v8; // xmm0
  __m128 v9; // [esp+10h] [ebp-10h]

  v9 = *(__m128 *)&m0->M[1][0];
  v4 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v;
  v5 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m2->M[0][0], *(__m128 *)&m2->M[0][0], 85), *(__m128 *)&m1->M[1][0]),
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m2->M[0][0], *(__m128 *)&m2->M[0][0], 0), *(__m128 *)&m1->M[0][0])),
         _mm_and_ps(
           *(__m128 *)&m2->M[0][0],
           (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
  v6 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m2->M[1][0], *(__m128 *)&m2->M[1][0], 85), *(__m128 *)&m1->M[1][0]),
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m2->M[1][0], *(__m128 *)&m2->M[1][0], 0), *(__m128 *)&m1->M[0][0])),
         _mm_and_ps(
           *(__m128 *)&m2->M[1][0],
           (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), v9),
           _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), *(__m128 *)&m0->M[0][0])),
         _mm_and_ps(v5, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v6, v6, 85), v9),
           _mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), *(__m128 *)&m0->M[0][0])),
         _mm_and_ps(v6, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
  *(__m128 *)&this->M[0][0] = _mm_and_ps(
                                v7,
                                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v);
  *(__m128 *)&this->M[1][0] = _mm_and_ps(v8, v4);
}
