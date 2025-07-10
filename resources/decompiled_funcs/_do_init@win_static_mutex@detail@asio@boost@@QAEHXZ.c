DWORD __thiscall boost::asio::detail::win_static_mutex::do_init(boost::asio::detail::win_static_mutex *this)
{
  DWORD CurrentProcessId; // eax
  HANDLE mutex; // [esp+1Ch] [ebp-120h]
  DWORD last_error; // [esp+20h] [ebp-11Ch]
  DWORD last_errora; // [esp+20h] [ebp-11Ch]
  wchar_t mutex_name[128]; // [esp+24h] [ebp-118h] BYREF
  CPPEH_RECORD ms_exc; // [esp+124h] [ebp-18h]

  CurrentProcessId = GetCurrentProcessId();
  swprintf_s(mutex_name, 0x80u, L"asio-58CCDC44-6264-4842-90C2-F3C545CB8AA7-%u-%p", CurrentProcessId, this);
  mutex = CreateMutexW(0, 1, mutex_name);
  last_error = GetLastError();
  if ( !mutex )
    return GetLastError();
  if ( last_error == 183 )
    WaitForSingleObject(mutex, 0xFFFFFFFF);
  if ( this->initialised_ )
  {
    ReleaseMutex(mutex);
    CloseHandle(mutex);
    return 0;
  }
  else
  {
    ms_exc.registration.TryLevel = 0;
    if ( InitializeCriticalSectionAndSpinCount(&this->crit_section_, 0x80000000) )
    {
      ms_exc.registration.TryLevel = -1;
      this->initialised_ = 1;
      ReleaseMutex(mutex);
      CloseHandle(mutex);
      return 0;
    }
    else
    {
      last_errora = GetLastError();
      ReleaseMutex(mutex);
      CloseHandle(mutex);
      ms_exc.registration.TryLevel = -1;
      return last_errora;
    }
  }
}
