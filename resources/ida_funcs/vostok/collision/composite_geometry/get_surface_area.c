double __thiscall vostok::collision::composite_geometry::get_surface_area(vostok::collision::composite_geometry *this)
{
  vostok::collision::geometry_instance **m_begin; // esi
  vostok::collision::geometry_instance **m_end; // edi
  double result; // st7
  float areas_sum; // [esp+0h] [ebp-4h]

  m_begin = this->m_geometry_instances.m_begin;
  m_end = this->m_geometry_instances.m_end;
  areas_sum = 0.0;
  if ( m_begin == m_end )
    return 0.0;
  do
  {
    result = ((double (__thiscall *)(vostok::collision::geometry_instance *))(*m_begin)->get_surface_area)(*m_begin)
           + areas_sum;
    ++m_begin;
    areas_sum = result;
  }
  while ( m_begin != m_end );
  return result;
}
