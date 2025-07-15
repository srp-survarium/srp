void __thiscall survarium::booby_trap_core::on_state_timer_finished(survarium::booby_trap_core *this)
{
  survarium::booby_trap_state m_trap_state; // [esp+0h] [ebp-8h]

  m_trap_state = this->m_trap_state;
  if ( m_trap_state == booby_trap_state_armed || m_trap_state > booby_trap_state_disarmed )
    this->switch_to_state(this, booby_trap_state_disarmed);
  else
    this->m_owner->remove_trap(this->m_owner, this);
}
