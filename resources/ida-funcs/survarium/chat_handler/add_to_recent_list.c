void __userpurge survarium::chat_handler::add_to_recent_list(const char *name@<edi>, survarium::chat_handler *this)
{
  survarium::flash_value v2; // [esp+8h] [ebp-1Ch] BYREF

  if ( !this->m_game_ui_mode )
  {
    *(_DWORD *)v2.body = 0;
    *(_DWORD *)&v2.body[4] = 0;
    survarium::flash_value::SetString(&v2, name);
    Scaleform::GFx::Movie::Invoke(
      this->m_current_chat_ui.m_object->movie->m_movie,
      "root.add_chat_recent",
      0,
      (const Scaleform::GFx::Value *)&v2,
      1u);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v2);
  }
}
