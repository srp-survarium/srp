bool __cdecl survarium::trap_is_active(
        const vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *trap)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize(v1);
  return trap->m_object->m_trap_state != booby_trap_state_removed;
}
