void __thiscall survarium::artefact_base::added_to_inventory(survarium::artefact_base *this)
{
  this->enable_passive_effects(this);
  this->m_state = artefact_state_picked_passive;
}
