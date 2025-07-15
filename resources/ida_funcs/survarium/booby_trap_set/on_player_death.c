void __thiscall survarium::booby_trap_set::on_player_death(survarium::booby_trap_set *this)
{
  survarium::booby_trap_set::remove_current_ghost_model(this, (int)this);
}
