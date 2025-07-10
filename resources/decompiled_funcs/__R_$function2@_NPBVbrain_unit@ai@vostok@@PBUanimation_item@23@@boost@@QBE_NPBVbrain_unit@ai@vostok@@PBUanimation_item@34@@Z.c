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
