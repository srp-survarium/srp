void __thiscall vostok::input::receiver::keyboard::~keyboard(vostok::input::receiver::keyboard *this)
{
  IDirectInputDevice8A *m_device; // eax

  m_device = this->m_device;
  this->__vftable = (vostok::input::receiver::keyboard_vtbl *)&vostok::input::receiver::keyboard::`vftable';
  m_device->Unacquire(m_device);
  this->m_device->Release(this->m_device);
}
