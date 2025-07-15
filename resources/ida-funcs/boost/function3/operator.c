void __userpurge boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum>::operator()(
        boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *this@<ecx>,
        _DWORD *eax0@<eax>,
        vostok::resources::query_result *a0,
        const vostok::resources::memory_usage_type *a1,
        vostok::resources::class_id_enum a2)
{
  const std::exception *v6; // eax
  boost::bad_function_call v7; // [esp+8h] [ebp-110h] BYREF

  if ( !*eax0 )
  {
    boost::bad_function_call::bad_function_call(&v7);
    boost::throw_exception(v6);
    stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v7);
  }
  (*(void (__cdecl **)(_DWORD *, vostok::resources::query_result *, const vostok::resources::memory_usage_type *, vostok::resources::class_id_enum))((*eax0 & 0xFFFFFFFE) + 4))(
    eax0 + 2,
    a0,
    a1,
    a2);
}


void __thiscall boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::operator()(
        boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *> *this,
        const vostok::ai::brain_unit *a0,
        const vostok::ai::npc *a1,
        const vostok::ai::weapon *a2)
{
  const std::exception *v4; // eax
  boost::bad_function_call v6; // [esp+20h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v6);
    boost::throw_exception(v4);
    boost::bad_function_call::~bad_function_call(&v6);
  }
  (*(void (__cdecl **)(boost::detail::function::function_buffer *, const vostok::ai::brain_unit *, const vostok::ai::npc *, const vostok::ai::weapon *))(((int)this->vtable & 0xFFFFFFFE) + 4))(
    &this->functor,
    a0,
    a1,
    a2);
}


int __thiscall boost::function3<bool,vostok::ai::brain_unit const *,vostok::ai::animation_item const *,vostok::ai::sound_item const *>::operator()(
        boost::function3<bool,vostok::ai::brain_unit const *,vostok::ai::animation_item const *,vostok::ai::sound_item const *> *this,
        const vostok::ai::brain_unit *a0,
        const vostok::ai::animation_item *a1,
        const vostok::ai::sound_item *a2)
{
  const std::exception *v4; // eax
  boost::bad_function_call v7; // [esp+24h] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v7);
    boost::throw_exception(v4);
    boost::bad_function_call::~bad_function_call(&v7);
  }
  return (*(int (__cdecl **)(boost::detail::function::function_buffer *, const vostok::ai::brain_unit *, const vostok::ai::animation_item *, const vostok::ai::sound_item *))(((int)this->vtable & 0xFFFFFFFE) + 4))(
           &this->functor,
           a0,
           a1,
           a2);
}
