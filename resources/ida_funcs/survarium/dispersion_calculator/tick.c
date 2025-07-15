void __thiscall survarium::dispersion_calculator::tick(
        survarium::dispersion_calculator *this,
        survarium::weapon_user_state_enum character_state,
        bool is_moving,
        bool is_aiming,
        unsigned __int8 broken_hands_count,
        bool using_double_handed_weapon,
        unsigned int current_time_in_ms)
{
  survarium::weapon_dispersion_calculator::tick(&this->m_weapon_calculator, current_time_in_ms);
  survarium::character_dispersion_calculator::tick(
    &this->m_character_calculator,
    character_state,
    is_moving,
    is_aiming,
    broken_hands_count,
    using_double_handed_weapon,
    current_time_in_ms);
}
