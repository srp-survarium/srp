void __thiscall vostok::ai::planning::base_lexeme::increment_counter(vostok::ai::planning::base_lexeme *this)
{
  if ( this->m_destroy_manually )
    ++this->m_counter;
}
