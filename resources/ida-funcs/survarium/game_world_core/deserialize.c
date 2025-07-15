void __usercall survarium::game_world_core::deserialize(
        survarium::game_world_core *this@<edi>,
        const survarium::game_state_history_item *item@<eax>)
{
  survarium::players_mask_history_item *m_last; // eax
  survarium::bullet_manager *v4; // ecx
  unsigned int m_active_clients_mask; // eax
  survarium::bullet **m_begin; // ecx
  int v7; // edx
  int v8; // ebx
  survarium::bullet_manager *i; // ebx
  unsigned __int8 v10; // al
  vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *v11; // ebx
  bool j; // zf
  survarium::base_player *m_object; // ebx
  survarium::player_history_item *v14; // eax
  unsigned int m_buffer; // ecx
  unsigned __int8 *v16; // edx
  survarium::base_player_vtbl *v17; // ecx
  int v18; // ebx
  vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *v19; // ebx
  survarium::statistics_events_handler *m_statistics_events_handler; // ecx
  int v21; // edx
  vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *v22; // ecx
  vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *v23; // eax
  survarium::serializable_object *m_first; // ecx
  survarium::serializable_object *k; // esi
  vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *v26; // esi
  int v27; // [esp-4h] [ebp-54h]
  _DWORD v28[3]; // [esp+Ch] [ebp-44h] BYREF
  _DWORD v29[3]; // [esp+18h] [ebp-38h] BYREF
  unsigned int time_offset; // [esp+24h] [ebp-2Ch] BYREF
  unsigned int v31; // [esp+28h] [ebp-28h]
  unsigned int m_size; // [esp+2Ch] [ebp-24h]
  _DWORD v33[3]; // [esp+30h] [ebp-20h] BYREF
  vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *m_end; // [esp+3Ch] [ebp-14h]
  survarium::base_player_vtbl *v35; // [esp+40h] [ebp-10h]
  unsigned int v36; // [esp+44h] [ebp-Ch]
  survarium::bullet_manager *v37; // [esp+48h] [ebp-8h]
  int v38; // [esp+4Ch] [ebp-4h]

  this->m_in_deserialize_now = 1;
  survarium::game_world_core::trim_statistic_events_history(
    this,
    *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1]);
  m_last = this->m_active_clients_history.m_items.m_last;
  if ( m_last )
  {
    while ( m_last->time_in_ms > *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1] )
    {
      m_last = m_last->prev;
      if ( !m_last )
        goto LABEL_4;
    }
    v4 = (survarium::bullet_manager *)m_last;
  }
  else
  {
LABEL_4:
    v4 = 0;
  }
  m_active_clients_mask = this->m_active_clients_mask;
  v37 = 0;
  if ( (survarium::bullet **)m_active_clients_mask != v4->m_bullets.m_begin )
  {
    m_begin = v4->m_bullets.m_begin;
    v7 = m_active_clients_mask & (unsigned int)m_begin;
    v4 = (survarium::bullet_manager *)(m_active_clients_mask & (unsigned int)m_begin ^ (unsigned int)m_begin);
    v37 = v4;
    v38 = v7 ^ m_active_clients_mask;
    if ( v7 != m_active_clients_mask )
    {
      do
      {
        v8 = (unsigned __int8)vostok::bit_index(v38 & ~(v38 - 1));
        this->m_clients.m_begin[v8].m_object->remove(this->m_clients.m_begin[v8].m_object, 1);
        survarium::game_world_core::make_client_inactive(this, this->m_clients.m_begin[v8].m_object);
        v38 &= v38 - 1;
      }
      while ( v38 );
    }
    for ( i = v37; i; i = (survarium::bullet_manager *)(((unsigned int)&i[-1].m_game_world_core + 7) & (unsigned int)i) )
    {
      v10 = vostok::bit_index((unsigned int)i & ~((unsigned int)&i[-1].m_game_world_core + 7));
      survarium::game_world_core::make_client_active(
        (vostok::particle::particle_system_instance_impl *)this->m_clients.m_begin[v10].m_object,
        this);
    }
  }
  v11 = this->m_active_clients.m_begin;
  this->m_current_time_in_ms = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1];
  m_end = this->m_active_clients.m_end;
  for ( j = v11 == m_end; ; j = v11 == m_end )
  {
    v38 = (int)v11;
    if ( j )
      break;
    if ( ((1 << v11->m_object->id) & (unsigned int)v37) == 0 )
      v11->m_object->remove(v11->m_object, 0);
    m_object = v11->m_object;
    v14 = &item->players.elems[m_object->id];
    m_buffer = (unsigned int)v14->player_state.m_buffer.m_buffer;
    m_size = v14->player_state.m_buffer.m_size;
    time_offset = m_buffer;
    v31 = m_buffer;
    v16 = v14->client_specific_state.m_buffer.m_buffer;
    v36 = v14->client_specific_state.m_buffer.m_size;
    v33[0] = v16;
    v33[1] = v16;
    v33[2] = v36;
    v17 = m_object->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable;
    v18 = item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B993F + 2];
    v35 = v17;
    v27 = v18;
    v19 = (vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *)v38;
    v17->deserialize(
      *(survarium::base_player **)v38,
      (vostok::network_core::buffer_reader *)&time_offset,
      v36 != 0 ? (vostok::network_core::buffer_reader *)v33 : 0,
      &v14->animation_tree,
      *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1],
      *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1] - 1000000000,
      v27);
    v11 = v19 + 1;
  }
  time_offset = *(_DWORD *)((char *)&loc_B6A94 + (_DWORD)item);
  v31 = time_offset;
  m_size = *(_DWORD *)((char *)&loc_B6A9C + (_DWORD)item);
  survarium::bullet_manager::deserialize(
    v4,
    this->m_bullet_manager,
    (survarium::bullet **)&time_offset,
    (vostok::network_core::buffer_reader *)(*(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1]
                                          - 1000000000));
  m_statistics_events_handler = this->m_statistics_events_handler;
  if ( m_statistics_events_handler )
  {
    v21 = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1] - 1000000000;
    time_offset = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B76BB + 1];
    v31 = time_offset;
    m_size = *(_DWORD *)((char *)&loc_B76C4 + (_DWORD)item);
    m_statistics_events_handler->deserialize(
      m_statistics_events_handler,
      (vostok::network_core::buffer_reader *)&time_offset,
      v21);
  }
  v22 = this->m_game_rules.m_end;
  v29[0] = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B78E3 + 1];
  v29[1] = v29[0];
  v29[2] = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B78EA + 2];
  v23 = this->m_game_rules.m_begin;
  v38 = (int)v23;
  m_end = (vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *)v22;
  if ( v23 != v22 )
  {
    while ( 1 )
    {
      v23->m_object->deserialize(
        v23->m_object,
        (vostok::network_core::buffer_reader *)v29,
        *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1] - 1000000000);
      v38 += 4;
      if ( (vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *)v38 == m_end )
        break;
      v23 = (vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *)v38;
    }
  }
  m_first = this->m_serializable_objects.m_first;
  v28[0] = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B990B + 1];
  v28[1] = v28[0];
  v28[2] = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9913 + 1];
  v38 = (int)m_first;
  if ( m_first )
  {
    while ( 1 )
    {
      m_first->deserialize(
        m_first,
        (vostok::network_core::buffer_reader *)v28,
        *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1] - 1000000000);
      v38 = *(_DWORD *)(v38 + 8);
      if ( !v38 )
        break;
      m_first = (survarium::serializable_object *)v38;
    }
  }
  for ( k = this->m_serializable_objects.m_first; k; k = k->next )
    k->post_deserialize_resolve(k, this);
  v26 = this->m_active_clients.m_begin;
  for ( m_end = this->m_active_clients.m_end; v26 != m_end; ++v26 )
    v26->m_object->insert(v26->m_object, ((1 << v26->m_object->id) & (unsigned int)v37) != 0);
  this->m_in_deserialize_now = 0;
}


