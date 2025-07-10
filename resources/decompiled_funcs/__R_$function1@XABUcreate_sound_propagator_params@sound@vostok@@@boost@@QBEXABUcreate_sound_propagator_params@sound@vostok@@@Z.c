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
