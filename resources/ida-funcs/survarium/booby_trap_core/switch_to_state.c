void __usercall survarium::booby_trap_core::switch_to_state(
        survarium::booby_trap_core *this@<eax>,
        survarium::booby_trap_state new_state@<edi>,
        survarium::booby_trap_core *a3@<ecx>)
{
  survarium::booby_trap_set_core *m_owner; // eax
  unsigned int fired_life_time; // eax

  if ( this->m_trap_state == booby_trap_state_armed )
    survarium::booby_trap_core::remove_collision(a3, (survarium::collision_geometry_subscriber *)this, 0);
  if ( new_state )
  {
    if ( new_state == booby_trap_state_armed )
    {
      this->m_state_timer = this->m_owner->m_config.armed_life_time;
    }
    else
    {
      m_owner = this->m_owner;
      if ( new_state == booby_trap_state_fired )
        fired_life_time = m_owner->m_config.fired_life_time;
      else
        fired_life_time = m_owner->m_config.disarmed_life_time;
      this->m_state_timer = fired_life_time;
      if ( !fired_life_time )
      {
        survarium::booby_trap_core::remove(this);
        return;
      }
    }
  }
  this->m_trap_state = new_state;
}
