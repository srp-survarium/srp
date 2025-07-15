vostok::math::float3 *__userpurge vostok::collision::sphere_geometry_instance::get_random_surface_point@<eax>(
        vostok::collision::sphere_geometry_instance *this@<ecx>,
        float a2@<xmm0>,
        vostok::math::float3 *result,
        vostok::math::random32 *randomizer)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  __m128i v7; // xmm0
  long double v9; // [esp+4h] [ebp-Ch]
  float v10; // [esp+8h] [ebp-8h]
  float v11; // [esp+Ch] [ebp-4h]
  float v12; // [esp+Ch] [ebp-4h]
  float v13; // [esp+1Ch] [ebp+Ch]

  vostok::collision::sphere_geometry_instance::radius(this);
  v5 = a2 * 2.0;
  v11 = vostok::math::random32::random_f(randomizer, v5);
  vostok::collision::sphere_geometry_instance::radius(this);
  v12 = v11 - v5;
  v13 = vostok::math::random32::random_f(randomizer, 6.2831855);
  vostok::collision::sphere_geometry_instance::radius(this);
  v6 = v5 * v5;
  v7 = (__m128i)LODWORD(v12);
  HIDWORD(v9) = fsqrt(v6 - (float)(*(float *)v7.m128i_i32 * *(float *)v7.m128i_i32));
  __libm_sse2_cos(v9);
  result->x = v13 * v10;
  *(double *)v7.m128i_i64 = v13;
  __libm_sse2_sin(v7);
  result->z = v12;
  result->y = v13 * v10;
  return result;
}
