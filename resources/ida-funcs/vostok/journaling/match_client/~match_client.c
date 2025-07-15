void __thiscall vostok::journaling::match_client::~match_client(vostok::journaling::match_client *this)
{
  int *p_m_fake_packet_allocator; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // [esp-4h] [ebp-10h]

  p_m_fake_packet_allocator = (int *)&this->m_fake_packet_allocator;
  this->__vftable = (vostok::journaling::match_client_vtbl *)&vostok::journaling::match_client::`vftable';
  vostok::network_core::delete_udp_match_packet(
    &this->m_fake_packet_allocator,
    (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)&this->m_fake_packet);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&this->m_on_packet_received);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    p_m_fake_packet_allocator);
  survarium::base_match_client::~base_match_client(this);
}
