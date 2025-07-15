void __userpurge survarium::damage_zone_core::activate(
        survarium::damage_zone_core *this@<edi>,
        vostok::physics::world *world@<eax>,
        survarium::collision_sensor *a3@<ecx>,
        BOOL forced)
{
  this->m_physics_world = world;
  survarium::collision_sensor::insert(a3, (int)&this->survarium::collision_sensor, world);
  this->m_last_hit_time_ms = -1;
  this->on_activation(this, forced);
}
