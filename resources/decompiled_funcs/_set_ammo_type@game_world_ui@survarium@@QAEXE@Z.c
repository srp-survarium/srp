void __usercall survarium::game_world_ui::set_ammo_type(
        survarium::game_world_ui *this@<edx>,
        const unsigned __int8 ammo_type@<al>)
{
  survarium::flash_movie_resource *m_object; // eax
  survarium::flash_value value; // [esp+0h] [ebp-18h] BYREF

  *(_DWORD *)&value.body[8] = ammo_type;
  m_object = this->m_game_hud_ui.m_object;
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 4;
  Scaleform::GFx::Movie::Invoke(
    m_object->movie->m_movie,
    "root.set_weapon_ammo_type",
    0,
    (const Scaleform::GFx::Value *)&value,
    1u);
  if ( (value.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)value.body + 8))(
      *(_DWORD *)value.body,
      &value,
      *(_DWORD *)&value.body[8]);
}
