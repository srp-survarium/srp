void __thiscall survarium::booby_trap_core::defuse_completed(survarium::booby_trap_core *this)
{
  this->switch_to_state(this, booby_trap_state_disarmed);
}
