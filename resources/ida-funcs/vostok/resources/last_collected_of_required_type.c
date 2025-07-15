vostok::resources::resource_base *__fastcall vostok::resources::last_collected_of_required_type(
        int a1,
        vostok::resources::resources_to_free_collection *collection)
{
  vostok::resources::resource_base *result; // eax
  vostok::resources::resource_base *m_first; // ecx
  const vostok::resources::memory_type *type; // edx

  result = 0;
  if ( collection->query )
  {
    m_first = collection->resources.m_first;
    if ( m_first )
    {
      type = collection->required_memory.type;
      do
      {
        if ( m_first->m_memory_usage_self.vostok::resources::resource_quality::type == type )
          result = m_first;
        m_first = m_first->m_next_for_grm_observer_list;
      }
      while ( m_first );
    }
  }
  return result;
}
