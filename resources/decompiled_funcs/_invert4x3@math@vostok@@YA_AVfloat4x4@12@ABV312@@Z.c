vostok::math::float4x4 *__usercall vostok::math::invert4x3@<eax>(
        const vostok::math::float4x4 *other@<ecx>,
        vostok::math::float4x4 *a2@<eax>)
{
  return invert_impl(
           other,
           a2,
           (float)((float)((float)((float)(other->j.y * other->k.z) - (float)(other->j.z * other->k.y)) * other->i.x)
                 - (float)((float)((float)(other->j.x * other->k.z) - (float)(other->k.x * other->j.z)) * other->i.y))
         + (float)((float)((float)(other->j.x * other->k.y) - (float)(other->k.x * other->j.y)) * other->i.z));
}
