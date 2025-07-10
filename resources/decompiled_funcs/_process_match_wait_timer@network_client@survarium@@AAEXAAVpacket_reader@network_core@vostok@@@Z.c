void __fastcall survarium::network_client::process_match_wait_timer(survarium::network_client *this, int a2)
{
  survarium::game_world_ui *v2; // ecx

  *(_DWORD *)&this->m_use_physics_controller_for_current += 4;
  v2 = (survarium::game_world_ui *)"st_final_countdown";
  if ( *(_DWORD *)(a2 + 16768) != 3 )
    v2 = (survarium::game_world_ui *)&stru_971AC4;
  survarium::game_world_ui::set_pregame(v2, (const char *)(*(_DWORD *)(a2 + 24) + 620), (unsigned int)v2);
}
