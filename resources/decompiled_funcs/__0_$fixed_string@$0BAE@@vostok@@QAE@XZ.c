void __thiscall vostok::fixed_string<260>::fixed_string<260>(vostok::fixed_string<260> *this)
{
  char *m_buffer; // ecx

  m_buffer = this->m_buffer;
  this->m_begin = m_buffer;
  this->m_end = m_buffer;
  this->m_max_end = m_buffer + 260;
  *m_buffer = 0;
  *m_buffer = 0;
}
