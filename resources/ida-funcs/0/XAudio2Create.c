HRESULT __cdecl XAudio2Create(LPVOID *ppXAudio2, unsigned int Flags)
{
  GUID *v2; // eax
  HRESULT v3; // esi
  LPVOID ppv; // [esp+0h] [ebp-4h] BYREF

  v2 = &_GUID_db05ea35_0329_4d4b_a53a_6dead03d3852;
  if ( (Flags & 1) == 0 )
    v2 = &_GUID_5a508685_a254_4fba_9b82_9a24b00306af;
  v3 = CoCreateInstance(v2, 0, 1u, &_GUID_8bcf1f58_9fe7_4583_8ac6_e2adc465c8bb, &ppv);
  if ( v3 >= 0 )
  {
    v3 = (*(int (__stdcall **)(LPVOID, unsigned int, int))(*(_DWORD *)ppv + 20))(ppv, Flags, -1);
    if ( v3 < 0 )
      (*(void (__stdcall **)(LPVOID))(*(_DWORD *)ppv + 8))(ppv);
    else
      *ppXAudio2 = ppv;
  }
  return v3;
}
