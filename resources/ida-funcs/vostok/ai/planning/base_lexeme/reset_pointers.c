void __thiscall vostok::ai::planning::base_lexeme::reset_pointers(vostok::ai::planning::base_lexeme *this)
{
  unsigned __int8 m_operation_type; // al
  const vostok::ai::planning::base_lexeme::function_pointers *v2; // eax
  bool v3; // zf

  m_operation_type = this->m_operation_type;
  if ( m_operation_type == 1 )
  {
    v2 = &vostok::ai::planning::base_lexeme::s_or_function_pointers;
  }
  else
  {
    v3 = m_operation_type == 0;
    v2 = &vostok::ai::planning::base_lexeme::s_and_function_pointers;
    if ( !v3 )
      v2 = &vostok::ai::planning::base_lexeme::s_predicate_function_pointers;
  }
  this->m_function_pointers = v2;
}
