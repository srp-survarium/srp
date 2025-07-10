// attributes: thunk
void __thiscall survarium::generic_anomaly::activate(
        survarium::generic_anomaly *this,
        vostok::physics::world *world,
        survarium::scheduler *scheduler)
{
  survarium::generic_anomaly_core::activate(this, world, scheduler);
}
