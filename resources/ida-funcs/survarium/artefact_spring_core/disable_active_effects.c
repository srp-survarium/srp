void __thiscall survarium::artefact_spring_core::disable_active_effects(survarium::artefact_spring_core *this)
{
  survarium::artefact_spring_core::remove_active_modifiers(this, (int)this);
  this->m_time_left_to_deactivate = 0;
}
