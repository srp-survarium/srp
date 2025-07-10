BOOL __fastcall vostok::collision::loose_oct_tree::out_of_bounds(
        const vostok::math::float3 *aabb_extents,
        const vostok::math::float3 *aabb_center,
        vostok::collision::loose_oct_tree *this)
{
  float v3; // xmm3_4
  float m_aabb_extents; // xmm1_4
  float v5; // xmm2_4

  v3 = aabb_extents->z + fabs(aabb_center->z - this->m_aabb_center.z);
  m_aabb_extents = this->m_aabb_extents;
  v5 = aabb_extents->y + fabs(aabb_center->y - this->m_aabb_center.y);
  return m_aabb_extents < (float)(aabb_extents->x + fabs(aabb_center->x - this->m_aabb_center.x))
      || m_aabb_extents < v5
      || m_aabb_extents < v3;
}
