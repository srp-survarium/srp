BOOL __usercall vostok::math::operator<@<eax>(
        const vostok::math::float3_pod *left@<ecx>,
        const vostok::math::float3_pod *right@<eax>)
{
  return right->x > left->x && right->y > left->y && right->z > left->z;
}
