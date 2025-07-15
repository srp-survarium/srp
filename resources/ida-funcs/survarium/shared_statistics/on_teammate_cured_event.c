void __thiscall survarium::shared_statistics::on_teammate_cured_event(
        survarium::shared_statistics *this,
        unsigned __int8 initiator)
{
  survarium::shared_statistics::on_event(
    this,
    &this->m_player_stats.elems[initiator],
    1u,
    match_stats_event_teammate_cure);
}
