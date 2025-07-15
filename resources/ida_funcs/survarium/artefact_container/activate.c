// attributes: thunk
void __thiscall survarium::artefact_container::activate(
        survarium::artefact_container *this,
        survarium::generic_anomaly_core *owner,
        vostok::physics::world *world,
        survarium::scheduler *scheduler)
{
  survarium::artefact_container_core::activate(this, owner, world, scheduler);
}
