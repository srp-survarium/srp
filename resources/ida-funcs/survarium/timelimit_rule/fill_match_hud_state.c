void __thiscall survarium::timelimit_rule::fill_match_hud_state(
        survarium::timelimit_rule *this,
        survarium::match_hud_state *state,
        const unsigned int current_time_in_ms)
{
  unsigned int v4; // edi
  unsigned __int64 v5; // rax
  unsigned int m_match_length_ms; // esi
  survarium::match_hud_state *v7; // ebx
  unsigned int m_countdown_time; // esi
  int v9; // esi
  double v10; // st7
  unsigned int m_wait_players_time; // esi
  unsigned __int64 v12; // rax

  v4 = current_time_in_ms - this->m_state_start_time_ms;
  if ( this->m_current_state == game_status_waiting_for_players )
  {
    v7 = state;
    sprintf_s<128>((char (*)[128])state->pregame_str, "st_waiting_for_players");
    m_wait_players_time = this->m_wait_players_time;
    if ( v4 <= m_wait_players_time )
    {
      v9 = m_wait_players_time - v4;
      v10 = (double)v9;
      goto LABEL_12;
    }
LABEL_10:
    LODWORD(v12) = 0;
LABEL_15:
    v7->is_pregame = 1;
    v7->pregame_time_sec = v12;
    return;
  }
  if ( this->m_current_state == game_status_final_countdown )
  {
    v7 = state;
    sprintf_s<128>((char (*)[128])state->pregame_str, "st_final_countdown");
    m_countdown_time = this->m_countdown_time;
    if ( v4 <= m_countdown_time )
    {
      v9 = m_countdown_time - v4;
      v10 = (double)v9;
LABEL_12:
      if ( v9 < 0 )
        v10 = v10 + 4294967300.0;
      v12 = (unsigned __int64)(v10 * 0.001);
      goto LABEL_15;
    }
    goto LABEL_10;
  }
  LODWORD(v5) = this->m_current_state - 3;
  if ( this->m_current_state == game_status_inprocess )
  {
    m_match_length_ms = this->m_match_length_ms;
    if ( v4 <= m_match_length_ms )
      v5 = (unsigned __int64)((double)(m_match_length_ms - v4) * 0.001);
    state->match_time_sec = v5;
    state->is_pregame = 0;
  }
}
