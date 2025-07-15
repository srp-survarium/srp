void __thiscall survarium::victory_item_core::deactivate(survarium::victory_item_core *this, BOOL real_remove)
{
  vostok::ai::fsm_state **p_m_current_state; // edi
  vostok::ai::fsm_state *m_current_state; // ecx
  survarium::game_world_core *v5; // ecx
  survarium::game_world_core *m_game_world_core; // ebx
  vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *v7; // edi
  survarium::victory_items_container_core *m_container; // eax
  survarium::base_player *v9; // eax
  survarium::base_player *m_user; // edx
  survarium::gather_victory_items_rule *m_game_rule; // ecx
  survarium::victory_item_core_vtbl *v12; // eax
  survarium::statistics_events_handler *m_statistics_events_handler; // ecx
  survarium::base_player *v14; // [esp-8h] [ebp-18h]
  _DWORD v15[2]; // [esp+8h] [ebp-8h] BYREF
  int v16; // [esp+18h] [ebp+8h]

  p_m_current_state = &this->m_logic.m_current_state;
  m_current_state = this->m_logic.m_current_state;
  if ( m_current_state )
  {
    m_current_state->finalize(m_current_state);
    *p_m_current_state = 0;
  }
  this->m_portable_interactive_object->deactivate(this->m_portable_interactive_object, real_remove);
  if ( real_remove )
  {
    this->m_user->m_inventory.m_object->m_carried_item = 0;
    m_game_world_core = this->m_game_rule->m_game_world_core;
    v7 = survarium::game_world_core::new_game_statistic_event_history_item(
           v5,
           (int)m_game_world_core,
           this->m_user->m_current_time_in_ms);
    *(_DWORD *)&v7->data[24] = 1;
    v7->data[1] = this->m_user->id;
    m_container = this->m_container;
    if ( m_container
      && vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::contains_object(
           (vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->m_user->m_usable_object_user_data,
           (int)&m_container->m_usable_object_users,
           &this->m_user->m_usable_object_user_data)
      && (v9 = this->m_user, v9->m_is_alive)
      && !v9->m_has_to_die )
    {
      this->put_to_container(this, real_remove);
      m_user = this->m_user;
      m_game_rule = this->m_game_rule;
      this->m_spotted_mask = 0;
      v15[1] = 0;
      v16 = 0;
      v15[0] = this->m_container->m_owner_team;
      m_game_rule->on_event(m_game_rule, gather_victory_item_event, v15, m_user->m_current_time_in_ms);
    }
    else
    {
      v12 = this->survarium::carryable_object::survarium::interactive_object::__vftable;
      this->m_container = 0;
      v12->drop(this);
      v14 = this->m_user;
      this->m_spotted_mask = 0;
      this->set_spotted(&this->survarium::spottable_object, v14);
      v16 = 3;
    }
    survarium::player_params_modifiers_container::remove_modifier(
      &this->m_user->m_profile->modifiers,
      movement_speed_modifier,
      &this->m_move_speed_modifier);
    v7->data[0] = v16;
    survarium::game_world_core::commit_game_statistic_event_history_item(
      m_game_world_core,
      (survarium::game_statistic_event_history_item *)v7);
    m_statistics_events_handler = m_game_world_core->m_statistics_events_handler;
    if ( m_statistics_events_handler )
      m_statistics_events_handler->on_victory_item_event(
        m_statistics_events_handler,
        this->m_user->id,
        (survarium::victory_item_event_type)v16,
        this);
    this->m_user = 0;
  }
}
