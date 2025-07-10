void __thiscall vostok::network::connect_order::~connect_order(vostok::network::connect_order *this)
{
  vostok::memory::base_allocator *v1; // eax
  const vostok::variant<32> **v2; // eax
  vostok::network_core::udp_match_packet *packet; // [esp+30h] [ebp-8h] BYREF
  char *temp; // [esp+34h] [ebp-4h] BYREF

  this->__vftable = (vostok::network::connect_order_vtbl *)&vostok::network::connect_order::`vftable';
  temp = this->m_host;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::free_helper<vostok::memory::base_allocator,char>(v1, &temp);
  packet = (vostok::network_core::udp_match_packet *)this->m_packet;
  v2 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)&this->m_packets_allocator);
  vostok::network_core::delete_udp_match_packet(
    (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *)v2,
    (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **)&packet);
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::~intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>((vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *)&this->m_packets_allocator);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->m_connector);
  this->__vftable = (vostok::network::connect_order_vtbl *)&vostok::network::order::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->next_for_orders);
}
