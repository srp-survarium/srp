int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  vostok::debug::crash_handlers_guard *v4; // ecx
  HANDLE CurrentProcess; // eax
  int v6; // esi
  vostok::debug::crash_handler handler; // [esp+Ch] [ebp-8h] BYREF

  handler.next = 0;
  handler.__vftable = (vostok::debug::crash_handler_vtbl *)&application_mutex_guard::`vftable';
  s_mutex_1 = CreateMutexA(0, 0, "survarium_or_its_installer_is_already_running");
  if ( !s_mutex_1 || GetLastError() == 183 )
  {
    MessageBoxA(
      0,
      "Survarium or its installer is already running.\r\n\r\nYou may close it and try again.",
      "Survarium",
      0x10u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(CurrentProcess, 1u);
  }
  vostok::debug::add_crash_handler(&handler, v4);
  vostok::debug::protected_call((void (__cdecl *)(void *))main_protected, 0);
  v6 = s_exit_code;
  handler.__vftable = (vostok::debug::crash_handler_vtbl *)&application_mutex_guard::`vftable';
  vostok::debug::remove_crash_handler(&handler);
  if ( s_mutex_1 )
  {
    CloseHandle(s_mutex_1);
    s_mutex_1 = 0;
  }
  return v6;
}
