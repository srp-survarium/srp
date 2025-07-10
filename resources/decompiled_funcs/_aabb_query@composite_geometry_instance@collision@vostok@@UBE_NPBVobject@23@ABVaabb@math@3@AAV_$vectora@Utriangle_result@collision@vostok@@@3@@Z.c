char __thiscall vostok::collision::composite_geometry_instance::aabb_query(
        vostok::collision::composite_geometry_instance *this,
        const vostok::collision::object *object,
        const vostok::math::aabb *aabb,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  const vostok::collision::composite_geometry *m_geometry; // eax
  vostok::collision::geometry_instance **m_begin; // esi
  vostok::collision::geometry_instance **m_end; // edi
  char v7; // bl
  vostok::math::cuboid local_cuboid; // [esp+10h] [ebp-78h] BYREF

  m_geometry = this->m_geometry;
  m_begin = m_geometry->m_geometry_instances.m_begin;
  m_end = m_geometry->m_geometry_instances.m_end;
  v7 = 0;
  vostok::math::cuboid::cuboid(&local_cuboid, aabb, &this->m_inverted_matrix);
  for ( ; m_begin != m_end; ++m_begin )
  {
    if ( (*m_begin)->cuboid_query(*m_begin, object, &local_cuboid, triangles) || v7 )
      v7 = 1;
  }
  return v7;
}
