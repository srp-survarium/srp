void __thiscall survarium::booby_trap::on_trap_disarmed_message(survarium::booby_trap *this)
{
  this->switch_to_state(this, booby_trap_state_disarmed);
}
