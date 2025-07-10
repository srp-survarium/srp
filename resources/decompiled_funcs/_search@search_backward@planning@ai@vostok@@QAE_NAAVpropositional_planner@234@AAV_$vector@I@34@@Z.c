bool __thiscall vostok::ai::planning::search_backward::search(
        vostok::ai::planning::search_backward *this,
        vostok::ai::planning::propositional_planner *graph,
        vostok::ai::vector<unsigned int> *path)
{
  survarium::game_camera *v3; // ecx
  unsigned int v6; // [esp+2Ch] [ebp-4Ch]
  vostok::ai::std_allocator<vostok::ai::planning::specified_action> __a; // [esp+33h] [ebp-45h] BYREF
  int v8; // [esp+34h] [ebp-44h]
  vostok::ai::planning::propositional_planner_base *v9; // [esp+38h] [ebp-40h]
  bool v10; // [esp+3Fh] [ebp-39h]
  stlp_std::priv::_Vector_base<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > v11; // [esp+40h] [ebp-38h] BYREF
  int v12; // [esp+4Ch] [ebp-2Ch]
  unsigned int v13; // [esp+50h] [ebp-28h]
  char v14; // [esp+57h] [ebp-21h]
  vostok::ai::path_heuristics::planner_backward::impl heuristics; // [esp+58h] [ebp-20h] BYREF
  vostok::ai::search_restrictor::planner_backward::impl restrictor; // [esp+5Ch] [ebp-1Ch] BYREF
  vostok::ai::path_constructor::planner_backward::impl<vostok::ai::planning::search_base::vertex_type,vostok::ai::vector<unsigned int> > path_constructor; // [esp+74h] [ebp-4h] BYREF

  this->m_graph_wrapper.m_graph = graph;
  path_constructor.m_path = path;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&heuristics);
  heuristics.m_graph = graph;
  v14 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  v13 = -1;
  v9 = &graph->vostok::ai::planning::propositional_planner_base;
  v8 = graph->m_operators.m_objects._M_impl._M_finish - graph->m_operators.m_objects._M_impl._M_start;
  stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>(
    &v11,
    &__a);
  v12 = 0;
  v6 = vostok::ai::planning::search_base::max_vertex_count() - v8 - 1;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&restrictor);
  restrictor.m_wrapper = &this->m_graph_wrapper;
  restrictor.m_start_vertex_id = &graph->m_target_state;
  restrictor.m_target_vertex_id = (const vostok::ai::planning::world_state *)&v11;
  restrictor.m_max_range = v13;
  restrictor.m_max_iteration_count = -1;
  restrictor.m_max_visited_vertex_count = v6;
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>((stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *)&v11);
  v10 = vostok::ai::a_star::find<vostok::ai::planning::search_base::priority_queue_impl_type,vostok::ai::graph_wrapper::planner_backward::impl,vostok::ai::path_constructor::planner_backward::impl<vostok::ai::planning::search_base::vertex_type,vostok::ai::vector<unsigned int>>,vostok::ai::path_heuristics::planner_backward::impl,vostok::ai::search_restrictor::planner_backward::impl>(
          &this->m_search->m_priority_queue,
          &this->m_graph_wrapper,
          &path_constructor,
          &heuristics,
          &restrictor);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&restrictor);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&heuristics);
  return v10;
}
