bool __thiscall survarium::lobby_menu::is_mouse_over_ui(survarium::lobby_menu *this)
{
  survarium::flash_movie_resource *m_object; // ecx
  char v3; // bl
  bool v4; // bl
  survarium::flash_value is_mouse_over_val; // [esp+8h] [ebp-18h] BYREF

  m_object = this->m_lobby_menu_ui.m_object;
  *(_DWORD *)is_mouse_over_val.body = 0;
  *(_DWORD *)&is_mouse_over_val.body[4] = 0;
  Scaleform::GFx::Movie::Invoke(
    m_object->movie->m_movie,
    "root.get_mouse_over",
    (Scaleform::GFx::Value *)&is_mouse_over_val,
    0,
    0);
  v3 = is_mouse_over_val.body[8];
  Scaleform::GFx::Movie::Invoke(
    this->m_game->m_chat_handler->m_chat_ui.m_object->movie->m_movie,
    "root.get_mouse_over",
    (Scaleform::GFx::Value *)&is_mouse_over_val,
    0,
    0);
  v4 = v3 || is_mouse_over_val.body[8];
  if ( (is_mouse_over_val.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)is_mouse_over_val.body + 8))(
      *(_DWORD *)is_mouse_over_val.body,
      &is_mouse_over_val,
      *(_DWORD *)&is_mouse_over_val.body[8]);
  return v4;
}
