void __thiscall Scaleform::Render::Matrix4x4<float>::TransformHomogeneousAndScaleCorners(
        Scaleform::Render::Matrix4x4<float> *this,
        __m128 *bounds,
        float sx,
        float sy,
        __m128 *dest)
{
  __m128 v5; // xmm5
  __m128 v6; // xmm7
  __m128 v7; // xmm3
  __m128 v8; // xmm6
  __m128 v9; // xmm2
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm4
  __m128 v14; // xmm5
  __m128 v15; // xmm6
  __m128 v16; // xmm2
  __m128 v17; // xmm7
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // [esp+0h] [ebp-B0h]
  __m128 v21; // [esp+0h] [ebp-B0h]
  __m128 v22; // [esp+10h] [ebp-A0h]
  __m128 v23; // [esp+10h] [ebp-A0h]
  __m128 v24; // [esp+20h] [ebp-90h]
  __m128 v25; // [esp+60h] [ebp-50h]
  __m128 v26; // [esp+70h] [ebp-40h]
  __m128 v27; // [esp+80h] [ebp-30h]
  __m128 v28; // [esp+90h] [ebp-20h]
  __m128 v29; // [esp+A0h] [ebp-10h]

  v22.m128_f32[0] = sx;
  v5 = *(__m128 *)&this->M[1][0];
  v6 = *(__m128 *)&this->M[2][0];
  v22.m128_f32[1] = sy;
  v28 = _mm_shuffle_ps(
          _mm_shuffle_ps(*(__m128 *)&this->M[0][0], v5, 255),
          _mm_shuffle_ps(v6, *(__m128 *)&this->M[3][0], 255),
          136);
  v7 = _mm_shuffle_ps(*bounds, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 4);
  v8 = _mm_shuffle_ps(*bounds, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 6);
  v20 = _mm_shuffle_ps(*bounds, (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,0>'::`2'::v, 14);
  v9 = _mm_mul_ps(v7, v6);
  v10 = _mm_mul_ps(v7, *(__m128 *)&this->M[0][0]);
  v11 = _mm_mul_ps(v7, v5);
  v26 = _mm_mul_ps(v7, *(__m128 *)&this->M[3][0]);
  v12 = _mm_mul_ps(v8, *(__m128 *)&this->M[0][0]);
  v13 = _mm_mul_ps(v8, v5);
  v14 = _mm_mul_ps(v8, v6);
  v24 = _mm_mul_ps(v8, *(__m128 *)&this->M[3][0]);
  v25 = _mm_mul_ps(v20, *(__m128 *)&this->M[0][0]);
  v27 = _mm_mul_ps(v20, *(__m128 *)&this->M[1][0]);
  v29 = _mm_mul_ps(v20, v6);
  v21 = _mm_mul_ps(v20, *(__m128 *)&this->M[3][0]);
  v23 = _mm_mul_ps(
          _mm_shuffle_ps(v22, v22, 68),
          (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<1056964608,1056964608,1056964608,1056964608>'::`2'::v);
  v15 = _mm_shuffle_ps(
          _mm_unpacklo_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
              _mm_shuffle_ps(v10, v10, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
              _mm_shuffle_ps(v11, v11, 170))),
          _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170)),
          4);
  v16 = _mm_shuffle_ps(v28, v28, 255);
  v17 = _mm_shuffle_ps(
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
          4);
  v18 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<1065353216,1065353216,1065353216,1065353216>'::`2'::v;
  v19 = (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<1065353216,3212836864,1065353216,3212836864>'::`2'::v;
  *dest = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(
                  _mm_div_ps(
                    _mm_add_ps(v15, v28),
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                        _mm_shuffle_ps(v26, v26, 170)),
                      v16)),
                  _mm_div_ps(
                    _mm_add_ps(v17, v28),
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                        _mm_shuffle_ps(v24, v24, 170)),
                      v16)),
                  68),
                (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<1065353216,3212836864,1065353216,3212836864>'::`2'::v),
              (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<1065353216,1065353216,1065353216,1065353216>'::`2'::v),
            v23);
  dest[1] = _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_div_ps(
                    _mm_add_ps(
                      _mm_shuffle_ps(
                        _mm_unpacklo_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                            _mm_shuffle_ps(v25, v25, 170)),
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                            _mm_shuffle_ps(v27, v27, 170))),
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                          _mm_shuffle_ps(v29, v29, 170)),
                        4),
                      v28),
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                        _mm_shuffle_ps(v21, v21, 170)),
                      v16)),
                  v19),
                v18),
              v23);
}
