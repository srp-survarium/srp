int __cdecl _tmainCRTStartup()
{
  int v0; // eax
  char *v1; // eax
  int wShowWindow; // ecx
  int v3; // eax
  _STARTUPINFOA StartupInfo; // [esp+10h] [ebp-68h] BYREF
  int mainret; // [esp+58h] [ebp-20h]
  int managedapp; // [esp+5Ch] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+60h] [ebp-18h]

  ms_exc.registration.TryLevel = 0;
  GetStartupInfoA(&StartupInfo);
  ms_exc.registration.TryLevel = -2;
  managedapp = LOWORD(_sbh_sizeHeaderList.unused) == 23117
            && *(int *)((char *)&_sbh_sizeHeaderList.unused + dword_1003C) == 17744
            && *(__int16 *)((char *)&word_10018 + dword_1003C) == 267
            && *(_DWORD *)&byte_10040[dword_1003C + 52] > 0xEu
            && *(_DWORD *)&byte_10040[dword_1003C + 168] != 0;
  if ( !_heap_init(1) )
    fast_error_exit(28);
  if ( !_mtinit() )
    fast_error_exit(16);
  _RTC_Initialize();
  ms_exc.registration.TryLevel = 1;
  if ( _ioinit() < 0 )
    _amsg_exit(27);
  _acmdln = GetCommandLineA();
  _aenvptr = (char *)__crtGetEnvironmentStringsA();
  if ( _setargv() < 0 )
    _amsg_exit(8);
  if ( _setenvp() < 0 )
    _amsg_exit(9);
  v0 = _cinit(1);
  if ( v0 )
    _amsg_exit(v0);
  v1 = (char *)_wincmdln();
  if ( (StartupInfo.dwFlags & 1) != 0 )
    wShowWindow = StartupInfo.wShowWindow;
  else
    wShowWindow = 10;
  v3 = WinMain(&_sbh_sizeHeaderList, 0, v1, wShowWindow);
  mainret = v3;
  if ( !managedapp )
    exit(v3);
  _cexit();
  return mainret;
}
