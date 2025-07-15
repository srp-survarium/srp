HRESULT __cdecl vostok::render::get_dx_version_via_dxdiag(unsigned int *major_version, unsigned int *minor_version)
{
  _DWORD v3[4]; // [esp+10h] [ebp-30h] BYREF
  VARIANTARG pvarg; // [esp+20h] [ebp-20h] BYREF
  int v5; // [esp+30h] [ebp-10h] BYREF
  LPVOID ppv; // [esp+34h] [ebp-Ch] BYREF
  int v7; // [esp+38h] [ebp-8h] BYREF
  bool v8; // [esp+3Ch] [ebp-4h]
  char v9; // [esp+3Dh] [ebp-3h]
  char v10; // [esp+3Eh] [ebp-2h]
  char v11; // [esp+3Fh] [ebp-1h]

  v11 = 0;
  v10 = 0;
  v8 = CoInitialize(0) >= 0;
  v9 = 0;
  ppv = 0;
  if ( CoCreateInstance(&CLSID_DxDiagProvider, 0, 1u, &IID_IDxDiagProvider, &ppv) >= 0 )
  {
    v3[0] = 16;
    v3[1] = 111;
    v3[2] = 0;
    v3[3] = 0;
    if ( (*(int (__stdcall **)(LPVOID, _DWORD *))(*(_DWORD *)ppv + 12))(ppv, v3) >= 0 )
    {
      v5 = 0;
      v7 = 0;
      if ( (*(int (__stdcall **)(LPVOID, int *))(*(_DWORD *)ppv + 16))(ppv, &v5) >= 0 )
      {
        if ( (*(int (__stdcall **)(int, const wchar_t *, int *))(*(_DWORD *)v5 + 20))(v5, L"DxDiag_SystemInfo", &v7) >= 0 )
        {
          VariantInit(&pvarg);
          if ( (*(int (__stdcall **)(int, const wchar_t *, VARIANTARG *))(*(_DWORD *)v7 + 32))(
                 v7,
                 L"dwDirectXVersionMajor",
                 &pvarg) >= 0
            && pvarg.vt == 19 )
          {
            *major_version = pvarg.decVal.Lo32;
            v11 = 1;
          }
          VariantClear(&pvarg);
          if ( (*(int (__stdcall **)(int, const wchar_t *, VARIANTARG *))(*(_DWORD *)v7 + 32))(
                 v7,
                 L"dwDirectXVersionMinor",
                 &pvarg) >= 0
            && pvarg.vt == 19 )
          {
            *minor_version = pvarg.decVal.Lo32;
            v10 = 1;
          }
          VariantClear(&pvarg);
          if ( v11 && v10 )
            v9 = 1;
          (*(void (__stdcall **)(int))(*(_DWORD *)v7 + 8))(v7);
        }
        (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
      }
    }
    (*(void (__stdcall **)(LPVOID))(*(_DWORD *)ppv + 8))(ppv);
  }
  if ( v8 )
    CoUninitialize();
  if ( v9 )
    return 0;
  else
    return -2147467259;
}
