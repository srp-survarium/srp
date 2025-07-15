char __thiscall vostok::ai::graph_wrapper::planner_backward::impl::apply(
        vostok::ai::graph_wrapper::planner_backward::impl *this,
        const vostok::ai::vector<vostok::ai::planning::world_state_property> *search_state,
        const vostok::ai::vector<vostok::ai::planning::world_state_property> *preconditions,
        const vostok::ai::vector<vostok::ai::planning::world_state_property> *effects)
{
  vostok::ai::planning::world_state *p_m_new_state; // [esp+5Ch] [ebp-2Ch]
  vostok::ai::planning::world_state_property *iter_end_effects; // [esp+6Ch] [ebp-1Ch]
  vostok::ai::planning::world_state_property *iter_end_preconditions; // [esp+70h] [ebp-18h]
  vostok::ai::planning::world_state_property *iter_end_search; // [esp+74h] [ebp-14h]
  vostok::ai::planning::world_state_property *iter_effects; // [esp+78h] [ebp-10h]
  vostok::ai::planning::world_state_property *iter_preconditions; // [esp+7Ch] [ebp-Ch]
  vostok::ai::planning::world_state_property *iter_search; // [esp+80h] [ebp-8h]
  bool changed; // [esp+87h] [ebp-1h]

  p_m_new_state = &this->m_new_state;
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::erase(
    &this->m_new_state.m_properties._M_impl,
    this->m_new_state.m_properties._M_impl._M_start,
    this->m_new_state.m_properties._M_impl._M_finish);
  p_m_new_state->m_hash = 0;
  changed = 0;
  iter_preconditions = preconditions->_M_impl._M_start;
  iter_end_preconditions = preconditions->_M_impl._M_finish;
  iter_search = search_state->_M_impl._M_start;
  iter_end_search = search_state->_M_impl._M_finish;
  iter_effects = effects->_M_impl._M_start;
  iter_end_effects = effects->_M_impl._M_finish;
  while ( iter_search != iter_end_search && iter_preconditions != iter_end_preconditions )
  {
    if ( iter_search->m_id <= iter_preconditions->m_id )
    {
      if ( iter_search->m_id == iter_preconditions->m_id )
      {
        if ( iter_search->m_value != iter_preconditions->m_value )
          changed = 1;
        vostok::ai::planning::world_state::add_back(&this->m_new_state, iter_preconditions);
        ++iter_search;
        ++iter_preconditions;
      }
      else
      {
        while ( iter_effects != iter_end_effects && iter_effects->m_id < iter_search->m_id )
          ++iter_effects;
        if ( iter_effects == iter_end_effects || iter_effects->m_id != iter_search->m_id )
        {
          vostok::ai::planning::world_state::add_back(&this->m_new_state, iter_search++);
        }
        else
        {
          survarium::weapon_user_dead_state::finalize((survarium::game_camera *)iter_search);
          changed = 1;
          ++iter_effects;
          ++iter_search;
        }
      }
    }
    else
    {
      vostok::ai::planning::world_state::add_back(&this->m_new_state, iter_preconditions++);
    }
  }
  if ( iter_search == iter_end_search )
  {
    if ( changed )
    {
      while ( iter_preconditions != iter_end_preconditions )
        vostok::ai::planning::world_state::add_back(&this->m_new_state, iter_preconditions++);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    while ( iter_effects != iter_end_effects && iter_search != iter_end_search )
    {
      if ( iter_effects->m_id >= iter_search->m_id )
      {
        if ( iter_effects->m_id <= iter_search->m_id )
        {
          survarium::weapon_user_dead_state::finalize((survarium::game_camera *)iter_effects);
          changed = 1;
          ++iter_effects;
        }
        else
        {
          vostok::ai::planning::world_state::add_back(&this->m_new_state, iter_search);
        }
        ++iter_search;
      }
      else
      {
        ++iter_effects;
      }
    }
    if ( changed )
    {
      if ( iter_search == iter_end_search )
      {
        return 1;
      }
      else
      {
        while ( iter_search != iter_end_search )
          vostok::ai::planning::world_state::add_back(&this->m_new_state, iter_search++);
        return 1;
      }
    }
    else
    {
      return 0;
    }
  }
}
