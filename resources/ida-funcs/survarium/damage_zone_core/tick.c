void __thiscall survarium::damage_zone_core::tick(
        survarium::damage_zone_core *this,
        unsigned int time_delta,
        vostok::physics::loose_ptr_data *current_time)
{
  bool v4; // al
  unsigned int m_construct_thread_id; // eax

  survarium::collision_sensor::tick((survarium::collision_sensor *)this, time_delta, current_time);
  if ( LOBYTE(this->m_parent_resources.m_first) )
  {
    v4 = (unsigned int)((*((_DWORD *)&this->vostok::resources::resource_flags + 3)
                       - this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags) >> 2) > 0;
  }
  else
  {
    m_construct_thread_id = this->m_construct_thread_id;
    v4 = m_construct_thread_id != -1 && m_construct_thread_id + this->m_creation_source >= (unsigned int)current_time;
  }
  BYTE1(this->m_memory_type_data) = v4;
}


void __thiscall survarium::damage_zone_core::tick(char *this, unsigned int a2, vostok::physics::loose_ptr_data *a3)
{
  survarium::damage_zone_core::tick((survarium::damage_zone_core *)(this - 52), a2, a3);
}
