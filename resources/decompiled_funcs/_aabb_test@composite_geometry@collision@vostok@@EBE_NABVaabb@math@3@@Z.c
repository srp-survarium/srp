char __thiscall vostok::collision::composite_geometry::aabb_test(
        vostok::collision::composite_geometry *this,
        const vostok::math::aabb *aabb)
{
  vostok::collision::geometry_instance **m_begin; // esi
  vostok::collision::geometry_instance **m_end; // edi

  m_begin = this->m_geometry_instances.m_begin;
  m_end = this->m_geometry_instances.m_end;
  if ( m_begin == m_end )
    return 0;
  while ( !(*m_begin)->aabb_test(*m_begin, aabb) )
  {
    if ( ++m_begin == m_end )
      return 0;
  }
  return 1;
}
