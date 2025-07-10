vostok::ai::planning::base_lexeme_ptr *__thiscall vostok::ai::planning::base_lexeme::expand_brackets_as_predicate(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::memory::stack_allocator *allocator,
        vostok::ai::planning::base_lexeme *right)
{
  vostok::ai::planning::base_lexeme::generate_permutations(right, result, allocator, this);
  return result;
}
