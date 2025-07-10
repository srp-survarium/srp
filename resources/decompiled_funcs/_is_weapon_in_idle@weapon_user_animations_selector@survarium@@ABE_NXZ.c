bool __thiscall survarium::weapon_user_animations_selector::is_weapon_in_idle(
        survarium::weapon_user_animations_selector *this)
{
  survarium::game_camera *v1; // ecx
  bool v3; // [esp+0h] [ebp-24h]
  vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> v4; // [esp+1Ch] [ebp-8h] BYREF
  bool v5; // [esp+23h] [ebp-1h]

  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_user->m_current_active_object,
    &v4.m_object);
  survarium::weapon_user_dead_state::finalize(v1);
  v3 = BYTE2(v4.m_object[3].m_current_satisfaction)
    || LOBYTE(v4.m_object[3].m_next_in_increase_quality_queue) && !LOBYTE(v4.m_object[3].m_quality_levels_count);
  v5 = v3;
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>(&v4);
  return v5;
}
