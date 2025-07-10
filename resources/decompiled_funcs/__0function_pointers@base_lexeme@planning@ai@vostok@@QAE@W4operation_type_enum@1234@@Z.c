void __thiscall vostok::ai::planning::base_lexeme::function_pointers::function_pointers(
        vostok::ai::planning::base_lexeme::function_pointers *this,
        vostok::ai::planning::base_lexeme::operation_type_enum operation_type)
{
  switch ( operation_type )
  {
    case operation_type_and:
      goto LABEL_4;
    case operation_type_or:
      this->m_value_invertor = vostok::ai::planning::base_lexeme::invert_value_as_or;
      this->m_operands_counter = vostok::ai::planning::base_lexeme::count_operands_as_or;
      this->m_brackets_opener1 = vostok::ai::planning::base_lexeme::expand_brackets_as_or;
      this->m_brackets_opener2 = vostok::ai::planning::base_lexeme::expand_brackets_as_or;
      this->m_generator = vostok::ai::planning::base_lexeme::generate_permutations_as_or;
      this->m_world_state_filler = vostok::ai::planning::base_lexeme::add_to_target_world_state_as_or;
      this->m_preconditions_filler = vostok::ai::planning::base_lexeme::add_to_preconditions_as_or;
      this->m_effects_filler = vostok::ai::planning::base_lexeme::add_to_effects_as_or;
      break;
    case operation_type_predicate:
      this->m_value_invertor = vostok::ai::planning::base_lexeme::invert_value_as_predicate;
      this->m_operands_counter = vostok::ai::planning::base_lexeme::count_operands_as_predicate;
      this->m_brackets_opener1 = vostok::ai::planning::base_lexeme::expand_brackets_as_predicate;
      this->m_brackets_opener2 = (vostok::ai::planning::base_lexeme_ptr *(__thiscall *)(vostok::ai::planning::base_lexeme *, vostok::ai::planning::base_lexeme_ptr *, vostok::memory::stack_allocator *, const vostok::ai::planning::base_lexeme *))vostok::ai::planning::base_lexeme::expand_brackets_as_predicate;
      this->m_generator = vostok::ai::planning::base_lexeme::generate_permutations_as_predicate;
      this->m_world_state_filler = (void (__thiscall *)(vostok::ai::planning::base_lexeme *, vostok::ai::planning::specified_problem *, unsigned int *)) __thiscall vostok::ai::perceptors::enemy_perceptor::`vcall'{4,{flat}};
      this->m_preconditions_filler = (void (__thiscall *)(vostok::ai::planning::base_lexeme *, vostok::ai::planning::generalized_action *)) __thiscall vostok::ai::planning::base_lexeme::`vcall'{8,{flat}};
      this->m_effects_filler = (void (__thiscall *)(vostok::ai::planning::base_lexeme *, vostok::ai::planning::generalized_action *)) __thiscall vostok::sound::world::`vcall'{12,{flat}};
      break;
    default:
LABEL_4:
      this->m_value_invertor = vostok::ai::planning::base_lexeme::invert_value_as_and;
      this->m_operands_counter = vostok::ai::planning::base_lexeme::count_operands_as_and;
      this->m_brackets_opener1 = vostok::ai::planning::base_lexeme::expand_brackets_as_and;
      this->m_brackets_opener2 = (vostok::ai::planning::base_lexeme_ptr *(__thiscall *)(vostok::ai::planning::base_lexeme *, vostok::ai::planning::base_lexeme_ptr *, vostok::memory::stack_allocator *, const vostok::ai::planning::base_lexeme *))vostok::ai::planning::base_lexeme::expand_brackets_as_and;
      this->m_generator = vostok::ai::planning::base_lexeme::generate_permutations_as_and;
      this->m_world_state_filler = vostok::ai::planning::base_lexeme::add_to_target_world_state_as_and;
      this->m_preconditions_filler = vostok::ai::planning::base_lexeme::add_to_preconditions_as_and;
      this->m_effects_filler = vostok::ai::planning::base_lexeme::add_to_effects_as_and;
      return;
  }
}
