void __thiscall vostok::network::send_order::~send_order(vostok::network::send_order *this)
{
  vostok::memory::base_allocator *v1; // eax
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+13h] [ebp-5h] BYREF
  const vostok::network_core::tcp_packet *temp; // [esp+14h] [ebp-4h] BYREF

  this->__vftable = (vostok::network::send_order_vtbl *)&vostok::network::send_order::`vftable';
  temp = this->m_packet;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  call_destructor_predicate = 0;
  vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,vostok::network_core::tcp_packet,vostok::memory::detail::call_destructor_predicate>(
    v1,
    &temp,
    &call_destructor_predicate);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->m_sender);
  this->__vftable = (vostok::network::send_order_vtbl *)&vostok::network::order::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->next_for_orders);
}
