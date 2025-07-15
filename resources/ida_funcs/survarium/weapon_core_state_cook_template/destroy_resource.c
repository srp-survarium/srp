void __thiscall survarium::weapon_core_state_cook_template<survarium::pistol_weapon_core_aimed_idle_state>::destroy_resource(
        survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state> *this,
        vostok::resources::unmanaged_resource *resource)
{
  char *p_m_prev_in_global_list; // ecx

  if ( resource )
    p_m_prev_in_global_list = (char *)&resource[-1].m_prev_in_global_list;
  else
    p_m_prev_in_global_list = 0;
  (**(void (__thiscall ***)(char *, _DWORD))p_m_prev_in_global_list)(p_m_prev_in_global_list, 0);
}
