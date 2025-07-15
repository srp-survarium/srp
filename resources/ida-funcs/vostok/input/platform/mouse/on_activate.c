void __thiscall vostok::input::platform::mouse::on_activate(vostok::input::platform::mouse *this)
{
  volatile int *p_m_busy; // esi

  p_m_busy = &this->m_busy;
  while ( !_InterlockedCompareExchange(p_m_busy, 1, 0) )
    ;
  this->m_device->Acquire(this->m_device);
  _InterlockedExchange(p_m_busy, 0);
}
