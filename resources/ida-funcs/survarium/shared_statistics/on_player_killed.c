void __thiscall survarium::shared_statistics::on_player_killed(
        survarium::shared_statistics *this,
        survarium::shared_statistics *current_time_in_ms,
        unsigned int killer_id,
        unsigned __int8 victim_id,
        unsigned __int8 is_headshot,
        bool victim_had_victory_item,
        char additional_arg,
        int a8)
{
  survarium::shared_statistics *v8; // ebx
  const survarium::player_shared_statistics *v9; // esi
  survarium::player_shared_statistics *v10; // eax
  survarium::player_shared_statistics *v11; // ebx
  survarium::shared_statistics *v12; // ecx
  unsigned __int8 last_hit_enemy_id; // cl
  unsigned int last_killed_enemy_ms; // eax
  const survarium::player_shared_statistics *v15; // edi
  unsigned int *v16; // eax
  survarium::match_stats_events_dict_enum v17; // [esp-4h] [ebp-1Ch]
  survarium::game_team_id v18; // [esp+10h] [ebp-8h]
  survarium::game_team_id team; // [esp+14h] [ebp-4h]
  unsigned __int8 v20; // [esp+2Bh] [ebp+13h]

  v8 = current_time_in_ms;
  v9 = &current_time_in_ms->m_player_stats.elems[is_headshot];
  if ( victim_id == 0xFF )
    team = team_undefined;
  else
    team = current_time_in_ms->m_match_options->player_profiles.elems[victim_id].team;
  v18 = current_time_in_ms->m_match_options->player_profiles.elems[is_headshot].team;
  v17 = match_stats_event_death;
  v10 = &current_time_in_ms->m_player_stats.elems[is_headshot];
  if ( victim_id == is_headshot )
  {
    survarium::shared_statistics::on_event(current_time_in_ms, v10, 1u, match_stats_event_death);
    v17 = match_stats_event_suicide;
    v10 = &current_time_in_ms->m_player_stats.elems[is_headshot];
  }
  survarium::shared_statistics::on_event(current_time_in_ms, v10, 1u, v17);
  if ( victim_id != 0xFF && victim_id != is_headshot )
  {
    v11 = &current_time_in_ms->m_player_stats.elems[victim_id];
    if ( team == v18 )
    {
      survarium::shared_statistics::on_event(current_time_in_ms, v11, 1u, match_stats_event_team_kill);
      v8 = current_time_in_ms;
    }
    else
    {
      survarium::shared_statistics::on_event(current_time_in_ms, v11, 1u, match_stats_event_kill);
      if ( victim_had_victory_item )
        survarium::shared_statistics::on_event(current_time_in_ms, v11, 1u, match_stats_event_headshot_kill);
      if ( additional_arg )
        survarium::shared_statistics::on_event(current_time_in_ms, v11, 1u, match_stats_event_victory_item_carry_kill);
      survarium::shared_statistics::give_assists(v12, current_time_in_ms, v11, v9);
      last_hit_enemy_id = v9->intermediate.last_hit_enemy_id;
      if ( last_hit_enemy_id != 0xFF
        && last_hit_enemy_id != victim_id
        && v9->intermediate.last_hit_ms.elems[last_hit_enemy_id] + 2000 >= killer_id
        && ((1 << last_hit_enemy_id) & a8) != 0 )
      {
        survarium::shared_statistics::on_event(current_time_in_ms, v11, 1u, match_stats_event_teammate_rescue);
      }
      last_killed_enemy_ms = v9->intermediate.last_killed_enemy_ms;
      if ( last_killed_enemy_ms && last_killed_enemy_ms + 2000 >= killer_id )
        survarium::shared_statistics::on_event(current_time_in_ms, v11, 1u, match_stats_event_revenge);
      v11->intermediate.last_killed_enemy_ms = killer_id;
      v8 = current_time_in_ms;
    }
  }
  v20 = 0;
  if ( v8->m_players_count )
  {
    do
    {
      v15 = &v8->m_player_stats.elems[v20];
      if ( v15 != v9
        && survarium::shared_statistics::team(v8, &v8->m_player_stats.elems[v20]) != v18
        && v15->intermediate.last_hit_enemy_id == is_headshot )
      {
        v15->intermediate.last_hit_ms.elems[is_headshot] = 0;
        v16 = stlp_std::max_element<unsigned int *>(
                v15->intermediate.last_hit_ms.elems,
                &v15->intermediate.last_killed_enemy_ms);
        if ( *v16 )
          v15->intermediate.last_hit_enemy_id = ((char *)v16 - (char *)&v15->intermediate.last_hit_ms) >> 2;
        else
          v15->intermediate.last_hit_enemy_id = -1;
        v8 = current_time_in_ms;
      }
      ++v20;
    }
    while ( v20 != v8->m_players_count );
  }
  memset(&v9->intermediate.last_hit_ms, 0, sizeof(v9->intermediate.last_hit_ms));
  v9->intermediate.last_killed_enemy_ms = 0;
  v9->intermediate.last_hit_enemy_id = -1;
  survarium::shared_statistics::reset_received_damage(is_headshot, v8);
}
