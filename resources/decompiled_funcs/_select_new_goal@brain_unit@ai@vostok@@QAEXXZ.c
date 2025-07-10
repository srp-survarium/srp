void __thiscall vostok::ai::brain_unit::select_new_goal(vostok::ai::brain_unit *this)
{
  vostok::ai::planning::goal_selector::set_current_goal(
    this->m_goal_selector,
    &this->m_world->m_search_service,
    this->m_specified_problem,
    &this->m_behaviour,
    &this->m_blackboard);
}
