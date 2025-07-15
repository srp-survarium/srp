void __thiscall survarium::victory_item_core::initialize(survarium::victory_item_core *this)
{
  survarium::gather_victory_items_rule *m_game_rule; // eax
  survarium::base_player *m_user; // ecx
  vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *v4; // eax
  survarium::victory_items_container_core *m_container; // edi
  survarium::base_player *v6; // edx
  survarium::gather_victory_items_rule *v7; // ecx
  survarium::gather_victory_items_rule_vtbl *v8; // eax
  vostok::threading::mutex *v9; // ecx
  survarium::game_statistic_event_history_item *v10; // eax
  int v11; // esi
  survarium::game_world_core *v12; // edx
  int v13; // ecx
  unsigned int m_current_time_in_ms; // [esp-4h] [ebp-24h]
  unsigned int v15; // [esp-4h] [ebp-24h]
  survarium::base_player *v16; // [esp-4h] [ebp-24h]
  _DWORD v17[2]; // [esp+Ch] [ebp-14h] BYREF
  survarium::game_world_core *m_game_world_core; // [esp+14h] [ebp-Ch]
  survarium::game_statistic_event_history_item *v19; // [esp+18h] [ebp-8h]
  int v20; // [esp+1Ch] [ebp-4h]

  m_game_rule = this->m_game_rule;
  m_user = this->m_user;
  m_current_time_in_ms = m_user->m_current_time_in_ms;
  m_game_world_core = m_game_rule->m_game_world_core;
  v4 = survarium::game_world_core::new_game_statistic_event_history_item(
         (survarium::game_world_core *)m_user,
         (int)m_game_world_core,
         m_current_time_in_ms);
  *(_DWORD *)&v4->data[24] = 1;
  v4->data[1] = this->m_user->id;
  m_container = this->m_container;
  v19 = (survarium::game_statistic_event_history_item *)v4;
  if ( m_container )
  {
    survarium::victory_items_container_core::take_item(m_container, this);
    this->m_user->m_inventory.m_object->m_carried_item = this;
    this->taken_from_container(this);
    v6 = this->m_user;
    v7 = this->m_game_rule;
    v17[1] = 1;
    v17[0] = m_container->m_owner_team;
    v15 = v6->m_current_time_in_ms;
    v8 = v7->survarium::game_match_rule_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable;
    v20 = 1;
    v8->on_event(v7, gather_victory_item_event, v17, v15);
  }
  else
  {
    this->picked_up_by_player(this);
    v20 = 2;
  }
  v16 = this->m_user;
  this->m_spotted_mask = 0;
  this->set_spotted(&this->survarium::spottable_object, v16);
  vostok::ai::fsm::set_initial_state(&this->m_logic, this->m_logic.m_states.m_first, ignore_current_state);
  this->m_portable_interactive_object->initialize(this->m_portable_interactive_object);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &this->m_user->m_profile->modifiers.m_modifiers.elems[4],
    &this->m_move_speed_modifier,
    v9);
  v10 = v19;
  v11 = (int)m_game_world_core;
  v12 = m_game_world_core;
  v19->data0.char_arg[0] = v20;
  survarium::game_world_core::commit_game_statistic_event_history_item(v12, v10);
  v13 = *(_DWORD *)(v11 + 51168);
  if ( v13 )
    (*(void (__thiscall **)(int, _DWORD, int, survarium::victory_item_core *))(*(_DWORD *)v13 + 12))(
      v13,
      this->m_user->id,
      v20,
      this);
}
