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
