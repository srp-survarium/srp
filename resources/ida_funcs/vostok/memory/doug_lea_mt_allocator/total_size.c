unsigned int __thiscall vostok::memory::doug_lea_mt_allocator::total_size(vostok::memory::doug_lea_mt_allocator *this)
{
  unsigned int v2; // esi
  mutex_mt_raii guard; // [esp+8h] [ebp-8h] BYREF

  mutex_mt_raii::mutex_mt_raii((mutex_mt_raii *)this, &guard);
  v2 = vostok::memory::doug_lea_allocator::total_size(this);
  if ( guard.m_is_tasks_aware )
    LeaveCriticalSection((LPCRITICAL_SECTION)&guard.m_instance->m_mutex);
  else
    LeaveCriticalSection((LPCRITICAL_SECTION)&guard.m_instance->m_mutex_tasks_unaware);
  return v2;
}
