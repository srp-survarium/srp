int *__userpurge vostok::memory::doug_lea_mt_allocator::realloc_impl@<eax>(
        vostok::memory::doug_lea_mt_allocator *this@<ecx>,
        mutex_mt_raii *a2@<eax>,
        char *pointer,
        unsigned int new_size)
{
  int *v5; // esi
  mutex_mt_raii guard; // [esp+8h] [ebp-8h] BYREF

  mutex_mt_raii::mutex_mt_raii(a2, &guard);
  v5 = vostok::memory::doug_lea_allocator::realloc_impl((vostok::memory::doug_lea_allocator *)a2, pointer, new_size);
  if ( guard.m_is_tasks_aware )
    LeaveCriticalSection((LPCRITICAL_SECTION)&guard.m_instance->m_mutex);
  else
    LeaveCriticalSection((LPCRITICAL_SECTION)&guard.m_instance->m_mutex_tasks_unaware);
  return v5;
}
