void __usercall survarium::weapon_core::update_recoil(
        survarium::weapon_core *this@<edi>,
        unsigned int current_time_in_ms@<esi>)
{
  survarium::character_recoil_calculator::tick(
    &this->m_recoil_calculator.m_character_calculator,
    this->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.m_size,
    current_time_in_ms,
    this->m_aimed);
  this->m_recoil_calculator.m_weapon_calculator.m_player_recoil_multiplier = this->m_recoil_calculator.m_character_calculator.m_current_value;
}
