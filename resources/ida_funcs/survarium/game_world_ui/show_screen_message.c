void __fastcall survarium::game_world_ui::show_screen_message(
        int a1,
        const char *message_id,
        survarium::game_world_ui *this)
{
  survarium::flash_value message_val; // [esp+10h] [ebp-418h] BYREF
  wchar_t message[512]; // [esp+28h] [ebp-400h] BYREF

  survarium::text_translator::translate_text(&this->m_game_world->m_game->m_text_translator, message_id, message);
  *(_DWORD *)message_val.body = 0;
  *(_DWORD *)&message_val.body[4] = 0;
  survarium::flash_value::SetStringW(&message_val, message);
  Scaleform::GFx::Movie::Invoke(
    this->m_game_hud_ui.m_object->movie->m_movie,
    "root.set_context_message",
    0,
    (const Scaleform::GFx::Value *)&message_val,
    1u);
  if ( (message_val.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)message_val.body + 8))(
      *(_DWORD *)message_val.body,
      &message_val,
      *(_DWORD *)&message_val.body[8]);
}
