vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *__usercall vostok::network_core::new_udp_match_packet@<eax>(
        vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *allocator@<eax>)
{
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *m_allocated_count; // ecx
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *impl; // eax
  vostok::network_core::udp_match_packet *v4; // ecx
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *v5; // esi

  m_allocated_count = (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *)allocator->m_allocated_count;
  if ( (unsigned int)m_allocated_count >= allocator->m_max_count )
    return 0;
  impl = vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::allocate_impl(
           m_allocated_count,
           (int)allocator);
  v5 = impl;
  if ( impl )
    vostok::network_core::udp_match_packet::udp_match_packet(v4, (int)impl);
  return v5;
}
