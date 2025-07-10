vostok::math::float3 *__thiscall vostok::math::aabb::extents(vostok::math::aabb *this, vostok::math::float3 *result)
{
  vostok::math::float3 *v2; // eax
  float v3; // xmm1_4
  float v4; // xmm2_4

  v2 = result;
  v3 = (float)(this->max.y - this->min.y) * 0.5;
  v4 = (float)(this->max.z - this->min.z) * 0.5;
  result->x = (float)(this->max.x - this->min.x) * 0.5;
  result->y = v3;
  result->z = v4;
  return v2;
}
