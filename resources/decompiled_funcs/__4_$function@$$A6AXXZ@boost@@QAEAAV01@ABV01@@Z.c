boost::function<void __cdecl(void)> *__thiscall boost::function<void __cdecl (void)>::operator=(
        boost::function<void __cdecl(void)> *this,
        const boost::function<void __cdecl(void)> *f)
{
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function0<void> v5; // [esp+8h] [ebp-20h] BYREF

  v5.vtable = 0;
  boost::function0<void>::assign_to_own(&v5, f);
  boost::function0<void>::swap(&v5, this);
  if ( v5.vtable )
  {
    if ( ((int)v5.vtable & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v5.vtable & 0xFFFFFFFE);
      if ( v3 )
        v3(&v5.functor, &v5.functor, 2);
    }
  }
  return this;
}
