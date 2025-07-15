void __thiscall survarium::weapon_core::register_in_game_world(
        survarium::weapon_core *this,
        vostok::resources::unmanaged_resource *game_world)
{
  char *p_m_transition_time; // edi
  unsigned __int8 v4; // al

  p_m_transition_time = (char *)&this[-1].m_aim_progress.m_transition_time;
  v4 = survarium::game_world_core::register_interactive_object(
         (survarium::game_world_core *)this,
         game_world,
         (survarium::interactive_object *const)&this[-1].m_aim_progress.m_transition_time);
  *((_DWORD *)p_m_transition_time + 1) = game_world;
  p_m_transition_time[12] = v4;
  this->m_prev_in_global_delay_delete_list = game_world;
}
