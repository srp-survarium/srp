void __thiscall vostok::fixed_string<64>::fixed_string<64>(
        vostok::fixed_string<64> *this,
        const vostok::fixed_string<64> *src)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v4; // ecx
  unsigned int v5; // edi

  m_begin = (unsigned __int8 *)src->m_begin;
  v4 = src->m_end - src->m_begin;
  this->m_max_end = (char *)&this[1];
  v5 = v4;
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  memcpy((unsigned __int8 *)this->m_buffer, m_begin, v4);
  this->m_end += v5;
  *this->m_end = 0;
}
