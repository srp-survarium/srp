void __thiscall survarium::collision_sensor::tick(
        survarium::collision_sensor *this,
        unsigned int time_delta_ms,
        vostok::physics::loose_ptr_data *current_time_ms)
{
  survarium::collision_sensor::query_overlapping_objects(
    this,
    (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>)this,
    time_delta_ms,
    current_time_ms);
}
