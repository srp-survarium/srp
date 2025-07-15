void __thiscall survarium::key_binder::remap_keys(survarium::key_binder *this, survarium::key_binder *thisa)
{
  int v2; // edi
  survarium::keyboard_key_descr *v3; // esi
  survarium::game *m_game; // ecx
  int v5; // eax
  int v6; // eax
  bool v7; // zf
  char *key_name; // eax
  char buff[128]; // [esp+Ch] [ebp-80h] BYREF

  v2 = 0;
  if ( survarium::keyboards[0].key_name )
  {
    v3 = survarium::keyboards;
    do
    {
      m_game = thisa->m_game;
      buff[0] = 0;
      v5 = (int)m_game->input_world(m_game);
      v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 36))(v5);
      v7 = (*(unsigned __int8 (__thiscall **)(int, int, char *, int))(*(_DWORD *)v6 + 4))(v6, v3->dik, buff, 128) == 0;
      key_name = buff;
      if ( v7 )
        key_name = (char *)v3->key_name;
      strcpy_s(v3->key_local_name, 0x80u, key_name);
      v3 = &survarium::keyboards[++v2];
    }
    while ( v3->key_name );
  }
}
