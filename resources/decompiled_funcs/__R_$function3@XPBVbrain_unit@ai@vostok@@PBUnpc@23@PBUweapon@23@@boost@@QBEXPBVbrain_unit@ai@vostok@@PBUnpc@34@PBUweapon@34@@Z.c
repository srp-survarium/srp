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
