BOOL __thiscall survarium::artefact_spring_core::active_effect_ended(survarium::artefact_spring_core *this)
{
  return this->m_time_left_to_deactivate == 0;
}
