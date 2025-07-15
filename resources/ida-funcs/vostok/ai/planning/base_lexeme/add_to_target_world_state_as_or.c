void __thiscall vostok::ai::planning::base_lexeme::add_to_target_world_state_as_or(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::specified_problem *problem,
        unsigned int *offset)
{
  unsigned int **v3; // ebx
  vostok::buffer_vector<unsigned int> *v5; // ecx

  v3 = (unsigned int **)offset;
  ((void (__stdcall *)(vostok::ai::planning::specified_problem *, unsigned int *))this->m_left.m_lexeme->m_function_pointers->m_world_state_filler)(
    problem,
    offset);
  offset = *v3;
  vostok::buffer_vector<unsigned int>::push_back(v5, (int)&problem->m_target_offsets, (const unsigned int *)&offset);
  ((void (__stdcall *)(vostok::ai::planning::specified_problem *, unsigned int **))this->m_right.m_lexeme->m_function_pointers->m_world_state_filler)(
    problem,
    v3);
}
