vostok::math::float3 *__usercall vostok::math::float3_pod::operator-@<eax>(
        vostok::math::float3_pod *this@<ecx>,
        vostok::math::float3 *a2@<eax>)
{
  a2->x = -this->x;
  a2->y = -this->y;
  a2->z = -this->z;
  return a2;
}
