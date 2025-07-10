void __thiscall vostok::fixed_string<256>::fixed_string<256>(vostok::fixed_string<256> *this)
{
  char *m_buffer; // ecx

  m_buffer = this->m_buffer;
  this->m_begin = m_buffer;
  this->m_end = m_buffer;
  this->m_max_end = m_buffer + 256;
  *m_buffer = 0;
  *m_buffer = 0;
}
