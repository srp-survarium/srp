vostok::ai::planning::operands_calculator *__thiscall vostok::ai::planning::base_lexeme::count_operands_as_and(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::operands_calculator *result)
{
  unsigned int v3; // ecx
  vostok::ai::planning::operands_calculator *v4; // eax
  unsigned int v5; // edx
  vostok::ai::planning::operands_calculator v6; // [esp+4h] [ebp-18h] BYREF
  vostok::ai::planning::operands_calculator resulta; // [esp+10h] [ebp-Ch] BYREF

  vostok::ai::planning::base_lexeme::count_operands_for_brackets_expansion(
    (vostok::ai::planning::base_lexeme *)this->m_left.m_lexeme,
    &resulta);
  vostok::ai::planning::base_lexeme::count_operands_for_brackets_expansion(
    (vostok::ai::planning::base_lexeme *)this->m_right.m_lexeme,
    &v6);
  v3 = v6.operands_count * resulta.operands_count;
  v4 = result;
  v5 = v6.and_count + v6.operands_count * resulta.operands_count + resulta.and_count;
  result->operands_count = v6.operands_count * resulta.operands_count;
  result->and_count = v5;
  result->or_count = resulta.or_count + v3 + v6.or_count - 1;
  return v4;
}
