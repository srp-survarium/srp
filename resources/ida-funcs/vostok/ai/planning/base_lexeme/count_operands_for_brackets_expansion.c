vostok::ai::planning::operands_calculator *__thiscall vostok::ai::planning::base_lexeme::count_operands_for_brackets_expansion(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::operands_calculator *result)
{
  unsigned int *v2; // esi
  vostok::ai::planning::operands_calculator *v3; // eax
  _BYTE v4[12]; // [esp+8h] [ebp-Ch] BYREF

  v2 = (unsigned int *)((int (__stdcall *)(_BYTE *))this->m_function_pointers->m_operands_counter)(v4);
  v3 = result;
  result->operands_count = *v2++;
  result->and_count = *v2;
  result->or_count = v2[1];
  return v3;
}
