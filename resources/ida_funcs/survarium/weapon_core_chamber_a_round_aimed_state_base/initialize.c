void __thiscall survarium::weapon_core_chamber_a_round_aimed_state_base::initialize(
        survarium::weapon_core_chamber_a_round_aimed_state_base *this)
{
  survarium::weapon_core_animation_end_aware_state::initialize(this);
  this->m_weapon->instant_aim_start(this->m_weapon);
}
