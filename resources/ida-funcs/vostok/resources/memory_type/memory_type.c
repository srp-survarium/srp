void __usercall vostok::resources::memory_type::memory_type(
        vostok::resources::memory_type *this@<edi>,
        const char *name@<eax>,
        vostok::threading::mutex_tasks_unaware *a3@<ecx>)
{
  vostok::timing::timer *v3; // ecx

  this->m_name = name;
  this->m_next = 0;
  this->in_list = 0;
  this->resources.m_size = 0;
  this->resources.m_first = 0;
  this->resources.m_last = 0;
  this->sort_actuality_tick = 0;
  this->queue.m_size = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    a3,
    (_RTL_CRITICAL_SECTION *)&this->queue.vostok::threading::mutex);
  this->queue.m_first = 0;
  this->queue.m_last = 0;
  this->listen_type = listen_none;
  vostok::timing::timer::timer(v3, (LARGE_INTEGER *)&this->listen_all_timer);
}
