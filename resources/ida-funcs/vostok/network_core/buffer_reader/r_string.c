char *__thiscall vostok::network_core::buffer_reader::r_string(
        vostok::network_core::buffer_reader *this,
        char *string,
        unsigned __int8 *buffer_size)
{
  unsigned __int8 *v3; // eax
  unsigned int v4; // esi

  v3 = (unsigned __int8 *)*((_DWORD *)string + 1);
  v4 = *v3;
  *((_DWORD *)string + 1) = v3 + 1;
  memcpy(buffer_size, v3 + 1, v4);
  *((_DWORD *)string + 1) += v4;
  buffer_size[v4] = 0;
  return (char *)buffer_size;
}


void __usercall vostok::network_core::buffer_reader::r_string(
        vostok::network_core::buffer_reader *this@<ecx>,
        int a2@<eax>)
{
  unsigned __int8 *v2; // esi
  unsigned __int8 *v3; // edx
  int v4; // esi
  const unsigned __int8 *m_buffer; // edx
  const unsigned __int8 *v6; // edx
  const unsigned __int8 *v7; // edi
  const unsigned __int8 *i; // [esp+8h] [ebp-8h]

  v2 = *(unsigned __int8 **)(a2 + 4);
  v3 = v2 + 1;
  v4 = *v2;
  *(_DWORD *)(a2 + 4) = v3;
  m_buffer = this->m_buffer;
  this->m_pointer = this->m_buffer;
  *m_buffer = 0;
  v6 = *(const unsigned __int8 **)(a2 + 4);
  v7 = &v6[v4];
  for ( i = v6; v6 != v7; i = v6 )
  {
    *this->m_pointer = *v6;
    v6 = i + 1;
    ++this->m_pointer;
  }
  *this->m_pointer = 0;
  *(_DWORD *)(a2 + 4) += v4;
}
