void __cdecl vostok::network_core::delete_udp_match_packet(
        vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *allocator,
        vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **packet)
{
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node *v2; // [esp+8h] [ebp-Ch]

  vostok::network_core::udp_match_packet::helper::call_destructor();
  v2 = *packet;
  v2->next = allocator->m_free_list_head.pointer;
  allocator->m_free_list_head.pointer = v2;
  --allocator->m_allocated_count;
  *packet = 0;
}
