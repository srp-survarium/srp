void __thiscall survarium::game_statistics_handler::on_pain_body_part_damage_received(
        survarium::game_statistics_handler *this,
        unsigned __int8 initiator,
        unsigned __int8 receiver,
        float amount)
{
  float *v4; // eax

  if ( initiator != 0xFF
    && this->m_shared_statistics.m_match_options->player_profiles.elems[initiator].team != this->m_shared_statistics.m_match_options->player_profiles.elems[receiver].team )
  {
    v4 = &this->m_shared_statistics.m_player_stats.elems[receiver].intermediate.received_damage.elems[initiator];
    *v4 = *v4 + amount;
  }
}
