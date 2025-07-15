void __thiscall survarium::game_statistics_handler::on_event(
        survarium::game_statistics_handler *this,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *player,
        survarium::match_stats_events_dict_enum event,
        unsigned __int16 count)
{
  __int16 *v5; // esi
  __int16 v6; // bx
  float v7; // xmm0_4
  survarium::game_statistics_handler *v8; // [esp+0h] [ebp-14h]

  v5 = &this->m_players_scores.elems[(unsigned __int8)player];
  v6 = *v5;
  if ( event == match_stats_event_bring_victory_item
    || event == match_stats_event_steal_victory_item
    || event == match_stats_event_recover_victory_item )
  {
    v7 = FLOAT_0_0099999998;
  }
  else
  {
    v7 = s_bm_current_air_resistance;
  }
  *v5 += vostok::math::floor((float)((float)((float)this->m_match_options->events_scores.elems[event] * (float)count)
                                   * v7) + 0.5);
  if ( *v5 != v6 )
    survarium::game_statistics_handler::emit_score_changed_event(
      v8,
      (int)this,
      player,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(unsigned __int16)*v5);
}
