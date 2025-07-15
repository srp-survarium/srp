void __thiscall vostok::input::platform::keyboard::on_deactivate(vostok::input::platform::keyboard *this)
{
  this->m_device->Unacquire(this->m_device);
}
