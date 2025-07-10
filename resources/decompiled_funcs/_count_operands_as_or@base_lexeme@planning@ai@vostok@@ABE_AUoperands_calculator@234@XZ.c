vostok::ai::planning::operands_calculator *__thiscall vostok::ai::planning::base_lexeme::count_operands_as_or(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::operands_calculator *result)
{
  vostok::ai::planning::operands_calculator *v3; // [esp+4h] [ebp-34h]
  vostok::ai::planning::operands_calculator *v4; // [esp+8h] [ebp-30h]
  unsigned int v5; // [esp+Ch] [ebp-2Ch]
  unsigned int v6; // [esp+10h] [ebp-28h]
  vostok::ai::planning::base_lexeme *m_lexeme; // [esp+18h] [ebp-20h]
  vostok::ai::planning::operands_calculator v8; // [esp+20h] [ebp-18h] BYREF
  vostok::ai::planning::operands_calculator v9; // [esp+2Ch] [ebp-Ch] BYREF

  m_lexeme = (vostok::ai::planning::base_lexeme *)this->m_left.m_lexeme;
  v3 = vostok::ai::planning::base_lexeme::count_operands_for_brackets_expansion(
         (vostok::ai::planning::base_lexeme *)this->m_right.m_lexeme,
         &v9);
  v4 = vostok::ai::planning::base_lexeme::count_operands_for_brackets_expansion(m_lexeme, &v8);
  v5 = v3->or_count + v4->or_count;
  v6 = v3->and_count + v4->and_count;
  result->operands_count = v3->operands_count + v4->operands_count;
  result->and_count = v6;
  result->or_count = v5;
  return result;
}
