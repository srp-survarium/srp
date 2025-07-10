void __thiscall vostok::network::string_response::string_response(
        vostok::network::string_response *this,
        vostok::memory::base_allocator *allocator,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *functor,
        char *string0)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v4; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx
  vostok::network::string_response *thisb; // [esp+0h] [ebp-18h]

  this->__vftable = (vostok::network::string_response_vtbl *)&vostok::network::response::`vftable';
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_functor0);
  this->__vftable = (vostok::network::string_response_vtbl *)&vostok::network::string_response::`vftable';
  boost::function<void __cdecl (unsigned int,float,float,char const *)>::function<void __cdecl (unsigned int,float,float,char const *)>(
    functor,
    (const boost::function<void __cdecl(unsigned int,float,float,char const *)> *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v4);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v5);
  thisb->m_string0 = vostok::strings::duplicate<vostok::memory::base_allocator>(string0);
  thisb->m_string1 = 0;
  thisb->m_string2 = 0;
  thisb->m_allocator = allocator;
}
