unsigned int __fastcall vostok::console_commands::advance_term_string(int a1, vostok::memory::reader *F)
{
  const unsigned __int8 *m_data; // esi
  unsigned int m_size; // edi
  unsigned int result; // eax
  const unsigned __int8 *v5; // ecx

  m_data = F->m_data;
  m_size = F->m_size;
  result = 0;
  while ( F->m_pointer - m_data < m_size )
  {
    v5 = F->m_pointer + 1;
    ++result;
    F->m_pointer = v5;
    if ( v5 - m_data < m_size && (*v5 == 13 || *v5 == 10) )
    {
      while ( v5 - m_data < m_size && (*v5 == 13 || *v5 == 10) )
        F->m_pointer = ++v5;
      return result;
    }
  }
  return result;
}
