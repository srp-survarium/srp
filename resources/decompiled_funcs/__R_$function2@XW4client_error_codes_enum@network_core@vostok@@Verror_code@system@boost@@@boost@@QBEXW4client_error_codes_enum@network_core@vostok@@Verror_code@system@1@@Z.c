void __thiscall boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::operator()(
        boost::function3<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum> *this,
        const char *a0,
        survarium::hit_affects_type_enum a1,
        survarium::affect_event_type_enum a2)
{
  const std::exception *v4; // eax
  boost::detail::function::basic_vtable4<void,unsigned int,float,float,char const *> *vtable; // eax
  boost::bad_function_call v7; // [esp+20h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v7);
    boost::throw_exception(v4);
    boost::bad_function_call::~bad_function_call(&v7);
  }
  vtable = boost::function5<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum,vostok::sign_up_info const &>::get_vtable(
             (boost::function4<void,unsigned int,float,float,char const *> *)&this->functor,
             this);
  ((void (__cdecl *)(boost::detail::function::function_buffer *, const char *, survarium::hit_affects_type_enum, survarium::affect_event_type_enum))vtable->invoker)(
    &this->functor,
    a0,
    a1,
    a2);
}
