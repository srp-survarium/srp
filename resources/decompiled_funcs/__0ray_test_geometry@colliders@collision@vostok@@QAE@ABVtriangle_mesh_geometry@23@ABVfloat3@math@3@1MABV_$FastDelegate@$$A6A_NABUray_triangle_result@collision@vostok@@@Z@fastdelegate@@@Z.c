void __userpurge vostok::collision::colliders::ray_test_geometry::ray_test_geometry(
        const vostok::collision::triangle_mesh_geometry *geometry@<edi>,
        const vostok::math::float3 *origin@<ecx>,
        const vostok::math::float3 *direction@<eax>,
        vostok::collision::colliders::ray_test_geometry *this,
        float max_distance,
        const fastdelegate::FastDelegate<bool __cdecl(vostok::collision::ray_triangle_result const &)> *predicate)
{
  vostok::collision::colliders::ray_test_geometry *v6; // esi
  const fastdelegate::FastDelegate<bool __cdecl(vostok::collision::ray_triangle_result const &)> *v7; // eax
  bool v8; // zf

  v6 = this;
  vostok::collision::colliders::ray_aabb_collider::ray_aabb_collider(&this->m_ray_aabb_collider, origin, direction);
  v7 = predicate;
  v6->m_max_distance = max_distance;
  this = (vostok::collision::colliders::ray_test_geometry *)(LODWORD(v6->m_ray_aabb_collider.m_direction.y) & 0x7FFFFFFF);
  v8 = *(float *)&this == *(float *)&clear_value;
  v6->m_predicate = v7;
  v6->m_geometry = geometry;
  v6->m_result = 0;
  LOBYTE(this) = 0;
  if ( v8 )
    vostok::collision::colliders::ray_test_geometry::query<vostok::collision::colliders::geometry::vertical_predicate<1>>(
      v6,
      geometry->m_root,
      (const vostok::collision::colliders::geometry::vertical_predicate<1> *)&this);
  else
    vostok::collision::colliders::ray_test_geometry::query<vostok::collision::colliders::geometry::vertical_predicate<0>>(
      v6,
      geometry->m_root,
      (const vostok::collision::colliders::geometry::vertical_predicate<0> *)&this);
}
