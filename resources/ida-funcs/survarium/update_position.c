void __usercall survarium::update_position(
        const survarium::game_team_id player_team@<edx>,
        survarium::victory_item_status *item_status@<eax>,
        float a3@<xmm2>,
        const unsigned __int8 player)
{
  float *v4; // ecx
  float v5; // xmm1_4
  float v6; // xmm0_4
  bool v7; // cc

  item_status->nearest_positions[player_team == team_1] = a3;
  v4 = &item_status->nearest_positions[player_team];
  v5 = *v4;
  if ( player_team )
  {
    v6 = s_bm_current_air_resistance;
    if ( s_bm_current_air_resistance > a3 )
      v6 = a3;
    v7 = v6 <= v5;
  }
  else
  {
    v6 = 0.0;
    if ( a3 > 0.0 )
      v6 = a3;
    v7 = v5 <= v6;
  }
  if ( v7 )
    v6 = *v4;
  *v4 = v6;
  item_status->carried_distances.elems[player] = item_status->carried_distances.elems[player] + fabs(v5 - v6);
}
