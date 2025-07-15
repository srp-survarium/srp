void __thiscall survarium::game_world_core::~game_world_core(survarium::game_world_core *this, int a2)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *i; // edi
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> > *v4; // ecx
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> > *v5; // ecx
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> > *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  survarium::history<survarium::game_statistic_event_history_item,vostok::memory::single_size_fixed_allocator<44,540,vostok::threading::single_threading_policy> > *v8; // ecx
  survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *v9; // ecx
  survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *v10; // ecx
  survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *v11; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *v13; // ecx
  survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *v14; // [esp-4h] [ebp-14h]

  *(_DWORD *)(*(_DWORD *)(a2 + 51160) + 176) = 0;
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 51156));
  v2 = *(boost::function1<void,vostok::sound::create_sound_propagator_params const &> **)(a2 + 50124);
  *(_DWORD *)(a2 + 50128) = v2;
  for ( i = *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 49600);
        i != *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 49604);
        ++i )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  }
  *(_DWORD *)(a2 + 49604) = *(_DWORD *)(a2 + 49600);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)(a2 + 49568));
  survarium::registry_of_artefacts::unregister_artefacts(
    v4,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 49504));
  survarium::registry_of_artefacts::unregister_artefacts(
    v5,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 49412));
  survarium::registry_of_artefacts::unregister_artefacts(
    v6,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 49320));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)(a2 + 25512));
  while ( *(_DWORD *)(a2 + 25492) )
    survarium::history<survarium::game_statistic_event_history_item,vostok::memory::single_size_fixed_allocator<44,540,vostok::threading::single_threading_policy>>::pop_front(
      v8,
      (_DWORD *)(a2 + 25488));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v8,
    (int *)(a2 + 25008));
  while ( *(_DWORD *)(a2 + 24988) )
    survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy>>::pop_front(
      v9,
      (_DWORD *)(a2 + 24984));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v9,
    (int *)(a2 + 24296));
  while ( *(_DWORD *)(a2 + 24276) )
    survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy>>::pop_front(
      v10,
      (_DWORD *)(a2 + 24272));
  vostok::buffer_vector<survarium::fixed_history<survarium::player_input_history_item,27>>::destroy(
    *(survarium::fixed_history<survarium::player_input_history_item,27> **)(a2 + 9860),
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
    (survarium::fixed_history<survarium::player_input_history_item,27> **)(a2 + 9864));
  v11 = v14;
  *(_DWORD *)(a2 + 9864) = *(_DWORD *)(a2 + 9860);
  while ( *(_DWORD *)(a2 + 9844) )
    survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::pop_front(
      v11,
      (_DWORD *)(a2 + 9840));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
    (int *)(a2 + 9792));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v12,
    (int *)(a2 + 24));
  while ( *(_DWORD *)(a2 + 4) )
    survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy>>::pop_front(
      v13,
      (_DWORD *)a2);
}
