bool __thiscall survarium::weapon_core::must_chamber_a_round_predicate(survarium::weapon_core *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return !this->m_is_round_chambered
      && this->m_ammo_in_magazine
      && !survarium::weapon_user_animations_selector::is_in_jump(&this->m_user_animations_selector);
}
