void __thiscall survarium::game_world_ui::show_capture_progress(survarium::game_world_ui *this)
{
  survarium::flash_movie_resource *m_object; // edx
  survarium::flash_value b_val; // [esp+0h] [ebp-1Ch] BYREF

  m_object = this->m_game_hud_ui.m_object;
  *(_DWORD *)b_val.body = 0;
  *(_DWORD *)&b_val.body[4] = 2;
  b_val.body[8] = 1;
  Scaleform::GFx::Movie::Invoke(
    m_object->movie->m_movie,
    "root.show_capture_progress",
    0,
    (const Scaleform::GFx::Value *)&b_val,
    1u);
  if ( (b_val.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)b_val.body + 8))(
      *(_DWORD *)b_val.body,
      &b_val,
      *(_DWORD *)&b_val.body[8]);
}
