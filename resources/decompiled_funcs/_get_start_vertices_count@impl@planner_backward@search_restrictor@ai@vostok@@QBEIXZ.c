int __thiscall vostok::ai::search_restrictor::planner_backward::impl::get_start_vertices_count(
        vostok::ai::search_restrictor::planner_backward::impl *this)
{
  const vostok::ai::graph_wrapper::propositional_planner_base::impl *m_wrapper; // [esp+Ch] [ebp-8h]

  m_wrapper = this->m_wrapper;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_wrapper);
  return m_wrapper->m_graph->m_target_state_offsets._M_impl._M_finish
       - m_wrapper->m_graph->m_target_state_offsets._M_impl._M_start
       + 1;
}
