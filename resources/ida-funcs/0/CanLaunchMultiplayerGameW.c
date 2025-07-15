int __cdecl CanLaunchMultiplayerGameW(wchar_t *strGameExeFullPath)
{
  wchar_t *v2; // edi
  INetFwProfile *FirewallProfile; // eax
  INetFwProfile *v4; // esi
  int v5; // [esp+4h] [ebp-18h] BYREF
  int v6; // [esp+8h] [ebp-14h] BYREF
  int v7; // [esp+Ch] [ebp-10h] BYREF
  __int16 v8; // [esp+10h] [ebp-Ch] BYREF
  __int16 v9[3]; // [esp+14h] [ebp-8h] BYREF
  unsigned __int8 v10; // [esp+1Bh] [ebp-1h]
  bool psz_3; // [esp+27h] [ebp+Bh]

  v10 = 1;
  v5 = 0;
  v7 = 0;
  v6 = 0;
  if ( !strGameExeFullPath )
    return 0;
  v2 = SysAllocString(strGameExeFullPath);
  if ( !v2 )
    return 0;
  psz_3 = CoInitialize(0) >= 0;
  FirewallProfile = GetFirewallProfile();
  v4 = FirewallProfile;
  if ( FirewallProfile
    && FirewallProfile->get_FirewallEnabled(FirewallProfile, v9) >= 0
    && v9[0]
    && (v4->get_ExceptionsNotAllowed(v4, (__int16 *)&v5) < 0 || !(_WORD)v5)
    && v4->get_AuthorizedApplications(v4, (INetFwAuthorizedApplications **)&v6) >= 0
    && (*(int (__stdcall **)(int, wchar_t *, int *))(*(_DWORD *)v6 + 40))(v6, v2, &v7) >= 0
    && (*(int (__stdcall **)(int, __int16 *))(*(_DWORD *)v7 + 68))(v7, &v8) >= 0
    && !v8 )
  {
    v10 = 0;
  }
  if ( v7 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v7 + 8))(v7);
  if ( v6 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
  if ( psz_3 )
    CoUninitialize();
  SysFreeString(v2);
  return v10;
}
