void __thiscall survarium::artefact_spring_core::enable_active_effects(
        survarium::artefact_spring_core *this,
        const unsigned int current_time_ms)
{
  this->m_time_left_to_deactivate = this->m_config.active.duration_ms;
  survarium::artefact_spring_core::add_active_modifiers(this, (int)this);
}
