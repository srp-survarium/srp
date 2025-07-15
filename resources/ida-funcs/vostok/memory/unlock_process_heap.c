void __cdecl vostok::memory::unlock_process_heap()
{
  LeaveCriticalSection((LPCRITICAL_SECTION)s_process_heap_walk.m_variable);
}
