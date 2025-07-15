void __thiscall vostok::network::send_queued_order::~send_queued_order(vostok::network::send_queued_order *this)
{
  vostok::network_core::udp_match_stats *m_target_stats; // ebp
  vostok::network_core::udp_match_stats *p_m_copied_stats; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx

  m_target_stats = this->m_target_stats;
  p_m_copied_stats = &this->m_copied_stats;
  this->__vftable = (vostok::network::send_queued_order_vtbl *)&vostok::network::send_queued_order::`vftable';
  if ( vostok::network_core::operator>=(&this->m_copied_stats, m_target_stats) )
  {
    qmemcpy(m_target_stats, p_m_copied_stats, sizeof(vostok::network_core::udp_match_stats));
    v4 = 0;
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&this->m_functor);
  this->__vftable = (vostok::network::send_queued_order_vtbl *)&vostok::network::order::`vftable';
}
