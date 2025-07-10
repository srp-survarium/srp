void __thiscall boost::function4<void,unsigned int,float,float,char const *>::operator()(
        boost::function4<void,unsigned int,float,float,char const *> *this,
        unsigned int a0,
        float a1,
        float a2,
        boost::function4<void,unsigned int,float,float,char const *> *a3)
{
  const std::exception *v5; // eax
  boost::detail::function::basic_vtable4<void,unsigned int,float,float,char const *> *vtable; // eax
  boost::bad_function_call v8; // [esp+2Ch] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v8);
    boost::throw_exception(v5);
    boost::bad_function_call::~bad_function_call(&v8);
  }
  vtable = boost::function5<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum,vostok::sign_up_info const &>::get_vtable(
             a3,
             this);
  ((void (__cdecl *)(boost::detail::function::function_buffer *, unsigned int, _DWORD, _DWORD, boost::function4<void,unsigned int,float,float,char const *> *))vtable->invoker)(
    &this->functor,
    a0,
    LODWORD(a1),
    LODWORD(a2),
    a3);
}
