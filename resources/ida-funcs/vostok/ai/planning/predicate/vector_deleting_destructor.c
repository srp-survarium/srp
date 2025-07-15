vostok::ai::planning::predicate *__thiscall vostok::ai::planning::predicate::`vector deleting destructor'(
        vostok::ai::planning::predicate *this,
        char a2)
{
  vostok::ai::planning::expression_parameter *i; // [esp+8h] [ebp-4h]

  for ( i = this->m_parameters.m_begin; i != this->m_parameters.m_end; ++i )
    ;
  this->m_parameters.m_end = this->m_parameters.m_begin;
  vostok::ai::planning::base_lexeme::~base_lexeme(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