void __thiscall survarium::game_world_core::deserialize(
        survarium::game_world_core *this,
        survarium::game_world_core *reader,
        vostok::network_core::buffer_reader *a3)
{
  survarium::game_world_core *v3; // ecx
  survarium::game_state_history_item *v4; // eax
  survarium::game_state_history_item *v5; // edi
  survarium::game_state_history_item *v6; // ecx
  survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy> > *v7; // ecx
  survarium::players_mask_history_item *m_first; // esi
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *v9; // eax
  unsigned int v10; // edi
  bool has_passed_filters; // al
  unsigned int v12; // eax
  unsigned int v13; // edx
  bool v14; // al
  unsigned int v15; // eax
  unsigned int v16; // edx
  bool v17; // zf
  survarium::game_state_history_item *v18; // esi
  vostok::network_core::buffer_reader *v19; // eax
  survarium::fixed_history<survarium::player_input_history_item,27> *v20; // eax
  survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *m_last; // ecx
  unsigned int v22; // esi
  survarium::player_input_history_item *v23; // eax
  vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *m_begin; // ecx
  survarium::base_player *m_object; // esi
  survarium::player_input_history_item *v26; // eax
  survarium::player_input *p_input; // edi
  survarium::game_state_history_item *v28; // ecx
  survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy> > *v29; // [esp-4h] [ebp-4Ch]
  survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy> > *v30; // [esp-4h] [ebp-4Ch]
  unsigned __int8 __val[4]; // [esp+10h] [ebp-38h] BYREF
  survarium::game_state_history_item *item; // [esp+14h] [ebp-34h]
  client_id_predicate __comp[4]; // [esp+18h] [ebp-30h]
  unsigned int v34; // [esp+1Ch] [ebp-2Ch]
  survarium::player_input_history_item *v35; // [esp+20h] [ebp-28h]
  survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *v36; // [esp+24h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v37; // [esp+28h] [ebp-20h] BYREF

  *(_DWORD *)__comp = 0;
  survarium::game_world_core::clear(this, (int)reader);
  survarium::game_world_core::new_game_state_history_item(v3, (int)reader);
  v5 = v4;
  item = v4;
  v34 = (unsigned int)survarium::game_state_history_item::deserialize(
                        v6,
                        (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)v4,
                        a3);
  survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::insert(
    &reader->m_game_states_history,
    v5);
  m_first = reader->m_active_clients_history.m_items.m_first;
  if ( m_first )
  {
    while ( m_first->time_in_ms < *(_DWORD *)&v5->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937
                                                                                                 + 1] )
    {
      m_first = m_first->next;
      if ( !m_first )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    m_first = 0;
  }
  if ( m_first
    && m_first->time_in_ms == *(_DWORD *)&v5->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1] )
  {
    m_first->clients_mask = v34;
  }
  else
  {
    v9 = survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy>>::new_item(
           v7,
           (int)&reader->m_active_clients_history);
    *(_DWORD *)&v9->data[8] = v34;
    *(_DWORD *)&v9->data[12] = *(_DWORD *)&v5->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1];
    survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy>>::insert(
      (survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *)&reader->m_active_clients_history,
      (survarium::player_input_history_item *)m_first,
      (survarium::player_input_history_item *)v9);
    v10 = v34;
    while ( m_first )
    {
      v10 &= ~survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::greater_equal>(
                (survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *)v7,
                (int)reader,
                m_first->time_in_ms)->players_events_masks.elems[2];
      m_first->clients_mask |= v10;
      m_first = m_first->next;
    }
  }
  if ( reader->m_is_first_time )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"net_sync",
                                 (const char *)4),
          v7 = v29,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v7,
        &v37);
      v12 = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1] / 0x3E8u;
      v13 = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1] % 0x3E8u;
      *(_DWORD *)__comp = 1;
      vostok::logging::append(
        &v37,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x137u,
        "void __thiscall survarium::game_world_core::deserialize(class vostok::network_core::buffer_reader &)",
        "net_sync",
        info,
        "--- THE VERY FIRST SYNCHRONIZATION --- %d.%03d",
        v12,
        v13);
    }
    if ( (*(_BYTE *)__comp & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
        (int *)&v37);
    last_hash_time_in_ms = 0;
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (v14 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_sync", (const char *)3),
          v7 = v30,
          v14) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v7,
        &v37);
      v15 = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1] / 0x3E8u;
      v16 = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1] % 0x3E8u;
      *(_DWORD *)__comp = 2;
      vostok::logging::append(
        &v37,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x13Bu,
        "void __thiscall survarium::game_world_core::deserialize(class vostok::network_core::buffer_reader &)",
        "net_sync",
        warning,
        "--- FULL RESYNC --- %d.%03d",
        v15,
        v16);
    }
    if ( (*(_BYTE *)__comp & 2) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
        (int *)&v37);
    if ( (reader->m_resync_event_callback.vtable != 0
        ? (unsigned int)vostok::memory::process_allocator::finalize_impl
        : 0) != 0 )
      boost::function1<void,vostok::collision::object const &>::operator()(
        (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)item,
        &reader->m_resync_event_callback.vtable,
        *(const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> **)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1]);
  }
  survarium::game_world_core::deserialize(reader, item);
  v17 = !reader->m_is_first_time;
  v18 = item;
  reader->m_max_current_time_in_ms = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1];
  reader->m_last_resync_time_in_ms = *(_DWORD *)&v18->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1];
  if ( !v17 )
  {
    v19 = (vostok::network_core::buffer_reader *)v34;
    reader->m_is_first_time = 0;
    v34 = (unsigned int)v19;
    if ( v19 )
    {
      while ( 1 )
      {
        __val[0] = vostok::bit_index(v34 & ~(v34 - 1));
        v20 = &reader->m_players_inputs_history.m_begin[__val[0]];
        m_last = (survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *)v20->m_items.m_last;
        v36 = v20;
        if ( m_last )
        {
          v22 = *(_DWORD *)&v18->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1];
          do
          {
            if ( m_last[1].m_items.m_size <= v22 )
              break;
            m_last = (survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *)m_last->m_items.m_first;
          }
          while ( m_last );
        }
        v23 = (survarium::player_input_history_item *)survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy>>::new_item(
                                                        m_last,
                                                        (int)v20);
        m_begin = reader->m_active_clients.m_begin;
        v35 = v23;
        __comp[0] = 0;
        m_object = stlp_std::lower_bound<vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *,unsigned char,client_id_predicate>(
                     m_begin,
                     reader->m_active_clients.m_end,
                     __val)->m_object;
        v26 = v35;
        m_object = (survarium::base_player *)((char *)m_object + 744);
        p_input = &v35->input;
        LODWORD(v35->input.rotation_delta.x) = m_object->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable;
        m_object = (survarium::base_player *)((char *)m_object + 4);
        p_input = (survarium::player_input *)((char *)p_input + 4);
        LODWORD(p_input->rotation_delta.x) = m_object->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable;
        v28 = item;
        LODWORD(p_input->rotation_delta.y) = m_object->type;
        v26->time_in_ms = *(_DWORD *)&v28->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1];
        survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy>>::insert(
          v36,
          0,
          v26);
        v34 &= v34 - 1;
        if ( !v34 )
          break;
        v18 = item;
      }
    }
  }
}
