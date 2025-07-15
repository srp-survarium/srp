void __thiscall survarium::game_world_core::trim_statistic_events_history(
        survarium::game_world_core *this,
        unsigned int time_in_ms)
{
  survarium::game_statistic_event_history_item *m_last; // eax
  survarium::game_statistic_event_history_item *prev; // esi
  survarium::game_statistic_event_history_item *next; // edx
  vostok::memory::single_size_fixed_allocator<44,540,vostok::threading::single_threading_policy> *m_allocator; // edx

  for ( ; this->m_game_statistic_events_history.m_items.m_first; --m_allocator->m_allocated_count )
  {
    m_last = this->m_game_statistic_events_history.m_items.m_last;
    if ( m_last->time_in_ms <= time_in_ms )
      break;
    if ( this->m_game_statistic_events_history.m_items.m_first )
    {
      prev = m_last->prev;
      next = m_last->next;
      m_last->prev = 0;
      m_last->next = 0;
      if ( prev )
        prev->next = next;
      else
        this->m_game_statistic_events_history.m_items.m_first = next;
      if ( next )
        next->prev = prev;
      else
        this->m_game_statistic_events_history.m_items.m_last = prev;
      m_last->prev = 0;
      m_last->next = 0;
      --this->m_game_statistic_events_history.m_items.m_size;
    }
    m_allocator = this->m_game_statistic_events_history.m_allocator;
    m_last->data0.u32_arg = (unsigned int)m_allocator->m_free_list_head.pointer;
    m_allocator->m_free_list_head.pointer = (vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *)m_last;
  }
}
