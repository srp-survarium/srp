int *__userpurge vostok::memory::doug_lea_mt_allocator::malloc_impl@<eax>(
        vostok::memory::doug_lea_mt_allocator *this@<ecx>,
        mutex_mt_raii *a2@<eax>,
        unsigned int size)
{
  int *v4; // esi
  mutex_mt_raii guard; // [esp+8h] [ebp-8h] BYREF

  mutex_mt_raii::mutex_mt_raii(a2, &guard);
  v4 = vostok::memory::doug_lea_allocator::malloc_impl((vostok::memory::doug_lea_allocator *)a2, size);
  if ( guard.m_is_tasks_aware )
    LeaveCriticalSection((LPCRITICAL_SECTION)&guard.m_instance->m_mutex);
  else
    LeaveCriticalSection((LPCRITICAL_SECTION)&guard.m_instance->m_mutex_tasks_unaware);
  return v4;
}
