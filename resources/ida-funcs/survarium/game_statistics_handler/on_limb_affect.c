void __thiscall survarium::game_statistics_handler::on_limb_affect(
        survarium::game_statistics_handler *this,
        survarium::curing_event_status *current_time_in_ms,
        unsigned __int8 player,
        survarium::affect_event_type_enum affect_event)
{
  survarium::curing_event_status *v4; // eax

  if ( affect_event == affect_canceling )
  {
    v4 = &this->m_shared_statistics.m_teammate_cure_event_manager.m_curing_event_statuses.elems[player];
    if ( (survarium::curing_event_status *)v4->m_last_canceled_affect_time != current_time_in_ms )
    {
      v4->m_last_canceled_affect_time = (unsigned int)current_time_in_ms;
      survarium::curing_event_status::on_event_conditions_are_met(current_time_in_ms);
    }
  }
}
