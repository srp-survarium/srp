void __usercall vostok::ai::planning::base_lexeme::function_pointers::function_pointers(
        vostok::ai::planning::base_lexeme::function_pointers *this@<ecx>,
        _DWORD *a2@<eax>)
{
  if ( this )
  {
    if ( this == (vostok::ai::planning::base_lexeme::function_pointers *)1 )
    {
      *a2 = vostok::ai::planning::base_lexeme::invert_value_as_or;
      a2[1] = vostok::ai::planning::base_lexeme::count_operands_as_or;
      a2[2] = vostok::ai::planning::base_lexeme::expand_brackets_as_or;
      a2[3] = vostok::ai::planning::base_lexeme::expand_brackets_as_or;
      a2[4] = vostok::ai::planning::base_lexeme::generate_permutations_as_or;
      a2[5] = vostok::ai::planning::base_lexeme::add_to_target_world_state_as_or;
      a2[6] = vostok::ai::planning::base_lexeme::add_to_preconditions_as_or;
      a2[7] = vostok::animation::mixing::binary_tree_null_weight_searcher::visit;
    }
    else
    {
      *a2 = vostok::ai::planning::base_lexeme::invert_value_as_predicate;
      a2[1] = vostok::ai::planning::base_lexeme::count_operands_as_predicate;
      a2[2] = vostok::ai::planning::base_lexeme::expand_brackets_as_or;
      a2[3] = vostok::ai::planning::base_lexeme::expand_brackets_as_predicate;
      a2[4] = vostok::ai::planning::base_lexeme::generate_permutations_as_and;
      a2[5] =  __thiscall survarium::collision_geometry_subscriber::`vcall'{4,{flat}};
      a2[6] =  __thiscall vostok::engine::engine_world::`vcall'{8,{flat}};
      a2[7] =  __thiscall vostok::sound::world::`vcall'{12,{flat}};
    }
  }
  else
  {
    *a2 = vostok::ai::planning::base_lexeme::invert_value_as_and;
    a2[1] = vostok::ai::planning::base_lexeme::count_operands_as_and;
    a2[2] = vostok::ai::planning::base_lexeme::expand_brackets_as_and;
    a2[3] = vostok::ai::planning::base_lexeme::expand_brackets_as_predicate;
    a2[4] = vostok::ai::planning::base_lexeme::generate_permutations_as_and;
    a2[5] = vostok::ai::planning::base_lexeme::add_to_target_world_state_as_and;
    a2[6] = vostok::ai::planning::base_lexeme::add_to_preconditions_as_and;
    a2[7] = vostok::ai::planning::base_lexeme::add_to_effects_as_and;
  }
}
