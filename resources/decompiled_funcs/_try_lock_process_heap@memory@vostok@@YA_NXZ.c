BOOL __cdecl vostok::memory::try_lock_process_heap()
{
  return TryEnterCriticalSection((LPCRITICAL_SECTION)s_process_heap_walk.m_variable);
}
