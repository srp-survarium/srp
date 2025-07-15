char __thiscall vostok::ai::graph_wrapper::planner_forward::impl::applicable(
        vostok::ai::graph_wrapper::planner_forward::impl *this,
        const vostok::ai::vector<vostok::ai::planning::world_state_property> *search_state,
        const vostok::ai::vector<vostok::ai::planning::world_state_property> *preconditions,
        const vostok::ai::vector<vostok::ai::planning::world_state_property> *start_state)
{
  survarium::game_camera *m_id; // ecx
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  vostok::ai::planning::world_state_property *iter_end_preconditions; // [esp+54h] [ebp-18h]
  const vostok::ai::planning::world_state_property *iter_initial; // [esp+58h] [ebp-14h] BYREF
  const vostok::ai::planning::world_state_property *iter_end_search; // [esp+5Ch] [ebp-10h] BYREF
  const vostok::ai::planning::world_state_property *iter_search; // [esp+60h] [ebp-Ch] BYREF
  const vostok::ai::planning::world_state_property *iter_preconditions; // [esp+64h] [ebp-8h]
  const vostok::ai::planning::world_state_property *iter_end_initial; // [esp+68h] [ebp-4h] BYREF

  iter_search = search_state->_M_impl._M_start;
  iter_end_search = search_state->_M_impl._M_finish;
  iter_preconditions = preconditions->_M_impl._M_start;
  iter_end_preconditions = preconditions->_M_impl._M_finish;
  iter_initial = start_state->_M_impl._M_start;
  iter_end_initial = start_state->_M_impl._M_finish;
  while ( iter_search != iter_end_search && iter_preconditions != iter_end_preconditions )
  {
    if ( iter_search->m_id >= iter_preconditions->m_id )
    {
      m_id = (survarium::game_camera *)iter_search->m_id;
      if ( iter_search->m_id == iter_preconditions->m_id )
      {
        if ( iter_search->m_value != iter_preconditions->m_value )
          return 0;
        ++iter_search;
        ++iter_preconditions;
      }
      else
      {
        while ( iter_initial != iter_end_initial )
        {
          m_id = (survarium::game_camera *)iter_initial->m_id;
          if ( iter_initial->m_id >= iter_preconditions->m_id )
            break;
          ++iter_initial;
        }
        if ( iter_initial == iter_end_initial
          || (m_id = (survarium::game_camera *)iter_initial->m_id, iter_initial->m_id > iter_preconditions->m_id) )
        {
          survarium::weapon_user_dead_state::finalize(m_id);
          vostok::ai::planning::propositional_planner::evaluate(
            this->m_graph,
            &iter_initial,
            (vostok::ai::planning::world_state_property **)&iter_end_initial,
            &iter_preconditions->m_id);
        }
        if ( iter_initial->m_value != iter_preconditions->m_value )
          return 0;
        ++iter_initial;
        ++iter_preconditions;
      }
    }
    else
    {
      ++iter_search;
    }
  }
  if ( iter_search != iter_end_search )
    return 1;
  iter_search = iter_initial;
  iter_end_search = iter_end_initial;
  while ( iter_preconditions != iter_end_preconditions )
  {
    v6 = (survarium::game_camera *)iter_search;
    if ( iter_search == iter_end_search
      || (v6 = (survarium::game_camera *)iter_preconditions, iter_search->m_id > iter_preconditions->m_id) )
    {
      survarium::weapon_user_dead_state::finalize(v6);
      vostok::ai::planning::propositional_planner::evaluate(
        this->m_graph,
        &iter_search,
        (vostok::ai::planning::world_state_property **)&iter_end_search,
        &iter_preconditions->m_id);
      goto LABEL_28;
    }
    v7 = (survarium::game_camera *)iter_search;
    if ( iter_search->m_id >= iter_preconditions->m_id )
    {
LABEL_28:
      survarium::weapon_user_dead_state::finalize(v7);
      if ( iter_search->m_value != iter_preconditions->m_value )
        return 0;
      ++iter_search;
      ++iter_preconditions;
    }
    else
    {
      ++iter_search;
    }
  }
  return 1;
}
