void __usercall vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(
        vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *this@<ecx>,
        vostok::network_core::udp_match_packets_allocator **a2@<eax>)
{
  vostok::network_core::udp_match_packets_allocator *m_object; // ecx

  *a2 = 0;
  m_object = this->m_object;
  if ( m_object )
  {
    *a2 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}
