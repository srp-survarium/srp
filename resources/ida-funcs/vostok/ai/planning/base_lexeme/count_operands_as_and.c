vostok::ai::planning::operands_calculator *__thiscall vostok::ai::planning::base_lexeme::count_operands_as_and(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::operands_calculator *result)
{
  unsigned int v4; // [esp+4h] [ebp-34h]
  unsigned int v5; // [esp+8h] [ebp-30h]
  vostok::ai::planning::operands_calculator v6; // [esp+18h] [ebp-20h] BYREF
  const vostok::ai::planning::operands_calculator *right; // [esp+24h] [ebp-14h]
  const vostok::ai::planning::operands_calculator *left; // [esp+28h] [ebp-10h]
  vostok::ai::planning::operands_calculator v9; // [esp+2Ch] [ebp-Ch] BYREF

  vostok::ai::planning::base_lexeme::count_operands_for_brackets_expansion(
    (vostok::ai::planning::base_lexeme *)this->m_left.m_lexeme,
    &v6);
  left = &v6;
  vostok::ai::planning::base_lexeme::count_operands_for_brackets_expansion(
    (vostok::ai::planning::base_lexeme *)this->m_right.m_lexeme,
    &v9);
  right = &v9;
  v4 = v9.or_count + left->or_count + v9.operands_count * left->operands_count - 1;
  v5 = v9.and_count + left->and_count + v9.operands_count * left->operands_count;
  result->operands_count = v9.operands_count * left->operands_count;
  result->and_count = v5;
  result->or_count = v4;
  return result;
}
