void __thiscall vostok::network::receive_udp_response::~receive_udp_response(
        vostok::network::receive_udp_response *this)
{
  const vostok::variant<32> **v1; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  vostok::network_core::udp_match_packet *temp; // [esp+28h] [ebp-4h] BYREF

  this->__vftable = (vostok::network::receive_udp_response_vtbl *)&vostok::network::receive_udp_response::`vftable';
  temp = this->m_packet;
  v1 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)&this->m_allocator);
  vostok::network_core::delete_udp_match_packet(
    (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *)v1,
    (vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node **)&temp);
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::~intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(&this->m_allocator);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (int *)&this->m_receiver);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_copied_stats);
  this->__vftable = (vostok::network::receive_udp_response_vtbl *)&vostok::network::response::`vftable';
}
