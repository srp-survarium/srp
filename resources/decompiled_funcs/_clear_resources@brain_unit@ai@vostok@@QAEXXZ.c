void __thiscall vostok::ai::brain_unit::clear_resources(vostok::ai::brain_unit *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  survarium::game_camera *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // eax
  survarium::game_camera *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // eax
  survarium::game_camera *v7; // ecx
  vostok::memory::doug_lea_allocator *v8; // eax
  survarium::game_camera *v9; // ecx
  vostok::memory::doug_lea_allocator *v10; // eax
  survarium::game_camera *v11; // ecx
  vostok::memory::doug_lea_allocator *v12; // eax
  vostok::ai::selectors::target_selector_base *selector; // [esp+D0h] [ebp-10h] BYREF
  vostok::ai::perceptors::perceptor_base *perceptor; // [esp+D4h] [ebp-Ch] BYREF
  vostok::ai::sensors::passive_sensor_base *passive_sensor; // [esp+D8h] [ebp-8h] BYREF
  vostok::ai::sensors::active_sensor_base *active_sensor; // [esp+DCh] [ebp-4h] BYREF

  vostok::ai::working_memory::clear_resources(&this->m_working_memory);
  survarium::weapon_user_dead_state::finalize(v1);
  ((void (__thiscall *)(vostok::ai::sound_player *, vostok::ai::sound_player *))this->m_sound_player.m_object->clear_resources)(
    this->m_sound_player.m_object,
    this->m_sound_player.m_object);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_goal_selector);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::goal_selector>(
    v2,
    &this->m_goal_selector);
  survarium::weapon_user_dead_state::finalize(v3);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::specified_problem>(
    v4,
    &this->m_specified_problem);
  while ( 1 )
  {
    active_sensor = (vostok::ai::sensors::active_sensor_base *)vostok::intrusive_list<vostok::ai::planning::base_filter,vostok::ai::planning::base_filter *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front((vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_active_sensors);
    if ( !active_sensor )
      break;
    survarium::weapon_user_dead_state::finalize(v5);
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::ai::sensors::active_sensor_base,vostok::memory::detail::call_destructor_predicate>(
      v6,
      &active_sensor);
  }
  while ( 1 )
  {
    passive_sensor = (vostok::ai::sensors::passive_sensor_base *)vostok::intrusive_list<vostok::ai::planning::base_filter,vostok::ai::planning::base_filter *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front((vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_passive_sensors);
    if ( !passive_sensor )
      break;
    survarium::weapon_user_dead_state::finalize(v7);
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::ai::sensors::passive_sensor_base,vostok::memory::detail::call_destructor_predicate>(
      v8,
      &passive_sensor);
  }
  while ( 1 )
  {
    perceptor = (vostok::ai::perceptors::perceptor_base *)vostok::intrusive_list<vostok::ai::planning::base_filter,vostok::ai::planning::base_filter *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front((vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_perceptors);
    if ( !perceptor )
      break;
    survarium::weapon_user_dead_state::finalize(v9);
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::inventory,vostok::memory::detail::call_destructor_predicate>(
      v10,
      (vostok::sound::sound_scene **)&perceptor);
  }
  while ( 1 )
  {
    selector = (vostok::ai::selectors::target_selector_base *)vostok::intrusive_list<vostok::ai::planning::base_filter,vostok::ai::planning::base_filter *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front((vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_target_selectors);
    if ( !selector )
      break;
    survarium::weapon_user_dead_state::finalize(v11);
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::inventory,vostok::memory::detail::call_destructor_predicate>(
      v12,
      (vostok::sound::sound_scene **)&selector);
  }
}
