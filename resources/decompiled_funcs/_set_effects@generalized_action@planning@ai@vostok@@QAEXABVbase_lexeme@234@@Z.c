void __thiscall vostok::ai::planning::generalized_action::set_effects(
        vostok::ai::planning::generalized_action *this,
        vostok::ai::planning::base_lexeme *target_expression)
{
  void *v2; // esp
  char *v3; // eax
  survarium::game_camera *v4; // ecx
  vostok::memory::stack_allocator *v5; // ecx
  unsigned __int64 v6; // [esp-Ch] [ebp-5Ch]
  int v7; // [esp+0h] [ebp-50h] BYREF
  vostok::ai::planning::generalized_action *thisa; // [esp+4h] [ebp-4Ch]
  char v9; // [esp+Bh] [ebp-45h]
  vostok::ai::planning::generalized_action **v10; // [esp+Ch] [ebp-44h]
  char v11; // [esp+13h] [ebp-3Dh]
  survarium::game_camera *p_m_clones; // [esp+14h] [ebp-3Ch]
  char v13; // [esp+1Bh] [ebp-35h]
  vostok::ai::planning::operands_calculator *p_result; // [esp+1Ch] [ebp-34h]
  vostok::ai::planning::operands_calculator result; // [esp+20h] [ebp-30h] BYREF
  unsigned int j; // [esp+2Ch] [ebp-24h]
  unsigned int memory_size; // [esp+30h] [ebp-20h]
  vostok::ai::planning::base_lexeme_ptr new_expression; // [esp+34h] [ebp-1Ch] BYREF
  vostok::memory::stack_allocator allocator; // [esp+38h] [ebp-18h] BYREF

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
  v13 = 0;
  survarium::weapon_user_dead_state::finalize(v4);
  vostok::ai::planning::base_lexeme::add_to_effects((vostok::ai::planning::base_lexeme *)new_expression.m_lexeme, thisa);
  for ( j = 0; ; ++j )
  {
    p_m_clones = (survarium::game_camera *)&thisa->m_clones;
    if ( j >= thisa->m_clones.m_end - thisa->m_clones.m_begin )
      break;
    v11 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&thisa->m_clones);
    v10 = &thisa->m_clones.m_begin[j];
    v9 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)j);
    vostok::ai::planning::base_lexeme::add_to_effects(
      (vostok::ai::planning::base_lexeme *)new_expression.m_lexeme,
      *v10);
  }
  vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(&new_expression);
  vostok::memory::stack_allocator::~stack_allocator(v5, &allocator);
}
