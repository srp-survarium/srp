void __thiscall vostok::memory::doug_lea_mt_allocator::finalize_impl(vostok::memory::doug_lea_mt_allocator *this)
{
  mutex_mt_raii guard; // [esp+8h] [ebp-8h] BYREF

  mutex_mt_raii::mutex_mt_raii((mutex_mt_raii *)this, &guard);
  destroy_mspace((char *)this->m_arena);
  if ( guard.m_is_tasks_aware )
    LeaveCriticalSection((LPCRITICAL_SECTION)&guard.m_instance->m_mutex);
  else
    LeaveCriticalSection((LPCRITICAL_SECTION)&guard.m_instance->m_mutex_tasks_unaware);
}
