void __thiscall client_destroyer::execute(client_destroyer *this)
{
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network::match_client_impl>(
    vostok::network::g_allocator,
    this->m_client);
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::operator=(
    0,
    (vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> **)&this->m_responses_allocator);
}
