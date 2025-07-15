void __thiscall vostok::input::platform::keyboard::~keyboard(vostok::input::platform::keyboard *this)
{
  IDirectInputDevice8A **p_m_device; // esi
  IDirectInputDevice8A *m_device; // eax

  p_m_device = &this->m_device;
  m_device = this->m_device;
  this->__vftable = (vostok::input::platform::keyboard_vtbl *)&vostok::input::platform::keyboard::`vftable';
  m_device->Unacquire(m_device);
  (*p_m_device)->Release(*p_m_device);
}
