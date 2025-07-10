vostok::ai::planning::base_lexeme_ptr *__thiscall vostok::ai::planning::base_lexeme::generate_permutations_as_predicate(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::memory::stack_allocator *allocator,
        const vostok::ai::planning::base_lexeme *left)
{
  vostok::memory::stack_allocator *v4; // eax
  const vostok::ai::planning::base_lexeme *const v5; // eax
  void *_Where; // [esp+8h] [ebp-Ch]
  vostok::ai::planning::base_lexeme *v9; // [esp+10h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::stack_allocator::malloc_impl(v4, 0x18u);
  v9 = (vostok::ai::planning::base_lexeme *)operator new(0x18u, _Where);
  if ( v9 )
  {
    vostok::ai::planning::base_lexeme::base_lexeme(v9, operation_type_and, left, this, 1u);
    vostok::ai::planning::base_lexeme_ptr::base_lexeme_ptr(result, v5);
  }
  else
  {
    vostok::ai::planning::base_lexeme_ptr::base_lexeme_ptr(result, 0);
  }
  return result;
}
