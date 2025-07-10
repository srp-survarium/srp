unsigned int __thiscall vostok::ai::path_heuristics::planner_backward::impl::estimate(
        vostok::ai::path_heuristics::planner_backward::impl *this,
        const vostok::ai::planning::world_state *current_vertex_id_ptr,
        const vostok::ai::planning::world_state *neighbour_vertex_id)
{
  survarium::game_camera *v3; // ecx
  vostok::ai::planning::world_state_property *iter_vertex; // [esp+2Ch] [ebp-14h]
  unsigned int result; // [esp+30h] [ebp-10h]
  vostok::ai::planning::world_state_property *iter_end_vertex; // [esp+34h] [ebp-Ch]
  const vostok::ai::planning::world_state_property *iter_end_graph; // [esp+38h] [ebp-8h] BYREF
  const vostok::ai::planning::world_state_property *iter_graph; // [esp+3Ch] [ebp-4h] BYREF

  result = 0;
  iter_graph = this->m_graph->m_current_state.m_properties._M_impl._M_start;
  iter_end_graph = this->m_graph->m_current_state.m_properties._M_impl._M_finish;
  iter_vertex = neighbour_vertex_id->m_properties._M_impl._M_start;
  iter_end_vertex = neighbour_vertex_id->m_properties._M_impl._M_finish;
  while ( iter_vertex != iter_end_vertex )
  {
    if ( iter_graph == iter_end_graph || iter_graph->m_id > iter_vertex->m_id )
    {
      vostok::ai::planning::propositional_planner::evaluate(
        this->m_graph,
        &iter_graph,
        (vostok::ai::planning::world_state_property **)&iter_end_graph,
        &iter_vertex->m_id);
      survarium::weapon_user_dead_state::finalize(v3);
    }
    if ( iter_graph->m_id >= iter_vertex->m_id )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)iter_graph);
      if ( iter_graph->m_value != iter_vertex->m_value )
        ++result;
      ++iter_graph;
      ++iter_vertex;
    }
    else
    {
      ++iter_graph;
    }
  }
  return result;
}
