void __thiscall survarium::game_statistics_handler::on_artefact_took(
        survarium::game_statistics_handler *this,
        unsigned __int8 holder)
{
  survarium::shared_statistics::on_event(
    &this->m_shared_statistics,
    &this->m_shared_statistics.m_player_stats.elems[holder],
    1u,
    match_stats_event_artefact);
}
