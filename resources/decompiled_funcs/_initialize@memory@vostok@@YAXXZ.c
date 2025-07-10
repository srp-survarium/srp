void __cdecl vostok::memory::initialize()
{
  allocator_data *m_begin; // esi
  allocator_data *m_end; // edi
  HMODULE LibraryA; // eax
  BOOL (__stdcall *HeapSetInformation)(HANDLE, HEAP_INFORMATION_CLASS, PVOID, SIZE_T); // esi
  HANDLE ProcessHeap; // eax
  void *heap_handle; // eax
  int v6; // [esp+20h] [ebp-4h] BYREF

  m_begin = s_allocators.m_variable->m_begin;
  m_end = s_allocators.m_variable->m_end;
  if ( s_allocators.m_variable->m_begin != m_end )
  {
    do
    {
      ((void (__thiscall *)(vostok::memory::base_allocator *, void *, _DWORD, _DWORD, const char *))m_begin->allocator->initialize)(
        m_begin->allocator,
        m_begin->arena_address,
        m_begin->arena_size,
        HIDWORD(m_begin->arena_size),
        m_begin->arena_id);
      ++m_begin;
    }
    while ( m_begin != m_end );
  }
  if ( !vostok::debug::is_debugger_present() )
  {
    LibraryA = LoadLibraryA("kernel32.dll");
    HeapSetInformation = (BOOL (__stdcall *)(HANDLE, HEAP_INFORMATION_CLASS, PVOID, SIZE_T))GetProcAddress(
                                                                                              LibraryA,
                                                                                              "HeapSetInformation");
    if ( HeapSetInformation )
    {
      v6 = 2;
      ProcessHeap = GetProcessHeap();
      HeapSetInformation(ProcessHeap, HeapCompatibilityInformation, &v6, 4);
      heap_handle = _get_heap_handle();
      HeapSetInformation(heap_handle, HeapCompatibilityInformation, &v6, 4);
    }
  }
  vostok::core::logging_initialize();
  vostok::memory::dump_statistics(1);
}
