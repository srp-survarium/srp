void __thiscall vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::~intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(
        vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *this)
{
  vostok::network_core::udp_match_packets_allocator *m_object; // eax
  vostok::memory::base_allocator *m_allocator; // ecx

  if ( this->m_object && !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
  {
    m_object = this->m_object;
    m_allocator = this->m_object->m_allocator;
    if ( m_object )
      m_allocator->call_free(m_allocator, m_object);
  }
}
