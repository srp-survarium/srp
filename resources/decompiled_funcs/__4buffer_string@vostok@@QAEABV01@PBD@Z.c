const vostok::buffer_string *__thiscall vostok::buffer_string::operator=(vostok::buffer_string *this, const char *s)
{
  char *m_begin; // eax

  m_begin = this->m_begin;
  this->m_end = this->m_begin;
  *m_begin = 0;
  return vostok::buffer_string::operator+=(this, s);
}
