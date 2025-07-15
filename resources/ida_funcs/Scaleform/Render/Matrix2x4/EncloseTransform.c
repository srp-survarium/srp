void __thiscall Scaleform::Render::Matrix2x4<float>::EncloseTransform(
        Scaleform::Render::Matrix2x4<float> *this,
        Scaleform::Render::Rect<float> *pr,
        __m128 *r)
{
  __m128 v3; // xmm3
  __m128 v4; // xmm2
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  __m128 v14; // xmm2

  v3 = *(__m128 *)&this->M[1][0];
  v4 = *r;
  v5 = _mm_shuffle_ps(*(__m128 *)&this->M[0][0], v3, 255);
  v6 = _mm_unpacklo_ps(*(__m128 *)&this->M[0][0], v3);
  v7 = _mm_mul_ps(_mm_unpacklo_ps(v4, v4), v6);
  v8 = _mm_mul_ps(_mm_unpackhi_ps(v4, v4), v6);
  v9 = _mm_unpacklo_ps(v7, v8);
  v10 = _mm_unpackhi_ps(v7, v8);
  v11 = _mm_add_ps(v10, v9);
  v12 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 177), v10);
  v13 = _mm_min_ps(v11, v12);
  v14 = _mm_max_ps(v11, v12);
  *(__m128 *)pr = _mm_add_ps(
                    _mm_shuffle_ps(
                      _mm_min_ps(v13, _mm_shuffle_ps(v13, v13, 177)),
                      _mm_max_ps(v14, _mm_shuffle_ps(v14, v14, 177)),
                      136),
                    _mm_shuffle_ps(v5, v5, 136));
}


Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Matrix2x4<float>::EncloseTransform(
        Scaleform::Render::Matrix2x4<float> *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Rect<float> *r)
{
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(this, result, r);
  return result;
}
