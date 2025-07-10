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
