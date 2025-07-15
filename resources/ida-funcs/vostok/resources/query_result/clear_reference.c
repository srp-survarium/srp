void __thiscall vostok::resources::query_result::clear_reference(vostok::resources::query_result *this)
{
  vostok::resources::query_result *i; // eax

  if ( (this->m_flags & 0x40) != 0 )
  {
    for ( i = this->m_next_referer; (i->m_flags & 0x40) == 0; i = i->m_next_referer )
      ;
    while ( i->m_next_referer != this )
      i = i->m_next_referer;
    i->m_next_referer = this->m_next_referer;
    _InterlockedAnd(&this->m_flags, 0xFFFFFFBF);
    this->m_next_referer = this;
  }
}
