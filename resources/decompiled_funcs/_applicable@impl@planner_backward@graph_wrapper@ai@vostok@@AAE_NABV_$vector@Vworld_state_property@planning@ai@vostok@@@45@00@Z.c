char __thiscall vostok::ai::graph_wrapper::planner_backward::impl::applicable(
        vostok::ai::graph_wrapper::planner_backward::impl *this,
        const vostok::ai::vector<vostok::ai::planning::world_state_property> *search_state,
        const vostok::ai::vector<vostok::ai::planning::world_state_property> *preconditions,
        const vostok::ai::vector<vostok::ai::planning::world_state_property> *effects)
{
  vostok::ai::planning::world_state_property *it_end_search; // [esp+1Ch] [ebp-18h]
  vostok::ai::planning::world_state_property *it_end_preconditions; // [esp+24h] [ebp-10h]
  vostok::ai::planning::world_state_property *it_preconditions; // [esp+28h] [ebp-Ch]
  vostok::ai::planning::world_state_property *it_search; // [esp+2Ch] [ebp-8h]
  vostok::ai::planning::world_state_property *it_effects; // [esp+30h] [ebp-4h]

  it_search = search_state->_M_impl._M_start;
  it_end_search = search_state->_M_impl._M_finish;
  it_effects = effects->_M_impl._M_start;
  it_preconditions = preconditions->_M_impl._M_start;
  it_end_preconditions = preconditions->_M_impl._M_finish;
  while ( it_effects != effects->_M_impl._M_finish && it_search != it_end_search )
  {
    if ( it_effects->m_id >= it_search->m_id )
    {
      if ( it_effects->m_id == it_search->m_id )
      {
        if ( it_effects->m_value != it_search->m_value )
          return 0;
        ++it_effects;
        ++it_search;
      }
      else
      {
        while ( it_preconditions != it_end_preconditions && it_preconditions->m_id < it_search->m_id )
          ++it_preconditions;
        if ( it_preconditions == it_end_preconditions )
        {
          ++it_search;
        }
        else if ( it_preconditions->m_id == it_search->m_id )
        {
          if ( it_preconditions->m_value != it_search->m_value )
            return 0;
          ++it_preconditions;
          ++it_search;
        }
        else
        {
          ++it_search;
        }
      }
    }
    else
    {
      ++it_effects;
    }
  }
  if ( it_search == it_end_search )
    return 1;
  while ( it_preconditions != it_end_preconditions && it_search != it_end_search )
  {
    if ( it_preconditions->m_id >= it_search->m_id )
    {
      if ( it_preconditions->m_id <= it_search->m_id )
      {
        if ( it_preconditions->m_value != it_search->m_value )
          return 0;
        ++it_preconditions;
        ++it_search;
      }
      else
      {
        ++it_search;
      }
    }
    else
    {
      ++it_preconditions;
    }
  }
  return 1;
}
