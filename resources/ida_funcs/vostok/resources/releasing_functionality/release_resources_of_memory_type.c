void __userpurge vostok::resources::releasing_functionality::release_resources_of_memory_type<vostok::resources::release_unconditionaly>(
        vostok::resources::memory_type *info@<eax>,
        vostok::resources::releasing_functionality *this,
        vostok::resources::release_unconditionaly predicate)
{
  vostok::resources::resource_base *m_first; // edi
  vostok::resources::resource_base *m_next_in_memory_type; // esi

  m_first = info->resources.m_first;
  if ( m_first )
  {
    do
    {
      m_next_in_memory_type = m_first->m_next_in_memory_type;
      if ( m_first->m_quality_levels_count == 1 || !m_first->is_increasing_quality(m_first) )
        vostok::resources::releasing_functionality::release_resource(this, m_first);
      m_first = m_next_in_memory_type;
    }
    while ( m_next_in_memory_type );
  }
}
