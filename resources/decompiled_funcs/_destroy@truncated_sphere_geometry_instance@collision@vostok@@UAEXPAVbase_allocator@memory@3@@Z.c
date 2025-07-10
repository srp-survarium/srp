void __thiscall vostok::collision::truncated_sphere_geometry_instance::destroy(
        vostok::collision::truncated_sphere_geometry_instance *this,
        vostok::memory::base_allocator *allocator)
{
  vostok::math::float4 *m_begin; // eax

  m_begin = this->m_planes.m_begin;
  if ( m_begin != this->m_planes.m_end )
  {
    if ( m_begin )
      allocator->call_free(allocator, m_begin);
  }
}
