void __thiscall vostok::ai::graph_wrapper::planner_forward::impl::apply(
        vostok::ai::graph_wrapper::planner_forward::impl *this,
        const vostok::ai::vector<vostok::ai::planning::world_state_property> *search_state,
        const vostok::ai::vector<vostok::ai::planning::world_state_property> *effects,
        const vostok::ai::vector<vostok::ai::planning::world_state_property> *start_state)
{
  survarium::game_camera *v4; // ecx
  vostok::ai::planning::world_state_property *m_id; // ecx
  vostok::ai::planning::world_state *p_m_new_state; // [esp+80h] [ebp-28h]
  vostok::ai::planning::world_state_property *iter_end_effects; // [esp+90h] [ebp-18h]
  const vostok::ai::planning::world_state_property *iter_initial; // [esp+94h] [ebp-14h] BYREF
  const vostok::ai::planning::world_state_property *iter_end_search; // [esp+98h] [ebp-10h] BYREF
  const vostok::ai::planning::world_state_property *iter_effects; // [esp+9Ch] [ebp-Ch]
  const vostok::ai::planning::world_state_property *iter_search; // [esp+A0h] [ebp-8h] BYREF
  const vostok::ai::planning::world_state_property *iter_end_initial; // [esp+A4h] [ebp-4h] BYREF

  p_m_new_state = &this->m_new_state;
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::erase(
    &this->m_new_state.m_properties._M_impl,
    this->m_new_state.m_properties._M_impl._M_start,
    this->m_new_state.m_properties._M_impl._M_finish);
  p_m_new_state->m_hash = 0;
  iter_search = search_state->_M_impl._M_start;
  iter_end_search = search_state->_M_impl._M_finish;
  iter_effects = effects->_M_impl._M_start;
  iter_end_effects = effects->_M_impl._M_finish;
  iter_initial = start_state->_M_impl._M_start;
  iter_end_initial = start_state->_M_impl._M_finish;
  while ( iter_search != iter_end_search && iter_effects != iter_end_effects )
  {
    if ( iter_search->m_id >= iter_effects->m_id )
    {
      if ( iter_search->m_id == iter_effects->m_id )
      {
        if ( iter_search->m_value == iter_effects->m_value )
          vostok::ai::planning::world_state::add_back(&this->m_new_state, iter_effects);
        ++iter_search;
        ++iter_effects;
      }
      else
      {
        while ( iter_initial != iter_end_initial && iter_initial->m_id < iter_effects->m_id )
          ++iter_initial;
        v4 = (survarium::game_camera *)iter_initial;
        if ( iter_initial == iter_end_initial
          || (v4 = (survarium::game_camera *)iter_effects, iter_initial->m_id > iter_effects->m_id) )
        {
          survarium::weapon_user_dead_state::finalize(v4);
          vostok::ai::planning::propositional_planner::evaluate(
            this->m_graph,
            &iter_initial,
            (vostok::ai::planning::world_state_property **)&iter_end_initial,
            &iter_effects->m_id);
        }
        if ( iter_initial->m_value != iter_effects->m_value )
          vostok::ai::planning::world_state::add_back(&this->m_new_state, iter_effects);
        ++iter_initial;
        ++iter_effects;
      }
    }
    else
    {
      vostok::ai::planning::world_state::add_back(&this->m_new_state, iter_search++);
    }
  }
  if ( iter_search == iter_end_search )
  {
    iter_search = iter_initial;
    m_id = (vostok::ai::planning::world_state_property *)iter_end_initial;
    iter_end_search = iter_end_initial;
    while ( 1 )
    {
      if ( iter_effects == iter_end_effects )
        return;
      if ( iter_search == iter_end_search )
        break;
      m_id = (vostok::ai::planning::world_state_property *)iter_search->m_id;
      if ( iter_search->m_id > iter_effects->m_id )
        break;
      m_id = (vostok::ai::planning::world_state_property *)iter_effects;
      if ( iter_search->m_id >= iter_effects->m_id )
      {
LABEL_30:
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_id);
        m_id = (vostok::ai::planning::world_state_property *)iter_search->m_value;
        if ( m_id != (vostok::ai::planning::world_state_property *)iter_effects->m_value )
          vostok::ai::planning::world_state::add_back(&this->m_new_state, iter_effects);
        ++iter_search;
        ++iter_effects;
      }
      else
      {
        ++iter_search;
      }
    }
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_id);
    vostok::ai::planning::propositional_planner::evaluate(
      this->m_graph,
      &iter_search,
      (vostok::ai::planning::world_state_property **)&iter_end_search,
      &iter_effects->m_id);
    goto LABEL_30;
  }
  while ( iter_search != iter_end_search )
    vostok::ai::planning::world_state::add_back(&this->m_new_state, iter_search++);
}
