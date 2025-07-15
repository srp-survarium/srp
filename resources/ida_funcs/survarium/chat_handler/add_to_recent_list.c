void __userpurge survarium::chat_handler::add_to_recent_list(const wchar_t *name@<edi>, survarium::chat_handler *this)
{
  survarium::flash_value obj; // [esp+8h] [ebp-18h] BYREF

  if ( !this->m_game_ui_mode )
  {
    *(_DWORD *)obj.body = 0;
    *(_DWORD *)&obj.body[4] = 0;
    survarium::flash_value::SetStringW(&obj, name);
    Scaleform::GFx::Movie::Invoke(
      this->m_chat_ui.m_object->movie->m_movie,
      "root.add_chat_recent",
      0,
      (const Scaleform::GFx::Value *)&obj,
      1u);
    if ( (obj.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)obj.body + 8))(
        *(_DWORD *)obj.body,
        &obj,
        *(_DWORD *)&obj.body[8]);
  }
}
