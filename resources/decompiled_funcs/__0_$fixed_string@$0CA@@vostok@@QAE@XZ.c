void __thiscall vostok::fixed_string<32>::fixed_string<32>(vostok::fixed_string<32> *this)
{
  char *m_buffer; // ecx

  m_buffer = this->m_buffer;
  this->m_begin = m_buffer;
  this->m_end = m_buffer;
  this->m_max_end = m_buffer + 32;
  *m_buffer = 0;
  *m_buffer = 0;
}
