void __thiscall survarium::booby_trap_set::remove(survarium::booby_trap_set *this)
{
  survarium::booby_trap_set::remove_current_ghost_model(this, (int)this);
  survarium::booby_trap_set_core::remove(this);
}
