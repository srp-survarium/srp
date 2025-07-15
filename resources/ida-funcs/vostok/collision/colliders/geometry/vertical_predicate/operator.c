bool __userpurge vostok::collision::colliders::geometry::vertical_predicate<0>::operator()@<al>(
        const Opcode::AABBNoLeafNode *node@<eax>,
        vostok::collision::colliders::ray_aabb_collider *this,
        const vostok::collision::colliders::ray_geometry_base *query,
        float *distance)
{
  IceMaths::Point mExtents; // [esp+8h] [ebp-38h] BYREF
  IceMaths::Point mCenter; // [esp+14h] [ebp-2Ch] BYREF
  vostok::collision::colliders::sse::aabb_a16 v7; // [esp+20h] [ebp-20h] BYREF

  mCenter = node->mAABB.mCenter;
  mExtents = node->mAABB.mExtents;
  vostok::collision::colliders::sse::construct_aabb_a16(
    (const vostok::math::float3 *)&mCenter,
    (const vostok::math::float3 *)&mExtents,
    &v7);
  return vostok::collision::colliders::ray_aabb_collider::intersects_aabb_sse(
           &v7,
           this,
           &query->m_ray_aabb_collider.m_origin.x);
}
