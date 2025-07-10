void __thiscall boost::function0<void>::assign_to_own(boost::function0<void> *this, const boost::function0<void> *f)
{
  boost::detail::function::vtable_base *vtable; // eax
  boost::detail::function::function_buffer *p_functor; // ecx

  vtable = f->vtable;
  if ( f->vtable )
  {
    this->vtable = vtable;
    p_functor = &this->functor;
    if ( ((unsigned __int8)vtable & 1) != 0 )
      *p_functor = f->functor;
    else
      (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((unsigned int)vtable & 0xFFFFFFFE))(
        &f->functor,
        p_functor,
        0);
  }
}
