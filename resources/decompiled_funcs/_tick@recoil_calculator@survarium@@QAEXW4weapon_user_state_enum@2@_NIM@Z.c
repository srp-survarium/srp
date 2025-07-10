void __thiscall survarium::recoil_calculator::tick(
        survarium::recoil_calculator *this,
        survarium::weapon_user_state_enum character_state,
        bool is_aiming,
        unsigned int current_time_in_ms,
        float time_scale)
{
  survarium::character_recoil_calculator::tick(
    &this->m_character_calculator,
    character_state,
    is_aiming,
    current_time_in_ms,
    time_scale);
  survarium::weapon_recoil_calculator::tick(&this->m_weapon_calculator, current_time_in_ms, time_scale);
  this->m_weapon_calculator.m_player_recoil_multiplier = this->m_character_calculator.m_current_value;
}
