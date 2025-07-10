void __thiscall boost::function1<void,enum vostok::network_core::disconnect_event_types_enum>::operator()(
        boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *this,
        boost::function4<void,unsigned int,float,float,char const *> *a0)
{
  const std::exception *v2; // eax
  boost::detail::function::basic_vtable4<void,unsigned int,float,float,char const *> *vtable; // eax
  boost::bad_function_call v5; // [esp+20h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v5);
    boost::throw_exception(v2);
    boost::bad_function_call::~bad_function_call(&v5);
  }
  vtable = boost::function5<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum,vostok::sign_up_info const &>::get_vtable(
             a0,
             this);
  ((void (__cdecl *)(boost::detail::function::function_buffer *, boost::function4<void,unsigned int,float,float,char const *> *))vtable->invoker)(
    &this->functor,
    a0);
}
