void __thiscall vostok::ai::planning::base_lexeme::add_to_preconditions_as_or(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::generalized_action *action)
{
  vostok::ai::planning::generalized_action *v3; // ecx
  vostok::ai::planning::generalized_action *v4; // eax

  ((void (__stdcall *)(vostok::ai::planning::generalized_action *))this->m_left.m_lexeme->m_function_pointers->m_preconditions_filler)(action);
  v4 = vostok::ai::planning::generalized_action::clone(v3, (int)action);
  ((void (__stdcall *)(vostok::ai::planning::generalized_action *))this->m_right.m_lexeme->m_function_pointers->m_preconditions_filler)(v4);
}
