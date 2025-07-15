void __thiscall survarium::artefact_container_core::activate(
        survarium::artefact_container_core *this,
        survarium::generic_anomaly_core *owner,
        vostok::physics::world *world,
        survarium::scheduler *__formal)
{
  this->m_owner = owner;
  survarium::usable_object::insert(this, world);
}
