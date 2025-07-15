vostok::ai::planning::base_lexeme_ptr *__thiscall vostok::ai::planning::base_lexeme::expand_brackets_as_predicate(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::ai::planning::base_lexeme_ptr *allocator,
        vostok::ai::planning::base_lexeme *right)
{
  const vostok::ai::planning::base_lexeme *v5; // [esp+0h] [ebp-4h]

  vostok::ai::planning::base_lexeme::generate_permutations(
    right,
    result,
    allocator,
    (vostok::memory::stack_allocator *)this,
    v5);
  return result;
}
