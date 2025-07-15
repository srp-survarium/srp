void __userpurge survarium::game_options::assign_binding(
        const char *key@<eax>,
        survarium::game_options *this,
        survarium::game_action_id action_id)
{
  unsigned __int8 v4; // bl
  survarium::key_bind_descr *v5; // eax
  vostok::buffer_string *p_new_binded_key; // esi
  survarium::flash_value *v7; // eax
  int i; // ecx
  survarium::text_translator *p_m_text_translator; // eax
  int v10; // ecx
  survarium::flash_movie_resource *m_object; // edx
  int *v12; // esi
  int j; // edi
  int v14; // ecx
  bool is_default; // [esp+21h] [ebp-46Dh]
  survarium::flash_value bind_value[3]; // [esp+22h] [ebp-46Ch] BYREF
  int v17; // [esp+6Ah] [ebp-424h] BYREF
  int v18; // [esp+72h] [ebp-41Ch] BYREF
  int v19; // [esp+76h] [ebp-418h]
  wchar_t *v20; // [esp+7Ah] [ebp-414h]
  wchar_t w_key_name_txt[514]; // [esp+8Ah] [ebp-404h] BYREF

  is_default = 0;
  v4 = 0;
  while ( 1 )
  {
    v5 = &survarium::key_bind_descriptions[v4];
    if ( v5->action_id == action_id )
      break;
LABEL_5:
    if ( ++v4 >= 0x21u )
      goto LABEL_8;
  }
  p_new_binded_key = &v5->new_binded_key;
  if ( strcmp(v5->new_binded_key.m_begin, key) )
  {
    vostok::buffer_string::assignf(p_new_binded_key, "%s", key);
    goto LABEL_5;
  }
  is_default = 1;
LABEL_8:
  v7 = bind_value;
  for ( i = 2; i >= 0; --i )
  {
    if ( v7 )
    {
      *(_DWORD *)v7->body = 0;
      *(_DWORD *)&v7->body[4] = 0;
    }
    ++v7;
  }
  if ( (bind_value[0].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)bind_value[0].body + 8))(
      *(_DWORD *)bind_value[0].body,
      bind_value,
      *(_DWORD *)&bind_value[0].body[8]);
    *(_DWORD *)bind_value[0].body = 0;
  }
  p_m_text_translator = &this->m_game->m_text_translator;
  *(_DWORD *)&bind_value[0].body[4] = 4;
  *(_DWORD *)&bind_value[0].body[8] = action_id;
  survarium::text_translator::translate_text(p_m_text_translator, key, w_key_name_txt);
  v10 = 0;
  v18 = 0;
  v19 = 7;
  v20 = w_key_name_txt;
  if ( (bind_value[1].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)bind_value[1].body + 8))(
      *(_DWORD *)bind_value[1].body,
      &bind_value[1],
      *(_DWORD *)&bind_value[1].body[8]);
    v10 = v18;
    *(_DWORD *)bind_value[1].body = 0;
  }
  *(_DWORD *)&bind_value[1].body[4] = 7;
  *(_DWORD *)&bind_value[1].body[8] = w_key_name_txt;
  if ( (v19 & 0x40) != 0 )
    (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v10 + 8))(v10, &v18, v20);
  if ( (bind_value[2].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)bind_value[2].body + 8))(
      *(_DWORD *)bind_value[2].body,
      &bind_value[2],
      *(_DWORD *)&bind_value[2].body[8]);
    *(_DWORD *)bind_value[2].body = 0;
  }
  m_object = this->m_options_ui.m_object;
  *(_DWORD *)&bind_value[2].body[4] = 2;
  bind_value[2].body[8] = is_default;
  Scaleform::GFx::Movie::Invoke(
    m_object->movie->m_movie,
    "root.set_keybind",
    0,
    (const Scaleform::GFx::Value *)bind_value,
    3u);
  v12 = &v17;
  for ( j = 2; j >= 0; --j )
  {
    v14 = *(v12 - 5);
    v12 -= 6;
    if ( (v14 & 0x40) != 0 )
    {
      (*(void (__stdcall **)(int *, int))(*(_DWORD *)*v12 + 8))(v12, v12[2]);
      *v12 = 0;
    }
    v12[1] = 0;
  }
}
