const vostok::fixed_string<16> *__usercall vostok::fixed_string<16>::operator=@<eax>(
        vostok::fixed_string<16> *this@<ecx>,
        vostok::buffer_string *a2@<esi>)
{
  char *m_begin; // eax

  m_begin = a2->m_begin;
  if ( (vostok::fixed_string<16> *)a2->m_begin != this )
  {
    a2->m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(a2, (const char *)this);
  }
  return (const vostok::fixed_string<16> *)a2;
}
