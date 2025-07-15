void __thiscall vostok::input::input_world::unacquire(vostok::input::input_world *this)
{
  vostok::input::receiver::keyboard *m_keyboard; // eax
  vostok::input::receiver::mouse *m_mouse; // esi

  if ( this->m_acquired )
  {
    m_keyboard = this->m_keyboard;
    this->m_acquired = 0;
    if ( m_keyboard )
      m_keyboard->m_device->Unacquire(m_keyboard->m_device);
    m_mouse = this->m_mouse;
    if ( m_mouse )
      m_mouse->m_device->Unacquire(m_mouse->m_device);
  }
}
