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
