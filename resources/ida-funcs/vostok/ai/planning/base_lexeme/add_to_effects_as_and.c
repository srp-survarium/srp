void __thiscall vostok::ai::planning::base_lexeme::add_to_effects_as_and(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::generalized_action *action)
{
  ((void (__stdcall *)(vostok::ai::planning::generalized_action *))this->m_left.m_lexeme->m_function_pointers->m_effects_filler)(action);
  ((void (__stdcall *)(vostok::ai::planning::generalized_action *))this->m_right.m_lexeme->m_function_pointers->m_effects_filler)(action);
}
