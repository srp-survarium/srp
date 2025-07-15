BOOL __thiscall survarium::breath_vibration_calculator::insufficient_breath(
        survarium::breath_vibration_calculator *this)
{
  return this->m_breath_holding_reserve <= 0.0;
}
