void __thiscall survarium::base_player::on_pain_regenerated(survarium::base_player *this)
{
  survarium::statistics_events_handler *m_statistics_events_handler; // eax

  m_statistics_events_handler = this->m_game_world_core->m_statistics_events_handler;
  if ( m_statistics_events_handler )
    m_statistics_events_handler->on_pain_body_part_regenerated(m_statistics_events_handler, this->id);
}
