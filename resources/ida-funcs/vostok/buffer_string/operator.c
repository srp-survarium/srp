vostok::buffer_string *__usercall vostok::buffer_string::operator=@<eax>(
        vostok::buffer_string *this@<ecx>,
        vostok::buffer_string *result@<eax>)
{
  vostok::buffer_string *v2; // esi
  char *m_begin; // eax

  v2 = result;
  if ( result != this )
  {
    m_begin = result->m_begin;
    v2->m_end = v2->m_begin;
    *m_begin = 0;
    vostok::buffer_string::append(v2, this->m_end, this->m_begin);
    return v2;
  }
  return result;
}


vostok::buffer_string *__usercall vostok::buffer_string::operator+=@<eax>(
        vostok::buffer_string *this@<eax>,
        char *s@<edx>)
{
  char i; // cl
  char *m_end; // esi

  if ( s )
  {
    for ( i = *s; *s; i = *++s )
    {
      m_end = this->m_end;
      if ( m_end >= this->m_max_end )
        break;
      *m_end = i;
      ++this->m_end;
    }
    *this->m_end = 0;
  }
  return this;
}
