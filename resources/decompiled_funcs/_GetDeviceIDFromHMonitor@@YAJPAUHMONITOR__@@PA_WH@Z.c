HRESULT __cdecl GetDeviceIDFromHMonitor(HMONITOR__ *hm, wchar_t *strDeviceID)
{
  HMODULE LibraryA; // edi
  FARPROC ProcAddress; // eax
  int v4; // esi
  _DISPLAY_DEVICEA dispdev; // [esp+10h] [ebp-3C4h] BYREF
  DDRAW_MATCH match; // [esp+1B8h] [ebp-21Ch] BYREF

  LibraryA = LoadLibraryA(&stru_95DC74.m_buffer[52]);
  if ( !LibraryA )
    return -2147467259;
  memset((int)&match, 0, sizeof(match));
  match.hMonitor = hm;
  ProcAddress = GetProcAddress(LibraryA, &stru_95DC74.m_buffer[64]);
  if ( ProcAddress )
    ((void (__stdcall *)(int (__stdcall *)(_GUID *, char *, char *, _BYTE *, HMONITOR__ *), DDRAW_MATCH *, int))ProcAddress)(
      DDEnumCallbackEx,
      &match,
      1);
  if ( !match.bFound
    || (v4 = 0, memset((int)&dispdev, 0, sizeof(dispdev)), dispdev.cb = 424, !EnumDisplayDevicesA(0, 0, &dispdev, 0)) )
  {
LABEL_10:
    FreeLibrary(LibraryA);
    return -2147467259;
  }
  while ( (dispdev.StateFlags & 8) != 0
       || (dispdev.StateFlags & 1) == 0
       || _stricmp(match.strDriverName, dispdev.DeviceName) )
  {
    if ( !EnumDisplayDevicesA(0, ++v4, &dispdev, 0) )
      goto LABEL_10;
  }
  MultiByteToWideChar(0, 0, dispdev.DeviceID, -1, strDeviceID, 512);
  FreeLibrary(LibraryA);
  return 0;
}
