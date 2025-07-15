double __thiscall vostok::math::float4_pod::squared_length(vostok::math::float4_pod *this)
{
  return this->z * this->z + this->y * this->y + this->w * this->w + this->x * this->x;
}
