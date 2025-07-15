void __thiscall initialize(vostok::memory::base_allocator *this, void *a2, unsigned __int64 a3, const char *a4)
{
  HMODULE ModuleHandleA; // eax

  if ( !s_initialized_4 )
  {
    if ( InterlockedIncrement(&s_initializer_lock) == 1 )
    {
      ModuleHandleA = GetModuleHandleA("ntdll.dll");
      s_pfnCaptureStackBackTrace = (unsigned __int16 (__stdcall *)(unsigned int, unsigned int, void **, unsigned int *))GetProcAddress(ModuleHandleA, "RtlCaptureStackBackTrace");
      if ( !s_pfnCaptureStackBackTrace && (s_log_disable_counter == 0 ? (unsigned int)s_log_callback : 0) != 0 )
        ((void (__cdecl *)(const vostok::logging::filter_tree *, int, _DWORD, const char *))(s_log_disable_counter == 0
                                                                                           ? (unsigned int)s_log_callback
                                                                                           : 0))(
          &stru_802CB8,
          1,
          0,
          "can't find function RtlCaptureStackBackTrace in ntdll.dll");
      load_library_0();
      if ( s_use_dbghelp )
        InitSymInfo();
      InterlockedExchange(&s_initialized_4, 1);
    }
    else
    {
      while ( !s_initialized_4 )
        Sleep(1u);
    }
  }
}
