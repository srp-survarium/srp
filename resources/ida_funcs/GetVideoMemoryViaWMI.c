unsigned int __cdecl GetVideoMemoryViaWMI(unsigned __int64 *pdwAdapterRam)
{
  HMONITOR__ *hMonitor; // ecx
  wchar_t *v2; // edi
  HRESULT (__stdcall *ConnectServer)(IWbemLocator *, wchar_t *const, wchar_t *const, wchar_t *const, wchar_t *const, int, wchar_t *const, IWbemContext *, IWbemServices **); // eax
  HMODULE LibraryW; // eax
  HMODULE v5; // esi
  FARPROC ProcAddress; // eax
  wchar_t *v7; // esi
  HRESULT (__stdcall *CreateInstanceEnum)(IWbemServices *, wchar_t *const, int, IWbemContext *, IEnumWbemClassObject **); // edx
  IEnumWbemClassObject *v9; // eax
  int v10; // edi
  wchar_t *v11; // esi
  wchar_t *v12; // esi
  unsigned int i; // esi
  IWbemClassObject *v14; // eax
  bool bGotMemory; // [esp+B0h] [ebp-456h]
  bool bFound; // [esp+B1h] [ebp-455h]
  IEnumWbemClassObject *pEnumVideoControllers; // [esp+B2h] [ebp-454h] BYREF
  IWbemServices *pIWbemServices; // [esp+B6h] [ebp-450h] BYREF
  IWbemLocator *pIWbemLocator; // [esp+BAh] [ebp-44Ch] BYREF
  unsigned int uReturned; // [esp+BEh] [ebp-448h] BYREF
  wchar_t *pClassName; // [esp+C2h] [ebp-444h]
  wchar_t *pNamespace; // [esp+C6h] [ebp-440h]
  HRESULT hrCoInitialize; // [esp+CAh] [ebp-43Ch]
  tagVARIANT var; // [esp+CEh] [ebp-438h] BYREF
  IWbemClassObject *pVideoControllers[10]; // [esp+DEh] [ebp-428h] BYREF
  wchar_t strInputDeviceID[512]; // [esp+106h] [ebp-400h] BYREF

  GetDeviceIDFromHMonitor(hMonitor, strInputDeviceID);
  bGotMemory = 0;
  pIWbemLocator = 0;
  pIWbemServices = 0;
  *pdwAdapterRam = 0;
  hrCoInitialize = CoInitializeEx(0, 2u);
  if ( CoCreateInstance(&CLSID_WbemLocator, 0, 1u, &IID_IWbemLocator, (LPVOID *)&pIWbemLocator) >= 0 )
  {
    if ( !pIWbemLocator )
      goto LABEL_41;
    v2 = SysAllocString((const OLECHAR *)&stru_95DC74.m_buffer[88]);
    ConnectServer = pIWbemLocator->ConnectServer;
    pNamespace = v2;
    if ( ConnectServer(pIWbemLocator, v2, 0, 0, 0, 0, 0, 0, &pIWbemServices) < 0 || !pIWbemServices )
      goto LABEL_35;
    LibraryW = LoadLibraryW((LPCWSTR)&stru_95DC74.m_buffer[120]);
    v5 = LibraryW;
    if ( LibraryW )
    {
      ProcAddress = GetProcAddress(LibraryW, &stru_95DC74.m_buffer[140]);
      if ( ProcAddress )
        ((void (__stdcall *)(IWbemServices *, int, _DWORD, _DWORD, int, int, _DWORD, _DWORD))ProcAddress)(
          pIWbemServices,
          10,
          0,
          0,
          3,
          3,
          0,
          0);
      FreeLibrary(v5);
    }
    pEnumVideoControllers = 0;
    v7 = SysAllocString((const OLECHAR *)&stru_95DC74.m_buffer[160]);
    CreateInstanceEnum = pIWbemServices->CreateInstanceEnum;
    pClassName = v7;
    if ( CreateInstanceEnum(pIWbemServices, v7, 0, 0, &pEnumVideoControllers) >= 0 )
    {
      v9 = pEnumVideoControllers;
      if ( !pEnumVideoControllers )
      {
LABEL_31:
        if ( v7 )
        {
          SysFreeString(v7);
          v9 = pEnumVideoControllers;
        }
        if ( v9 )
          v9->Release(v9);
LABEL_35:
        if ( v2 )
          SysFreeString(v2);
        if ( pIWbemServices )
        {
          pIWbemServices->Release(pIWbemServices);
          pIWbemServices = 0;
        }
        goto LABEL_39;
      }
      memset(pVideoControllers, 0, sizeof(pVideoControllers));
      uReturned = 0;
      pEnumVideoControllers->Reset(pEnumVideoControllers);
      if ( pEnumVideoControllers->Next(pEnumVideoControllers, 5000, 10u, pVideoControllers, &uReturned) >= 0 )
      {
        v10 = 0;
        bFound = 0;
        if ( uReturned )
        {
          while ( 1 )
          {
            v11 = SysAllocString((const OLECHAR *)&stru_95DC74.m_buffer[204]);
            if ( pVideoControllers[v10]->Get(pVideoControllers[v10], v11, 0, &var, 0, 0) >= 0
              && wcsstr(var.bstrVal, strInputDeviceID) )
            {
              bFound = 1;
            }
            VariantClear(&var);
            if ( v11 )
              SysFreeString(v11);
            if ( bFound )
              break;
            if ( ++v10 >= uReturned )
              goto LABEL_25;
          }
          v12 = SysAllocString((const OLECHAR *)&stru_95DC74.m_buffer[228]);
          if ( pVideoControllers[v10]->Get(pVideoControllers[v10], v12, 0, &var, 0, 0) >= 0 )
          {
            bGotMemory = 1;
            *pdwAdapterRam = var.decVal.Lo32;
          }
          VariantClear(&var);
          if ( v12 )
            SysFreeString(v12);
        }
LABEL_25:
        for ( i = 0; i < uReturned; ++i )
        {
          v14 = pVideoControllers[i];
          if ( v14 )
          {
            v14->Release(pVideoControllers[i]);
            pVideoControllers[i] = 0;
          }
        }
        v2 = pNamespace;
        v7 = pClassName;
      }
    }
    v9 = pEnumVideoControllers;
    goto LABEL_31;
  }
LABEL_39:
  if ( pIWbemLocator )
  {
    pIWbemLocator->Release(pIWbemLocator);
    pIWbemLocator = 0;
  }
LABEL_41:
  if ( hrCoInitialize >= 0 )
    CoUninitialize();
  return bGotMemory ? 0 : 0x80004005;
}
