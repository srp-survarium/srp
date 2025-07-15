bool __usercall vostok::collision::loose_oct_tree::out_of_bounds@<al>(
        vostok::collision::loose_oct_tree *this@<esi>,
        const vostok::math::float3 *aabb_center@<eax>,
        const vostok::math::float3 *aabb_extents@<edi>)
{
  vostok::math::float3 *v3; // eax
  float m_aabb_extents; // xmm3_4
  bool v5; // al
  vostok::math::float3 v7; // [esp+0h] [ebp-18h] BYREF
  vostok::math::float3 object; // [esp+Ch] [ebp-Ch] BYREF

  object.x = aabb_center->x - this->m_aabb_center.x;
  object.y = aabb_center->y - this->m_aabb_center.y;
  object.z = aabb_center->z - this->m_aabb_center.z;
  v3 = vostok::math::abs(&object, &v7);
  m_aabb_extents = this->m_aabb_extents;
  v5 = m_aabb_extents >= (float)(v3->x + aabb_extents->x)
    && this->m_aabb_extents >= (float)(v3->y + aabb_extents->y)
    && m_aabb_extents >= (float)(v3->z + aabb_extents->z);
  return !v5;
}
