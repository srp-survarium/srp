void __thiscall vostok::ai::graph_wrapper::propositional_planner_base::impl::on_before_search(
        vostok::ai::graph_wrapper::propositional_planner_base::impl *this)
{
  vostok::ai::planning::operator_pair *M_start; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  M_start = this->m_graph->m_operators.m_objects._M_impl._M_start;
  this->m_begin = M_start;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)M_start);
  this->m_end = this->m_graph->m_operators.m_objects._M_impl._M_finish;
}
