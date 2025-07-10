void __thiscall vostok::network::enqueue_order::~enqueue_order(vostok::network::enqueue_order *this)
{
  const vostok::variant<32> **v1; // eax
  vostok::network_core::udp_match_packet *temp; // [esp+54h] [ebp-4h] BYREF

  this->__vftable = (vostok::network::enqueue_order_vtbl *)&vostok::network::enqueue_order::`vftable';
  temp = this->m_packet;
  v1 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)&this->m_allocator);
  vostok::network_core::delete_udp_match_packet(
    (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *)v1,
    (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **)&temp);
  if ( vostok::network_core::operator>=(&this->m_copied_stats, this->m_target_stats) )
    qmemcpy(this->m_target_stats, &this->m_copied_stats, sizeof(vostok::network_core::udp_match_stats));
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::~intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(&this->m_allocator);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->m_enqueuer);
  this->__vftable = (vostok::network::enqueue_order_vtbl *)&vostok::network::order::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->next_for_orders);
}
