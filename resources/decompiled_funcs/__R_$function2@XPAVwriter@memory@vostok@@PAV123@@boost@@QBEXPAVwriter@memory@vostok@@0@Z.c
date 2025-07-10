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
