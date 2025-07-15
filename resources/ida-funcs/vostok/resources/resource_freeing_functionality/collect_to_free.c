void __usercall vostok::resources::resource_freeing_functionality::collect_to_free(
        vostok::resources::resource_freeing_functionality *this@<edi>,
        vostok::resources::resource_base *resource@<esi>)
{
  vostok::resources::resources_to_free_collection *m_collection; // eax

  m_collection = this->m_collection;
  resource->m_next_for_grm_observer_list = 0;
  ++m_collection->resources.m_size;
  if ( m_collection->resources.m_first )
    m_collection->resources.m_last->m_next_for_grm_observer_list = resource;
  else
    m_collection->resources.m_first = resource;
  m_collection->resources.m_last = resource;
  vostok::threading::interlocked_or(&resource->m_flags.m_flags, 0x20u);
  if ( this->m_collection->collected_memory.type == resource->m_memory_usage_self.vostok::resources::resource_quality::type )
    this->m_collection->collected_memory.size += resource->m_memory_usage_self.size;
}
