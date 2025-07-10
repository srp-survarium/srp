void __thiscall vostok::network::string_order::string_order(
        vostok::network::string_order *this,
        vostok::memory::base_allocator *allocator,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *functor,
        char *string0)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v4; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->next_for_orders);
  this->__vftable = (vostok::network::string_order_vtbl *)&vostok::network::order::`vftable';
  this->__vftable = (vostok::network::string_order_vtbl *)&vostok::network::string_order::`vftable';
  boost::function<void __cdecl (unsigned int,float,float,char const *)>::function<void __cdecl (unsigned int,float,float,char const *)>(functor);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v4, &this->m_functor1.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v5, &this->m_functor2.vtable);
  this->m_string0 = vostok::strings::duplicate<vostok::memory::base_allocator>(string0);
  this->m_string1 = 0;
  this->m_string2 = 0;
  this->m_allocator = allocator;
}
