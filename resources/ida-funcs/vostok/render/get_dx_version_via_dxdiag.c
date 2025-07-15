unsigned int __cdecl vostok::render::get_dx_version_via_dxdiag(
        unsigned int *major_version,
        unsigned int *minor_version)
{
  char v2; // bl
  bool does_minor_version_obtained; // [esp+3Fh] [ebp-33h]
  bool does_dx_version_obtained; // [esp+40h] [ebp-32h]
  bool should_cleanup_COM; // [esp+41h] [ebp-31h]
  IDxDiagContainer *pDxDiagSystemInfo; // [esp+42h] [ebp-30h] BYREF
  IDxDiagProvider *dxdiag_provider; // [esp+46h] [ebp-2Ch] BYREF
  IDxDiagContainer *pDxDiagRoot; // [esp+4Ah] [ebp-28h] BYREF
  tagVARIANT var; // [esp+4Eh] [ebp-24h] BYREF
  _DXDIAG_INIT_PARAMS dxDiagInitParam; // [esp+5Eh] [ebp-14h] BYREF

  v2 = 0;
  does_minor_version_obtained = 0;
  should_cleanup_COM = CoInitialize(0) >= 0;
  does_dx_version_obtained = 0;
  dxdiag_provider = 0;
  if ( CoCreateInstance(&CLSID_DxDiagProvider, 0, 1u, &IID_IDxDiagProvider, (LPVOID *)&dxdiag_provider) >= 0 )
  {
    dxDiagInitParam.dwSize = 16;
    dxDiagInitParam.dwDxDiagHeaderVersion = 111;
    dxDiagInitParam.bAllowWHQLChecks = 0;
    dxDiagInitParam.pReserved = 0;
    if ( dxdiag_provider->Initialize(dxdiag_provider, &dxDiagInitParam) >= 0 )
    {
      pDxDiagRoot = 0;
      pDxDiagSystemInfo = 0;
      if ( dxdiag_provider->GetRootContainer(dxdiag_provider, &pDxDiagRoot) >= 0 )
      {
        if ( pDxDiagRoot->GetChildContainer(pDxDiagRoot, L"DxDiag_SystemInfo", &pDxDiagSystemInfo) >= 0 )
        {
          VariantInit(&var);
          if ( pDxDiagSystemInfo->GetPropA(pDxDiagSystemInfo, L"dwDirectXVersionMajor", &var) >= 0 && var.vt == 19 )
          {
            *major_version = var.decVal.Lo32;
            v2 = 1;
          }
          VariantClear(&var);
          if ( pDxDiagSystemInfo->GetPropA(pDxDiagSystemInfo, L"dwDirectXVersionMinor", &var) >= 0 && var.vt == 19 )
          {
            *minor_version = var.decVal.Lo32;
            does_minor_version_obtained = 1;
          }
          VariantClear(&var);
          if ( v2 && does_minor_version_obtained )
            does_dx_version_obtained = 1;
          pDxDiagSystemInfo->Release(pDxDiagSystemInfo);
        }
        pDxDiagRoot->Release(pDxDiagRoot);
      }
    }
    dxdiag_provider->Release(dxdiag_provider);
  }
  if ( should_cleanup_COM )
    CoUninitialize();
  return does_dx_version_obtained ? 0 : 0x80004005;
}
