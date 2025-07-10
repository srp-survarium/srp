vostok::buffer_string *__thiscall vostok::buffer_string::append<char *>(
        vostok::buffer_string *this,
        char **begin_src,
        char **end_src)
{
  vostok::buffer_string *result; // eax
  char *i; // edx

  result = this;
  for ( i = *begin_src; i != *end_src; ++i )
    *this->m_end++ = *i;
  *this->m_end = 0;
  return result;
}
