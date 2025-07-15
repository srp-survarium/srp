void __userpurge survarium::game_world_core::process_events(
        const survarium::game_event_history_item *item@<esi>,
        survarium::game_world_core *this)
{
  survarium::game_world_core *v2; // eax
  survarium::game_world_core **m_begin; // ebx
  survarium::game_world_core *v4; // edi
  survarium::player_input_history_item *m_first; // eax
  int v6; // ecx
  int v7; // ecx
  vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *m_end; // [esp+8h] [ebp-4h]

  v2 = this;
  m_begin = (survarium::game_world_core **)this->m_clients.m_begin;
  m_end = this->m_clients.m_end;
  if ( m_begin != (survarium::game_world_core **)m_end )
  {
    while ( 1 )
    {
      if ( (item->sync_infos.elems[(unsigned __int8)(*m_begin)->m_game_events_history.m_allocator.m_buffer[232]].my_events_mask
          & 2) != 0 )
        survarium::game_world_core::on_player_entered_match(
          *m_begin,
          v2,
          (vostok::particle::particle_system_instance_impl *)*m_begin,
          (survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy> > *)item->time_in_ms);
      v4 = *m_begin;
      if ( (item->sync_infos.elems[(unsigned __int8)(*m_begin)->m_game_events_history.m_allocator.m_buffer[232]].my_events_mask
          & 1) != 0 )
      {
        m_first = this->m_players_inputs_history.m_begin[(unsigned __int8)(*m_begin)->m_game_events_history.m_allocator.m_buffer[232]].m_items.m_first;
        if ( m_first )
        {
          while ( m_first->time_in_ms < item->time_in_ms )
          {
            m_first = m_first->next;
            if ( !m_first )
              goto LABEL_10;
          }
        }
        else
        {
LABEL_10:
          m_first = 0;
        }
        if ( survarium::are_different(
               &m_first->input,
               (const survarium::player_input *)&v4->m_game_events_history.m_allocator.m_buffer[672]) )
        {
          (*(void (__thiscall **)(survarium::game_world_core *, unsigned int, int))(v4->m_game_events_history.m_items.m_size
                                                                                  + 44))(
            v4,
            item->time_in_ms,
            v6);
        }
      }
      v7 = (unsigned __int8)(*m_begin)->m_game_events_history.m_allocator.m_buffer[232];
      if ( (item->sync_infos.elems[v7].my_events_mask & 4) != 0 )
        survarium::game_world_core::on_player_left_match(
          (survarium::game_world_core *)(v7 * 16),
          this,
          (survarium::base_player *)*m_begin,
          (survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy> > *)item->time_in_ms);
      if ( ++m_begin == (survarium::game_world_core **)m_end )
        break;
      v2 = this;
    }
  }
}
