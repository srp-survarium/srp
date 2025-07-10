vostok::math::float3 *__thiscall vostok::math::float3_pod::operator/=(vostok::math::float3_pod *this, float value)
{
  float v2; // xmm0_4
  vostok::math::float3 *result; // eax
  float v4; // xmm1_4
  float v5; // xmm0_4

  v2 = *(float *)&clear_value / value;
  result = (vostok::math::float3 *)this;
  this->x = this->x * (float)(*(float *)&clear_value / value);
  v4 = v2 * this->y;
  v5 = v2 * this->z;
  this->y = v4;
  this->z = v5;
  return result;
}
