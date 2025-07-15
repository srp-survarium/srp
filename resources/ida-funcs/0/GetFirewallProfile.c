INetFwProfile *__cdecl GetFirewallProfile()
{
  int v1; // [esp+0h] [ebp-Ch] BYREF
  LPVOID ppv; // [esp+4h] [ebp-8h] BYREF
  int v3; // [esp+8h] [ebp-4h] BYREF

  ppv = 0;
  v3 = 0;
  v1 = 0;
  if ( CoCreateInstance(
         &_GUID_304ce942_6e39_40d8_943a_b913c40c9cd4,
         0,
         1u,
         &_GUID_f7898af5_cac4_4632_a2ec_da06e5111af2,
         &ppv) >= 0
    && (*(int (__stdcall **)(LPVOID, int *))(*(_DWORD *)ppv + 28))(ppv, &v3) >= 0 )
  {
    (*(void (__stdcall **)(int, int *))(*(_DWORD *)v3 + 28))(v3, &v1);
  }
  if ( v3 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
  if ( ppv )
    (*(void (__stdcall **)(LPVOID))(*(_DWORD *)ppv + 8))(ppv);
  return (INetFwProfile *)v1;
}
