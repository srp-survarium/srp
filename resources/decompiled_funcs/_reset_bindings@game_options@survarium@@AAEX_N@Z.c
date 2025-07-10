void __thiscall survarium::game_options::reset_bindings(
        survarium::game_options *this,
        survarium::game_options *is_default,
        bool is_defaulta)
{
  survarium::game_action_id action_id; // ebx
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  const char *v10; // edi
  survarium::flash_value *v11; // eax
  int i; // ecx
  const char **p_m_begin; // ebx
  survarium::keyboard_key_descr *v14; // ecx
  char *v15; // esi
  int j; // ebx
  int v17; // ecx
  const char *v18; // [esp+0h] [ebp-46Ch]
  survarium::key_bind_descr *v19; // [esp+10h] [ebp-45Ch]
  int v20; // [esp+14h] [ebp-458h]
  const char *key_name; // [esp+18h] [ebp-454h]
  survarium::flash_value bind_value[3]; // [esp+1Ch] [ebp-450h] BYREF
  char v23; // [esp+64h] [ebp-408h] BYREF
  wchar_t w_key_name_txt[512]; // [esp+6Ch] [ebp-400h] BYREF

  v19 = survarium::key_bind_descriptions;
  v20 = 33;
  do
  {
    action_id = v19->action_id;
    v4 = (int)&is_default->m_game->m_key_binder->m_key_bindings[v19->action_id];
    v5 = *(_DWORD *)(v4 + 4);
    if ( v5 )
    {
      v6 = *(_DWORD *)(v5 + 4);
    }
    else
    {
      v7 = *(_DWORD *)(v4 + 8);
      if ( v7 )
        v6 = *(_DWORD *)(v7 + 4);
      else
        v6 = 0;
    }
    v8 = 0;
    if ( !survarium::keyboards[0].key_name )
      goto LABEL_11;
    v9 = 0;
    while ( dword_9C4224[v9] != v6 )
    {
      ++v8;
      v9 = 34 * v8;
      if ( !survarium::keyboards[v8].key_name )
        goto LABEL_11;
    }
    v14 = &survarium::keyboards[v8];
    if ( v14 )
    {
      v10 = v14->key_name;
      key_name = v14->key_name;
    }
    else
    {
LABEL_11:
      key_name = 0;
      v10 = 0;
    }
    v11 = bind_value;
    for ( i = 2; i >= 0; --i )
    {
      if ( v11 )
      {
        *(_DWORD *)v11->body = 0;
        *(_DWORD *)&v11->body[4] = 0;
      }
      ++v11;
    }
    if ( (bind_value[0].body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)bind_value[0].body + 8))(
        *(_DWORD *)bind_value[0].body,
        bind_value,
        *(_DWORD *)&bind_value[0].body[8]);
      *(_DWORD *)bind_value[0].body = 0;
    }
    *(_DWORD *)&bind_value[0].body[4] = 4;
    *(_DWORD *)&bind_value[0].body[8] = action_id;
    if ( v10 )
    {
      survarium::text_translator::translate_text(&is_default->m_game->m_text_translator, v10, w_key_name_txt);
      survarium::flash_value::SetStringW(&bind_value[1], w_key_name_txt);
      p_m_begin = (const char **)&v19->old_binded_key.m_begin;
      vostok::buffer_string::assignf(&v19->old_binded_key, "%s", key_name);
    }
    else
    {
      p_m_begin = (const char **)&v19->old_binded_key.m_begin;
      vostok::buffer_string::assignf(&v19->old_binded_key, "%s", (const char *)&buf);
      survarium::flash_value::SetStringW(&bind_value[1], &word_96B534);
    }
    if ( (bind_value[2].body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)bind_value[2].body + 8))(
        *(_DWORD *)bind_value[2].body,
        &bind_value[2],
        *(_DWORD *)&bind_value[2].body[8]);
      *(_DWORD *)bind_value[2].body = 0;
    }
    v18 = *p_m_begin;
    *(_DWORD *)&bind_value[2].body[4] = 2;
    bind_value[2].body[8] = is_defaulta;
    vostok::buffer_string::assignf(&v19->new_binded_key, "%s", v18);
    Scaleform::GFx::Movie::Invoke(
      is_default->m_options_ui.m_object->movie->m_movie,
      "root.set_keybind",
      0,
      (const Scaleform::GFx::Value *)bind_value,
      3u);
    v15 = &v23;
    for ( j = 2; j >= 0; --j )
    {
      v17 = *((_DWORD *)v15 - 5);
      v15 -= 24;
      if ( (v17 & 0x40) != 0 )
      {
        (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v15 + 8))(v15, *((_DWORD *)v15 + 2));
        *(_DWORD *)v15 = 0;
      }
      *((_DWORD *)v15 + 1) = 0;
    }
    ++v19;
    --v20;
  }
  while ( v20 );
}
