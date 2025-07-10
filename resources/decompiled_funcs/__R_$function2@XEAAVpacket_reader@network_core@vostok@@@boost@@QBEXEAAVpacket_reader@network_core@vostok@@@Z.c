void __thiscall boost::function2<void,unsigned char,vostok::network_core::packet_reader &>::operator()(
        boost::function2<void,unsigned char,vostok::network_core::packet_reader &> *this,
        unsigned __int8 a0,
        boost::function4<void,unsigned int,float,float,char const *> *a1)
{
  const std::exception *v3; // eax
  boost::detail::function::basic_vtable4<void,unsigned int,float,float,char const *> *vtable; // eax
  boost::bad_function_call v6; // [esp+20h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v6);
    boost::throw_exception(v3);
    boost::bad_function_call::~bad_function_call(&v6);
  }
  vtable = boost::function5<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum,vostok::sign_up_info const &>::get_vtable(
             a1,
             this);
  ((void (__cdecl *)(boost::detail::function::function_buffer *, _DWORD, boost::function4<void,unsigned int,float,float,char const *> *))vtable->invoker)(
    &this->functor,
    a0,
    a1);
}
