void __thiscall survarium::game_statistics_handler::on_player_damaged(
        survarium::game_statistics_handler *this,
        unsigned int current_time_in_ms,
        unsigned __int8 initiator,
        survarium::player_stances_enum initiator_stance,
        unsigned __int8 receiver,
        float amount,
        survarium::profile_slot_enum weapon_slot,
        bool bullet_first_hit)
{
  survarium::intermediate_shared_statistics *p_intermediate; // eax

  if ( initiator != 0xFF
    && this->m_shared_statistics.m_match_options->player_profiles.elems[initiator].team != this->m_shared_statistics.m_match_options->player_profiles.elems[receiver].team )
  {
    p_intermediate = &this->m_shared_statistics.m_player_stats.elems[initiator].intermediate;
    p_intermediate->last_hit_ms.elems[receiver] = current_time_in_ms;
    p_intermediate->last_hit_enemy_id = receiver;
  }
}
