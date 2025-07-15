bool __cdecl survarium::find_free_trap_predicate(
        vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> trap)
{
  survarium::game_camera *v1; // ecx
  bool v3; // [esp+Bh] [ebp-1h]

  survarium::weapon_user_dead_state::finalize(v1);
  v3 = trap.m_object->m_trap_state == booby_trap_state_removed;
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&trap);
  return v3;
}
