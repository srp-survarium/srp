int __thiscall compression::ppmd::stream::get_char(compression::ppmd::stream *this)
{
  unsigned __int8 *m_pointer; // edx
  int result; // eax

  m_pointer = this->m_pointer;
  if ( m_pointer >= &this->m_buffer[this->m_buffer_size] )
    return -1;
  result = *m_pointer;
  this->m_pointer = m_pointer + 1;
  return result;
}
