void __thiscall initialize(vostok::memory::base_allocator *this, void *a2, unsigned __int64 a3, const char *a4)
{
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  void (__cdecl *log_callback)(const char *, bool, bool, const char *); // [esp+4h] [ebp-8h]
  HMODULE handle; // [esp+8h] [ebp-4h]

  if ( !s_initialized_3 )
  {
    if ( InterlockedIncrement(&s_initializer_lock) == 1 )
    {
      handle = GetModuleHandleA("ntdll.dll");
      survarium::weapon_user_dead_state::finalize(v4);
      s_pfnCaptureStackBackTrace = (unsigned __int16 (__stdcall *)(unsigned int, unsigned int, void **, unsigned int *))GetProcAddress(handle, "RtlCaptureStackBackTrace");
      if ( !s_pfnCaptureStackBackTrace )
      {
        log_callback = vostok::debug::get_log_callback();
        if ( log_callback )
          log_callback("debug", 1, 0, "can't find function RtlCaptureStackBackTrace in ntdll.dll");
      }
      load_library(v5);
      if ( s_use_dbghelp )
        InitSymInfo(0);
      InterlockedExchange(&s_initialized_3, 1);
    }
    else
    {
      while ( !s_initialized_3 )
        Sleep(1u);
    }
  }
}
