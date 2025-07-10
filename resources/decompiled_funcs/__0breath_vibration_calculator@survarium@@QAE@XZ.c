void __thiscall survarium::breath_vibration_calculator::breath_vibration_calculator(
        survarium::breath_vibration_calculator *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  vostok::ai::fsm::fsm(&this->m_logic);
  this->m_user = 0;
  this->m_params = 0;
  this->m_last_time_in_ms = 0;
  LODWORD(this->m_current_multiplier) = clear_value;
  LODWORD(this->m_target_multiplier) = clear_value;
  this->m_vertical_value = *(float *)&FLOAT_0_0;
  this->m_horizontal_value = *(float *)&FLOAT_0_0;
  LODWORD(this->m_character_multiplier) = clear_value;
  LODWORD(this->m_breath_holding_reserve) = clear_value;
  this->m_is_breath_holded = 0;
  survarium::breath_vibration_calculator::initialize_logic(this);
}
