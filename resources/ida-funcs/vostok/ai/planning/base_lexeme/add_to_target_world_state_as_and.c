void __thiscall vostok::ai::planning::base_lexeme::add_to_target_world_state_as_and(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::specified_problem *problem,
        unsigned int *offset)
{
  vostok::ai::planning::base_lexeme::add_to_target_world_state(
    (vostok::ai::planning::base_lexeme *)this->m_left.m_lexeme,
    problem,
    offset);
  vostok::ai::planning::base_lexeme::add_to_target_world_state(
    (vostok::ai::planning::base_lexeme *)this->m_right.m_lexeme,
    problem,
    offset);
}
