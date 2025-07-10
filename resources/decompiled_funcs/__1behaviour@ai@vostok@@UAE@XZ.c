void __thiscall vostok::ai::behaviour::~behaviour(vostok::ai::behaviour *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  survarium::game_camera *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // eax
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  vostok::memory::doug_lea_allocator *v7; // eax
  survarium::game_camera *v8; // ecx
  vostok::memory::doug_lea_allocator *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // eax
  survarium::game_camera *v11; // ecx
  vostok::memory::doug_lea_allocator *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // eax
  survarium::game_camera *v14; // ecx
  vostok::ai::planning::generalized_action *pointer; // [esp+90h] [ebp-20h] BYREF
  vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v17; // [esp+94h] [ebp-1Ch]
  const survarium::game_material *const_pointer; // [esp+98h] [ebp-18h] BYREF
  vostok::ai::planning::action_instance *action; // [esp+9Ch] [ebp-14h] BYREF
  vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *filters; // [esp+A0h] [ebp-10h]
  vostok::ai::planning::action_parameter *parameter; // [esp+A4h] [ebp-Ch] BYREF
  vostok::ai::planning::goal *first_goal; // [esp+A8h] [ebp-8h] BYREF
  vostok::ai::planning::base_filter *filter; // [esp+ACh] [ebp-4h]

  this->__vftable = (vostok::ai::behaviour_vtbl *)&vostok::ai::behaviour::`vftable';
  while ( 1 )
  {
    filter = (vostok::ai::planning::base_filter *)vostok::ai::pre_perceptors_filter::pop_aux_filter(&this->m_ignorance_filter);
    if ( !filter )
      break;
    vostok::ai::behaviour::delete_filter(filter);
  }
  while ( 1 )
  {
    first_goal = (vostok::ai::planning::goal *)vostok::intrusive_list<survarium::landing_point,survarium::landing_point *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front((vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->m_goals);
    if ( !first_goal )
      break;
    while ( 1 )
    {
      parameter = vostok::ai::planning::goal::pop_parameter(first_goal);
      if ( !parameter )
        break;
      survarium::weapon_user_dead_state::finalize(v1);
      vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::game_material,vostok::memory::detail::call_destructor_predicate>(
        v2,
        (survarium::game_camera **)&parameter);
    }
    while ( 1 )
    {
      filters = vostok::ai::planning::goal::pop_filter_list(first_goal);
      if ( !filters )
        break;
      vostok::ai::behaviour::delete_parameters_filters(filters);
    }
    survarium::weapon_user_dead_state::finalize(v3);
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::ai::planning::goal,vostok::memory::detail::call_destructor_predicate>(
      v4,
      &first_goal);
  }
  while ( 1 )
  {
    action = vostok::ai::planning::pddl_problem::pop_action_instance(this->m_problem);
    if ( !action )
      break;
    while ( 1 )
    {
      const_pointer = (const survarium::game_material *)vostok::ai::planning::action_instance::pop_parameter(action);
      if ( !const_pointer )
        break;
      survarium::weapon_user_dead_state::finalize(v6);
      vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::game_material,vostok::memory::detail::call_destructor_predicate>(
        v7,
        (survarium::game_camera **)&const_pointer);
    }
    while ( 1 )
    {
      v17 = vostok::ai::planning::action_instance::pop_filter_list(action);
      if ( !v17 )
        break;
      vostok::ai::behaviour::delete_parameters_filters(v17);
    }
    survarium::weapon_user_dead_state::finalize(v8);
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::ai::planning::action_instance,vostok::memory::detail::call_destructor_predicate>(
      v9,
      &action);
  }
  survarium::weapon_user_dead_state::finalize(v5);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::pddl_problem>(
    v10,
    &this->m_problem);
  while ( 1 )
  {
    pointer = vostok::ai::planning::pddl_domain::pop_action(this->m_domain);
    if ( !pointer )
      break;
    survarium::weapon_user_dead_state::finalize(v11);
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::ai::planning::generalized_action,vostok::memory::detail::call_destructor_predicate>(
      v12,
      &pointer);
  }
  survarium::weapon_user_dead_state::finalize(v11);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::pddl_domain>(
    v13,
    &this->m_domain);
  survarium::weapon_user_dead_state::finalize(v14);
  vostok::ai::pre_perceptors_filter::~pre_perceptors_filter(&this->m_ignorance_filter);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_vision_parameters);
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->vostok::resources::unmanaged_resource);
}
