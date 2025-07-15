float __usercall vostok::math::float3_pod::dot_product@<xmm0>(
        vostok::math::float3_pod *this@<ecx>,
        const vostok::math::float3_pod *other@<eax>)
{
  return (float)((float)(other->z * this->z) + (float)(other->y * this->y)) + (float)(other->x * this->x);
}
