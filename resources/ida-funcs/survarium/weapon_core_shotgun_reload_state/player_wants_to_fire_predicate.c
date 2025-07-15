int __thiscall survarium::weapon_core_shotgun_reload_state::player_wants_to_fire_predicate(
        survarium::weapon_core_shotgun_reload_state *this)
{
  survarium::weapon_core *m_weapon; // eax
  unsigned int v2; // ecx
  int result; // eax

  m_weapon = this->m_weapon;
  if ( !(m_weapon->m_ammo_in_magazine + m_weapon->m_is_round_chambered) )
    return 0;
  v2 = m_weapon->m_user->m_input.actions_mask >> 5;
  result = 1;
  if ( (v2 & 1) == 0 )
    return 0;
  return result;
}
