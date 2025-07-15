void __thiscall survarium::player_respawn_rule::on_event(
        survarium::player_respawn_rule *this,
        survarium::event_id_type event_id,
        unsigned __int8 *event_args,
        const unsigned int current_time_ms)
{
  if ( event_id == player_killed_event )
    this->m_player_respawn_times.elems[event_args[1]] = this->m_game_world_core->m_start_fixed_time_in_ms
                                                      + 50
                                                      * ((this->m_game_world_core->m_start_fixed_time_in_ms < current_time_ms + this->m_respawn_interval_time_in_ms
                                                        ? current_time_ms
                                                        + this->m_respawn_interval_time_in_ms
                                                        - this->m_game_world_core->m_start_fixed_time_in_ms
                                                        - 1
                                                        : 0)
                                                       / 0x32
                                                       + 1);
}
