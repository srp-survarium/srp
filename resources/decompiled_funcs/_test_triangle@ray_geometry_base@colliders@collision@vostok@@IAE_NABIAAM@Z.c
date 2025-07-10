bool __userpurge vostok::collision::colliders::ray_geometry_base::test_triangle@<al>(
        vostok::collision::colliders::ray_geometry_base *this@<esi>,
        unsigned int *triangle@<edx>,
        float *range)
{
  const unsigned int *v3; // edi
  const vostok::math::float3 *v4; // eax

  v3 = this->m_geometry->indices(this->m_geometry, *triangle);
  v4 = this->m_geometry->vertices(this->m_geometry);
  return vostok::collision::test_triangle(
           &v4[*v3],
           &v4[v3[1]],
           &v4[v3[2]],
           &this->m_ray_aabb_collider.m_origin,
           &this->m_ray_aabb_collider.m_direction,
           this->m_max_distance,
           range);
}
