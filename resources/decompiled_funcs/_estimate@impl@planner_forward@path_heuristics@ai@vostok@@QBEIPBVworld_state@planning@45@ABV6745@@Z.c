unsigned int __thiscall vostok::ai::path_heuristics::planner_forward::impl::estimate(
        vostok::ai::path_heuristics::planner_forward::impl *this,
        const vostok::ai::planning::world_state *current_vertex_id_ptr,
        const vostok::ai::planning::world_state *neighbour_vertex_id)
{
  vostok::ai::vector<unsigned int> *p_m_target_state_offsets; // edx
  survarium::game_camera *v4; // ecx
  unsigned int v6; // [esp+0h] [ebp-D8h]
  vostok::ai::planning::world_state result; // [esp+B8h] [ebp-20h] BYREF
  unsigned int estimation; // [esp+C8h] [ebp-10h]
  unsigned int i; // [esp+CCh] [ebp-Ch]
  unsigned int min_result; // [esp+D0h] [ebp-8h]
  unsigned int offsets_count; // [esp+D4h] [ebp-4h]

  p_m_target_state_offsets = &this->m_graph->m_target_state_offsets;
  v4 = (survarium::game_camera *)(this->m_graph->m_target_state_offsets._M_impl._M_finish
                                - p_m_target_state_offsets->_M_impl._M_start
                                + 1);
  offsets_count = p_m_target_state_offsets->_M_impl._M_finish - p_m_target_state_offsets->_M_impl._M_start + 1;
  if ( offsets_count == 1 )
    return vostok::ai::path_heuristics::planner_forward::impl::estimate_impl(
             this,
             neighbour_vertex_id,
             this->m_graph->m_target_state.m_properties._M_impl._M_start,
             this->m_graph->m_target_state.m_properties._M_impl._M_finish);
  min_result = -1;
  for ( i = 0; i < offsets_count; ++i )
  {
    vostok::ai::planning::propositional_planner::target(this->m_graph, &result, i);
    estimation = vostok::ai::path_heuristics::planner_forward::impl::estimate_impl(
                   this,
                   neighbour_vertex_id,
                   result.m_properties._M_impl._M_start,
                   result.m_properties._M_impl._M_finish);
    if ( min_result == -1 || min_result > estimation )
      v6 = estimation;
    else
      v6 = min_result;
    min_result = v6;
    stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(&result.m_properties._M_impl);
    v4 = (survarium::game_camera *)(i + 1);
  }
  survarium::weapon_user_dead_state::finalize(v4);
  return min_result;
}
