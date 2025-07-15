vostok::math::plane *__fastcall vostok::math::create_plane_normalized(
        const vostok::math::float3 *normalized_normal,
        const vostok::math::float3 *point_on_plane,
        vostok::math::plane *a3)
{
  vostok::math::plane *result; // eax
  float v4; // xmm1_4
  float v5; // xmm0_4

  result = a3;
  v4 = normalized_normal->y * point_on_plane->y;
  *(_QWORD *)&a3->normal.x = *(_QWORD *)&normalized_normal->x;
  v5 = (float)((float)(normalized_normal->z * point_on_plane->z) + v4)
     + (float)(normalized_normal->x * point_on_plane->x);
  a3->normal.z = normalized_normal->z;
  a3->d = -v5;
  return result;
}
