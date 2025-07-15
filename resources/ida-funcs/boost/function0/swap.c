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


void __thiscall boost::function0<bool>::swap(boost::function0<bool> *this, boost::function0<bool> *other)
{
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  boost::function0<bool> tmp; // [esp+8h] [ebp-20h] BYREF

  if ( other != this )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
      &tmp);
    boost::function0<bool>::move_assign(&tmp, this);
    boost::function0<bool>::move_assign(this, other);
    boost::function0<bool>::move_assign(other, &tmp);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v2,
      (int *)&tmp);
  }
}
