void __thiscall vostok::ai::planning::base_lexeme::invert_value_as_and(vostok::ai::planning::base_lexeme *this)
{
  vostok::ai::planning::base_lexeme::invert_value((vostok::ai::planning::base_lexeme *)this->m_left.m_lexeme);
  vostok::ai::planning::base_lexeme::invert_value((vostok::ai::planning::base_lexeme *)this->m_right.m_lexeme);
  this->m_operation_type = 1;
  vostok::ai::planning::base_lexeme::reset_pointers(this);
}
