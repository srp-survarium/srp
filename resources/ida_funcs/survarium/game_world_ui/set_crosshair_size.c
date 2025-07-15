void __usercall survarium::game_world_ui::set_crosshair_size(survarium::game_world_ui *this@<ecx>, float a2@<xmm0>)
{
  survarium::flash_movie_resource *m_object; // edx
  survarium::flash_value value; // [esp+0h] [ebp-18h] BYREF

  m_object = this->m_game_hud_ui.m_object;
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 5;
  *(double *)&value.body[8] = a2;
  Scaleform::GFx::Movie::Invoke(
    m_object->movie->m_movie,
    "root.set_crosshair_size",
    0,
    (const Scaleform::GFx::Value *)&value,
    1u);
  if ( (value.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)value.body + 8))(
      *(_DWORD *)value.body,
      &value,
      *(_DWORD *)&value.body[8]);
}
