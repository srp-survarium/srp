void __thiscall survarium::network_client::on_match_ready(
        survarium::network_client *this,
        survarium::game_state_history_item *data)
{
  survarium::pure_game_effect_emitter_base *m_object; // esi
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *p_m_match; // ebx
  survarium::pure_game_effect_emitter_base *v5; // esi
  survarium::network_client *v6; // esi
  survarium::pvp_match_core *v7; // ecx
  vostok::command_line::key *v8; // ecx
  survarium::game_world_core *v9; // ecx
  survarium::game_world_core *m_last; // edi
  const survarium::match_options *v11; // eax
  survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *v12; // edi
  survarium::game_world_core *v13; // ecx
  char v14; // al
  survarium::base_player *v15; // edi
  survarium::player *v16; // ecx
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *p_m_local_player; // esi
  void (__thiscall **p_enqueue)(survarium::base_match_client *, int); // edi
  int v19; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v20; // [esp+10h] [ebp-Ch] BYREF
  survarium::network_client *v21; // [esp+14h] [ebp-8h]
  unsigned __int8 player_id[4]; // [esp+18h] [ebp-4h]

  v21 = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v20,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->players.elems[0].player_state.m_raw_buffer.elems[300]);
  m_object = v20.m_object;
  data = 0;
  if ( v20.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    data = (survarium::game_state_history_item *)m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  p_m_match = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_match;
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&data,
    p_m_match);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20);
  vostok::resources::resource_ptr<survarium::server_game_project,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::server_game_project,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20,
    (const vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&p_m_match->m_object->m_lods[1]);
  v5 = v20.m_object;
  data = 0;
  if ( v20.m_object )
  {
    vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    data = (survarium::game_state_history_item *)v5;
    _InterlockedExchangeAdd((volatile signed __int32 *)&v5->vostok::resources::unmanaged_resource::m_flags, 1u);
  }
  v6 = v21;
  survarium::game_world::set_game_project(
    (const vostok::resources::resource_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base> *)&data,
    &v21->m_game->m_game_world);
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20);
  survarium::game_world::set_match(
    (survarium::game_world *)p_m_match,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v6->m_game->m_game_world);
  survarium::pvp_match_core::on_match_ready(v7, &p_m_match->m_object->__vftable);
  if ( !vostok::command_line::key::is_set(v8, (int)&s_disable_game_statistics_gathering) )
  {
    m_last = (survarium::game_world_core *)p_m_match->m_object->m_lods[1].m_emitter_instance_list.m_last;
    v11 = v6->match_options(v6);
    survarium::game_statistics_handler::start_match(&v6->m_game_statistics, v11, &v6->m_game_statistics, m_last);
  }
  v12 = (survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *)p_m_match->m_object->m_lods[1].m_emitter_instance_list.m_last;
  data = survarium::game_world_core::new_game_state_history_item(v9, (int)v12);
  survarium::game_world_core::serialize(v13, (int)v12, data);
  survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::insert(
    v12 + 492,
    data);
  v14 = *(_BYTE *)(LODWORD(p_m_match->m_object->m_lods[0].m_time_fade_out) + 29772);
  player_id[0] = 0;
  HIBYTE(data) = v14;
  if ( v14 )
  {
    v20.m_object = 0;
    do
    {
      v15 = survarium::game_world_core::player(
              (survarium::game_world_core *)p_m_match->m_object->m_lods[1].m_emitter_instance_list.m_last,
              player_id[0]);
      survarium::player::set_effect_presenter(
        (survarium::player *)v20.m_object,
        (int)v15,
        (survarium::base_game_effect_presenter *)&v6->m_game->m_game_world.m_third_person_game_effect_presenters[(unsigned int)v20.m_object]);
      survarium::player::initialize_player_icon(v16, (int)v15);
      if ( v15->is_local )
      {
        p_m_local_player = &v21->m_local_player;
        vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::operator=(
          &v21->m_local_player,
          (vostok::particle::particle_system_instance_impl *)v15);
        LOBYTE(p_m_match->m_object->m_lods[1].m_emitter_instance_list.m_last[90].m_first_inverted_transform.lines[1].x) = p_m_local_player->m_object->id;
      }
      ++player_id[0];
      v20.m_object = (survarium::pure_game_effect_emitter_base *)((char *)v20.m_object + 560);
      v6 = v21;
    }
    while ( player_id[0] < HIBYTE(data) );
  }
  p_enqueue = (void (__thiscall **)(survarium::base_match_client *, int))&v6->m_match_client->enqueue;
  v19 = (int)v6->m_match_client->new_packet(v6->m_match_client, (vostok::match::client::messages_enum)67);
  (*p_enqueue)(v6->m_match_client, v19);
}
