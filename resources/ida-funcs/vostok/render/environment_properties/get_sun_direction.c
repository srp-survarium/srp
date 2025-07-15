vostok::math::float3 *__usercall vostok::render::environment_properties::get_sun_direction@<eax>(
        vostok::render::environment_properties *this@<ecx>,
        int a2@<eax>,
        float *a3@<esi>)
{
  __m128 v3; // xmm0
  __m128i v4; // xmm0
  long double v6; // [esp+0h] [ebp-18h]
  long double v7; // [esp+0h] [ebp-18h]
  float v8; // [esp+0h] [ebp-18h]
  float v9; // [esp+Ch] [ebp-Ch]
  float v10; // [esp+10h] [ebp-8h]
  float v11; // [esp+14h] [ebp-4h]

  v3 = (__m128)*(unsigned int *)(a2 + 64);
  v3.m128_f32[0] = (float)((float)(v3.m128_f32[0] * 0.0055555557) + 0.5) * 3.1415927;
  v9 = v3.m128_f32[0];
  v11 = (float)(*(float *)(a2 + 60) * 0.0055555557) * 3.1415927;
  v4 = (__m128i)_mm_cvtps_pd(v3);
  __libm_sse2_sin(v4);
  *(float *)v4.m128i_i32 = *(double *)v4.m128i_i64;
  v10 = *(float *)v4.m128i_i32;
  __libm_sse2_cos(v6);
  *(float *)&v7 = v11 * *(float *)v4.m128i_i32;
  __libm_sse2_cos(v7);
  *(double *)v4.m128i_i64 = v11;
  __libm_sse2_sin(v4);
  *(float *)v4.m128i_i32 = s_bm_current_air_resistance
                         / fsqrt(
                             (float)((float)(v8 * v8) + (float)((float)(v11 * v10) * (float)(v11 * v10)))
                           + (float)(v9 * v9));
  *a3 = *(float *)v4.m128i_i32 * v8;
  a3[1] = *(float *)v4.m128i_i32 * v9;
  a3[2] = *(float *)v4.m128i_i32 * (float)(v11 * v10);
  return (vostok::math::float3 *)a3;
}
