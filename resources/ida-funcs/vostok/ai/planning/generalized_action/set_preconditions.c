void __thiscall vostok::ai::planning::generalized_action::set_preconditions(
        vostok::ai::planning::generalized_action *this,
        vostok::ai::planning::base_lexeme *target_expression)
{
  void *v2; // esp
  char *v3; // eax
  survarium::game_camera *v4; // ecx
  vostok::memory::stack_allocator *v5; // ecx
  unsigned __int64 v6; // [esp-Ch] [ebp-48h]
  int v7; // [esp+0h] [ebp-3Ch] BYREF
  vostok::ai::planning::generalized_action *thisa; // [esp+4h] [ebp-38h]
  char v9; // [esp+Bh] [ebp-31h]
  vostok::ai::planning::operands_calculator *p_result; // [esp+Ch] [ebp-30h]
  vostok::ai::planning::operands_calculator result; // [esp+10h] [ebp-2Ch] BYREF
  unsigned int memory_size; // [esp+1Ch] [ebp-20h]
  vostok::ai::planning::base_lexeme_ptr new_expression; // [esp+20h] [ebp-1Ch] BYREF
  vostok::memory::stack_allocator allocator; // [esp+24h] [ebp-18h] BYREF

  thisa = this;
  vostok::memory::stack_allocator::stack_allocator((vostok::memory::stack_allocator *)this, &allocator);
  vostok::ai::planning::base_lexeme::count_operands_for_brackets_expansion(target_expression, &result);
  p_result = &result;
  memory_size = 24 * (result.and_count + result.or_count);
  v2 = alloca(memory_size);
  v7 = (int)&v7;
  v6 = memory_size;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&result);
  vostok::memory::base_allocator::initialize(&allocator, v3, v6, "world state expression");
  vostok::ai::planning::base_lexeme::expand_brackets(target_expression, &new_expression, &allocator);
  v9 = 0;
  survarium::weapon_user_dead_state::finalize(v4);
  vostok::ai::planning::base_lexeme::add_to_preconditions(
    (vostok::ai::planning::base_lexeme *)new_expression.m_lexeme,
    thisa);
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(&new_expression);
  vostok::memory::stack_allocator::~stack_allocator(v5, &allocator);
}
