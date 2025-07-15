void __fastcall survarium::game_world_ui::set_using_info_message(
        int a1,
        const char *str,
        survarium::game_world_ui *this)
{
  survarium::flash_value *v3; // eax
  int i; // ecx
  survarium::flash_movie_resource *m_object; // ecx
  char *v6; // esi
  int j; // edi
  int v8; // eax
  survarium::flash_value message_val[3]; // [esp+10h] [ebp-450h] BYREF
  char v10; // [esp+58h] [ebp-408h] BYREF
  wchar_t message[512]; // [esp+60h] [ebp-400h] BYREF

  survarium::text_translator::translate_text(&this->m_game_world->m_game->m_text_translator, str, message);
  v3 = message_val;
  for ( i = 2; i >= 0; --i )
  {
    if ( v3 )
    {
      *(_DWORD *)v3->body = 0;
      *(_DWORD *)&v3->body[4] = 0;
    }
    ++v3;
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
  *(_DWORD *)&message_val[1].body[4] = 3;
  *(_DWORD *)&message_val[1].body[8] = 0;
  if ( (message_val[2].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)message_val[2].body + 8))(
      *(_DWORD *)message_val[2].body,
      &message_val[2],
      *(_DWORD *)&message_val[2].body[8]);
    *(_DWORD *)message_val[2].body = 0;
  }
  m_object = this->m_game_hud_ui.m_object;
  *(_DWORD *)&message_val[2].body[4] = 3;
  *(_DWORD *)&message_val[2].body[8] = 1000;
  Scaleform::GFx::Movie::Invoke(
    m_object->movie->m_movie,
    "root.set_context",
    0,
    (const Scaleform::GFx::Value *)message_val,
    3u);
  v6 = &v10;
  for ( j = 2; j >= 0; --j )
  {
    v8 = *((_DWORD *)v6 - 5);
    v6 -= 24;
    if ( (v8 & 0x40) != 0 )
    {
      (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v6 + 8))(v6, *((_DWORD *)v6 + 2));
      *(_DWORD *)v6 = 0;
    }
    *((_DWORD *)v6 + 1) = 0;
  }
}
