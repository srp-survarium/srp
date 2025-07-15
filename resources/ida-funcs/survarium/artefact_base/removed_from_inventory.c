void __thiscall survarium::artefact_base::removed_from_inventory(survarium::artefact_base *this)
{
  survarium::artefact_state_enum *p_m_state; // edi

  p_m_state = &this->m_state;
  if ( this->m_state == artefact_state_picked_active )
    this->disable_active_effects(this);
  this->disable_passive_effects(this);
  *p_m_state = artefact_state_inactive;
}
