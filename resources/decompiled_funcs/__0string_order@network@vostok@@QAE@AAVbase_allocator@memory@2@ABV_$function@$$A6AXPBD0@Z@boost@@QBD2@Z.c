void __thiscall vostok::network::string_order::string_order(
        vostok::network::string_order *this,
        vostok::memory::base_allocator *allocator,
        const boost::function1<void,enum vostok::handshaking_error_types_enum> *functor,
        char *string0,
        char *string1)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->next_for_orders);
  this->__vftable = (vostok::network::string_order_vtbl *)&vostok::network::order::`vftable';
  this->__vftable = (vostok::network::string_order_vtbl *)&vostok::network::string_order::`vftable';
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>((boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v5);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
    (boost::function1<void,enum vostok::handshaking_error_types_enum> *)&this->m_functor1,
    functor);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>((boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_functor2);
  this->m_string0 = vostok::strings::duplicate<vostok::memory::base_allocator>(string0);
  this->m_string1 = vostok::strings::duplicate<vostok::memory::base_allocator>(string1);
  this->m_string2 = 0;
  this->m_allocator = allocator;
}
