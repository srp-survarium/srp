void __thiscall vostok::fixed_string<64>::fixed_string<64>(vostok::fixed_string<64> *this)
{
  char *m_buffer; // ecx

  m_buffer = this->m_buffer;
  this->m_begin = m_buffer;
  this->m_end = m_buffer;
  this->m_max_end = m_buffer + 64;
  *m_buffer = 0;
  *m_buffer = 0;
}
