float __usercall vostok::math::operator|@<xmm0>(
        const vostok::math::float3_pod *left@<ecx>,
        const vostok::math::float3_pod *right@<eax>)
{
  return (float)((float)(left->z * right->z) + (float)(left->y * right->y)) + (float)(left->x * right->x);
}
