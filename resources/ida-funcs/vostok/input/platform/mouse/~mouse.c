void __thiscall vostok::input::platform::mouse::~mouse(vostok::input::platform::mouse *this)
{
  IDirectInputDevice8A *m_device; // eax

  m_device = this->m_device;
  this->__vftable = (vostok::input::platform::mouse_vtbl *)&vostok::input::platform::mouse::`vftable';
  m_device->Unacquire(m_device);
  this->m_device->Release(this->m_device);
}
