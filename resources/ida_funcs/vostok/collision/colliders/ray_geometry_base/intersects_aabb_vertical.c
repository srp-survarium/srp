char __userpurge vostok::collision::colliders::ray_geometry_base::intersects_aabb_vertical@<al>(
        const Opcode::AABBNoLeafNode *node@<eax>,
        float *distance@<esi>,
        vostok::collision::colliders::ray_geometry_base *this)
{
  vostok::math::float3 extents; // [esp+0h] [ebp-18h] BYREF
  vostok::math::float3 center; // [esp+Ch] [ebp-Ch] BYREF

  center = (vostok::math::float3)node->mAABB.mCenter;
  extents = (vostok::math::float3)node->mAABB.mExtents;
  return vostok::collision::colliders::ray_aabb_collider::intersects_aabb_vertical(
           &center,
           &extents,
           distance,
           &this->m_ray_aabb_collider);
}
