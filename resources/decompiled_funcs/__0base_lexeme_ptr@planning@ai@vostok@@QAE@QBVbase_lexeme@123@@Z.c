void __thiscall vostok::ai::planning::base_lexeme_ptr::base_lexeme_ptr(
        vostok::ai::planning::base_lexeme_ptr *this,
        const vostok::ai::planning::base_lexeme *const lexeme)
{
  this->m_lexeme = lexeme;
  if ( this->m_lexeme )
    vostok::ai::planning::base_lexeme::increment_counter((vostok::ai::planning::base_lexeme *)this->m_lexeme);
}
