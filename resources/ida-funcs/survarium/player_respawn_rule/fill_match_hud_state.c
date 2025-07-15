void __thiscall survarium::player_respawn_rule::fill_match_hud_state(
        survarium::player_respawn_rule *this,
        survarium::match_hud_state *state,
        const unsigned int time_ms)
{
  unsigned int v3; // eax
  unsigned __int64 v4; // rax

  if ( state->current_player_id == 0xFF || (v3 = this->m_player_respawn_times.elems[state->current_player_id], v3 == -1) )
  {
    state->local_respawn_time_sec = 0;
  }
  else
  {
    if ( v3 <= time_ms )
      LODWORD(v4) = 0;
    else
      v4 = (unsigned __int64)((double)(v3 - time_ms) * 0.001);
    state->local_respawn_time_sec = v4;
  }
}
