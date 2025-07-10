void __thiscall vostok::collision::composite_geometry::destroy(
        vostok::collision::composite_geometry *this,
        vostok::memory::base_allocator *allocator)
{
  vostok::collision::geometry_instance **m_begin; // esi
  vostok::collision::geometry_instance **i; // edi
  vostok::collision::geometry_instance **v5; // ebp

  m_begin = this->m_geometry_instances.m_begin;
  for ( i = this->m_geometry_instances.m_end; m_begin != i; ++m_begin )
    (*m_begin)->destroy(*m_begin, allocator);
  v5 = this->m_geometry_instances.m_begin;
  if ( v5 )
    allocator->call_free(allocator, v5);
}
