char __thiscall vostok::ai::search_restrictor::planner_forward::impl::target_reached_impl(
        vostok::ai::search_restrictor::planner_forward::impl *this,
        const vostok::ai::planning::world_state *vertex_id,
        vostok::ai::planning::world_state_property *it_target,
        const vostok::ai::planning::world_state_property *it_target_end)
{
  const vostok::ai::graph_wrapper::propositional_planner_base::impl *m_wrapper; // [esp+38h] [ebp-1Ch]
  const vostok::ai::planning::world_state_property *iter_vertex; // [esp+40h] [ebp-14h] BYREF
  const vostok::ai::planning::world_state_property *iter_end_vertex; // [esp+44h] [ebp-10h] BYREF
  vostok::ai::planning::propositional_planner *graph; // [esp+48h] [ebp-Ch]
  const vostok::ai::planning::world_state_property *iter_current; // [esp+4Ch] [ebp-8h] BYREF
  const vostok::ai::planning::world_state_property *iter_end_current; // [esp+50h] [ebp-4h] BYREF

  m_wrapper = this->m_wrapper;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_wrapper);
  graph = m_wrapper->m_graph;
  iter_vertex = vertex_id->m_properties._M_impl._M_start;
  iter_end_vertex = vertex_id->m_properties._M_impl._M_finish;
  iter_current = graph->m_current_state.m_properties._M_impl._M_start;
  iter_end_current = graph->m_current_state.m_properties._M_impl._M_finish;
  while ( it_target != it_target_end && iter_vertex != iter_end_vertex )
  {
    if ( iter_vertex->m_id >= it_target->m_id )
    {
      if ( iter_vertex->m_id > it_target->m_id )
      {
        while ( iter_current != iter_end_current && iter_current->m_id < it_target->m_id )
          ++iter_current;
        if ( iter_current == iter_end_current || iter_current->m_id > it_target->m_id )
          vostok::ai::planning::propositional_planner::evaluate(
            graph,
            &iter_current,
            (vostok::ai::planning::world_state_property **)&iter_end_current,
            &it_target->m_id);
        if ( iter_current->m_value != it_target->m_value )
          return 0;
        ++iter_current;
        ++it_target;
      }
      else
      {
        if ( iter_vertex->m_value != it_target->m_value )
          return 0;
        ++iter_vertex;
        ++it_target;
      }
    }
    else
    {
      ++iter_vertex;
    }
  }
  if ( iter_vertex != iter_end_vertex )
    return 1;
  iter_vertex = iter_current;
  iter_end_vertex = iter_end_current;
  while ( it_target != it_target_end )
  {
    if ( iter_vertex == iter_end_vertex || iter_vertex->m_id > it_target->m_id )
      vostok::ai::planning::propositional_planner::evaluate(
        graph,
        &iter_vertex,
        (vostok::ai::planning::world_state_property **)&iter_end_vertex,
        &it_target->m_id);
    if ( iter_vertex->m_id >= it_target->m_id )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)it_target);
      if ( iter_vertex->m_value != it_target->m_value )
        return 0;
      ++iter_vertex;
      ++it_target;
    }
    else
    {
      ++iter_vertex;
    }
  }
  return 1;
}
