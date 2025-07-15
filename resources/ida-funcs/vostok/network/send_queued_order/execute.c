void __thiscall vostok::network::send_queued_order::execute(vostok::network::send_queued_order *this)
{
  survarium::game_camera *m_client; // ecx
  const vostok::network_core::udp_match_stats *source_stats; // [esp+13Ch] [ebp-4h]

  boost::function0<void>::operator()(&this->m_functor);
  m_client = (survarium::game_camera *)this->m_client;
  source_stats = (const vostok::network_core::udp_match_stats *)((char *)&loc_258034
                                                               + (unsigned int)m_client->__vftable
                                                               + 4);
  survarium::weapon_user_dead_state::finalize(m_client);
  qmemcpy(&this->m_copied_stats, source_stats, sizeof(this->m_copied_stats));
}
