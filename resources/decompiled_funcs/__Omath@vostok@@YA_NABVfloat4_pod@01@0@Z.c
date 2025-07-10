BOOL __usercall vostok::math::operator>@<eax>(
        const vostok::math::float4_pod *left@<ecx>,
        const vostok::math::float4_pod *right@<eax>)
{
  return left->x > right->x && left->y > right->y && left->z > right->z && left->w > right->w;
}
