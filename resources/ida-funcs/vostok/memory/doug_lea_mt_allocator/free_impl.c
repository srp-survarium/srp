void __userpurge vostok::memory::doug_lea_mt_allocator::free_impl(
        vostok::memory::doug_lea_mt_allocator *this@<ecx>,
        int a2@<eax>,
        char *pointer)
{
  mutex_mt_raii guard; // [esp+10h] [ebp-8h] BYREF

  mutex_mt_raii::mutex_mt_raii((mutex_mt_raii *)a2, &guard);
  if ( pointer )
  {
    *(_BYTE *)(a2 + 42) = 0;
    vostok_mspace_free(*(malloc_state **)(a2 + 20), pointer);
  }
  if ( guard.m_is_tasks_aware )
    LeaveCriticalSection((LPCRITICAL_SECTION)&guard.m_instance->m_mutex);
  else
    LeaveCriticalSection((LPCRITICAL_SECTION)&guard.m_instance->m_mutex_tasks_unaware);
}
