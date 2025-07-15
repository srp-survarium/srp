HRESULT __usercall GetVideoMemoryViaDirectDraw@<eax>(unsigned __int64 *pdwAvailableVidMem@<esi>, HMONITOR__ *hMonitor)
{
  HRESULT (__stdcall *DirectDrawEnumerateExA)(LPDDENUMCALLBACKEXA, LPVOID, DWORD); // eax
  HRESULT (__stdcall *DirectDrawCreate)(GUID *, LPDIRECTDRAW *, IUnknown *); // eax
  int v4; // eax
  unsigned __int8 dst[540]; // [esp+8h] [ebp-244h] BYREF
  _DWORD v7[4]; // [esp+224h] [ebp-28h] BYREF
  unsigned int v8; // [esp+234h] [ebp-18h] BYREF
  int (__stdcall ***v9)(_DWORD, GUID *, int *); // [esp+238h] [ebp-14h] BYREF
  int v10; // [esp+23Ch] [ebp-10h] BYREF
  HMODULE hModule; // [esp+240h] [ebp-Ch]
  char v12; // [esp+247h] [ebp-5h]

  v9 = 0;
  v12 = 0;
  *pdwAvailableVidMem = 0;
  hModule = LoadLibraryA("ddraw.dll");
  if ( !hModule )
    return -2147467259;
  memset((int)dst, 0, 0x218u);
  *(_DWORD *)&dst[16] = hMonitor;
  DirectDrawEnumerateExA = (HRESULT (__stdcall *)(LPDDENUMCALLBACKEXA, LPVOID, DWORD))GetProcAddress(
                                                                                        hModule,
                                                                                        "DirectDrawEnumerateExA");
  if ( DirectDrawEnumerateExA )
    DirectDrawEnumerateExA((LPDDENUMCALLBACKEXA)DDEnumCallbackEx, dst, 1);
  DirectDrawCreate = (HRESULT (__stdcall *)(GUID *, LPDIRECTDRAW *, IUnknown *))GetProcAddress(
                                                                                  hModule,
                                                                                  "DirectDrawCreate");
  if ( DirectDrawCreate )
  {
    DirectDrawCreate((GUID *)dst, (LPDIRECTDRAW *)&v9, 0);
    if ( (**v9)(v9, &IID_IDirectDraw7, &v10) >= 0 )
    {
      memset(&v7[1], 0, 12);
      v7[0] = 268451840;
      v4 = (*(int (__stdcall **)(int, _DWORD *, unsigned int *, _DWORD))(*(_DWORD *)v10 + 92))(v10, v7, &v8, 0);
      *pdwAvailableVidMem = v8;
      if ( v4 >= 0 )
        v12 = 1;
      (*(void (__stdcall **)(int))(*(_DWORD *)v10 + 8))(v10);
    }
  }
  FreeLibrary(hModule);
  if ( v12 )
    return 0;
  else
    return -2147467259;
}
