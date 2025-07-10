void __userpurge survarium::game_world_ui::show_parametrized_message(
        const char *message_id@<edx>,
        survarium::game_world_ui *this,
        unsigned __int8 font_size,
        unsigned __int8 y_pos_in_percents,
        unsigned int timeout_in_ms)
{
  survarium::flash_value *v5; // eax
  int i; // ecx
  survarium::flash_movie_resource *m_object; // ecx
  char *v8; // esi
  int j; // edi
  int v10; // eax
  survarium::flash_value message_val[4]; // [esp+18h] [ebp-468h] BYREF
  char v12; // [esp+78h] [ebp-408h] BYREF
  wchar_t message[512]; // [esp+80h] [ebp-400h] BYREF

  survarium::text_translator::translate_text(&this->m_game_world->m_game->m_text_translator, message_id, message);
  v5 = message_val;
  for ( i = 3; i >= 0; --i )
  {
    if ( v5 )
    {
      *(_DWORD *)v5->body = 0;
      *(_DWORD *)&v5->body[4] = 0;
    }
    ++v5;
  }
  survarium::flash_value::SetStringW(message_val, message);
  if ( (message_val[1].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)message_val[1].body + 8))(
      *(_DWORD *)message_val[1].body,
      &message_val[1],
      *(_DWORD *)&message_val[1].body[8]);
    *(_DWORD *)message_val[1].body = 0;
  }
  *(_DWORD *)&message_val[1].body[4] = 4;
  *(_DWORD *)&message_val[1].body[8] = 25;
  if ( (message_val[2].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)message_val[2].body + 8))(
      *(_DWORD *)message_val[2].body,
      &message_val[2],
      *(_DWORD *)&message_val[2].body[8]);
    *(_DWORD *)message_val[2].body = 0;
  }
  *(_DWORD *)&message_val[2].body[4] = 4;
  *(_DWORD *)&message_val[2].body[8] = 20;
  if ( (message_val[3].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)message_val[3].body + 8))(
      *(_DWORD *)message_val[3].body,
      &message_val[3],
      *(_DWORD *)&message_val[3].body[8]);
    *(_DWORD *)message_val[3].body = 0;
  }
  m_object = this->m_game_hud_ui.m_object;
  *(_DWORD *)&message_val[3].body[4] = 4;
  *(_DWORD *)&message_val[3].body[8] = 3000;
  Scaleform::GFx::Movie::Invoke(
    m_object->movie->m_movie,
    "root.set_parameterized_message",
    0,
    (const Scaleform::GFx::Value *)message_val,
    4u);
  v8 = &v12;
  for ( j = 3; j >= 0; --j )
  {
    v10 = *((_DWORD *)v8 - 5);
    v8 -= 24;
    if ( (v10 & 0x40) != 0 )
    {
      (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v8 + 8))(v8, *((_DWORD *)v8 + 2));
      *(_DWORD *)v8 = 0;
    }
    *((_DWORD *)v8 + 1) = 0;
  }
}
