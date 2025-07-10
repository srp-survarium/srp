void __thiscall vostok::input::receiver::mouse::~mouse(vostok::input::receiver::mouse *this)
{
  IDirectInputDevice8A *m_device; // eax

  m_device = this->m_device;
  this->__vftable = (vostok::input::receiver::mouse_vtbl *)&vostok::input::receiver::mouse::`vftable';
  m_device->Unacquire(m_device);
  this->m_device->Release(this->m_device);
}
