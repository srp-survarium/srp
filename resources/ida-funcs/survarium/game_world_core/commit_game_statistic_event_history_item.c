void __usercall survarium::game_world_core::commit_game_statistic_event_history_item(
        survarium::game_world_core *this@<edx>,
        survarium::game_statistic_event_history_item *item@<eax>)
{
  vostok::memory::single_size_fixed_allocator<44,540,vostok::threading::single_threading_policy> *m_allocator; // ecx
  survarium::game_statistic_event_history_item *m_first; // ecx
  survarium::game_statistic_event_history_item *v4; // esi

  if ( this->m_in_deserialize_now )
  {
    m_allocator = this->m_game_statistic_events_history.m_allocator;
    item->data0.u32_arg = (unsigned int)m_allocator->m_free_list_head.pointer;
    m_allocator->m_free_list_head.pointer = (vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *)item;
    --m_allocator->m_allocated_count;
  }
  else
  {
    m_first = this->m_game_statistic_events_history.m_items.m_first;
    if ( m_first )
    {
      while ( m_first->time_in_ms <= item->time_in_ms )
      {
        m_first = m_first->next;
        if ( !m_first )
          goto LABEL_6;
      }
      v4 = m_first;
    }
    else
    {
LABEL_6:
      v4 = 0;
    }
    survarium::history<survarium::game_statistic_event_history_item,vostok::memory::single_size_fixed_allocator<44,540,vostok::threading::single_threading_policy>>::insert(
      &this->m_game_statistic_events_history,
      v4,
      item);
  }
}
