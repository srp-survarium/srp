HRESULT __cdecl GetVideoMemoryViaWMI(HMONITOR__ *hMonitor, unsigned __int64 *pdwAdapterRam)
{
  HMODULE LibraryW; // eax
  HMODULE v3; // edi
  HRESULT (__stdcall *CoSetProxyBlanket)(IUnknown *, DWORD, DWORD, OLECHAR *, DWORD, DWORD, RPC_AUTH_IDENTITY_HANDLE, DWORD); // eax
  int v5; // edi
  wchar_t *v6; // esi
  unsigned int i; // edi
  _DWORD *v8; // esi
  wchar_t wcs2[512]; // [esp+10h] [ebp-460h] BYREF
  _DWORD v11[10]; // [esp+410h] [ebp-60h] BYREF
  VARIANTARG pvarg; // [esp+438h] [ebp-38h] BYREF
  HRESULT v13; // [esp+44Ch] [ebp-24h]
  BSTR v14; // [esp+450h] [ebp-20h]
  BSTR v15; // [esp+454h] [ebp-1Ch]
  BSTR bstrString; // [esp+458h] [ebp-18h]
  int v17; // [esp+45Ch] [ebp-14h] BYREF
  unsigned int v18; // [esp+460h] [ebp-10h] BYREF
  LPVOID ppv; // [esp+464h] [ebp-Ch] BYREF
  IUnknown *v20; // [esp+468h] [ebp-8h] BYREF
  char v21; // [esp+46Eh] [ebp-2h]
  char v22; // [esp+46Fh] [ebp-1h]

  GetDeviceIDFromHMonitor(hMonitor, wcs2);
  v21 = 0;
  ppv = 0;
  v20 = 0;
  *pdwAdapterRam = 0;
  v13 = CoInitializeEx(0, 2u);
  if ( CoCreateInstance(&CLSID_WbemLocator, 0, 1u, &IID_IWbemLocator, &ppv) >= 0 )
  {
    if ( !ppv )
      goto LABEL_39;
    v14 = SysAllocString(L"\\\\.\\root\\cimv2");
    if ( (*(int (__stdcall **)(LPVOID, BSTR, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, IUnknown **))(*(_DWORD *)ppv + 12))(
           ppv,
           v14,
           0,
           0,
           0,
           0,
           0,
           0,
           &v20) >= 0
      && v20 )
    {
      LibraryW = LoadLibraryW(L"ole32.dll");
      v3 = LibraryW;
      if ( LibraryW )
      {
        CoSetProxyBlanket = (HRESULT (__stdcall *)(IUnknown *, DWORD, DWORD, OLECHAR *, DWORD, DWORD, RPC_AUTH_IDENTITY_HANDLE, DWORD))GetProcAddress(LibraryW, "CoSetProxyBlanket");
        if ( CoSetProxyBlanket )
          CoSetProxyBlanket(v20, 10, 0, 0, 3, 3, 0, 0);
        FreeLibrary(v3);
      }
      v17 = 0;
      v15 = SysAllocString(L"Win32_VideoController");
      if ( ((int (__stdcall *)(IUnknown *, BSTR, _DWORD, _DWORD, int *))v20->lpVtbl[6].QueryInterface)(
             v20,
             v15,
             0,
             0,
             &v17) >= 0 )
      {
        if ( v17 )
        {
          memset(v11, 0, sizeof(v11));
          v18 = 0;
          (*(void (__stdcall **)(int))(*(_DWORD *)v17 + 12))(v17);
          if ( (*(int (__stdcall **)(int, int, int, _DWORD *, unsigned int *))(*(_DWORD *)v17 + 16))(
                 v17,
                 5000,
                 10,
                 v11,
                 &v18) >= 0 )
          {
            v5 = 0;
            v22 = 0;
            if ( v18 )
            {
              while ( 1 )
              {
                bstrString = SysAllocString(L"PNPDeviceID");
                if ( (*(int (__stdcall **)(_DWORD, BSTR, _DWORD, VARIANTARG *, _DWORD, _DWORD))(*(_DWORD *)v11[v5] + 16))(
                       v11[v5],
                       bstrString,
                       0,
                       &pvarg,
                       0,
                       0) >= 0
                  && wcsstr(pvarg.bstrVal, wcs2) )
                {
                  v22 = 1;
                }
                VariantClear(&pvarg);
                if ( bstrString )
                  SysFreeString(bstrString);
                if ( v22 )
                  break;
                if ( ++v5 >= v18 )
                  goto LABEL_25;
              }
              v6 = SysAllocString(L"AdapterRAM");
              if ( (*(int (__stdcall **)(_DWORD, wchar_t *, _DWORD, VARIANTARG *, _DWORD, _DWORD))(*(_DWORD *)v11[v5]
                                                                                                 + 16))(
                     v11[v5],
                     v6,
                     0,
                     &pvarg,
                     0,
                     0) >= 0 )
              {
                v21 = 1;
                *pdwAdapterRam = pvarg.decVal.Lo32;
              }
              VariantClear(&pvarg);
              if ( v6 )
                SysFreeString(v6);
            }
LABEL_25:
            for ( i = 0; i < v18; ++i )
            {
              v8 = &v11[i];
              if ( *v8 )
              {
                (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v8 + 8))(*v8);
                *v8 = 0;
              }
            }
          }
        }
      }
      if ( v15 )
        SysFreeString(v15);
      if ( v17 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v17 + 8))(v17);
    }
    if ( v14 )
      SysFreeString(v14);
    if ( v20 )
    {
      v20->Release(v20);
      v20 = 0;
    }
  }
  if ( ppv )
  {
    (*(void (__stdcall **)(LPVOID))(*(_DWORD *)ppv + 8))(ppv);
    ppv = 0;
  }
LABEL_39:
  if ( v13 >= 0 )
    CoUninitialize();
  if ( v21 )
    return 0;
  else
    return -2147467259;
}
