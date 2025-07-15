void __userpurge survarium::medkit::set_active(
        survarium::medkit *this@<edi>,
        bool active@<al>,
        unsigned int current_time_in_ms)
{
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v3; // eax
  vostok::intrusive_list<survarium::medkit_actions_subscriber,survarium::medkit_actions_subscriber *,32,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy> *v4; // ecx
  bool v5; // zf
  survarium::damage_model *m_object; // esi
  vostok::intrusive_list<survarium::medkit_actions_subscriber,survarium::medkit_actions_subscriber *,32,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy> *v7; // ecx
  survarium::damage_model *v8; // ecx
  survarium::statistics_events_handler *v9; // ebx
  void (__thiscall **v10)(survarium::statistics_events_handler *, survarium::medkit *, int, _DWORD); // esi
  survarium::base_player *v11; // eax
  survarium::base_player *v12; // eax
  survarium::statistics_events_handler *m_statistics_events_handler; // ebx
  void (__thiscall **p_on_medkit_action)(_DWORD, _DWORD, _DWORD, _DWORD); // esi
  survarium::base_player *v15; // eax
  unsigned int i; // eax
  int v17; // ebx
  survarium::medkit::damage_protection *v18; // esi
  survarium::notify_medkit_activate v19; // [esp+8h] [ebp-10h] BYREF
  survarium::damage_model *v20; // [esp+14h] [ebp-4h]
  unsigned int j; // [esp+20h] [ebp+8h]

  this->m_active = active;
  v3 = this->m_inventory->m_holder->damage_model(this->m_inventory->m_holder);
  v5 = !this->m_active;
  m_object = v3->m_object;
  v20 = v3->m_object;
  if ( v5 )
  {
    if ( (double)this->m_delay_ms == 0.0 && this->m_activity_time_ms != this->m_config_activity_time_ms )
    {
      v12 = this->m_inventory->m_holder->cast_to_base_player(this->m_inventory->m_holder);
      survarium::player_params_modifiers_container::remove_modifier(
        (survarium::player_params_modifiers_container *)&(*(survarium::base_player_vtbl **)((char *)&v12->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                                                                          + (_DWORD)&loc_11066
                                                                                          + 2))[7],
        stamina_regenation_speed_modifier,
        &this->m_add_stamina_regen);
    }
    v19.current_time_in_ms = current_time_in_ms;
    v19.medkit = this;
    v19.activated = 0;
    vostok::intrusive_list<survarium::medkit_actions_subscriber,survarium::medkit_actions_subscriber *,32,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::for_each<survarium::notify_medkit_activate>(
      v4,
      (int)&m_object->m_medkit_actions_subscribers,
      &v19);
    m_statistics_events_handler = this->m_game_world_core->m_statistics_events_handler;
    if ( m_statistics_events_handler )
    {
      p_on_medkit_action = (void (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD))&m_statistics_events_handler->on_medkit_action;
      v15 = this->m_inventory->m_holder->cast_to_base_player(this->m_inventory->m_holder);
      (*p_on_medkit_action)(m_statistics_events_handler, this, 0, v15->id);
    }
    for ( i = 0; i < this->m_influences_count; this->m_applied_influence[i++] = 0.0 )
      ;
    survarium::game_world_core::unregister_tickable_object(this->m_game_world_core, &this->survarium::tickable_object);
  }
  else
  {
    this->m_activity_time_ms = this->m_config_activity_time_ms;
    this->m_delay_ms = this->m_config_delay_ms;
    survarium::game_world_core::register_tickable_object(
      (survarium::game_world_core *)&this->survarium::tickable_object,
      (int)this->m_game_world_core);
    v19.current_time_in_ms = current_time_in_ms;
    v19.medkit = this;
    v19.activated = 1;
    vostok::intrusive_list<survarium::medkit_actions_subscriber,survarium::medkit_actions_subscriber *,32,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::for_each<survarium::notify_medkit_activate>(
      v7,
      (int)&m_object->m_medkit_actions_subscribers,
      &v19);
    v9 = this->m_game_world_core->m_statistics_events_handler;
    if ( v9 )
    {
      v10 = (void (__thiscall **)(survarium::statistics_events_handler *, survarium::medkit *, int, _DWORD))&v9->on_medkit_action;
      v11 = this->m_inventory->m_holder->cast_to_base_player(this->m_inventory->m_holder);
      (*v10)(v9, this, 1, v11->id);
    }
  }
  v17 = 0;
  for ( j = 0; j < this->m_damage_protect_count; ++v17 )
  {
    v18 = &this->m_damage_protect[v17];
    if ( this->m_active )
      survarium::damage_model::register_body_part_damage_protector(v20, &v18->protector, v8, v18->body_part_name);
    else
      survarium::damage_model::unregister_body_part_damage_protector(
        v8,
        (int)v20,
        v18->body_part_name,
        &this->m_damage_protect[v17].protector);
    ++j;
  }
}
