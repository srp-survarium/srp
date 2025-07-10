vostok::ai::planning::operands_calculator *__thiscall vostok::ai::planning::base_lexeme::count_operands_as_predicate(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::operands_calculator *result)
{
  result->operands_count = 1;
  result->and_count = 0;
  result->or_count = 0;
  return result;
}
