void __thiscall boost::function0<void>::swap(boost::function0<void> *this, boost::function0<void> *other)
{
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function0<void> tmp; // [esp+8h] [ebp-20h] BYREF

  if ( other != this )
  {
    tmp.vtable = 0;
    boost::function0<void>::move_assign(&tmp, this);
    boost::function0<void>::move_assign(this, other);
    boost::function0<void>::move_assign(other, &tmp);
    if ( tmp.vtable )
    {
      if ( ((int)tmp.vtable & 1) == 0 )
      {
        v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)tmp.vtable & 0xFFFFFFFE);
        if ( v3 )
          v3(&tmp.functor, &tmp.functor, 2);
      }
    }
  }
}
