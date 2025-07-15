void __thiscall survarium::weapon_core_reload_state_base::initialize(survarium::weapon_core_reload_state_base *this)
{
  bool m_chamber_a_round_on_reload; // [esp+7h] [ebp-1h]

  survarium::weapon_core_animation_end_aware_state::initialize(this);
  if ( !survarium::weapon_core_base_state::deserializing(this) )
  {
    m_chamber_a_round_on_reload = this->m_weapon->m_chamber_a_round_on_reload;
    if ( m_chamber_a_round_on_reload
      && survarium::weapon_core::round_is_chambered(
           (survarium::weapon_core *)m_chamber_a_round_on_reload,
           (int)this->m_weapon) )
    {
      survarium::weapon_core::unload_chambered_round(this->m_weapon);
    }
  }
}
