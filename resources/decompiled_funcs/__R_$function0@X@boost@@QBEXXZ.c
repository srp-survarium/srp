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
