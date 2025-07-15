BOOL __thiscall survarium::breath_vibration_calculator::hold_button_state_equals_to(
        survarium::breath_vibration_calculator *this,
        bool btn_state)
{
  return this->m_is_breath_holded == btn_state;
}
