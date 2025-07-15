void __usercall mutex_mt_raii::mutex_mt_raii(
        mutex_mt_raii *this@<edi>,
        const vostok::memory::doug_lea_mt_allocator *instance@<eax>,
        vostok::threading::mutex *a3@<ecx>)
{
  vostok::memory::doug_lea_allocator *v3; // ecx

  this->m_instance = instance;
  LOBYTE(a3) = instance->m_is_tasks_aware;
  this->m_is_tasks_aware = (char)a3;
  if ( (_BYTE)a3 )
    vostok::threading::mutex::lock(a3, (_RTL_CRITICAL_SECTION *)&instance->m_mutex);
  else
    EnterCriticalSection((LPCRITICAL_SECTION)&instance->m_mutex_tasks_unaware);
  vostok::memory::doug_lea_allocator::user_current_thread_id(v3, (int)this->m_instance);
}
