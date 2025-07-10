vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> **__usercall vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *this@<ecx>,
        vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> **a2@<esi>)
{
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *v2; // eax
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *v3; // ecx
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *v4; // eax

  v2 = 0;
  if ( this )
  {
    v2 = this;
    _InterlockedExchangeAdd((volatile signed __int32 *)&this[4], 1u);
  }
  v3 = v2;
  v4 = *a2;
  *a2 = v3;
  if ( v4 && !_InterlockedExchangeAdd((volatile signed __int32 *)&v4[4], 0xFFFFFFFF) )
    (*(void (__thiscall **)(vostok::network_core::udp_match_packets_allocator *, vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *))&v4[3].m_object->m_free_list_head.pointer->data[24])(
      v4[3].m_object,
      v4);
  return a2;
}
