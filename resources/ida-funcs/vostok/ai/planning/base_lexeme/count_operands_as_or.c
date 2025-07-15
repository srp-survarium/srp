vostok::ai::planning::operands_calculator *__thiscall vostok::ai::planning::base_lexeme::count_operands_as_or(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::operands_calculator *result)
{
  vostok::ai::planning::base_lexeme *m_lexeme; // edi
  vostok::ai::planning::operands_calculator *v3; // esi
  vostok::ai::planning::operands_calculator *v4; // eax
  unsigned int v5; // edx
  vostok::ai::planning::operands_calculator v7; // [esp+8h] [ebp-18h] BYREF
  vostok::ai::planning::operands_calculator resulta; // [esp+14h] [ebp-Ch] BYREF

  m_lexeme = (vostok::ai::planning::base_lexeme *)this->m_left.m_lexeme;
  v3 = vostok::ai::planning::base_lexeme::count_operands_for_brackets_expansion(
         (vostok::ai::planning::base_lexeme *)this->m_right.m_lexeme,
         &resulta);
  v4 = vostok::ai::planning::base_lexeme::count_operands_for_brackets_expansion(m_lexeme, &v7);
  result->operands_count = v4->operands_count + v3->operands_count;
  v5 = v3->and_count + v4->and_count;
  result->or_count = v3->or_count + v4->or_count;
  result->and_count = v5;
  return result;
}
