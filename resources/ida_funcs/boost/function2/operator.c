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


void __thiscall boost::function2<void,unsigned int,unsigned int>::operator()(
        boost::function2<void,unsigned int,unsigned int> *this,
        unsigned int a0,
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
  ((void (__cdecl *)(boost::detail::function::function_buffer *, unsigned int, boost::function4<void,unsigned int,float,float,char const *> *))vtable->invoker)(
    &this->functor,
    a0,
    a1);
}


void __thiscall boost::function2<void,vostok::memory::writer *,vostok::memory::writer *>::operator()(
        boost::function2<void,vostok::memory::writer *,vostok::memory::writer *> *this,
        vostok::memory::writer *a0,
        vostok::memory::writer *a1)
{
  const std::exception *v3; // eax
  boost::bad_function_call v5; // [esp+28h] [ebp-110h] BYREF

  if ( !this->vtable )
  {
    boost::bad_function_call::bad_function_call(&v5);
    boost::throw_exception(v3);
    stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v5);
  }
  (*(void (__cdecl **)(boost::detail::function::function_buffer *, vostok::memory::writer *, vostok::memory::writer *))(((int)this->vtable & 0xFFFFFFFE) + 4))(
    &this->functor,
    a0,
    a1);
}


void __thiscall boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
        boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *this,
        const char *a0,
        const vostok::network_core::udp_match_packet *a1)
{
  const std::exception *v3; // eax
  boost::bad_function_call v5; // [esp+20h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v5);
    boost::throw_exception(v3);
    boost::bad_function_call::~bad_function_call(&v5);
  }
  (*(void (__cdecl **)(boost::detail::function::function_buffer *, const char *, const vostok::network_core::udp_match_packet *))(((int)this->vtable & 0xFFFFFFFE) + 4))(
    &this->functor,
    a0,
    a1);
}


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


int __thiscall boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
        boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *this,
        const char *a0,
        survarium::hit_affects_type_enum a1)
{
  const std::exception *v3; // eax
  boost::bad_function_call v6; // [esp+24h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v6);
    boost::throw_exception(v3);
    boost::bad_function_call::~bad_function_call(&v6);
  }
  return (*(int (__cdecl **)(boost::detail::function::function_buffer *, const char *, survarium::hit_affects_type_enum))(((int)this->vtable & 0xFFFFFFFE) + 4))(
           &this->functor,
           a0,
           a1);
}
