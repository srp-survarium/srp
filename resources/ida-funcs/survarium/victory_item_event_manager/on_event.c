void __userpurge survarium::victory_item_event_manager::on_event(
        survarium::victory_item_event_manager *this@<esi>,
        const survarium::victory_item_core *item@<eax>,
        int player,
        survarium::victory_item_event_type event)
{
  survarium::gather_victory_items_rule *m_match_options; // ecx
  int victory_item_id; // eax
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short> *v7; // ecx
  survarium::victory_item_status *v8; // ebx
  vostok::math::float4x4 *v9; // eax
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm7_4
  float v13; // xmm0_4
  survarium::game_team_id owner_team; // eax
  survarium::match_stats_events_dict_enum v15; // eax
  float v16; // xmm0_4
  survarium::game_team_id winner_team; // [esp+Ch] [ebp-44h]
  char v18[64]; // [esp+10h] [ebp-40h] BYREF

  m_match_options = (survarium::gather_victory_items_rule *)this->m_match_options;
  winner_team = *((_DWORD *)&m_match_options[1].m_memory_usage_self.survarium::game_match_rule_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type
                + 372 * (unsigned __int8)player);
  victory_item_id = survarium::gather_victory_items_rule::get_victory_item_id(
                      m_match_options,
                      (int)this->m_game_rule,
                      item);
  v8 = &this->m_victory_items.elems[victory_item_id];
  if ( this->m_victory_items.elems[victory_item_id].already_found_once || event != victory_item_spotted )
  {
    if ( event == victory_item_brought )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::operator()(
        v7,
        this,
        player,
        match_stats_event_put_victory_item_in_container,
        1);
    v9 = item->get_transform(item, v18);
    x = this->m_container_positions[0].x;
    y = this->m_container_positions[0].y;
    z = this->m_container_positions[0].z;
    v13 = this->m_container_positions[1].x - x;
    survarium::update_position(
      winner_team,
      v8,
      (float)((float)((float)(v13 * (float)(v9->c.x - x))
                    + (float)((float)(this->m_container_positions[1].y - y) * (float)(v9->c.y - y)))
            + (float)((float)(this->m_container_positions[1].z - z) * (float)(v9->c.z - z)))
    / (float)((float)((float)((float)(this->m_container_positions[1].z - z)
                            * (float)(this->m_container_positions[1].z - z))
                    + (float)((float)(this->m_container_positions[1].y - y)
                            * (float)(this->m_container_positions[1].y - y)))
            + (float)(v13 * v13)),
      player);
    if ( event == victory_item_brought )
    {
      owner_team = v8->owner_team;
      if ( owner_team == team_undefined )
        v15 = match_stats_event_bring_victory_item;
      else
        v15 = (owner_team == winner_team) + 17;
      survarium::victory_item_event_manager::generate_stats_events(v8, winner_team, this, v15);
      memset(v8, 0, 0x50u);
      if ( winner_team )
        v16 = s_bm_current_air_resistance;
      else
        v16 = 0.0;
      v8->nearest_positions[0] = v16;
      v8->nearest_positions[1] = v16;
      v8->owner_team = winner_team;
    }
  }
  else
  {
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::operator()(
      v7,
      this,
      player,
      match_stats_event_victory_item_found,
      1);
    v8->already_found_once = 1;
  }
}
