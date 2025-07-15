BOOL __thiscall survarium::artefact_onyx_core::active_effect_ended(survarium::artefact_onyx_core *this)
{
  return !this->m_time_left_to_deactivate || this->m_damage_to_absorb == 0.0;
}
