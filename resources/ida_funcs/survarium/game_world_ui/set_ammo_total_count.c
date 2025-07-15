void __userpurge survarium::game_world_ui::set_ammo_total_count(
        survarium::game_world_ui *this@<esi>,
        unsigned int first_type_count@<eax>,
        unsigned int second_type_count)
{
  survarium::flash_movie_resource *m_object; // edx
  survarium::flash_movie_resource *v4; // edx
  survarium::flash_value count; // [esp+8h] [ebp-18h] BYREF

  m_object = this->m_game_hud_ui.m_object;
  *(_DWORD *)count.body = 0;
  *(_DWORD *)&count.body[4] = 4;
  *(_DWORD *)&count.body[8] = first_type_count;
  Scaleform::GFx::Movie::Invoke(
    m_object->movie->m_movie,
    "root.set_primary_ammo",
    0,
    (const Scaleform::GFx::Value *)&count,
    1u);
  if ( (count.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)count.body + 8))(
      *(_DWORD *)count.body,
      &count,
      *(_DWORD *)&count.body[8]);
    *(_DWORD *)count.body = 0;
  }
  v4 = this->m_game_hud_ui.m_object;
  *(_DWORD *)&count.body[4] = 4;
  *(_DWORD *)&count.body[8] = second_type_count;
  Scaleform::GFx::Movie::Invoke(
    v4->movie->m_movie,
    "root.set_secondary_ammo",
    0,
    (const Scaleform::GFx::Value *)&count,
    1u);
  if ( (count.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)count.body + 8))(
      *(_DWORD *)count.body,
      &count,
      *(_DWORD *)&count.body[8]);
}
