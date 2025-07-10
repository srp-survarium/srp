char __thiscall vostok::ai::search_restrictor::planner_forward::impl::target_reached(
        vostok::ai::search_restrictor::planner_forward::impl *this,
        const vostok::ai::planning::world_state *vertex_id)
{
  const vostok::ai::graph_wrapper::propositional_planner_base::impl *m_wrapper; // [esp+F8h] [ebp-28h]
  vostok::ai::planning::world_state result; // [esp+104h] [ebp-1Ch] BYREF
  unsigned int i; // [esp+114h] [ebp-Ch]
  vostok::ai::planning::propositional_planner *graph; // [esp+118h] [ebp-8h]
  unsigned int offsets_count; // [esp+11Ch] [ebp-4h]

  m_wrapper = this->m_wrapper;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_wrapper);
  graph = m_wrapper->m_graph;
  offsets_count = graph->m_target_state_offsets._M_impl._M_finish - graph->m_target_state_offsets._M_impl._M_start + 1;
  if ( offsets_count == 1 )
    return vostok::ai::search_restrictor::planner_forward::impl::target_reached_impl(
             this,
             vertex_id,
             graph->m_target_state.m_properties._M_impl._M_start,
             graph->m_target_state.m_properties._M_impl._M_finish);
  for ( i = 0; i < offsets_count; ++i )
  {
    vostok::ai::planning::propositional_planner::target(graph, &result, i);
    if ( vostok::ai::search_restrictor::planner_forward::impl::target_reached_impl(
           this,
           vertex_id,
           result.m_properties._M_impl._M_start,
           result.m_properties._M_impl._M_finish) )
    {
      stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(&result.m_properties._M_impl);
      return 1;
    }
    stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(&result.m_properties._M_impl);
  }
  return 0;
}
