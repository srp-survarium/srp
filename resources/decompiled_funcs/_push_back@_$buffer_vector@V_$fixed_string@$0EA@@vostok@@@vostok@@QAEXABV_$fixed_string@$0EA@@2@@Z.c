void __userpurge vostok::buffer_vector<vostok::fixed_string<64>>::push_back(
        const vostok::fixed_string<64> *value@<eax>,
        vostok::buffer_vector<vostok::fixed_string<64> > *this)
{
  vostok::fixed_string<64> *m_end; // esi
  unsigned __int8 *m_begin; // edx
  unsigned int v4; // ecx
  unsigned int v5; // edi

  m_end = this->m_end;
  if ( m_end )
  {
    m_begin = (unsigned __int8 *)value->m_begin;
    v4 = value->m_end - value->m_begin;
    m_end->m_max_end = (char *)&m_end[1];
    v5 = v4;
    m_end->m_begin = m_end->m_buffer;
    m_end->m_end = m_end->m_buffer;
    memcpy((unsigned __int8 *)m_end->m_buffer, m_begin, v4);
    m_end->m_end += v5;
    *m_end->m_end = 0;
  }
  ++this->m_end;
}
