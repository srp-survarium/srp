void __thiscall survarium::game_world::tick(
        survarium::game_world *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> frame_delta_ms,
        unsigned int current_time_in_ms,
        bool is_game_paused)
{
  survarium::game *m_game; // esi
  int v6; // edi
  survarium::game_world_core *m_game_world_core; // edx
  _DWORD *v8; // eax
  survarium::pvp_match_core *m_object; // ecx
  vostok::particle::particle_system_instance_impl *v10; // edi
  unsigned int time_in_ms; // edx
  survarium::game_world_core *v12; // eax
  survarium::game_world_core *v13; // eax
  survarium::match_options *v14; // eax
  survarium::match_options *v15; // esi
  vostok::tasks::task_manager *v16; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v17; // ecx
  bool v18; // zf
  survarium::player *v19; // ecx
  unsigned __int8 v20; // al
  survarium::game_world_core *v21; // eax
  vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> *m_begin; // esi
  survarium::free_fly_camera *m_free_fly_camera; // eax
  survarium::free_fly_camera **m_camera_director; // ecx
  survarium::game_world_core *v25; // eax
  survarium::game_statistic_event_history_item *m_first; // edx
  vostok::particle::particle_system_instance_impl *m_last_update_history_time_ms; // edi
  survarium::game_statistic_event_history_item *v28; // eax
  survarium::game_statistic_event_history_item *i; // esi
  survarium::flash_text_manager *m_text_manager; // ebx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::player>,boost::_bi::list1<boost::_bi::value<survarium::player *> > > v31; // [esp-8h] [ebp-6Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v32; // [esp+1Ch] [ebp-48h] BYREF
  survarium::game_world_ui *v33; // [esp+20h] [ebp-44h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v34; // [esp+24h] [ebp-40h] BYREF
  bool is_sealed[4]; // [esp+28h] [ebp-3Ch]
  void (__thiscall *is_server_aware_of)(survarium::player *); // [esp+2Ch] [ebp-38h] BYREF
  int v37; // [esp+30h] [ebp-34h]
  vostok::particle::particle_system_instance_impl *v38; // [esp+34h] [ebp-30h]
  int v39; // [esp+38h] [ebp-2Ch]
  unsigned int v40; // [esp+3Ch] [ebp-28h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::player>,boost::_bi::list1<boost::_bi::value<survarium::player *> > > f; // [esp+44h] [ebp-20h] BYREF

  survarium::base_game_scene::tick(this, (unsigned int)frame_delta_ms.m_object, current_time_in_ms, is_game_paused);
  survarium::base_network_client::get_current_player(this->m_game->m_network_client, &v32);
  m_game = this->m_game;
  if ( v32.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( !m_game->m_network_client->m_is_spectator )
      {
        v6 = *(_DWORD *)((char *)&loc_11403 + (unsigned int)v32.m_object + 5);
        if ( survarium::are_different(
               (const survarium::player_input *)(v6 + 824),
               (const survarium::player_input *)(v6 + 836)) )
        {
          if ( LOBYTE(v32.m_object->m_skeleton_model.m_object) )
          {
            if ( *(_BYTE *)(v6 + 869) )
            {
              m_game_world_core = this->m_match.m_object->m_game_world_core;
              if ( m_game_world_core->m_game_states_history.m_items.m_first )
              {
                if ( !m_game->m_time_was_eaten_last_tick )
                {
                  LOBYTE(is_server_aware_of) = v32.m_object->m_lods[1].m_emitter_instance_list.gap4;
                  v37 = *(_DWORD *)(v6 + 824);
                  v38 = *(vostok::particle::particle_system_instance_impl **)(v6 + 828);
                  v39 = *(_DWORD *)(v6 + 832);
                  v40 = current_time_in_ms;
                  if ( !survarium::game_world_core::change_input(
                          (survarium::game_world_core *)&is_server_aware_of,
                          m_game_world_core,
                          (unsigned __int8 *)&is_server_aware_of,
                          0) )
                    this->m_game->m_network_client->on_new_input(this->m_game->m_network_client, current_time_in_ms);
                }
              }
            }
          }
          v8 = *(_DWORD **)((char *)&loc_11403 + (unsigned int)v32.m_object + 5);
          v8[209] = v8[206];
          v8[210] = v8[207];
          v8[211] = v8[208];
        }
      }
    }
  }
  m_object = this->m_match.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v10 = v32.m_object;
    time_in_ms = current_time_in_ms;
    if ( v32.m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        if ( !*(_BYTE *)(*(_DWORD *)((char *)&loc_11403 + (unsigned int)v32.m_object + 5) + 869) )
        {
          v12 = m_object->m_game_world_core;
          if ( v12->m_game_states_history.m_items.m_first )
          {
            if ( v12->m_game_events_history.m_items.m_first )
              time_in_ms = v12->m_game_events_history.m_items.m_last->time_in_ms;
          }
        }
      }
    }
    v13 = m_object->m_game_world_core;
    if ( v13->m_game_states_history.m_items.m_first && v13->m_start_fixed_time_in_ms != -1 )
      survarium::game_world_core::move((survarium::game_world_core *)m_object, v13, time_in_ms);
    v14 = this->m_game->m_network_client->match_options(this->m_game->m_network_client);
    v15 = v14;
    *(_DWORD *)is_sealed = v14;
    LOBYTE(v33) = 0;
    if ( s_mt_player_draw )
    {
      if ( v14->players_count )
      {
        do
        {
          this->m_game->m_network_client->get_active_player(
            this->m_game->m_network_client,
            (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&v34,
            (const unsigned __int8)v33);
          if ( v34.m_object
            && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          {
            v38 = v34.m_object;
            is_server_aware_of = survarium::player::mt_draw;
            v37 = 0;
            HIDWORD(v31.f_.f_) = survarium::player::mt_draw;
            v31.l_.a1_.t_ = 0;
            *((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31.l_
            + 1) = v34;
            LODWORD(v31.f_.f_) = &f;
            boost::function<void __cdecl (void)>::function<void __cdecl (void)>(0, v31, v39);
            vostok::tasks::task_manager::spawn_task(
              v16,
              (vostok::tasks::task *)&f,
              (boost::function<void __cdecl(void)> *)this->m_draw_player_task_type,
              0);
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              v17,
              (int *)&f);
            v15 = *(survarium::match_options **)is_sealed;
          }
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v34);
          LOBYTE(v33) = (_BYTE)v33 + 1;
        }
        while ( (unsigned __int8)v33 < v15->players_count );
        v10 = v32.m_object;
      }
      vostok::tasks::wait_for_all_children();
    }
    else if ( v14->players_count )
    {
      do
      {
        this->m_game->m_network_client->get_active_player(
          this->m_game->m_network_client,
          (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&v34,
          (const unsigned __int8)v33);
        if ( v34.m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          survarium::player::mt_draw((survarium::player *)v34.m_object);
        }
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v34);
        LOBYTE(v33) = (_BYTE)v33 + 1;
      }
      while ( (unsigned __int8)v33 < v15->players_count );
    }
    v18 = v15->players_count == 0;
    LOBYTE(v33) = 0;
    if ( !v18 )
    {
      do
      {
        this->m_game->m_network_client->get_active_player(
          this->m_game->m_network_client,
          (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&v34,
          (const unsigned __int8)v33);
        if ( v34.m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          survarium::player::st_draw(v19, (survarium::base_player *)v34.m_object);
        }
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v34);
        LOBYTE(v33) = (_BYTE)v33 + 1;
      }
      while ( (unsigned __int8)v33 < v15->players_count );
    }
    if ( v10
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v20 = v10->m_lods[1].m_emitter_instance_list.gap4;
    }
    else
    {
      v20 = -1;
    }
    this->game_ui.m_hud_state.current_player_id = v20;
    v21 = this->m_match.m_object->m_game_world_core;
    m_begin = v21->m_game_rules.m_begin;
    for ( *(_DWORD *)is_sealed = v21->m_game_rules.m_end;
          m_begin != *(vostok::resources::resource_ptr<survarium::game_match_rule_base,vostok::resources::unmanaged_intrusive_base> **)is_sealed;
          ++m_begin )
    {
      m_begin->m_object->fill_match_hud_state(m_begin->m_object, &this->game_ui.m_hud_state, current_time_in_ms);
    }
    m_free_fly_camera = this->m_free_fly_camera;
    m_camera_director = (survarium::free_fly_camera **)this->m_camera_director;
    if ( m_camera_director[33] == m_free_fly_camera )
      survarium::game_effect_player::present(
        (survarium::game_effect_player *)&this->m_first_person_game_effect_presenter,
        (int)&m_free_fly_camera->m_effect_player,
        &this->m_first_person_game_effect_presenter,
        0);
    v25 = this->m_match.m_object->m_game_world_core;
    m_first = v25->m_game_statistic_events_history.m_items.m_first;
    m_last_update_history_time_ms = (vostok::particle::particle_system_instance_impl *)this->game_ui.m_last_update_history_time_ms;
    v34.m_object = m_last_update_history_time_ms;
    if ( m_first )
    {
      m_camera_director = (survarium::free_fly_camera **)(v25->m_max_current_time_in_ms
                                                        - v25->m_event_horizon_interval_in_ms);
      v28 = m_first;
      v33 = (survarium::game_world_ui *)m_camera_director;
      do
      {
        if ( v28->time_in_ms > (unsigned int)m_last_update_history_time_ms )
          break;
        v28 = v28->next;
      }
      while ( v28 );
      for ( i = v28; i; i = i->next )
      {
        v18 = (unsigned int)m_camera_director < i->time_in_ms;
        is_sealed[0] = (unsigned int)m_camera_director >= i->time_in_ms;
        if ( !v18 || i->skip_horizon_time )
        {
          survarium::game_world_ui::process_statistic_event(&this->game_ui, i, is_sealed[0]);
          m_last_update_history_time_ms = v34.m_object;
          m_camera_director = (survarium::free_fly_camera **)v33;
        }
      }
    }
    if ( this->m_is_ui_shown )
      survarium::game_world_ui::update_ui(
        (survarium::game_world_ui *)m_camera_director,
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)&this->game_ui,
        frame_delta_ms,
        *(float *)&current_time_in_ms,
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)(m_last_update_history_time_ms != (vostok::particle::particle_system_instance_impl *)this->game_ui.m_last_update_history_time_ms));
    m_text_manager = this->m_text_manager;
    if ( m_text_manager->need_capture )
    {
      Scaleform::GFx::DrawTextManager::Capture(m_text_manager->text_manager_impl, 1);
      m_text_manager->need_capture = 0;
    }
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v32);
}
