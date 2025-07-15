BOOL __thiscall survarium::booby_trap_core::is_active(survarium::booby_trap_core *this)
{
  return this->m_trap_state != booby_trap_state_inactive;
}
