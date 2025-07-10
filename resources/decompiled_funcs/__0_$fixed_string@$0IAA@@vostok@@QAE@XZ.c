void __thiscall vostok::fixed_string<2048>::fixed_string<2048>(vostok::fixed_string<2048> *this)
{
  char *m_buffer; // ecx

  m_buffer = this->m_buffer;
  this->m_begin = m_buffer;
  this->m_end = m_buffer;
  this->m_max_end = m_buffer + 2048;
  *m_buffer = 0;
  *m_buffer = 0;
}
