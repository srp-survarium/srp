unsigned __int8 *__cdecl allocate(SIZE_T size)
{
  vostok::threading::mutex *v1; // ecx
  HANDLE ProcessHeap; // eax
  LPVOID v3; // esi

  vostok::threading::mutex::lock(v1, (_RTL_CRITICAL_SECTION *)s_process_heap_walk.m_variable);
  ProcessHeap = GetProcessHeap();
  v3 = HeapAlloc(ProcessHeap, 0, size);
  LeaveCriticalSection((LPCRITICAL_SECTION)s_process_heap_walk.m_variable);
  return (unsigned __int8 *)v3;
}
