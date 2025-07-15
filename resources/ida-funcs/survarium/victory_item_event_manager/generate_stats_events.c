void __userpurge survarium::victory_item_event_manager::generate_stats_events(
        const survarium::victory_item_status *item_status@<edx>,
        survarium::game_team_id winner_team@<edi>,
        survarium::victory_item_event_manager *this,
        survarium::match_stats_events_dict_enum event)
{
  unsigned int i; // esi
  float v5; // xmm0_4
  unsigned int v6; // eax
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short> *v7; // [esp+0h] [ebp-5Ch]
  boost::array<float,20> players_share; // [esp+Ch] [ebp-50h] BYREF

  survarium::victory_item_event_manager::calculate_players_share(this, item_status, winner_team, &players_share);
  for ( i = 0; i < this->m_match_options->players_count; ++i )
  {
    v5 = players_share.elems[i];
    if ( v5 > 0.0 )
    {
      v6 = vostok::math::floor((float)(v5 * s_spot_max_distance) + 0.5);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::operator()(
        v7,
        this,
        i,
        event,
        v6);
    }
  }
}
