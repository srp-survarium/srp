double __thiscall boost::function4<float,char const *,char const *,float,float>::operator()(
        boost::function4<float,char const *,char const *,float,float> *this,
        const char *a0,
        const char *a1,
        float a2,
        float a3)
{
  const std::exception *v5; // eax
  double result; // st7
  boost::bad_function_call v8; // [esp+2Ch] [ebp-110h] BYREF

  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) )
  {
    boost::bad_function_call::bad_function_call(&v8);
    boost::throw_exception(v5);
    boost::bad_function_call::~bad_function_call(&v8);
  }
  result = a2;
  (*(void (__cdecl **)(boost::detail::function::function_buffer *, const char *, const char *, _DWORD, _DWORD))(((int)this->vtable & 0xFFFFFFFE) + 4))(
    &this->functor,
    a0,
    a1,
    LODWORD(a2),
    LODWORD(a3));
  return result;
}
