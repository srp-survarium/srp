void (__thiscall *__thiscall boost::function0<void>::operator void (__thiscall boost::function0<void>::dummy::*)(void)(
        boost::function0<void> *this))(boost::function0<void>::dummy *this)
{
  return !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this)
       ? (void (__thiscall *)(boost::function0<void>::dummy *))boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
       : 0;
}


vostok::network_core::udp_match_packet *__thiscall boost::function0<vostok::network_core::udp_match_packet &>::operator()(
        boost::function0<vostok::network_core::udp_match_packet &> *this)
{
  const std::exception *v1; // eax
  boost::bad_function_call v4; // [esp+24h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v4);
    boost::throw_exception(v1);
    boost::bad_function_call::~bad_function_call(&v4);
  }
  return (vostok::network_core::udp_match_packet *)(*(int (__cdecl **)(boost::detail::function::function_buffer *))(((int)this->vtable & 0xFFFFFFFE) + 4))(&this->functor);
}


void __thiscall boost::function0<void>::operator()(boost::function0<void> *this)
{
  const std::exception *v2; // eax
  boost::bad_function_call v3; // [esp+8h] [ebp-110h] BYREF

  if ( !this->vtable )
  {
    boost::bad_function_call::bad_function_call(&v3);
    boost::throw_exception(v2);
    stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v3);
  }
  (*(void (__cdecl **)(boost::detail::function::function_buffer *))(((int)this->vtable & 0xFFFFFFFE) + 4))(&this->functor);
}


int __thiscall boost::function0<bool>::operator()(boost::function0<bool> *this)
{
  const std::exception *v1; // eax
  boost::detail::function::basic_vtable4<void,unsigned int,float,float,char const *> *vtable; // eax
  boost::bad_function_call v5; // [esp+20h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v5);
    boost::throw_exception(v1);
    boost::bad_function_call::~bad_function_call(&v5);
  }
  vtable = boost::function5<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum,vostok::sign_up_info const &>::get_vtable(
             (boost::function4<void,unsigned int,float,float,char const *> *)&this->functor,
             this);
  return ((int (__cdecl *)(boost::detail::function::function_buffer *))vtable->invoker)(&this->functor);
}
