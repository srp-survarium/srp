vostok::math::float3 *__thiscall vostok::math::float3_pod::normalize(vostok::math::float3_pod *this)
{
  double v2; // st7
  vostok::math::float3 *result; // eax
  double v4; // st6
  float x; // [esp+8h] [ebp-8h]
  float v6; // [esp+Ch] [ebp-4h]

  x = this->x;
  v2 = 1.0 / sqrtf((float)((float)(x * x) + (float)(this->y * this->y)) + (float)(this->z * this->z));
  result = (vostok::math::float3 *)this;
  v6 = v2;
  v4 = v2 * this->y;
  this->x = x * v6;
  this->y = v4;
  this->z = v2 * this->z;
  return result;
}
