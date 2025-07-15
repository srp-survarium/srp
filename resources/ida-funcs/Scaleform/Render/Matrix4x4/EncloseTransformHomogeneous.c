void __thiscall Scaleform::Render::Matrix4x4<float>::EncloseTransformHomogeneous(
        Scaleform::Render::Matrix4x4<float> *this,
        __m128 *pr,
        __m128 *r)
{
  __m128 v3; // xmm7
  __m128 v4; // xmm4
  __m128 v5; // xmm6
  __m128 v6; // xmm0
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm5
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm6
  __m128 v24; // xmm6
  __m128 v25; // [esp+0h] [ebp-40h]
  __m128 v26; // [esp+10h] [ebp-30h]
  __m128 v27; // [esp+10h] [ebp-30h]
  __m128 v28; // [esp+10h] [ebp-30h]
  __m128 v29; // [esp+20h] [ebp-20h]
  __m128 v30; // [esp+30h] [ebp-10h]

  v3 = *(__m128 *)&this->M[1][0];
  v4 = _mm_shuffle_ps(*r, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 6);
  v5 = _mm_shuffle_ps(
         _mm_shuffle_ps(*(__m128 *)&this->M[0][0], v3, 255),
         _mm_shuffle_ps(*(__m128 *)&this->M[2][0], *(__m128 *)&this->M[3][0], 255),
         136);
  v6 = _mm_shuffle_ps(*r, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 4);
  v29 = _mm_shuffle_ps(*r, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 12);
  v7 = _mm_shuffle_ps(*r, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 14);
  v8 = _mm_mul_ps(v6, *(__m128 *)&this->M[0][0]);
  v9 = _mm_mul_ps(v6, v3);
  v10 = _mm_mul_ps(v6, *(__m128 *)&this->M[2][0]);
  v26 = _mm_mul_ps(v6, *(__m128 *)&this->M[3][0]);
  v25 = _mm_shuffle_ps(v5, v5, 255);
  v11 = _mm_div_ps(
          _mm_add_ps(
            _mm_shuffle_ps(
              _mm_unpacklo_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                  _mm_shuffle_ps(v8, v8, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                  _mm_shuffle_ps(v9, v9, 170))),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                _mm_shuffle_ps(v10, v10, 170)),
              4),
            v5),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
              _mm_shuffle_ps(v26, v26, 170)),
            v25));
  v12 = _mm_mul_ps(v4, *(__m128 *)&this->M[0][0]);
  v13 = _mm_mul_ps(v4, v3);
  v14 = _mm_mul_ps(v4, *(__m128 *)&this->M[2][0]);
  v27 = _mm_mul_ps(v4, *(__m128 *)&this->M[3][0]);
  v30 = v5;
  v15 = _mm_div_ps(
          _mm_add_ps(
            _mm_shuffle_ps(
              _mm_unpacklo_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                  _mm_shuffle_ps(v12, v12, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                  _mm_shuffle_ps(v13, v13, 170))),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                _mm_shuffle_ps(v14, v14, 170)),
              4),
            v5),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
              _mm_shuffle_ps(v27, v27, 170)),
            v25));
  v16 = _mm_mul_ps(v7, *(__m128 *)&this->M[0][0]);
  v17 = _mm_mul_ps(v7, v3);
  v18 = _mm_mul_ps(v7, *(__m128 *)&this->M[2][0]);
  v28 = _mm_mul_ps(v7, *(__m128 *)&this->M[3][0]);
  v19 = _mm_div_ps(
          _mm_add_ps(
            _mm_shuffle_ps(
              _mm_unpacklo_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                  _mm_shuffle_ps(v16, v16, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                  _mm_shuffle_ps(v17, v17, 170))),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                _mm_shuffle_ps(v18, v18, 170)),
              4),
            v5),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
              _mm_shuffle_ps(v28, v28, 170)),
            v25));
  v20 = _mm_mul_ps(v29, *(__m128 *)&this->M[0][0]);
  v21 = _mm_mul_ps(v29, v3);
  v22 = _mm_mul_ps(v29, *(__m128 *)&this->M[2][0]);
  v23 = _mm_mul_ps(v29, *(__m128 *)&this->M[3][0]);
  v24 = _mm_div_ps(
          _mm_add_ps(
            _mm_shuffle_ps(
              _mm_unpacklo_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                  _mm_shuffle_ps(v20, v20, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                  _mm_shuffle_ps(v21, v21, 170))),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                _mm_shuffle_ps(v22, v22, 170)),
              4),
            v30),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
              _mm_shuffle_ps(v23, v23, 170)),
            v25));
  *pr = _mm_shuffle_ps(
          _mm_min_ps(_mm_min_ps(_mm_min_ps(v11, v15), v19), v24),
          _mm_max_ps(_mm_max_ps(_mm_max_ps(v11, v15), v19), v24),
          68);
}
