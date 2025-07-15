void __thiscall survarium::network_client::process_base_capture_progress(
        survarium::network_client *this,
        survarium::network_client *packet)
{
  unsigned int *v2; // eax
  unsigned int v3; // esi

  v2 = (unsigned int *)(*(_DWORD *)&this->m_use_physics_controller_for_current + 4);
  *(_DWORD *)&this->m_use_physics_controller_for_current = v2;
  v3 = *v2;
  *(_DWORD *)&this->m_use_physics_controller_for_current = v2 + 1;
  survarium::game_world_ui::set_base_capture_progress(
    &packet->m_game->m_game_world.game_ui,
    (unsigned int)&packet->m_game->m_game_world.game_ui,
    v3);
}
