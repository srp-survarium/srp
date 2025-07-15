const vostok::ai::planning::world_state *__thiscall vostok::ai::graph_wrapper::planner_forward::impl::vertex_id(
        vostok::ai::graph_wrapper::planner_forward::impl *this,
        const vostok::ai::planning::world_state *current_vertex_id,
        survarium::game_camera **iterator)
{
  vostok::ai::planning::world_state *start_state; // [esp+Ch] [ebp-14h]
  vostok::ai::planning::operator_impl *operator_impl; // [esp+14h] [ebp-Ch]
  const vostok::ai::planning::world_state *search_state; // [esp+18h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  search_state = this->m_current_state;
  operator_impl = (vostok::ai::planning::operator_impl *)LODWORD((*iterator)->m_inverted_view_matrix.i.x);
  survarium::weapon_user_dead_state::finalize(*iterator);
  start_state = &this->m_graph->m_current_state;
  if ( vostok::ai::graph_wrapper::planner_forward::impl::applicable(
         this,
         &search_state->m_properties,
         &operator_impl->m_preconditions.m_properties,
         &start_state->m_properties) )
  {
    this->m_applied = 1;
    vostok::ai::graph_wrapper::planner_forward::impl::apply(
      this,
      &search_state->m_properties,
      &operator_impl->m_effects.m_properties,
      &start_state->m_properties);
  }
  else
  {
    this->m_applied = 0;
  }
  return &this->m_new_state;
}
