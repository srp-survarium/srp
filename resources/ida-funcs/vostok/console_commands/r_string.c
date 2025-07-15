void __usercall vostok::console_commands::r_string(vostok::memory::reader *F@<eax>, char (*dest)[4096])
{
  const unsigned __int8 *m_data; // esi
  unsigned int m_size; // edi
  unsigned int v4; // ebx
  const unsigned __int8 *v5; // ecx
  char *_Src; // [esp+Ch] [ebp-4h]

  m_data = F->m_data;
  m_size = F->m_size;
  _Src = (char *)F->m_pointer;
  v4 = 0;
  while ( F->m_pointer - m_data < m_size )
  {
    v5 = F->m_pointer + 1;
    ++v4;
    F->m_pointer = v5;
    if ( v5 - m_data < m_size && (*v5 == 13 || *v5 == 10) )
    {
      while ( v5 - m_data < m_size && (*v5 == 13 || *v5 == 10) )
        F->m_pointer = ++v5;
      break;
    }
  }
  strncpy_s((char *)dest, 0x1000u, _Src, v4);
}
