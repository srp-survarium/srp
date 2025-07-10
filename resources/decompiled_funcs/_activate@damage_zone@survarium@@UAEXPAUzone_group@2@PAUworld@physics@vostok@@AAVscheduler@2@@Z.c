void __thiscall survarium::damage_zone::activate(
        survarium::damage_zone *this,
        survarium::zone_group *owner,
        vostok::physics::world *p_world,
        survarium::scheduler *scheduler)
{
  survarium::damage_zone *M_start; // ecx

  survarium::damage_zone_core::activate((survarium::damage_zone_core *)this, owner, p_world, scheduler);
  M_start = (survarium::damage_zone *)this->m_old_objects._M_impl._M_start;
  if ( M_start != (survarium::damage_zone *)this->m_old_objects._M_impl._M_finish )
    survarium::damage_zone::play_particles(
      M_start,
      (survarium::damage_zone *)((char *)this - 264),
      (const survarium::vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > *)&this->m_old_objects);
}
