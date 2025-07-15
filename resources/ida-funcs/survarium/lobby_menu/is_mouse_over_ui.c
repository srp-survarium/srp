char __thiscall survarium::lobby_menu::is_mouse_over_ui(survarium::lobby_menu *this)
{
  char v1; // bl
  survarium::flash_movie_resource *m_object; // eax
  Scaleform::GFx::Value presult; // [esp+Ch] [ebp-1Ch] BYREF
  bool BValue; // [esp+27h] [ebp-1h]

  v1 = 0;
  m_object = this->m_lobby_menu_ui.m_object;
  presult.pObjectInterface = 0;
  presult.Type = VT_Undefined;
  Scaleform::GFx::Movie::Invoke(m_object->movie->m_movie, "root.get_mouse_over", &presult, 0, 0);
  BValue = presult.mValue.BValue;
  Scaleform::GFx::Movie::Invoke(
    this->m_game->m_chat_handler->m_current_chat_ui.m_object->movie->m_movie,
    "root.get_mouse_over",
    &presult,
    0,
    0);
  if ( BValue || presult.mValue.BValue )
    v1 = 1;
  Scaleform::GFx::Value::~Value(&presult);
  return v1;
}
