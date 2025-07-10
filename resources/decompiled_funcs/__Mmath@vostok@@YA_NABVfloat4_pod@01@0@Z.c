BOOL __usercall vostok::math::operator<@<eax>(
        const vostok::math::float4_pod *left@<ecx>,
        const vostok::math::float4_pod *right@<eax>)
{
  return right->x > left->x && right->y > left->y && right->z > left->z && right->w > left->w;
}
