bool __userpurge vostok::collision::colliders::ray_geometry_base::test_triangle@<al>(
        vostok::collision::colliders::ray_geometry_base *this@<eax>,
        unsigned int *triangle@<edx>,
        float *range)
{
  const unsigned int *v4; // ebx
  const vostok::math::float3 *v5; // eax

  v4 = this->m_geometry->indices(this->m_geometry, *triangle);
  v5 = this->m_geometry->vertices(this->m_geometry);
  return vostok::collision::test_triangle(
           &v5[v4[1]],
           &v5[v4[2]],
           &this->m_ray_aabb_collider.m_origin,
           &this->m_ray_aabb_collider.m_direction,
           &v5[*v4],
           this->m_max_distance,
           range);
}
