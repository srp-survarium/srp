char __thiscall vostok::collision::composite_geometry::aabb_query(
        vostok::collision::composite_geometry *this,
        const vostok::collision::object *object,
        const vostok::math::aabb *aabb,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  vostok::collision::geometry_instance **m_begin; // esi
  vostok::collision::geometry_instance **m_end; // edi
  char i; // bl

  m_begin = this->m_geometry_instances.m_begin;
  m_end = this->m_geometry_instances.m_end;
  for ( i = 0; m_begin != m_end; ++m_begin )
  {
    if ( (*m_begin)->aabb_query(*m_begin, object, aabb, triangles) || i )
      i = 1;
  }
  return i;
}
