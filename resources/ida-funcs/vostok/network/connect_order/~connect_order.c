void __thiscall vostok::network::connect_order::~connect_order(vostok::network::connect_order *this)
{
  char *m_host; // eax
  vostok::memory::base_allocator *m_strings_allocator; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *v5; // [esp-4h] [ebp-10h]
  const vostok::network_core::udp_match_packet *m_packet; // [esp+8h] [ebp-4h] BYREF

  m_host = this->m_host;
  m_strings_allocator = this->m_strings_allocator;
  this->__vftable = (vostok::network::connect_order_vtbl *)&vostok::network::connect_order::`vftable';
  if ( m_host )
    m_strings_allocator->call_free(
      m_strings_allocator,
      m_host,
      "vostok::network::connect_order::~connect_order",
      "c:\\survarium.deploy\\sources\\vostok\\network\\sources\\connect_order.h",
      44u);
  m_packet = this->m_packet;
  vostok::network_core::delete_udp_match_packet(
    this->m_packets_allocator.m_object,
    (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)&m_packet);
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::dec(
    v5,
    (int **)&this->m_packets_allocator);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&this->m_connector);
  this->__vftable = (vostok::network::connect_order_vtbl *)&vostok::network::order::`vftable';
}
