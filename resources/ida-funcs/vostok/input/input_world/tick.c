void __thiscall vostok::input::input_world::tick(vostok::input::input_world *this, unsigned int current_time_in_ms)
{
  volatile int *p_m_target_state; // edi
  vostok::input::vector<vostok::input::handler *> *p_m_handlers; // ebp
  void **M_finish; // ebx
  void **i; // edi
  void **v7; // ebx
  void **j; // edi

  if ( this->m_acquired )
  {
    p_m_target_state = &this->m_target_state;
    if ( this->m_target_state != 2 )
    {
      if ( *p_m_target_state )
      {
        vostok::input::input_world::process_on_deactivate(this, this);
      }
      else
      {
        if ( this->m_gamepad )
          this->m_gamepad->on_activate(this->m_gamepad);
        if ( this->m_keyboard )
          this->m_keyboard->on_activate(this->m_keyboard);
        if ( this->m_mouse )
          this->m_mouse->on_activate(this->m_mouse);
      }
      _InterlockedExchange(p_m_target_state, 2);
    }
    p_m_handlers = &this->m_handlers;
    if ( this->m_handlers._M_impl._M_start != this->m_handlers._M_impl._M_finish )
    {
      if ( this->m_gamepad )
        this->m_gamepad->execute(this->m_gamepad);
      if ( this->m_keyboard )
        this->m_keyboard->execute(this->m_keyboard);
      if ( this->m_mouse )
        this->m_mouse->execute(this->m_mouse);
      M_finish = this->m_handlers._M_impl._M_finish;
      for ( i = p_m_handlers->_M_impl._M_start; i != M_finish; ++i )
        (*(void (__thiscall **)(void *, vostok::input::input_world *))(*(_DWORD *)*i + 20))(*i, this);
      if ( this->m_gamepad )
        this->m_gamepad->process(this->m_gamepad, &this->m_handlers);
      if ( this->m_keyboard )
        this->m_keyboard->process(this->m_keyboard, &this->m_handlers);
      if ( this->m_mouse )
        this->m_mouse->process(this->m_mouse, &this->m_handlers);
      v7 = this->m_handlers._M_impl._M_finish;
      for ( j = p_m_handlers->_M_impl._M_start; j != v7; ++j )
        (*(void (__thiscall **)(void *, vostok::input::input_world *))(*(_DWORD *)*j + 24))(*j, this);
    }
  }
}
