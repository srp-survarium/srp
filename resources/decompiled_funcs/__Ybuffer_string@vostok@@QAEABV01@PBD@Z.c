const vostok::buffer_string *__thiscall vostok::buffer_string::operator+=(vostok::buffer_string *this, const char *s)
{
  const vostok::buffer_string *result; // eax
  const char *v3; // ecx
  char i; // dl
  char *m_end; // esi

  result = this;
  v3 = s;
  if ( s )
  {
    for ( i = *s; i; i = *++v3 )
    {
      m_end = result->m_end;
      if ( m_end >= result->m_max_end )
        break;
      *m_end = i;
      ++result->m_end;
    }
    *result->m_end = 0;
  }
  return result;
}
