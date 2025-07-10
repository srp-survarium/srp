void __thiscall survarium::game_world_ui::set_broken_connection_message(
        survarium::game_world_ui *this,
        survarium::game_world_ui *str)
{
  survarium::flash_movie_resource *m_object; // ecx
  survarium::flash_value message_val[2]; // [esp+10h] [ebp-430h] BYREF
  wchar_t w_message[512]; // [esp+40h] [ebp-400h] BYREF

  if ( str->m_game_hud_ui.m_object )
  {
    survarium::text_translator::translate_text(
      &str->m_game_world->m_game->m_text_translator,
      "match server connection lost",
      w_message);
    `vector constructor iterator'(
      message_val[0].body,
      0x18u,
      2,
      (void *(__thiscall *)(void *))survarium::flash_value::flash_value);
    survarium::flash_value::SetStringW(message_val, w_message);
    if ( (message_val[1].body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)message_val[1].body + 8))(
        *(_DWORD *)message_val[1].body,
        &message_val[1],
        *(_DWORD *)&message_val[1].body[8]);
      *(_DWORD *)message_val[1].body = 0;
    }
    m_object = str->m_game_hud_ui.m_object;
    *(_DWORD *)&message_val[1].body[4] = 3;
    *(_DWORD *)&message_val[1].body[8] = 1000;
    Scaleform::GFx::Movie::Invoke(
      m_object->movie->m_movie,
      "root.set_warning_message",
      0,
      (const Scaleform::GFx::Value *)message_val,
      2u);
    `vector destructor iterator'(
      message_val[0].body,
      0x18u,
      2,
      (void (__thiscall *)(void *))survarium::flash_value::~flash_value);
  }
}
