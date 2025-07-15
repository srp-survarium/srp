void __thiscall survarium::game_world_core::on_player_left_match(
        survarium::game_world_core *this,
        survarium::game_world_core *player,
        survarium::base_player *time_in_ms,
        survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy> > *a4)
{
  survarium::players_mask_history_item *m_first; // esi
  survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy> > *v6; // ecx
  survarium::players_mask_history_item *v7; // edi
  survarium::players_mask_history_item *m_last; // eax
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *v9; // eax
  vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *m_begin; // esi
  vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *m_end; // edi
  char v12; // [esp+17h] [ebp+Bh]

  m_first = player->m_active_clients_history.m_items.m_first;
  if ( m_first )
  {
    while ( 1 )
    {
      v6 = a4;
      if ( m_first->time_in_ms >= (unsigned int)a4 )
        break;
      m_first = m_first->next;
      if ( !m_first )
        goto LABEL_6;
    }
  }
  else
  {
    v6 = a4;
LABEL_6:
    m_first = 0;
  }
  if ( m_first
    && (survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy> > *)m_first->time_in_ms == v6 )
  {
    v12 = 1;
    v7 = m_first;
  }
  else
  {
    m_last = player->m_active_clients_history.m_items.m_last;
    v12 = 0;
    while ( 1 )
    {
      if ( !m_last )
      {
        v7 = 0;
        goto LABEL_15;
      }
      if ( m_last->time_in_ms < (unsigned int)v6 )
        break;
      m_last = m_last->prev;
    }
    v7 = m_last;
  }
LABEL_15:
  if ( v12 )
    v9 = (vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *)m_first;
  else
    v9 = survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy>>::new_item(
           v6,
           (int)&player->m_active_clients_history);
  *(_DWORD *)&v9->data[8] = v7->clients_mask & ~(1 << time_in_ms->id);
  *(_DWORD *)&v9->data[12] = a4;
  if ( v12 )
    goto LABEL_22;
  survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy>>::insert(
    (survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *)&player->m_active_clients_history,
    (survarium::player_input_history_item *)m_first,
    (survarium::player_input_history_item *)v9);
  while ( m_first )
  {
    m_first->clients_mask &= ~(1 << time_in_ms->id);
LABEL_22:
    m_first = m_first->next;
  }
  m_begin = player->m_game_rules.m_begin;
  m_end = player->m_game_rules.m_end;
  while ( m_begin != m_end )
  {
    m_begin->m_object->on_player_left_match(m_begin->m_object, time_in_ms, (const unsigned int)a4);
    ++m_begin;
  }
  survarium::game_world_core::make_client_inactive(player, time_in_ms);
}
