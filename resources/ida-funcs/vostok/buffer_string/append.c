vostok::buffer_string *__thiscall vostok::buffer_string::append(vostok::buffer_string *this, char c)
{
  vostok::buffer_string *result; // eax

  result = this;
  *this->m_end++ = c;
  *this->m_end = 0;
  return result;
}


vostok::buffer_string *__thiscall vostok::buffer_string::append(
        vostok::buffer_string *this,
        char *begin_src,
        const char *end_src)
{
  memcpy((unsigned __int8 *)this->m_end, (unsigned __int8 *)begin_src, end_src - begin_src);
  this->m_end += end_src - begin_src;
  *this->m_end = 0;
  return this;
}


vostok::buffer_string *__thiscall vostok::buffer_string::append(vostok::buffer_string *this, char *c_string)
{
  unsigned int v3; // edi

  v3 = strlen(c_string);
  memcpy((unsigned __int8 *)this->m_end, (unsigned __int8 *)c_string, v3);
  this->m_end += v3;
  *this->m_end = 0;
  return this;
}


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
