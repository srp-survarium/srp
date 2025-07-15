vostok::input::receiver::mouse *__thiscall vostok::input::receiver::mouse::`scalar deleting destructor'(
        vostok::input::receiver::mouse *this,
        char a2)
{
  IDirectInputDevice8A *m_device; // eax

  m_device = this->m_device;
  this->__vftable = (vostok::input::receiver::mouse_vtbl *)&vostok::input::receiver::mouse::`vftable';
  m_device->Unacquire(m_device);
  this->m_device->Release(this->m_device);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
