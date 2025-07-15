void __thiscall vostok::network_core::udp_match_packets_allocator::udp_match_packets_allocator(
        vostok::network_core::udp_match_packets_allocator *this,
        vostok::memory::base_allocator *allocator,
        void *arena,
        unsigned int arena_size)
{
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>(
    this,
    arena,
    arena_size);
  this->m_allocator = allocator;
  this->m_reference_count = 0;
}
