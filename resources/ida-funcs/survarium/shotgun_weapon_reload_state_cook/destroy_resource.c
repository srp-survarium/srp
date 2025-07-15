void __thiscall survarium::shotgun_weapon_reload_state_cook::destroy_resource(
        survarium::shotgun_weapon_reload_state_cook *this,
        vostok::resources::unmanaged_resource *resource)
{
  char *p_m_prev_in_global_list; // ecx

  if ( resource )
    p_m_prev_in_global_list = (char *)&resource[-1].m_prev_in_global_list;
  else
    p_m_prev_in_global_list = 0;
  (**(void (__thiscall ***)(char *, _DWORD))p_m_prev_in_global_list)(p_m_prev_in_global_list, 0);
}
