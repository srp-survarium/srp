bool __thiscall survarium::weapon_user_animations_selector::is_weapon_firing(
        survarium::weapon_user_animations_selector *this)
{
  survarium::game_camera *v1; // ecx
  vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> v3; // [esp+18h] [ebp-8h] BYREF
  char m_quality_levels_count; // [esp+1Fh] [ebp-1h]

  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_user->m_current_active_object,
    &v3.m_object);
  survarium::weapon_user_dead_state::finalize(v1);
  m_quality_levels_count = v3.m_object[3].m_quality_levels_count;
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>(&v3);
  return m_quality_levels_count;
}
