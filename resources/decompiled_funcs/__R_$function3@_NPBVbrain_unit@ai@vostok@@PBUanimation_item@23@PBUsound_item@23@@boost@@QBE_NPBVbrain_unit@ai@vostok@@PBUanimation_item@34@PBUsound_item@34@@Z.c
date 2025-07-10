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
