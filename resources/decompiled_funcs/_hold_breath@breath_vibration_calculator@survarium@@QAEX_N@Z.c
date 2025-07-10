void __thiscall survarium::breath_vibration_calculator::hold_breath(
        survarium::breath_vibration_calculator *this,
        bool value)
{
  if ( value != this->m_is_breath_holded )
    this->m_is_breath_holded = value;
}
