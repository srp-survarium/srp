void __thiscall vostok::console_commands::console_command::~console_command(
        vostok::console_commands::console_command *this)
{
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  this->__vftable = (vostok::console_commands::console_command_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  vtable = this->m_on_change_event.vtable;
  if ( vtable )
  {
    if ( ((unsigned __int8)vtable & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
      if ( v3 )
        v3(&this->m_on_change_event.functor, &this->m_on_change_event.functor, 2);
    }
    this->m_on_change_event.vtable = 0;
  }
}
