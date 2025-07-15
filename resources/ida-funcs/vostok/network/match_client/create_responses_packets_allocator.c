void __thiscall vostok::network::match_client::create_responses_packets_allocator(vostok::network::match_client *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  vostok::memory::doug_lea_allocator *v3; // [esp+34h] [ebp-18h]
  int *_Where; // [esp+38h] [ebp-14h]
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *v5; // [esp+44h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)vostok::network::g_allocator);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v1, (unsigned int)&loc_25800F + 5);
  v5 = (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *)operator new((unsigned int)&loc_25800F + 5, _Where);
  if ( v5 )
  {
    v3 = vostok::network::g_allocator;
    vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>(
      v5,
      (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node *)&v5[1].m_max_count,
      (unsigned int)&loc_257FFD + 3);
    v5[1].m_free_list_head.pointer = (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node *)v3;
    v5[1].m_allocated_count = 0;
    vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *)v5,
      (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> **)&this->m_response_packets_allocator);
  }
  else
  {
    vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::operator=(
      0,
      (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> **)&this->m_response_packets_allocator);
  }
}
