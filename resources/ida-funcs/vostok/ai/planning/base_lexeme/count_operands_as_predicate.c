vostok::ai::planning::operands_calculator *__thiscall vostok::ai::planning::base_lexeme::count_operands_as_predicate(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::operands_calculator *result)
{
  vostok::ai::planning::operands_calculator *v2; // eax

  v2 = result;
  result->and_count = 0;
  result->or_count = 0;
  result->operands_count = 1;
  return v2;
}
