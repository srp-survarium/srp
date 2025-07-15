void __thiscall survarium::network_client::process_game_status(
        survarium::network_client *this,
        survarium::network_client *packet)
{
  const vostok::network_core::base_packet **v2; // eax
  const vostok::network_core::base_packet *v3; // ebp
  const vostok::network_core::base_packet *m_game_status; // eax
  survarium::game_world_ui *p_game_ui; // esi
  survarium::player *v6; // ecx
  survarium::base_network_client *v7; // ecx
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> v8; // [esp-4h] [ebp-14h] BYREF
  unsigned __int8 v9; // [esp+0h] [ebp-10h]
  unsigned __int8 v10; // [esp+4h] [ebp-Ch]
  unsigned int v11; // [esp+8h] [ebp-8h]

  v2 = *(const vostok::network_core::base_packet ***)&this->m_use_physics_controller_for_current;
  v3 = *v2;
  *(_DWORD *)&this->m_use_physics_controller_for_current = v2 + 1;
  m_game_status = (const vostok::network_core::base_packet *)packet->m_game_status;
  if ( m_game_status != v3 )
  {
    p_game_ui = &packet->m_game->m_game_world.game_ui;
    if ( v3 == (const vostok::network_core::base_packet *)4 )
    {
      survarium::game_world_ui::show_pregame(&packet->m_game->m_game_world.game_ui, 0);
      if ( packet->m_local_player.m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        && packet->m_is_time_synchronized_first_time )
      {
        survarium::game_world_ui::show_parametrized_message(p_game_ui, "st_start_match_welcome_message", v9, v10, v11);
        v8.m_object = v6;
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(
          &v8,
          &packet->m_local_player,
          (survarium::profile_player_character *)v6);
        survarium::base_network_client::attach_to_player(v7, v8);
        packet->m_game_status = game_status_inprocess;
        return;
      }
    }
    else if ( !m_game_status )
    {
      survarium::game_world_ui::show_pregame(&packet->m_game->m_game_world.game_ui, 1);
      if ( packet->m_local_player.m_object )
      {
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          survarium::network_client::setup_camera_for_warmup(
            (survarium::network_client *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
            (int)packet);
      }
    }
    packet->m_game_status = (survarium::game_status)v3;
  }
}
