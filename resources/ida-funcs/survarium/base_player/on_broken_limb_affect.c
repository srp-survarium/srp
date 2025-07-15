void __thiscall survarium::base_player::on_broken_limb_affect(
        survarium::base_player *this,
        const char *bodypart,
        const survarium::hit_affects_type_enum affect,
        survarium::affect_event_type_enum type,
        unsigned int current_time_in_ms)
{
  survarium::statistics_events_handler *m_statistics_events_handler; // ecx

  m_statistics_events_handler = this->m_game_world_core->m_statistics_events_handler;
  if ( m_statistics_events_handler )
    m_statistics_events_handler->on_limb_affect(m_statistics_events_handler, current_time_in_ms, this->id, type);
  this->m_need_to_select_animations = 1;
}
