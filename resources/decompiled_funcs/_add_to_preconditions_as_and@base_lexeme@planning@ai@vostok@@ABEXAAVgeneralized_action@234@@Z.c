void __thiscall vostok::ai::planning::base_lexeme::add_to_preconditions_as_and(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::generalized_action *action)
{
  vostok::ai::planning::base_lexeme::add_to_preconditions(
    (vostok::ai::planning::base_lexeme *)this->m_left.m_lexeme,
    action);
  vostok::ai::planning::base_lexeme::add_to_preconditions(
    (vostok::ai::planning::base_lexeme *)this->m_right.m_lexeme,
    action);
}
