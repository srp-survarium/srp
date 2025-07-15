void __thiscall survarium::booby_trap_core::remove(survarium::booby_trap_core *this)
{
  survarium::tickable_object *v2; // eax
  survarium::booby_trap_core *v3; // ecx

  if ( this )
    v2 = &this->survarium::tickable_object;
  else
    v2 = 0;
  survarium::game_world_core::unregister_tickable_object(this->m_game_world_core, v2);
  survarium::booby_trap_core::switch_to_state(this, booby_trap_state_inactive, v3);
}
