vostok::math::float3 *__cdecl vostok::particle::random_float3(
        vostok::math::float3 *result,
        const vostok::math::float3 *min_value,
        const vostok::math::float3 *max_value)
{
  unsigned int other_x; // [esp+4h] [ebp-Ch]
  unsigned int other_y; // [esp+8h] [ebp-8h]
  float other_z; // [esp+Ch] [ebp-4h]

  other_z = vostok::particle::random_float(min_value->z, max_value->z);
  *(float *)&other_y = vostok::particle::random_float(min_value->y, max_value->y);
  *(float *)&other_x = vostok::particle::random_float(min_value->x, max_value->x);
  vostok::math::float3::float3(result, other_x, other_y, other_z);
  return result;
}
