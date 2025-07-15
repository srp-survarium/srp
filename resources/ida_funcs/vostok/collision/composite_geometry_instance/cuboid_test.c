char __thiscall vostok::collision::composite_geometry_instance::cuboid_test(
        vostok::collision::composite_geometry_instance *this,
        const vostok::math::cuboid *cuboid)
{
  const vostok::collision::composite_geometry *m_geometry; // eax
  vostok::collision::geometry_instance **m_end; // ebx
  vostok::collision::geometry_instance **m_begin; // edi
  vostok::math::cuboid local_cuboid; // [esp+10h] [ebp-78h] BYREF

  m_geometry = this->m_geometry;
  m_end = m_geometry->m_geometry_instances.m_end;
  m_begin = m_geometry->m_geometry_instances.m_begin;
  vostok::math::cuboid::cuboid(&local_cuboid, cuboid, &this->m_inverted_matrix);
  if ( m_begin == m_end )
    return 0;
  while ( !(*m_begin)->cuboid_test(*m_begin, &local_cuboid) )
  {
    if ( ++m_begin == m_end )
      return 0;
  }
  return 1;
}
