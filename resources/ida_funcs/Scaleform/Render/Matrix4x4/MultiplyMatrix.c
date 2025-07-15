void __thiscall Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(
        Scaleform::Render::Matrix4x4<float> *this,
        const Scaleform::Render::Matrix4x4<float> *m1,
        const Scaleform::Render::Matrix4x4<float> *m2)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm5
  __m128 v9; // xmm7
  __m128 v10; // xmm6
  __m128 v11; // xmm0
  __m128 v12; // [esp+30h] [ebp-20h]

  v3 = *(__m128 *)&m1->M[0][0];
  v4 = *(__m128 *)&m1->M[1][0];
  v5 = *(__m128 *)&m1->M[2][0];
  v6 = *(__m128 *)&m1->M[3][0];
  v7 = *(__m128 *)&m2->M[0][0];
  v8 = *(__m128 *)&m2->M[2][0];
  v12 = *(__m128 *)&m2->M[1][0];
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), v12),
           _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), *(__m128 *)&m2->M[0][0])),
         _mm_mul_ps(_mm_shuffle_ps(v3, v3, 170), v8));
  v10 = _mm_shuffle_ps(v3, v3, 255);
  v11 = *(__m128 *)&m2->M[3][0];
  *(__m128 *)&this->M[0][0] = _mm_add_ps(v9, _mm_mul_ps(v10, v11));
  *(__m128 *)&this->M[1][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), v12),
                                    _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), v7)),
                                  _mm_mul_ps(_mm_shuffle_ps(v4, v4, 170), v8)),
                                _mm_mul_ps(_mm_shuffle_ps(v4, v4, 255), v11));
  *(__m128 *)&this->M[2][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), v12),
                                    _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), v7)),
                                  _mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), v8)),
                                _mm_mul_ps(_mm_shuffle_ps(v5, v5, 255), v11));
  *(__m128 *)&this->M[3][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v6, v6, 85), v12),
                                    _mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), v7)),
                                  _mm_mul_ps(_mm_shuffle_ps(v6, v6, 170), v8)),
                                _mm_mul_ps(_mm_shuffle_ps(v6, v6, 255), v11));
}


void __thiscall Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(
        Scaleform::Render::Matrix4x4<float> *this,
        const Scaleform::Render::Matrix4x4<float> *m1,
        const Scaleform::Render::Matrix3x4<float> *m2)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm3
  __m128 v6; // xmm4
  __m128 v7; // xmm5
  __m128 v8; // xmm0
  __m128 v9; // [esp+60h] [ebp-30h]

  v3 = *(__m128 *)&m1->M[1][0];
  v4 = *(__m128 *)&m1->M[2][0];
  v5 = *(__m128 *)&m1->M[3][0];
  v6 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v;
  v9 = *(__m128 *)&m2->M[1][0];
  v7 = *(__m128 *)&m2->M[2][0];
  v8 = *(__m128 *)&m2->M[0][0];
  *(__m128 *)&this->M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 85), v9),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 0),
                                      *(__m128 *)&m2->M[0][0])),
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 170), v7)),
                                _mm_and_ps(
                                  *(__m128 *)&m1->M[0][0],
                                  (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v));
  *(__m128 *)&this->M[1][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), v9),
                                    _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), v8)),
                                  _mm_mul_ps(_mm_shuffle_ps(v3, v3, 170), v7)),
                                _mm_and_ps(v3, v6));
  *(__m128 *)&this->M[2][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), v9),
                                    _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), v8)),
                                  _mm_mul_ps(_mm_shuffle_ps(v4, v4, 170), v7)),
                                _mm_and_ps(v4, v6));
  *(__m128 *)&this->M[3][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), v9),
                                    _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), v8)),
                                  _mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), v7)),
                                _mm_and_ps(v5, v6));
}


void __thiscall Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(
        Scaleform::Render::Matrix4x4<float> *this,
        const Scaleform::Render::Matrix2x4<float> *m1,
        const Scaleform::Render::Matrix4x4<float> *m2)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm5
  __m128 v5; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm0

  v3 = *(__m128 *)&m1->M[1][0];
  v4 = *(__m128 *)&m2->M[1][0];
  v5 = *(__m128 *)&m2->M[2][0];
  v6 = *(__m128 *)&m2->M[3][0];
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), v4),
           _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), *(__m128 *)&m2->M[0][0])),
         _mm_mul_ps(_mm_shuffle_ps(v3, v3, 170), v5));
  *(__m128 *)&this->M[0][0] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 85), v4),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 0),
                                      *(__m128 *)&m2->M[0][0])),
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 170), v5)),
                                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&m1->M[0][0], *(__m128 *)&m1->M[0][0], 255), v6));
  *(__m128 *)&this->M[1][0] = _mm_add_ps(v7, _mm_mul_ps(_mm_shuffle_ps(v3, v3, 255), v6));
  *(__m128 *)&this->M[2][0] = v5;
  *(__m128 *)&this->M[3][0] = v6;
}
