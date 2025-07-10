void __thiscall vostok::ai::planning::base_lexeme::add_to_target_world_state(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::specified_problem *problem,
        unsigned int *offset)
{
  this->m_function_pointers->m_world_state_filler(this, problem, offset);
}
