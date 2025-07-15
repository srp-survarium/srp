void __thiscall survarium::network_client::on_idle(survarium::network_client *this, unsigned int game_time_in_ms)
{
  survarium::pvp_match_core *m_object; // ecx
  survarium::game_world_core *m_game_world_core; // eax
  unsigned int m_event_horizon_interval_in_ms; // edx
  unsigned int v6; // esi
  survarium::base_match_client *v7; // eax

  m_object = this->m_match.m_object;
  if ( m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      m_game_world_core = m_object->m_game_world_core;
      if ( m_game_world_core->m_game_states_history.m_items.m_first )
      {
        m_event_horizon_interval_in_ms = m_game_world_core->m_event_horizon_interval_in_ms;
        if ( m_event_horizon_interval_in_ms + m_game_world_core->m_max_current_time_in_ms < game_time_in_ms )
        {
          m_object = (survarium::pvp_match_core *)m_object->m_game_world_core;
          if ( m_game_world_core->m_start_fixed_time_in_ms != -1 )
            survarium::game_world_core::move(
              (survarium::game_world_core *)m_object,
              (survarium::game_world_core *)m_object,
              m_game_world_core->m_start_fixed_time_in_ms
            + 50
            * ((game_time_in_ms - m_event_horizon_interval_in_ms - m_game_world_core->m_start_fixed_time_in_ms)
             / 0x32));
        }
      }
    }
  }
  v6 = survarium::network_client::try_send_all((survarium::network_client *)m_object, (int)this, game_time_in_ms, 0);
  if ( this->m_match_client->m_last_send_queed_packets_time_in_ms != v6 )
  {
    v7 = this->match_client(this);
    v7->send_queued_packets(v7, v6);
  }
}
