vostok::ai::planning::operands_calculator *__thiscall vostok::ai::planning::base_lexeme::count_operands_for_brackets_expansion(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::operands_calculator *result)
{
  _BYTE v3[12]; // [esp+4h] [ebp-Ch] BYREF

  *result = *this->m_function_pointers->m_operands_counter(this, v3);
  return result;
}
