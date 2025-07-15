void __thiscall vostok::network::string_order::~string_order(vostok::network::string_order *this)
{
  vostok::memory::base_allocator *v1; // eax
  vostok::memory::base_allocator *v2; // eax
  vostok::memory::base_allocator *v3; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx
  char *temp; // [esp+18h] [ebp-4h] BYREF

  this->__vftable = (vostok::network::string_order_vtbl *)&vostok::network::string_order::`vftable';
  temp = this->m_string0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::free_helper<vostok::memory::base_allocator,char>(v1, &temp);
  temp = this->m_string1;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::free_helper<vostok::memory::base_allocator,char>(v2, &temp);
  temp = this->m_string2;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::free_helper<vostok::memory::base_allocator,char>(v3, &temp);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->m_functor2);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->m_functor1);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(v4);
  this->__vftable = (vostok::network::string_order_vtbl *)&vostok::network::order::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->next_for_orders);
}
