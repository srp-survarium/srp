unsigned int __thiscall vostok::ai::path_heuristics::planner_forward::impl::estimate_impl(
        vostok::ai::path_heuristics::planner_forward::impl *this,
        const vostok::ai::planning::world_state *vertex_id,
        vostok::ai::planning::world_state_property *it_target_begin,
        const vostok::ai::planning::world_state_property *it_target_end)
{
  const vostok::ai::planning::world_state_property *iter_vertex; // [esp+44h] [ebp-14h] BYREF
  unsigned int result; // [esp+48h] [ebp-10h]
  const vostok::ai::planning::world_state_property *iter_end_vertex; // [esp+4Ch] [ebp-Ch] BYREF
  const vostok::ai::planning::world_state_property *iter_current; // [esp+50h] [ebp-8h] BYREF
  const vostok::ai::planning::world_state_property *iter_end_current; // [esp+54h] [ebp-4h] BYREF

  result = 0;
  iter_vertex = vertex_id->m_properties._M_impl._M_start;
  iter_end_vertex = vertex_id->m_properties._M_impl._M_finish;
  iter_current = this->m_graph->m_current_state.m_properties._M_impl._M_start;
  iter_end_current = this->m_graph->m_current_state.m_properties._M_impl._M_finish;
  while ( it_target_begin != it_target_end && iter_vertex != iter_end_vertex )
  {
    if ( iter_vertex->m_id >= it_target_begin->m_id )
    {
      if ( iter_vertex->m_id == it_target_begin->m_id )
      {
        if ( iter_vertex->m_value != it_target_begin->m_value )
          ++result;
        ++iter_vertex;
        ++it_target_begin;
      }
      else
      {
        while ( iter_current != iter_end_current && iter_current->m_id < it_target_begin->m_id )
          ++iter_current;
        if ( iter_current == iter_end_current || iter_current->m_id > it_target_begin->m_id )
          vostok::ai::planning::propositional_planner::evaluate(
            this->m_graph,
            &iter_current,
            (vostok::ai::planning::world_state_property **)&iter_end_current,
            &it_target_begin->m_id);
        if ( iter_current->m_value != it_target_begin->m_value )
          ++result;
        ++iter_current;
        ++it_target_begin;
      }
    }
    else
    {
      ++iter_vertex;
    }
  }
  if ( iter_vertex != iter_end_vertex )
    return result;
  iter_vertex = iter_current;
  iter_end_vertex = iter_end_current;
  while ( it_target_begin != it_target_end )
  {
    if ( iter_vertex == iter_end_vertex || iter_vertex->m_id > it_target_begin->m_id )
      vostok::ai::planning::propositional_planner::evaluate(
        this->m_graph,
        &iter_vertex,
        (vostok::ai::planning::world_state_property **)&iter_end_vertex,
        &it_target_begin->m_id);
    if ( iter_vertex->m_id >= it_target_begin->m_id )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)it_target_begin);
      if ( iter_vertex->m_value != it_target_begin->m_value )
        ++result;
      ++iter_vertex;
      ++it_target_begin;
    }
    else
    {
      ++iter_vertex;
    }
  }
  return result;
}
