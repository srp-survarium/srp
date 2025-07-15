void (__thiscall *__usercall boost::function1<void,char const *>::operator void (__thiscall boost::function1<void,char const *>::dummy::*)(void)@<eax>(
        boost::function1<void,char const *> *this@<ecx>,
        _DWORD *a2@<eax>))(boost::function1<void,char const *>::dummy *this)
{
  return *a2 != 0
       ? (void (__thiscall *)(boost::function1<void,char const *>::dummy *))survarium::weapon_user_dead_state::finalize
       : 0;
}


vostok::math::float4x4 *__userpurge boost::function1<vostok::math::float4x4,void const *>::operator()@<eax>(
        boost::function1<vostok::math::float4x4,void const *> *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::math::float4x4 *result,
        const void *a0)
{
  const std::exception *v5; // eax
  _BYTE v7[64]; // [esp+10h] [ebp-154h] BYREF
  boost::bad_function_call v8; // [esp+50h] [ebp-114h] BYREF

  if ( !*a2 )
  {
    boost::bad_function_call::bad_function_call(&v8);
    boost::throw_exception(v5);
    stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v8);
  }
  qmemcpy(
    (void *)result,
    (const void *)(*(int (__cdecl **)(_BYTE *, _DWORD *, const void *))((*a2 & 0xFFFFFFFE) + 4))(v7, a2 + 2, a0),
    sizeof(vostok::math::float4x4));
  return result;
}


void __userpurge boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
        boost::function1<void,char const *> *this@<ecx>,
        _DWORD *a2@<eax>,
        const char *a0)
{
  const std::exception *v4; // eax
  boost::bad_function_call v5; // [esp+8h] [ebp-110h] BYREF

  if ( !*a2 )
  {
    boost::bad_function_call::bad_function_call(&v5);
    boost::throw_exception(v4);
    stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v5);
  }
  (*(void (__cdecl **)(_DWORD *, const char *))((*a2 & 0xFFFFFFFE) + 4))(a2 + 2, a0);
}


void __thiscall boost::function1<void,vostok::sound::create_sound_propagator_params const &>::operator()(
        boost::function1<void,vostok::sound::create_sound_propagator_params const &> *this,
        const vostok::sound::create_sound_propagator_params *a0)
{
  const std::exception *v2; // eax
  boost::bad_function_call v4; // [esp+28h] [ebp-110h] BYREF

  if ( !this->vtable )
  {
    boost::bad_function_call::bad_function_call(&v4);
    boost::throw_exception(v2);
    stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v4);
  }
  (*(void (__cdecl **)(boost::detail::function::function_buffer *, const vostok::sound::create_sound_propagator_params *))(((int)this->vtable & 0xFFFFFFFE) + 4))(
    &this->functor,
    a0);
}


void __thiscall boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
        boost::function1<void,vostok::ai::sensors::sensed_object const &> *this,
        const vostok::ai::sensors::sensed_object *a0)
{
  const std::exception *v2; // eax
  boost::bad_function_call v4; // [esp+20h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v4);
    boost::throw_exception(v2);
    boost::bad_function_call::~bad_function_call(&v4);
  }
  (*(void (__cdecl **)(boost::detail::function::function_buffer *, const vostok::ai::sensors::sensed_object *))(((int)this->vtable & 0xFFFFFFFE) + 4))(
    &this->functor,
    a0);
}


void __userpurge boost::function1<void,vostok::collision::object const &>::operator()(
        boost::function1<void,vostok::collision::object const &> *this@<ecx>,
        _DWORD *a2@<eax>,
        const vostok::collision::object *a0)
{
  const std::exception *v4; // eax
  boost::bad_function_call v5; // [esp+8h] [ebp-110h] BYREF

  if ( !*a2 )
  {
    boost::bad_function_call::bad_function_call(&v5);
    boost::throw_exception(v4);
    stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v5);
  }
  (*(void (__cdecl **)(_DWORD *, const vostok::collision::object *))((*a2 & 0xFFFFFFFE) + 4))(a2 + 2, a0);
}


void __thiscall boost::function1<void,vostok::vfs::mount_result>::operator()(
        boost::function1<void,vostok::vfs::mount_result> *this,
        vostok::vfs::mount_result a0)
{
  const std::exception *v2; // eax
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v3[4]; // [esp-8h] [ebp-150h] BYREF
  const boost::function1<void,vostok::vfs::mount_result> *thisa; // [esp+8h] [ebp-140h]
  unsigned int v5; // [esp+10h] [ebp-138h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v6; // [esp+14h] [ebp-134h]
  boost::bad_function_call v7; // [esp+38h] [ebp-110h] BYREF

  thisa = this;
  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v7);
    boost::throw_exception(v2);
    boost::bad_function_call::~bad_function_call(&v7);
  }
  v6 = v3;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    v3,
    &a0.mount);
  v6[1].m_object = (vostok::vfs::vfs_mount *)a0.result;
  v5 = (int)thisa->vtable & 0xFFFFFFFE;
  (*(void (__cdecl **)(boost::detail::function::function_buffer *))(v5 + 4))(&thisa->functor);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&a0.mount);
}


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


void __thiscall boost::function1<void,bool>::operator()(boost::function1<void,bool> *this, bool a0)
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
  vtable = boost::function5<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum,vostok::sign_up_info const &>::get_vtable((boost::function4<void,unsigned int,float,float,char const *> *)a0);
  ((void (__cdecl *)(boost::detail::function::function_buffer *, bool))vtable->invoker)(&this->functor, a0);
}


int __thiscall boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
        boost::function1<unsigned int,char const *> *this,
        const char *a0)
{
  const std::exception *v2; // eax
  boost::bad_function_call v5; // [esp+24h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v5);
    boost::throw_exception(v2);
    boost::bad_function_call::~bad_function_call(&v5);
  }
  return (*(int (__cdecl **)(boost::detail::function::function_buffer *, const char *))(((int)this->vtable & 0xFFFFFFFE)
                                                                                      + 4))(
           &this->functor,
           a0);
}
