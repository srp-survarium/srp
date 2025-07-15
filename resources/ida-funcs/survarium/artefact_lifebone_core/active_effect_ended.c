BOOL __thiscall survarium::artefact_lifebone_core::active_effect_ended(survarium::artefact_lifebone_core *this)
{
  return this->m_time_left_to_deactivate == 0;
}
