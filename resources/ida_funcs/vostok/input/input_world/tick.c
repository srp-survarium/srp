void __thiscall vostok::input::input_world::tick(vostok::input::input_world *this, unsigned int current_time_in_ms)
{
  vostok::input::input_world *v2; // ebx
  vostok::input::input_world **p_m_target_state; // edi
  vostok::input::receiver::mouse *m_mouse; // eax
  int m_gamepad; // esi
  _DWORD *v6; // eax
  int v7; // eax
  void **M_finish; // edi
  void **i; // esi
  int v10; // esi
  int m_keyboard; // edi
  int v12; // esi
  void **v13; // edi
  void **j; // esi

  v2 = this;
  if ( this->m_acquired )
  {
    p_m_target_state = (vostok::input::input_world **)&this->m_target_state;
    if ( this->m_target_state != 2 )
    {
      if ( *p_m_target_state )
      {
        vostok::input::input_world::process_on_deactivate(*p_m_target_state, (int)this);
      }
      else
      {
        if ( this->m_keyboard )
          vostok::input::receiver::keyboard::on_activate(0, this->m_keyboard);
        m_mouse = v2->m_mouse;
        if ( m_mouse )
          m_mouse->m_device->Acquire(m_mouse->m_device);
      }
      this = (vostok::input::input_world *)_InterlockedExchange((volatile __int32 *)p_m_target_state, 2);
    }
    if ( v2->m_handlers._M_impl._M_start != v2->m_handlers._M_impl._M_finish )
    {
      m_gamepad = (int)v2->m_gamepad;
      if ( m_gamepad )
        vostok::input::receiver::gamepad::execute((vostok::input::receiver::gamepad *)this, m_gamepad);
      v6 = &v2->m_keyboard->__vftable;
      if ( v6 )
        vostok::input::receiver::keyboard::execute((vostok::input::receiver::keyboard *)this, v6);
      v7 = (int)v2->m_mouse;
      if ( v7 )
        vostok::input::receiver::mouse::execute((vostok::input::receiver::mouse *)this, v7);
      M_finish = v2->m_handlers._M_impl._M_finish;
      for ( i = v2->m_handlers._M_impl._M_start; i != M_finish; ++i )
        (*(void (__thiscall **)(void *, vostok::input::input_world *, unsigned int))(*(_DWORD *)*i + 16))(
          *i,
          v2,
          current_time_in_ms);
      v10 = (int)v2->m_gamepad;
      if ( v10 )
        vostok::input::receiver::gamepad::process((vostok::input::receiver::gamepad *)this, v10, &v2->m_handlers);
      m_keyboard = (int)v2->m_keyboard;
      if ( m_keyboard )
        vostok::input::receiver::keyboard::process(
          (vostok::input::receiver::keyboard *)this,
          m_keyboard,
          &v2->m_handlers);
      v12 = (int)v2->m_mouse;
      if ( v12 )
        vostok::input::receiver::mouse::process((vostok::input::receiver::mouse *)this, v12, &v2->m_handlers);
      v13 = v2->m_handlers._M_impl._M_finish;
      for ( j = v2->m_handlers._M_impl._M_start; j != v13; ++j )
        (*(void (__thiscall **)(void *, vostok::input::input_world *))(*(_DWORD *)*j + 20))(*j, v2);
    }
  }
}
