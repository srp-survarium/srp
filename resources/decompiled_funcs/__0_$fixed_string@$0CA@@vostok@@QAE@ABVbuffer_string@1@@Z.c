void __usercall vostok::fixed_string<32>::fixed_string<32>(
        vostok::fixed_string<32> *this@<esi>,
        const vostok::buffer_string *src@<eax>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // edi

  m_begin = (unsigned __int8 *)src->m_begin;
  v3 = src->m_end - src->m_begin;
  this->m_max_end = (char *)&this[1];
  v4 = v3;
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  memcpy((unsigned __int8 *)this->m_buffer, m_begin, v3);
  this->m_end += v4;
  *this->m_end = 0;
}
