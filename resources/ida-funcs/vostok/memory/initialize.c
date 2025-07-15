void __thiscall vostok::memory::initialize(vostok::command_line::key *this)
{
  char *m_begin; // esi
  allocator_data *m_end; // edi
  HMODULE LibraryA; // eax
  BOOL (__stdcall *HeapSetInformation)(HANDLE, HEAP_INFORMATION_CLASS, PVOID, SIZE_T); // esi
  HANDLE ProcessHeap; // eax
  void *heap_handle; // eax
  int v7; // [esp+Ch] [ebp-4h] BYREF

  m_begin = (char *)s_allocators.m_variable->m_begin;
  m_end = s_allocators.m_variable->m_end;
  while ( m_begin != (char *)m_end )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)m_begin + 4))(
      *(_DWORD *)m_begin,
      *((_DWORD *)m_begin + 4),
      *((_DWORD *)m_begin + 2),
      *((_DWORD *)m_begin + 3),
      *((_DWORD *)m_begin + 5));
    m_begin += 24;
  }
  vostok::memory::monitor::initialize(this, m_begin);
  if ( !vostok::debug::is_debugger_present() )
  {
    LibraryA = LoadLibraryA("kernel32.dll");
    HeapSetInformation = (BOOL (__stdcall *)(HANDLE, HEAP_INFORMATION_CLASS, PVOID, SIZE_T))GetProcAddress(
                                                                                              LibraryA,
                                                                                              "HeapSetInformation");
    if ( HeapSetInformation )
    {
      v7 = 2;
      ProcessHeap = GetProcessHeap();
      HeapSetInformation(ProcessHeap, HeapCompatibilityInformation, &v7, 4);
      heap_handle = _get_heap_handle();
      HeapSetInformation(heap_handle, HeapCompatibilityInformation, &v7, 4);
    }
  }
  vostok::core::logging_initialize();
  vostok::memory::dump_statistics(1);
}
