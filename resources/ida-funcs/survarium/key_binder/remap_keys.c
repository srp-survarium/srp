void __thiscall survarium::key_binder::remap_keys(survarium::key_binder *this, int a2)
{
  int v2; // edi
  survarium::keyboard_key_descr *v3; // esi
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  bool v7; // zf
  char *key_name; // eax
  _BYTE v9[128]; // [esp+4h] [ebp-80h] BYREF

  v2 = 0;
  if ( survarium::keyboards[0].key_name )
  {
    v3 = survarium::keyboards;
    do
    {
      v4 = *(_DWORD *)(a2 + 864);
      v9[0] = 0;
      v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 48))(v4);
      v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 36))(v5);
      v7 = (*(unsigned __int8 (__thiscall **)(int, int, _BYTE *, int))(*(_DWORD *)v6 + 4))(v6, v3->dik, v9, 128) == 0;
      key_name = v9;
      if ( v7 )
        key_name = (char *)v3->key_name;
      vostok::strings::copy<128>((char (*)[128])v3->key_local_name, key_name);
      v3 = &survarium::keyboards[++v2];
    }
    while ( v3->key_name );
  }
}
