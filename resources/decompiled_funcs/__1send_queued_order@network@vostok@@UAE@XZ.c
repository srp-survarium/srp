void __thiscall vostok::network::send_queued_order::~send_queued_order(vostok::network::send_queued_order *this)
{
  this->__vftable = (vostok::network::send_queued_order_vtbl *)&vostok::network::send_queued_order::`vftable';
  if ( vostok::network_core::operator>=(&this->m_copied_stats, this->m_target_stats) )
    qmemcpy(this->m_target_stats, &this->m_copied_stats, sizeof(vostok::network_core::udp_match_stats));
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_functor);
  this->__vftable = (vostok::network::send_queued_order_vtbl *)&vostok::network::order::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->next_for_orders);
}
