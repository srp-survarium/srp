const vostok::fixed_string<32> *__usercall vostok::buffer_string::operator=@<eax>(
        vostok::fixed_string<32> *this@<ecx>,
        vostok::fixed_string<32> *a2@<esi>)
{
  char *m_begin; // eax
  unsigned int v3; // edi

  if ( a2 != this )
  {
    m_begin = a2->m_begin;
    a2->m_end = a2->m_begin;
    *m_begin = 0;
    v3 = this->m_end - this->m_begin;
    memcpy((unsigned __int8 *)a2->m_end, (unsigned __int8 *)this->m_begin, v3);
    a2->m_end += v3;
    *a2->m_end = 0;
  }
  return a2;
}
