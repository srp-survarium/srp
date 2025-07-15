void __thiscall vostok::network::receive_response::~receive_response(vostok::network::receive_response *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+Fh] [ebp-5h] BYREF
  const vostok::network_core::tcp_packet *temp; // [esp+10h] [ebp-4h] BYREF

  this->__vftable = (vostok::network::receive_response_vtbl *)&vostok::network::receive_response::`vftable';
  temp = this->m_packet;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  call_destructor_predicate = 0;
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::network_core::tcp_packet,vostok::memory::detail::call_destructor_predicate>(
    v1,
    &temp,
    &call_destructor_predicate);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (int *)&this->m_receiver);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_receiver);
  this->__vftable = (vostok::network::receive_response_vtbl *)&vostok::network::response::`vftable';
}
