vostok::math::float4x4 *__userpurge vostok::physics::bt_animated_rigid_body::get_bone_transform@<eax>(
        vostok::physics::bt_animated_rigid_body *this@<ecx>,
        int a2@<eax>,
        long double a3@<esi:edi>,
        vostok::math::float4x4 *result,
        const unsigned int index)
{
  HIDWORD(a3) = *(_DWORD *)(*(_DWORD *)(a2 + 52) + 24) + 80 * (_DWORD)this;
  vostok::physics::from_bullet(a3, (int)result);
  return result;
}
