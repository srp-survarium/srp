void __thiscall boost::function1<void,vostok::sound::create_sound_propagator_params const &>::clear(
        boost::function1<void,vostok::sound::create_sound_propagator_params const &> *this)
{
  void (__cdecl **v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // [esp+8h] [ebp-4h]

  if ( this->vtable )
  {
    if ( ((int)this->vtable & 1) == 0 )
    {
      v2 = (void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)this->vtable & 0xFFFFFFFE);
      if ( *v2 )
        (*v2)(&this->functor, &this->functor, 2);
    }
    this->vtable = 0;
  }
}
