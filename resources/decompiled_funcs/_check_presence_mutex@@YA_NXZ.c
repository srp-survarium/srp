bool __cdecl check_presence_mutex()
{
  HANDLE v0; // eax
  HANDLE CurrentProcess; // eax

  v0 = OpenMutexA((DWORD)&loc_20000, 0, "survarium_already_running");
  s_presence_mutex = v0;
  if ( v0 )
  {
    CloseHandle(v0);
    MessageBoxA(0, "Survarium application already running", "Survarium", 0x10u);
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(CurrentProcess, 1u);
    return 0;
  }
  else
  {
    s_presence_mutex = CreateMutexA(0, 0, "survarium_already_running");
    return s_presence_mutex != 0;
  }
}
