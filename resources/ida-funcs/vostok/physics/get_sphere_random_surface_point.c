vostok::math::float3 *__usercall vostok::physics::get_sphere_random_surface_point@<eax>(
        float *a1@<esi>,
        vostok::math::random32 *result)
{
  __m128i v2; // xmm0
  long double v4; // [esp+4h] [ebp-Ch]
  float v5; // [esp+4h] [ebp-Ch]
  float v6; // [esp+8h] [ebp-8h]
  unsigned int v7; // [esp+Ch] [ebp-4h]

  *(float *)&v7 = vostok::math::random32::random_f(result, 2.0) - s_bm_current_air_resistance;
  v2 = (__m128i)v7;
  *((float *)&v4 + 1) = vostok::math::random32::random_f(result, 6.2831855);
  LODWORD(v4) = fsqrt(s_bm_current_air_resistance - (float)(*(float *)v2.m128i_i32 * *(float *)v2.m128i_i32));
  *(double *)v2.m128i_i64 = *((float *)&v4 + 1);
  __libm_sse2_cos(v4);
  *(float *)v2.m128i_i32 = *(double *)v2.m128i_i64;
  *a1 = *(float *)v2.m128i_i32 * v5;
  *(double *)v2.m128i_i64 = v6;
  __libm_sse2_sin(v2);
  a1[2] = *(float *)&v7;
  a1[1] = v6 * v5;
  return (vostok::math::float3 *)a1;
}
