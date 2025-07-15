vostok::math::aabb *__fastcall vostok::math::create_aabb_center_radius(
        const vostok::math::float3 *radius,
        const vostok::math::float3 *center,
        vostok::math::aabb *a3)
{
  float x; // xmm3_4
  float v4; // xmm0_4
  float y; // xmm4_4
  vostok::math::aabb *result; // eax
  float z; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm2_4

  x = center->x;
  v4 = radius->x;
  y = center->y;
  result = a3;
  z = center->z;
  v8 = radius->y;
  v9 = radius->z;
  a3->min.x = center->x - radius->x;
  a3->min.y = y - v8;
  a3->min.z = z - v9;
  a3->max.x = v4 + x;
  a3->max.y = v8 + y;
  a3->max.z = v9 + z;
  return result;
}
