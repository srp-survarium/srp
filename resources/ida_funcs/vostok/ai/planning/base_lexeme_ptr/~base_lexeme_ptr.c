void __thiscall vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(vostok::ai::planning::base_lexeme_ptr *this)
{
  if ( this->m_lexeme )
    vostok::ai::planning::base_lexeme::decrement_counter((vostok::ai::planning::base_lexeme *)this->m_lexeme);
}
