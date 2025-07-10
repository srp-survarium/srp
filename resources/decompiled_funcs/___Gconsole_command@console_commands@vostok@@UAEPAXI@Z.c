vostok::console_commands::cc_bool *__thiscall vostok::console_commands::console_command::`scalar deleting destructor'(
        vostok::console_commands::cc_bool *this,
        char a2)
{
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  this->__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  vtable = this->m_on_change_event.vtable;
  if ( vtable )
  {
    if ( ((unsigned __int8)vtable & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
      if ( v4 )
        v4(&this->m_on_change_event.functor, &this->m_on_change_event.functor, 2);
    }
    this->m_on_change_event.vtable = 0;
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
