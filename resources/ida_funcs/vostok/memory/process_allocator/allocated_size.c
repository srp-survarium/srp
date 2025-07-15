BOOL __thiscall vostok::memory::process_allocator::allocated_size(vostok::memory::process_allocator *this)
{
  BOOL result; // eax
  HANDLE ProcessHeap; // eax
  int v3; // esi

  result = TryEnterCriticalSection((LPCRITICAL_SECTION)s_process_heap_walk.m_variable);
  if ( result )
  {
    ProcessHeap = GetProcessHeap();
    v3 = mem_usage(ProcessHeap);
    LeaveCriticalSection((LPCRITICAL_SECTION)s_process_heap_walk.m_variable);
    return v3;
  }
  return result;
}
