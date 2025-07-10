float __cdecl vostok::math::length(const vostok::math::float3 *object)
{
  return sqrtf((float)((float)(object->x * object->x) + (float)(object->y * object->y)) + (float)(object->z * object->z));
}
