void __thiscall survarium::game_options::initialize_bindings(
        survarium::game_options *this,
        survarium::game_options *thisa)
{
  survarium::flash_movie_resource *m_object; // ecx
  survarium::action_type *p_type; // esi
  survarium::flash_movie_resource *v4; // ecx
  int v5; // edi
  int v6; // edi
  survarium::action_type v7; // edi
  int v8; // ecx
  survarium::game_options *v9; // ecx
  survarium::flash_value keybinds_value_prop; // [esp+80h] [ebp-464h] BYREF
  survarium::flash_value keybinds_value; // [esp+98h] [ebp-44Ch] BYREF
  int v12; // [esp+B0h] [ebp-434h]
  survarium::flash_value keybinds_array; // [esp+B4h] [ebp-430h] BYREF
  int v14; // [esp+CCh] [ebp-418h] BYREF
  int v15; // [esp+D0h] [ebp-414h]
  wchar_t *v16; // [esp+D4h] [ebp-410h]
  wchar_t label_txt[512]; // [esp+E4h] [ebp-400h] BYREF

  m_object = thisa->m_options_ui.m_object;
  *(_DWORD *)keybinds_array.body = 0;
  *(_DWORD *)&keybinds_array.body[4] = 0;
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&keybinds_array);
  *(_DWORD *)keybinds_value_prop.body = 0;
  *(_DWORD *)&keybinds_value_prop.body[4] = 0;
  p_type = &survarium::key_bind_descriptions[0].type;
  v12 = 33;
  do
  {
    v4 = thisa->m_options_ui.m_object;
    *(_DWORD *)keybinds_value.body = 0;
    *(_DWORD *)&keybinds_value.body[4] = 0;
    Scaleform::GFx::Movie::CreateObject(v4->movie->m_movie, (Scaleform::GFx::Value *)&keybinds_value, 0, 0, 0);
    v5 = *((_DWORD *)p_type - 3);
    if ( (keybinds_value_prop.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)keybinds_value_prop.body + 8))(
        *(_DWORD *)keybinds_value_prop.body,
        &keybinds_value_prop,
        *(_DWORD *)&keybinds_value_prop.body[8]);
      *(_DWORD *)keybinds_value_prop.body = 0;
    }
    *(_DWORD *)&keybinds_value_prop.body[4] = 4;
    *(_DWORD *)&keybinds_value_prop.body[8] = v5;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)keybinds_value.body
                                                                                         + 20))(
      *(_DWORD *)keybinds_value.body,
      *(_DWORD *)&keybinds_value.body[8],
      "action_id",
      &keybinds_value_prop,
      (keybinds_value.body[4] & 0x8F) == 10);
    v6 = *((_DWORD *)p_type - 1);
    if ( (keybinds_value_prop.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)keybinds_value_prop.body + 8))(
        *(_DWORD *)keybinds_value_prop.body,
        &keybinds_value_prop,
        *(_DWORD *)&keybinds_value_prop.body[8]);
      *(_DWORD *)keybinds_value_prop.body = 0;
    }
    *(_DWORD *)&keybinds_value_prop.body[4] = 4;
    *(_DWORD *)&keybinds_value_prop.body[8] = v6;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)keybinds_value.body
                                                                                         + 20))(
      *(_DWORD *)keybinds_value.body,
      *(_DWORD *)&keybinds_value.body[8],
      "group_id",
      &keybinds_value_prop,
      (keybinds_value.body[4] & 0x8F) == 10);
    v7 = *p_type;
    if ( (keybinds_value_prop.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)keybinds_value_prop.body + 8))(
        *(_DWORD *)keybinds_value_prop.body,
        &keybinds_value_prop,
        *(_DWORD *)&keybinds_value_prop.body[8]);
      *(_DWORD *)keybinds_value_prop.body = 0;
    }
    *(_DWORD *)&keybinds_value_prop.body[4] = 4;
    *(_DWORD *)&keybinds_value_prop.body[8] = v7;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)keybinds_value.body
                                                                                         + 20))(
      *(_DWORD *)keybinds_value.body,
      *(_DWORD *)&keybinds_value.body[8],
      "type",
      &keybinds_value_prop,
      (keybinds_value.body[4] & 0x8F) == 10);
    survarium::text_translator::translate_text(
      &thisa->m_game->m_text_translator,
      *((const char **)p_type - 2),
      label_txt);
    v8 = 0;
    v14 = 0;
    v15 = 7;
    v16 = label_txt;
    if ( (keybinds_value_prop.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)keybinds_value_prop.body + 8))(
        *(_DWORD *)keybinds_value_prop.body,
        &keybinds_value_prop,
        *(_DWORD *)&keybinds_value_prop.body[8]);
      v8 = v14;
      *(_DWORD *)keybinds_value_prop.body = 0;
    }
    *(_DWORD *)&keybinds_value_prop.body[4] = 7;
    *(_DWORD *)&keybinds_value_prop.body[8] = label_txt;
    if ( (v15 & 0x40) != 0 )
      (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v8 + 8))(v8, &v14, v16);
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)keybinds_value.body
                                                                                         + 20))(
      *(_DWORD *)keybinds_value.body,
      *(_DWORD *)&keybinds_value.body[8],
      "label",
      &keybinds_value_prop,
      (keybinds_value.body[4] & 0x8F) == 10);
    (*(void (__thiscall **)(_DWORD, _DWORD, survarium::flash_value *))(**(_DWORD **)keybinds_array.body + 60))(
      *(_DWORD *)keybinds_array.body,
      *(_DWORD *)&keybinds_array.body[8],
      &keybinds_value);
    if ( (keybinds_value.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)keybinds_value.body + 8))(
        *(_DWORD *)keybinds_value.body,
        &keybinds_value,
        *(_DWORD *)&keybinds_value.body[8]);
    p_type += 26;
    --v12;
  }
  while ( v12 );
  Scaleform::GFx::Movie::Invoke(
    thisa->m_options_ui.m_object->movie->m_movie,
    "root.set_keybindings",
    0,
    (const Scaleform::GFx::Value *)&keybinds_array,
    1u);
  survarium::game_options::reset_bindings(v9, thisa, 1);
  if ( (keybinds_value_prop.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)keybinds_value_prop.body + 8))(
      *(_DWORD *)keybinds_value_prop.body,
      &keybinds_value_prop,
      *(_DWORD *)&keybinds_value_prop.body[8]);
    *(_DWORD *)keybinds_value_prop.body = 0;
  }
  *(_DWORD *)&keybinds_value_prop.body[4] = 0;
  if ( (keybinds_array.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)keybinds_array.body + 8))(
      *(_DWORD *)keybinds_array.body,
      &keybinds_array,
      *(_DWORD *)&keybinds_array.body[8]);
}
