void __thiscall vostok::ai::planning::base_lexeme::add_to_target_world_state_as_and(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::specified_problem *problem,
        unsigned int *offset)
{
  ((void (__stdcall *)(vostok::ai::planning::specified_problem *, unsigned int *))this->m_left.m_lexeme->m_function_pointers->m_world_state_filler)(
    problem,
    offset);
  ((void (__stdcall *)(vostok::ai::planning::specified_problem *, unsigned int *))this->m_right.m_lexeme->m_function_pointers->m_world_state_filler)(
    problem,
    offset);
}
