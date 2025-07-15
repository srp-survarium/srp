char __thiscall vostok::collision::composite_geometry_instance::is_valid(
        vostok::collision::composite_geometry_instance *this)
{
  const vostok::collision::composite_geometry *m_geometry; // eax
  vostok::collision::geometry_instance **m_begin; // esi
  vostok::collision::geometry_instance **m_end; // edi

  m_geometry = this->m_geometry;
  m_begin = m_geometry->m_geometry_instances.m_begin;
  m_end = m_geometry->m_geometry_instances.m_end;
  if ( m_begin == m_end )
    return 1;
  while ( (*m_begin)->is_valid(*m_begin) )
  {
    if ( ++m_begin == m_end )
      return 1;
  }
  return 0;
}
