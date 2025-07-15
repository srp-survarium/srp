void __thiscall survarium::game_world_core::on_player_entered_match(
        survarium::game_world_core *this,
        survarium::game_world_core *player,
        vostok::particle::particle_system_instance_impl *time_in_ms,
        survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy> > *a4)
{
  survarium::players_mask_history_item *m_first; // esi
  survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy> > *v6; // ecx
  survarium::players_mask_history_item *v7; // edi
  survarium::players_mask_history_item *m_last; // eax
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *v9; // eax
  survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *v10; // ecx
  int v11; // edi
  vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *m_begin; // esi
  vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *m_end; // ebx
  char v14; // [esp+17h] [ebp+Bh]

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
    v14 = 1;
    v7 = m_first;
  }
  else
  {
    m_last = player->m_active_clients_history.m_items.m_last;
    v14 = 0;
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
  if ( v14 )
    v9 = (vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *)m_first;
  else
    v9 = survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy>>::new_item(
           v6,
           (int)&player->m_active_clients_history);
  v10 = (survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *)a4;
  *(_DWORD *)&v9->data[8] = v7->clients_mask | (1 << time_in_ms->m_lods[1].m_emitter_instance_list.gap4);
  *(_DWORD *)&v9->data[12] = a4;
  if ( v14 )
    goto LABEL_23;
  survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy>>::insert(
    (survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *)&player->m_active_clients_history,
    (survarium::player_input_history_item *)m_first,
    (survarium::player_input_history_item *)v9);
  while ( m_first )
  {
    LOBYTE(v10) = time_in_ms->m_lods[1].m_emitter_instance_list.gap4;
    v11 = 1 << (char)v10;
    if ( ((1 << (char)v10)
        & survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::greater_equal>(
            v10,
            (int)player,
            m_first->time_in_ms)->players_events_masks.elems[2]) != 0 )
      break;
    m_first->clients_mask |= v11;
LABEL_23:
    m_first = m_first->next;
  }
  survarium::game_world_core::make_client_active(time_in_ms, player);
  m_begin = player->m_game_rules.m_begin;
  m_end = player->m_game_rules.m_end;
  while ( m_begin != m_end )
  {
    m_begin->m_object->on_player_entered_match(
      m_begin->m_object,
      (survarium::base_player *)time_in_ms,
      (const unsigned int)a4);
    ++m_begin;
  }
}
