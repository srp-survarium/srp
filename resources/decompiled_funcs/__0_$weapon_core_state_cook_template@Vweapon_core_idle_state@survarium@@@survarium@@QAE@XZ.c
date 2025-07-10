void __thiscall survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>::weapon_core_state_cook_template<survarium::weapon_core_idle_state>(
        survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state> *this)
{
  s_weapon_core_idle_state_cook.__vftable = (survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>_vtbl *)&vostok::resources::cook_base::`vftable';
  s_weapon_core_idle_state_cook.m_cook_users_count.m_count = 0;
  s_weapon_core_idle_state_cook.m_class_id = weapon_idle_state_class;
  s_weapon_core_idle_state_cook.m_reuse_type = reuse_false;
  s_weapon_core_idle_state_cook.m_creation_thread_id = GetCurrentThreadId();
  s_weapon_core_idle_state_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_weapon_core_idle_state_cook.m_flags.m_flags = 0;
  s_weapon_core_idle_state_cook.m_next = 0;
  s_weapon_core_idle_state_cook.__vftable = (survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>_vtbl *)&survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>::`vftable';
  vostok::resources::resources_manager::register_cook(&s_weapon_core_idle_state_cook);
}
