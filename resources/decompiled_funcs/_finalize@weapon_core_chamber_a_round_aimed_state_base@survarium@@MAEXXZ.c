void __thiscall survarium::weapon_core_chamber_a_round_aimed_state_base::finalize(
        survarium::weapon_core_chamber_a_round_aimed_state_base *this)
{
  survarium::weapon_core_animation_end_aware_state::finalize(this);
  this->m_weapon->instant_aim_end(this->m_weapon);
}
