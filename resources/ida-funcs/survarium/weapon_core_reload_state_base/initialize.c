void __thiscall survarium::weapon_core_reload_state_base::initialize(survarium::weapon_core_reload_state_base *this)
{
  survarium::weapon_core *m_weapon; // ecx

  survarium::weapon_core_animation_end_aware_state::initialize(this);
  m_weapon = this->m_weapon;
  if ( m_weapon->m_chamber_a_round_on_reload && m_weapon->m_is_round_chambered )
  {
    ++m_weapon->m_ammo_in_magazine;
    m_weapon->m_is_round_chambered = 0;
    m_weapon->on_unload_chambered_round(m_weapon);
  }
}
