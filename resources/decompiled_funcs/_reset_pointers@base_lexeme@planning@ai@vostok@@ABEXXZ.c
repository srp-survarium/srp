void __thiscall vostok::ai::planning::base_lexeme::reset_pointers(vostok::ai::planning::base_lexeme *this)
{
  vostok::ai::planning::base_lexeme::function_pointers *v1; // [esp+0h] [ebp-Ch]
  const vostok::ai::planning::base_lexeme::function_pointers *v2; // [esp+4h] [ebp-8h]

  if ( this->m_operation_type == 1 )
  {
    v2 = &vostok::ai::planning::base_lexeme::s_or_function_pointers;
  }
  else
  {
    if ( this->m_operation_type )
      v1 = &vostok::ai::planning::base_lexeme::s_predicate_function_pointers;
    else
      v1 = &vostok::ai::planning::base_lexeme::s_and_function_pointers;
    v2 = v1;
  }
  this->m_function_pointers = v2;
}
