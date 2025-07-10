const vostok::fixed_string<2048> *__thiscall vostok::fixed_string<2048>::operator=(
        vostok::fixed_string<2048> *this,
        char *src)
{
  char *m_begin; // eax

  m_begin = this->m_begin;
  if ( this->m_begin != src )
  {
    this->m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(this, src);
  }
  return this;
}
