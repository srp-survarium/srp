vostok::input::receiver::keyboard *__thiscall vostok::input::receiver::keyboard::`vector deleting destructor'(
        vostok::input::receiver::keyboard *this,
        char a2)
{
  IDirectInputDevice8A *m_device; // eax

  m_device = this->m_device;
  this->__vftable = (vostok::input::receiver::keyboard_vtbl *)&vostok::input::receiver::keyboard::`vftable';
  m_device->Unacquire(m_device);
  this->m_device->Release(this->m_device);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
