void __thiscall boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *this,
        const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *f)
{
  boost::detail::function::vtable_base *vtable; // eax

  f->vtable = 0;
  vtable = this->vtable;
  if ( this->vtable )
  {
    f->vtable = vtable;
    if ( ((unsigned __int8)vtable & 1) != 0 )
      qmemcpy((void *)&f->functor, &this->functor, sizeof(f->functor));
    else
      (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((unsigned int)vtable & 0xFFFFFFFE))(
        &this->functor,
        &f->functor,
        0);
  }
}
