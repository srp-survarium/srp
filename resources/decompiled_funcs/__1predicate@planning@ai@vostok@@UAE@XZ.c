void __thiscall vostok::ai::planning::predicate::~predicate(vostok::ai::planning::predicate *this)
{
  vostok::ai::planning::expression_parameter *i; // [esp+8h] [ebp-4h]

  for ( i = this->m_parameters.m_begin; i != this->m_parameters.m_end; ++i )
    ;
  this->m_parameters.m_end = this->m_parameters.m_begin;
  vostok::ai::planning::base_lexeme::~base_lexeme(this);
}
