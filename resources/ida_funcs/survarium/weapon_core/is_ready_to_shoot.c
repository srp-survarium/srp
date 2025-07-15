bool __thiscall survarium::weapon_core::is_ready_to_shoot(survarium::weapon_core *this)
{
  BOOL m_is_round_chambered; // [esp+4h] [ebp-8h]

  if ( this->m_is_there_chamber_a_round_state )
    m_is_round_chambered = this->m_is_round_chambered;
  else
    m_is_round_chambered = this->m_ammo_in_magazine != 0;
  return m_is_round_chambered && this->m_bullets_in_queue && this->m_ready_for_fire;
}
