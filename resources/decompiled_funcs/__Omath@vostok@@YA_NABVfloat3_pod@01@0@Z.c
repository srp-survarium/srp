BOOL __usercall vostok::math::operator>@<eax>(
        const vostok::math::float3_pod *left@<ecx>,
        const vostok::math::float3_pod *right@<eax>)
{
  return left->x > right->x && left->y > right->y && left->z > right->z;
}
