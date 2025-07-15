void __thiscall survarium::single_player_respawn_rule::on_event(
        survarium::single_player_respawn_rule *this,
        survarium::event_id_type event_id,
        unsigned __int8 *event_args,
        unsigned int current_time_ms)
{
  if ( event_id == player_killed_event )
    this->m_player_death_times.elems[event_args[1]] = current_time_ms;
}
