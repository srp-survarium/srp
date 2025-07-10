void __thiscall boost::function0<bool>::assign_to<bool (__cdecl *)(void)>(
        boost::function0<bool> *this,
        bool (__cdecl *f)())
{
  boost::detail::function::function_buffer *p_functor; // [esp+4h] [ebp-Ch]
  char v4; // [esp+9h] [ebp-7h]

  p_functor = &this->functor;
  boost::detail::function::basic_vtable0<bool>::clear(
    (boost::detail::function::basic_vtable0<bool> *)&this->functor,
    (void (__cdecl **)(boost::detail::function::basic_vtable0<bool> *, boost::detail::function::basic_vtable0<bool> *, int))&stru_977EF0.m_fat_it.m_node);
  if ( f )
  {
    p_functor->obj_ptr = f;
    v4 = 1;
  }
  else
  {
    v4 = 0;
  }
  if ( v4 )
    this->vtable = (boost::detail::function::vtable_base *)((char *)&stru_977EF0.m_fat_it.m_node + 1);
  else
    this->vtable = 0;
}
