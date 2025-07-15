void __thiscall survarium::booby_trap_core::remove(survarium::booby_trap_core *this, survarium::scheduler *scheduler)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->unregister_tick(this, scheduler);
  this->switch_to_state(this, booby_trap_state_removed);
}
