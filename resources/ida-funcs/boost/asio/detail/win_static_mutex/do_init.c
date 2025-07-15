DWORD __thiscall boost::asio::detail::win_static_mutex::do_init(
        boost::asio::detail::win_static_mutex *this,
        char *mutex)
{
  DWORD CurrentProcessId; // eax
  HANDLE MutexW; // edi
  DWORD LastError; // eax
  DWORD v6; // esi
  wchar_t mutex_name[128]; // [esp+Ch] [ebp-118h] BYREF
  CPPEH_RECORD ms_exc; // [esp+10Ch] [ebp-18h]

  CurrentProcessId = GetCurrentProcessId();
  swprintf_s(mutex_name, 0x80u, (wchar_t *)L"asio-58CCDC44-6264-4842-90C2-F3C545CB8AA7-%u-%p", CurrentProcessId, mutex);
  MutexW = CreateMutexW(0, 1, mutex_name);
  LastError = GetLastError();
  if ( !MutexW )
    return GetLastError();
  if ( LastError == 183 )
    WaitForSingleObject(MutexW, 0xFFFFFFFF);
  if ( *mutex )
    goto LABEL_6;
  ms_exc.registration.TryLevel = 0;
  if ( InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(mutex + 4), 0x80000000) )
  {
    ms_exc.registration.TryLevel = -1;
    *mutex = 1;
LABEL_6:
    ReleaseMutex(MutexW);
    CloseHandle(MutexW);
    return 0;
  }
  v6 = GetLastError();
  ReleaseMutex(MutexW);
  CloseHandle(MutexW);
  ms_exc.registration.TryLevel = -1;
  return v6;
}
