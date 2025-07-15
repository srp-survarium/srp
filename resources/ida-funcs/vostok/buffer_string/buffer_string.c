void __thiscall vostok::buffer_string::buffer_string(
        vostok::buffer_string *this,
        char *buffer,
        const unsigned int *max_count,
        const char *const *begin_src,
        const char *const *end_src)
{
  unsigned int v6; // edi

  this->m_begin = buffer;
  this->m_end = buffer;
  this->m_max_end = &buffer[*max_count];
  v6 = *end_src - *begin_src;
  memcpy((unsigned __int8 *)buffer, *(unsigned __int8 **)begin_src, v6);
  this->m_end += v6;
  *this->m_end = 0;
}


void __thiscall vostok::buffer_string::buffer_string(
        vostok::buffer_string *this,
        char *buffer,
        const unsigned int *max_count)
{
  this->m_begin = buffer;
  this->m_end = buffer;
  this->m_max_end = &buffer[*max_count];
  *buffer = 0;
}


void __thiscall vostok::buffer_string::buffer_string(
        vostok::buffer_string *this,
        char *buffer,
        const unsigned int *max_count,
        const char *src)
{
  this->m_begin = buffer;
  this->m_end = buffer;
  this->m_max_end = &buffer[*max_count];
  *buffer = 0;
  vostok::buffer_string::operator+=(this, src);
}
