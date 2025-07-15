void __thiscall vostok::ai::planning::base_lexeme::add_to_preconditions(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::generalized_action *action)
{
  this->m_function_pointers->m_preconditions_filler(this, action);
}
