void __thiscall survarium::artefact_container_core::artefact_container_core(survarium::artefact_container_core *this)
{
  survarium::usable_object::usable_object(this);
  this->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::artefact_container_core_vtbl *)&survarium::artefact_container_core::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::artefact_container_core::`vftable'{for `survarium::link_resolver'};
  this->m_artefact.m_object = 0;
  this->m_owner = 0;
}
