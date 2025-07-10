void __userpurge vostok::collision::colliders::ray_geometry_base::ray_geometry_base(
        const vostok::math::float3 *origin@<ecx>,
        const vostok::math::float3 *direction@<eax>,
        vostok::collision::colliders::ray_geometry_base *this,
        const vostok::collision::triangle_mesh_geometry *geometry,
        float max_distance,
        const fastdelegate::FastDelegate<bool __cdecl(vostok::collision::ray_triangle_result const &)> *predicate)
{
  vostok::collision::colliders::ray_aabb_collider::ray_aabb_collider(&this->m_ray_aabb_collider, origin, direction);
  this->m_geometry = geometry;
  this->m_predicate = predicate;
  this->m_max_distance = max_distance;
  this->m_result = 0;
}
