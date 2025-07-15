void __thiscall survarium::generic_anomaly_core::activate(
        survarium::generic_anomaly_core *this,
        vostok::physics::world *world)
{
  unsigned int v2; // ebx
  survarium::collision_geometry_subscriber *v4; // esi
  survarium::collision_geometry_subscriber v5; // eax

  v2 = 0;
  this->m_physics_world = world;
  this->m_was_zone_trigger_event = 0;
  this->m_was_shoot_trigger_event = 0;
  if ( this->artefacts_enabled
    && this->m_artefact_containers._M_impl._M_finish - this->m_artefact_containers._M_impl._M_start )
  {
    do
    {
      v4 = (survarium::collision_geometry_subscriber *)this->m_artefact_containers._M_impl._M_start[v2];
      survarium::usable_object::insert((survarium::usable_object *)this, v4, world);
      v5.__vftable = v4->__vftable;
      BYTE1(v4[24].__vftable) = 1;
      v5.__vftable[2].cast_to_spottable(v4);
      ++v2;
    }
    while ( v2 < this->m_artefact_containers._M_impl._M_finish - this->m_artefact_containers._M_impl._M_start );
  }
  this->on_activation(this);
}
