void __thiscall survarium::artefact_onyx_core::enable_active_effects(
        survarium::artefact_onyx_core *this,
        const unsigned int current_time_ms)
{
  unsigned int duration_ms; // eax

  duration_ms = this->m_config.active.duration_ms;
  this->m_damage_to_absorb = this->m_config.active.absorb_total;
  this->m_time_left_to_deactivate = duration_ms;
}
