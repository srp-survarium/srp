void __thiscall survarium::booby_trap_core::tick(
        survarium::booby_trap_core *this,
        unsigned int time_delta_ms,
        vostok::physics::loose_ptr_data *current_time_ms)
{
  float z; // eax

  z = this->m_transform.c.z;
  if ( z != 0.0 )
  {
    if ( LODWORD(z) > time_delta_ms )
    {
      LODWORD(this->m_transform.c.z) = LODWORD(z) - time_delta_ms;
    }
    else if ( this->m_prev_in_global_delay_delete_list == (vostok::resources::unmanaged_resource *)1 )
    {
      survarium::booby_trap_core::switch_to_state(
        (survarium::booby_trap_core *)((char *)this - 16),
        booby_trap_state_disarmed,
        this);
    }
    else
    {
      survarium::booby_trap_core::remove((survarium::booby_trap_core *)((char *)this - 16));
    }
  }
  if ( this->m_prev_in_global_delay_delete_list == (vostok::resources::unmanaged_resource *)1 )
    survarium::collision_sensor::tick((survarium::collision_sensor *)this, time_delta_ms, current_time_ms);
}


void __thiscall survarium::booby_trap_core::tick(char *this, unsigned int a2, unsigned int a3)
{
  survarium::booby_trap_core::tick((survarium::booby_trap_core *)(this - 104), a2, a3);
}
