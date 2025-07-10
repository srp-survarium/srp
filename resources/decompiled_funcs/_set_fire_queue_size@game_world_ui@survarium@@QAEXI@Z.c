void __usercall survarium::game_world_ui::set_fire_queue_size(
        survarium::game_world_ui *this@<edx>,
        const unsigned int fire_queue_size@<eax>)
{
  survarium::flash_movie_resource *m_object; // eax
  survarium::flash_value value; // [esp+0h] [ebp-18h] BYREF

  *(_DWORD *)&value.body[8] = fire_queue_size;
  m_object = this->m_game_hud_ui.m_object;
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 4;
  Scaleform::GFx::Movie::Invoke(
    m_object->movie->m_movie,
    "root.set_weapon_fire_queue_size",
    0,
    (const Scaleform::GFx::Value *)&value,
    1u);
  if ( (value.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)value.body + 8))(
      *(_DWORD *)value.body,
      &value,
      *(_DWORD *)&value.body[8]);
}
