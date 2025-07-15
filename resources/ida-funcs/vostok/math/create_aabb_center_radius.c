vostok::math::aabb *__cdecl vostok::math::create_aabb_center_radius(
        vostok::math::aabb *result,
        const vostok::math::float3 *center,
        const vostok::math::float3 *radius)
{
  vostok::math::aabb *v3; // eax
  float v4; // ecx
  __int64 v5; // [esp+0h] [ebp-Ch]
  float v6; // [esp+8h] [ebp-4h]

  v3 = result;
  *(float *)&v5 = center->x - radius->x;
  *((float *)&v5 + 1) = center->y - radius->y;
  v6 = center->z - radius->z;
  *(_QWORD *)&result->min.x = v5;
  result->min.z = v6;
  *(float *)&v5 = center->x + radius->x;
  *((float *)&v5 + 1) = center->y + radius->y;
  v4 = radius->z + center->z;
  *(_QWORD *)&result->max.x = v5;
  result->max.z = v4;
  return v3;
}
