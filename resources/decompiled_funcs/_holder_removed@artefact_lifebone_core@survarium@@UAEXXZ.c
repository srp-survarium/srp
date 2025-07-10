void __thiscall survarium::artefact_lifebone_core::holder_removed(survarium::artefact_lifebone_core *this)
{
  if ( this->m_passive_mode )
    survarium::artefact_lifebone_core::switch_passive_mode_impl(this, 0);
}
