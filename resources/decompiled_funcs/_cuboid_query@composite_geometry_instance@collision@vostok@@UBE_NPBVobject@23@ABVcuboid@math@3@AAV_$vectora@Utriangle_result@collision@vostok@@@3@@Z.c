char __thiscall vostok::collision::composite_geometry_instance::cuboid_query(
        vostok::collision::composite_geometry_instance *this,
        const vostok::collision::object *object,
        const vostok::math::cuboid *cuboid,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  const vostok::collision::composite_geometry *m_geometry; // eax
  vostok::collision::geometry_instance **m_begin; // edi
  char v6; // bl
  vostok::collision::geometry_instance *const *e; // [esp+Ch] [ebp-7Ch]
  vostok::math::cuboid local_cuboid; // [esp+10h] [ebp-78h] BYREF

  m_geometry = this->m_geometry;
  m_begin = m_geometry->m_geometry_instances.m_begin;
  v6 = 0;
  e = m_geometry->m_geometry_instances.m_end;
  vostok::math::cuboid::cuboid(&local_cuboid, cuboid, &this->m_inverted_matrix);
  for ( ; m_begin != e; ++m_begin )
  {
    if ( (*m_begin)->cuboid_query(*m_begin, object, &local_cuboid, triangles) || v6 )
      v6 = 1;
  }
  return v6;
}
