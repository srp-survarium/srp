void __thiscall boost::function1<void,vostok::sound::create_sound_propagator_params const &>::assign_to_own(
        boost::function1<void,vostok::sound::create_sound_propagator_params const &> *this,
        const boost::function1<void,vostok::sound::create_sound_propagator_params const &> *f)
{
  if ( f->vtable )
  {
    this->vtable = f->vtable;
    if ( ((int)this->vtable & 1) != 0 )
      this->functor = f->functor;
    else
      (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((int)this->vtable & 0xFFFFFFFE))(
        &f->functor,
        &this->functor,
        0);
  }
}
