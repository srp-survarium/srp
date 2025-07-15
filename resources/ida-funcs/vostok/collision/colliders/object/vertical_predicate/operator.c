bool __userpurge vostok::collision::colliders::object::vertical_predicate<0>::operator()@<al>(
        const vostok::math::float3 *node_center@<ecx>,
        vostok::collision::colliders::ray_aabb_collider *this,
        const vostok::collision::colliders::ray_object *query,
        const vostok::math::float3 *radius,
        float *distance)
{
  vostok::collision::colliders::sse::aabb_a16 v6; // [esp+0h] [ebp-20h] BYREF

  vostok::collision::colliders::sse::construct_aabb_a16(node_center, &query->m_ray_aabb_collider.m_origin, &v6);
  return vostok::collision::colliders::ray_aabb_collider::intersects_aabb_sse(&v6, this, &radius->x);
}
