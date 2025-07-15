void __thiscall vostok::ai::planning::base_lexeme::invert_value_as_and(vostok::ai::planning::base_lexeme *this)
{
  ((void (*)(void))this->m_left.m_lexeme->m_function_pointers->m_value_invertor)();
  ((void (*)(void))this->m_right.m_lexeme->m_function_pointers->m_value_invertor)();
  this->m_operation_type = 1;
  vostok::ai::planning::base_lexeme::reset_pointers(this);
}
