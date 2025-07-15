vostok::math::float4 *__thiscall vostok::math::float4_pod::normalize(vostok::math::float4_pod *this)
{
  double v2; // st7
  vostok::math::float4 *result; // eax
  float v4; // xmm0_4
  float v5; // [esp+4h] [ebp-4h]

  v2 = vostok::math::float4_pod::squared_length(this);
  result = (vostok::math::float4 *)this;
  v5 = sqrt(v2);
  v4 = s_bm_current_air_resistance / v5;
  this->x = (float)(s_bm_current_air_resistance / v5) * this->x;
  this->y = this->y * v4;
  this->z = this->z * v4;
  this->w = this->w * v4;
  return result;
}
