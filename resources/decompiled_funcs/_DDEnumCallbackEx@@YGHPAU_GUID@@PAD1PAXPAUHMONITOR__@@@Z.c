int __stdcall DDEnumCallbackEx(
        _GUID *lpGUID,
        char *lpDriverDescription,
        char *lpDriverName,
        _BYTE *lpContext,
        HMONITOR__ *hm)
{
  if ( *((HMONITOR__ **)lpContext + 4) == hm )
  {
    lpContext[532] = 1;
    strcpy_s(lpContext + 20, 0x200u, lpDriverName);
    *(_GUID *)lpContext = *lpGUID;
  }
  return 1;
}
