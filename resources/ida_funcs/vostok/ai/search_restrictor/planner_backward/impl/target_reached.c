char __thiscall vostok::ai::search_restrictor::planner_backward::impl::target_reached(
        vostok::ai::search_restrictor::planner_backward::impl *this,
        const vostok::ai::planning::world_state *vertex_id)
{
  const vostok::ai::graph_wrapper::propositional_planner_base::impl *m_wrapper; // [esp+20h] [ebp-1Ch]
  vostok::ai::planning::world_state_property *iter_vertex; // [esp+28h] [ebp-14h]
  vostok::ai::planning::world_state_property *iter_end_vertex; // [esp+2Ch] [ebp-10h]
  const vostok::ai::planning::world_state_property *iter_end_graph; // [esp+30h] [ebp-Ch] BYREF
  const vostok::ai::planning::world_state_property *iter_graph; // [esp+34h] [ebp-8h] BYREF
  vostok::ai::planning::propositional_planner *graph; // [esp+38h] [ebp-4h]

  m_wrapper = this->m_wrapper;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_wrapper);
  graph = m_wrapper->m_graph;
  iter_graph = graph->m_current_state.m_properties._M_impl._M_start;
  iter_end_graph = graph->m_current_state.m_properties._M_impl._M_finish;
  iter_vertex = vertex_id->m_properties._M_impl._M_start;
  iter_end_vertex = vertex_id->m_properties._M_impl._M_finish;
  while ( iter_vertex != iter_end_vertex )
  {
    if ( iter_graph == iter_end_graph || iter_graph->m_id > iter_vertex->m_id )
      vostok::ai::planning::propositional_planner::evaluate(
        graph,
        &iter_graph,
        (vostok::ai::planning::world_state_property **)&iter_end_graph,
        &iter_vertex->m_id);
    if ( iter_graph->m_id >= iter_vertex->m_id )
    {
      if ( iter_graph->m_value != iter_vertex->m_value )
        return 0;
      ++iter_graph;
      ++iter_vertex;
    }
    else
    {
      ++iter_graph;
    }
  }
  return 1;
}
