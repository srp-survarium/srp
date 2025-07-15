unsigned __int8 *__cdecl allocate(unsigned int size)
{
  HANDLE ProcessHeap; // eax
  LPVOID v2; // esi

  vostok::threading::mutex::lock(s_process_heap_walk.m_variable);
  ProcessHeap = GetProcessHeap();
  v2 = HeapAlloc(ProcessHeap, 0, size);
  LeaveCriticalSection((LPCRITICAL_SECTION)s_process_heap_walk.m_variable);
  return (unsigned __int8 *)v2;
}
