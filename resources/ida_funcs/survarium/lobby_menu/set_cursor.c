void __usercall survarium::lobby_menu::set_cursor(survarium::lobby_menu *this@<edx>, unsigned __int8 id@<al>)
{
  survarium::flash_movie_resource *m_object; // eax
  survarium::flash_value c_id; // [esp+0h] [ebp-1Ch] BYREF

  *(_DWORD *)&c_id.body[8] = id;
  m_object = this->m_cursor_ui.m_object;
  *(_DWORD *)c_id.body = 0;
  *(_DWORD *)&c_id.body[4] = 4;
  Scaleform::GFx::Movie::Invoke(m_object->movie->m_movie, "root.setCursor", 0, (const Scaleform::GFx::Value *)&c_id, 1u);
  if ( (c_id.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)c_id.body + 8))(
      *(_DWORD *)c_id.body,
      &c_id,
      *(_DWORD *)&c_id.body[8]);
}
