btVector3 *__userpurge btConeTwistConstraint::GetPointForAngle@<eax>(
        btConeTwistConstraint *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        __m128i a4@<xmm0>,
        __m128 a5@<xmm1>,
        float result,
        float fAngleInRadians,
        float fLength)
{
  __m128 v8; // xmm0
  __m128i v9; // xmm0
  float v10; // xmm3_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  long double v14; // [esp+0h] [ebp-40h]
  long double v15; // [esp+0h] [ebp-40h]
  float v16; // [esp+Ch] [ebp-34h]
  float v17; // [esp+18h] [ebp-28h]
  float v18; // [esp+38h] [ebp-8h]

  __libm_sse2_cos(v14);
  *(double *)a4.m128i_i64 = result;
  __libm_sse2_sin(a4);
  a5.m128_f32[0] = result;
  v8 = (__m128)*(unsigned int *)(a2 + 480);
  if ( COERCE_FLOAT(LODWORD(result) & _mask__AbsFloat_) > 0.00000011920929 )
  {
    v8 = a5;
    v8.m128_f32[0] = fsqrt(
                       (float)((float)((float)(result * result) / (float)(result * result)) + s_bm_current_air_resistance)
                     / (float)((float)(s_bm_current_air_resistance / (float)(*(float *)(a2 + 484) * *(float *)(a2 + 484)))
                             + (float)((float)((float)(result * result) / (float)(result * result))
                                     / (float)(*(float *)(a2 + 480) * *(float *)(a2 + 480)))));
  }
  v8.m128_f32[0] = v8.m128_f32[0] * 0.5;
  v16 = v8.m128_f32[0];
  v9 = (__m128i)_mm_cvtps_pd(v8);
  __libm_sse2_sin(v9);
  *(float *)v9.m128i_i32 = *(double *)v9.m128i_i64;
  *(float *)v9.m128i_i32 = *(float *)v9.m128i_i32
                         / fsqrt(
                             (float)(COERCE_FLOAT(LODWORD(result) ^ _mask__NegFloat_)
                                   * COERCE_FLOAT(LODWORD(result) ^ _mask__NegFloat_))
                           + (float)(result * result));
  v17 = *(float *)v9.m128i_i32 * COERCE_FLOAT(LODWORD(result) ^ _mask__NegFloat_);
  __libm_sse2_cos(v15);
  v10 = (float)((float)(v16 * fAngleInRadians) + (float)((float)(*(float *)v9.m128i_i32 * result) * 0.0))
      - (float)(v17 * 0.0);
  v11 = (float)((float)(v17 * fAngleInRadians) + (float)(v16 * 0.0))
      - (float)((float)(*(float *)v9.m128i_i32 * 0.0) * 0.0);
  v18 = (float)((float)((float)(*(float *)v9.m128i_i32 * 0.0) * 0.0) + (float)(v16 * 0.0))
      - (float)((float)(*(float *)v9.m128i_i32 * result) * fAngleInRadians);
  v12 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(*(float *)v9.m128i_i32 * 0.0) * fAngleInRadians) ^ _mask__NegFloat_)
              - (float)((float)(*(float *)v9.m128i_i32 * result) * 0.0))
      - (float)(v17 * 0.0);
  *(float *)a3 = (float)((float)((float)(v12
                                       * COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)v9.m128i_i32 * 0.0) ^ _mask__NegFloat_))
                               + (float)(COERCE_FLOAT(LODWORD(v17) ^ _mask__NegFloat_) * v11))
                       + (float)(v10 * v16))
               - (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)v9.m128i_i32 * result) ^ _mask__NegFloat_) * v18);
  *(float *)(a3 + 4) = (float)((float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)v9.m128i_i32 * result) ^ _mask__NegFloat_)
                                             * v12)
                                     + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)v9.m128i_i32 * 0.0) ^ _mask__NegFloat_)
                                             * v18))
                             + (float)(v16 * v11))
                     - (float)(COERCE_FLOAT(LODWORD(v17) ^ _mask__NegFloat_) * v10);
  *(float *)(a3 + 8) = (float)((float)((float)(COERCE_FLOAT(LODWORD(v17) ^ _mask__NegFloat_) * v12)
                                     + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)v9.m128i_i32 * result) ^ _mask__NegFloat_)
                                             * v10))
                             + (float)(v18 * v16))
                     - (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)v9.m128i_i32 * 0.0) ^ _mask__NegFloat_) * v11);
  *(_DWORD *)(a3 + 12) = 0;
  return (btVector3 *)a3;
}
