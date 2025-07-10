void __thiscall survarium::game_options::show_options(survarium::game_options *this)
{
  survarium::flash_movie_resource *m_object; // edx
  survarium::flash_value b_show_value; // [esp+0h] [ebp-18h] BYREF

  m_object = this->m_options_ui.m_object;
  *(_DWORD *)b_show_value.body = 0;
  *(_DWORD *)&b_show_value.body[4] = 2;
  b_show_value.body[8] = 1;
  Scaleform::GFx::Movie::Invoke(
    m_object->movie->m_movie,
    "root.show_settings",
    0,
    (const Scaleform::GFx::Value *)&b_show_value,
    1u);
  if ( (b_show_value.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)b_show_value.body + 8))(
      *(_DWORD *)b_show_value.body,
      &b_show_value,
      *(_DWORD *)&b_show_value.body[8]);
}
