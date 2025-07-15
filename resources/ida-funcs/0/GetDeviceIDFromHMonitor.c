HRESULT __cdecl GetDeviceIDFromHMonitor(HMONITOR__ *hm, wchar_t *strDeviceID)
{
  HRESULT (__stdcall *DirectDrawEnumerateExA)(LPDDENUMCALLBACKEXA, LPVOID, DWORD); // eax
  DWORD v3; // edi
  BOOL i; // eax
  unsigned __int8 dst[536]; // [esp+10h] [ebp-3C8h] BYREF
  _DISPLAY_DEVICEA DisplayDevice; // [esp+228h] [ebp-1B0h] BYREF
  HMODULE hModule; // [esp+3D4h] [ebp-4h]

  hModule = LoadLibraryA("ddraw.dll");
  if ( hModule )
  {
    memset((int)dst, 0, sizeof(dst));
    *(_DWORD *)&dst[16] = hm;
    DirectDrawEnumerateExA = (HRESULT (__stdcall *)(LPDDENUMCALLBACKEXA, LPVOID, DWORD))GetProcAddress(
                                                                                          hModule,
                                                                                          "DirectDrawEnumerateExA");
    if ( DirectDrawEnumerateExA )
      DirectDrawEnumerateExA((LPDDENUMCALLBACKEXA)DDEnumCallbackEx, dst, 1);
    if ( dst[532] )
    {
      v3 = 0;
      memset((int)&DisplayDevice, 0, sizeof(DisplayDevice));
      DisplayDevice.cb = 424;
      for ( i = EnumDisplayDevicesA(0, 0, &DisplayDevice, 0); i; i = EnumDisplayDevicesA(0, v3, &DisplayDevice, 0) )
      {
        if ( (DisplayDevice.StateFlags & 8) == 0
          && (DisplayDevice.StateFlags & 1) != 0
          && !_stricmp((char *)&dst[20], DisplayDevice.DeviceName) )
        {
          MultiByteToWideChar(0, 0, DisplayDevice.DeviceID, -1, strDeviceID, 512);
          FreeLibrary(hModule);
          return 0;
        }
        ++v3;
      }
    }
    FreeLibrary(hModule);
  }
  return -2147467259;
}
