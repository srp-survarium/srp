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
