void __cdecl vostok::core::logging_finalize()
{
  HANDLE StdHandle; // eax
  HANDLE v1; // eax
  HANDLE v2; // eax
  char *v3; // esi

  if ( s_console_initialized )
  {
    StdHandle = GetStdHandle(0xFFFFFFF6);
    CloseHandle(StdHandle);
    v1 = GetStdHandle(0xFFFFFFF5);
    CloseHandle(v1);
    v2 = GetStdHandle(0xFFFFFFF4);
    CloseHandle(v2);
    FreeConsole();
  }
  vostok::logging::delete_log_file(&vostok::core::g_log_file);
  if ( s_logging_console_command )
  {
    v3 = __RTCastToVoid((void **)&s_logging_console_command->__vftable);
    ((void (__thiscall *)(vostok::logging::logging_filters_console_command *, _DWORD))s_logging_console_command->~vostok::logging::logging_filters_console_command)(
      s_logging_console_command,
      0);
    if ( v3 )
      pt3free(v3);
    s_logging_console_command = 0;
  }
  vostok::logging::delete_filter_tree(&vostok::core::g_log_filter_tree);
  vostok::debug::set_log_callback(0);
}
