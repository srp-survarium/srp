const vostok::ai::planning::world_state *__thiscall vostok::ai::graph_wrapper::planner_backward::impl::vertex_id(
        vostok::ai::graph_wrapper::planner_backward::impl *this,
        const vostok::ai::planning::world_state *current_vertex_id,
        const vostok::ai::planning::operator_pair *const *iterator)
{
  vostok::ai::planning::operator_impl *operator_impl; // [esp+Ch] [ebp-Ch]
  const vostok::ai::planning::world_state *search_state; // [esp+10h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  search_state = this->m_current_state;
  operator_impl = (*iterator)->m_operator;
  this->m_applied = vostok::ai::graph_wrapper::planner_backward::impl::applicable(
                      this,
                      &this->m_current_state->m_properties,
                      &operator_impl->m_preconditions.m_properties,
                      &operator_impl->m_effects.m_properties)
                 && vostok::ai::graph_wrapper::planner_backward::impl::apply(
                      this,
                      &search_state->m_properties,
                      &operator_impl->m_preconditions.m_properties,
                      &operator_impl->m_effects.m_properties);
  return &this->m_new_state;
}
