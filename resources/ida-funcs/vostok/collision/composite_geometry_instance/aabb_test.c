char __thiscall vostok::collision::composite_geometry_instance::aabb_test(
        vostok::collision::composite_geometry_instance *this,
        const vostok::math::aabb *aabb)
{
  const vostok::collision::composite_geometry *m_geometry; // eax
  vostok::collision::geometry_instance **m_begin; // esi
  vostok::collision::geometry_instance **m_end; // edi

  m_geometry = this->m_geometry;
  m_begin = m_geometry->m_geometry_instances.m_begin;
  m_end = m_geometry->m_geometry_instances.m_end;
  if ( m_begin == m_end )
    return 0;
  while ( !(*m_begin)->aabb_test(*m_begin, aabb) )
  {
    if ( ++m_begin == m_end )
      return 0;
  }
  return 1;
}
