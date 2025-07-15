void __thiscall survarium::weapon_core::update_breath_vibration(
        survarium::weapon_core *this,
        bool is_holding_breath,
        unsigned int current_time_in_ms,
        float time_scale)
{
  survarium::breath_vibration_calculator::hold_breath(&this->m_breath_vibration_calculator, is_holding_breath);
  LODWORD(this->m_breath_vibration_calculator.m_character_multiplier) = clear_value;
  survarium::breath_vibration_calculator::tick(&this->m_breath_vibration_calculator, current_time_in_ms, time_scale);
}
