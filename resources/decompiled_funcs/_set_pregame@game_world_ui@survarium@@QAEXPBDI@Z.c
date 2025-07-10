void __thiscall survarium::game_world_ui::set_pregame(
        survarium::game_world_ui *this,
        survarium::game_world_ui *str,
        const char *time_left,
        unsigned int time_lefta)
{
  survarium::flash_value message_val; // [esp+10h] [ebp-818h] BYREF
  wchar_t message[512]; // [esp+28h] [ebp-800h] BYREF
  wchar_t buff[512]; // [esp+428h] [ebp-400h] BYREF

  survarium::text_translator::translate_text(&str->m_game_world->m_game->m_text_translator, time_left, message);
  swprintf(
    0x200u,
    (unsigned int)time_left,
    time_lefta / 0x3C,
    buff,
    L"%s %02d : %02d",
    message,
    time_lefta / 0x3C,
    time_lefta % 0x3C);
  *(_DWORD *)message_val.body = 0;
  *(_DWORD *)&message_val.body[4] = 0;
  survarium::flash_value::SetStringW(&message_val, buff);
  Scaleform::GFx::Movie::Invoke(
    str->m_game_hud_ui.m_object->movie->m_movie,
    "root.set_pregame",
    0,
    (const Scaleform::GFx::Value *)&message_val,
    1u);
  if ( (message_val.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)message_val.body + 8))(
      *(_DWORD *)message_val.body,
      &message_val,
      *(_DWORD *)&message_val.body[8]);
}
