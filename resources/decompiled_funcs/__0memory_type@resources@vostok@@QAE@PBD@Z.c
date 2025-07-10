void __usercall vostok::resources::memory_type::memory_type(
        vostok::resources::memory_type *this@<esi>,
        const char *name@<eax>)
{
  this->m_next = 0;
  this->m_name = name;
  this->in_list = 0;
  this->resources.m_size = 0;
  this->resources.m_first = 0;
  this->resources.m_last = 0;
  this->sort_actuality_tick = 0;
  this->queue.m_size = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&this->queue.vostok::threading::mutex, 0x2710u);
  this->queue.m_first = 0;
  this->queue.m_last = 0;
  this->listen_type = listen_none;
  vostok::timing::timer::timer(&this->listen_all_timer);
}
