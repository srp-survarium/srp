void __thiscall survarium::single_player_respawn_rule::fill_match_hud_state(
        survarium::single_player_respawn_rule *this,
        survarium::match_hud_state *state,
        const unsigned int time_ms)
{
  unsigned __int8 current_player_id; // al
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned __int64 v6; // rax

  current_player_id = state->current_player_id;
  state->local_respawn_time_sec = 0;
  if ( current_player_id != 0xFF )
  {
    v4 = this->m_player_death_times.elems[current_player_id];
    if ( v4 != -1 )
    {
      v5 = v4 + 5000;
      if ( v5 <= time_ms )
        LODWORD(v6) = 0;
      else
        v6 = (unsigned __int64)((double)(v5 - time_ms) * 0.001);
      state->local_respawn_time_sec = v6;
    }
  }
}
