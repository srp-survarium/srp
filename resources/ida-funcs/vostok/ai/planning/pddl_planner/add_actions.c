void __thiscall vostok::ai::planning::pddl_planner::add_actions(
        vostok::ai::planning::pddl_planner *this,
        const vostok::ai::vector<vostok::ai::planning::specified_action> *specified_actions,
        vostok::ai::planning::specified_problem *actual_problem)
{
  survarium::game_camera *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // eax
  unsigned int cost; // eax
  vostok::ai::planning::operator_impl *v6; // eax
  survarium::game_camera *v7; // ecx
  survarium::game_camera *v8; // ecx
  survarium::game_camera *p_m_effects; // ecx
  vostok::ai::planning::operator_impl *v10; // [esp+0h] [ebp-178h]
  unsigned int v12; // [esp+8h] [ebp-170h]
  unsigned int v13; // [esp+18h] [ebp-160h]
  unsigned int v14; // [esp+24h] [ebp-154h]
  unsigned int v15; // [esp+34h] [ebp-144h]
  int *_Where; // [esp+40h] [ebp-138h]
  unsigned int v17; // [esp+48h] [ebp-130h]
  vostok::ai::planning::operator_impl *v18; // [esp+54h] [ebp-124h]
  vostok::ai::planning::pddl_world_state_property_impl *effect; // [esp+58h] [ebp-120h]
  unsigned int index; // [esp+5Ch] [ebp-11Ch]
  vostok::ai::planning::pddl_world_state_property_impl *property; // [esp+60h] [ebp-118h]
  unsigned int j; // [esp+64h] [ebp-114h]
  char operator_name[256]; // [esp+68h] [ebp-110h] BYREF
  vostok::ai::planning::operator_impl *action; // [esp+16Ch] [ebp-Ch]
  const vostok::ai::planning::specified_action *current_action; // [esp+170h] [ebp-8h]
  unsigned int i; // [esp+174h] [ebp-4h] BYREF

  for ( i = 0; i < specified_actions->_M_impl._M_finish - specified_actions->_M_impl._M_start; ++i )
  {
    vostok::sprintf<256>((char (*)[256])operator_name, "operator#%d", i);
    v17 = i;
    survarium::weapon_user_dead_state::finalize(v3);
    current_action = &specified_actions->_M_impl._M_start[v17];
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)current_action);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v4, 0x88u);
    v18 = (vostok::ai::planning::operator_impl *)operator new(0x88u, _Where);
    if ( v18 )
    {
      cost = vostok::ai::planning::specified_action::get_cost((vostok::ai::planning::specified_action *)current_action);
      vostok::ai::planning::operator_impl::operator_impl(v18, operator_name, cost);
      v10 = v6;
    }
    else
    {
      v10 = 0;
    }
    v7 = (survarium::game_camera *)v10;
    action = v10;
    for ( j = 0; ; ++j )
    {
      v15 = i;
      survarium::weapon_user_dead_state::finalize(v7);
      v8 = (survarium::game_camera *)(specified_actions->_M_impl._M_start[v15].m_preconditions._M_impl._M_finish
                                    - specified_actions->_M_impl._M_start[v15].m_preconditions._M_impl._M_start);
      if ( j >= (unsigned int)v8 )
        break;
      v14 = i;
      survarium::weapon_user_dead_state::finalize(v8);
      property = (vostok::ai::planning::pddl_world_state_property_impl *)vostok::ai::planning::specified_action::get_precondition(
                                                                           &specified_actions->_M_impl._M_start[v14],
                                                                           j);
      vostok::ai::planning::pddl_planner::add_world_state_property(
        this,
        (survarium::game_camera *)property,
        &action->m_preconditions,
        actual_problem);
    }
    for ( index = 0; ; ++index )
    {
      v13 = i;
      survarium::weapon_user_dead_state::finalize(v8);
      p_m_effects = (survarium::game_camera *)&specified_actions->_M_impl._M_start[v13].m_effects;
      if ( index >= ((char *)specified_actions->_M_impl._M_start[v13].m_effects._M_impl._M_finish
                   - (char *)p_m_effects->__vftable) >> 5 )
        break;
      v12 = i;
      survarium::weapon_user_dead_state::finalize(p_m_effects);
      effect = (vostok::ai::planning::pddl_world_state_property_impl *)vostok::ai::planning::specified_action::get_effect(
                                                                         &specified_actions->_M_impl._M_start[v12],
                                                                         index);
      vostok::ai::planning::pddl_planner::add_world_state_property(
        this,
        (survarium::game_camera *)effect,
        &action->m_effects,
        actual_problem);
      v8 = (survarium::game_camera *)(index + 1);
    }
    vostok::ai::planning::operator_holder::add(&this->m_planner.m_operators, &i, action);
  }
}
