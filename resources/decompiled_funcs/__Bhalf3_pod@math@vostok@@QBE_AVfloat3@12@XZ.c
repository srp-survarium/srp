vostok::math::float3 *__thiscall vostok::math::half3_pod::operator vostok::math::float3(
        vostok::math::half3_pod *this,
        vostok::math::float3 *result)
{
  _BYTE v4[12]; // [esp+4h] [ebp-30h]

  *(float *)v4 = vostok::math::half_pod::operator float(&this->x);
  *(float *)&v4[4] = vostok::math::half_pod::operator float(&this->y);
  *(float *)&v4[8] = vostok::math::half_pod::operator float(&this->z);
  *result = *(vostok::math::float3 *)v4;
  return result;
}
