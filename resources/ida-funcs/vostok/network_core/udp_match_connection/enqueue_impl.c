void __usercall vostok::network_core::udp_match_connection::enqueue_impl(
        vostok::network_core::udp_match_connection *this@<ecx>,
        int a2@<esi>)
{
  char v2; // al
  _WORD *v3; // eax

  v2 = HIBYTE(this->m_random_generator.x[26]);
  if ( v2 < 0 )
  {
    v3 = (_WORD *)(44 * (v2 & 0x3F) + a2 + 2718);
    LOWORD(this->m_random_generator.x[25]) = *v3;
    *(_WORD *)(this->m_random_generator.x[332] + 13) = (*v3)++;
  }
  if ( (this->m_random_generator.x[26] & 0x40000000) != 0 )
    ++*(_DWORD *)(a2 + 2624);
  vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)this,
    (_DWORD *)(a2 + 2628));
}
