void __thiscall survarium::artefact_container_core::deactivate(survarium::artefact_container_core *this)
{
  survarium::usable_object::remove(this);
  this->m_owner = 0;
}
