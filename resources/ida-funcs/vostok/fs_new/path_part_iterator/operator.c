bool __usercall vostok::fs_new::path_part_iterator::operator!=@<al>(
        vostok::fs_new::path_part_iterator *this@<ecx>,
        const vostok::fs_new::path_part_iterator *it@<eax>)
{
  bool v2; // al

  v2 = this->m_include_empty_string_in_iteration == it->m_include_empty_string_in_iteration
    && this->m_cur_str == it->m_cur_str;
  return !v2;
}


void __usercall vostok::fs_new::path_part_iterator::operator++(
        vostok::fs_new::path_part_iterator *this@<ecx>,
        int a2@<eax>)
{
  int v2; // ecx
  int v3; // edx
  int v4; // ecx
  char v5; // dl
  _BYTE *v6; // ecx
  _BYTE *v7; // ecx

  if ( *(_DWORD *)(a2 + 12) )
  {
    if ( *(_DWORD *)a2 == 1 )
    {
      *(_DWORD *)a2 = 0;
    }
    else
    {
      v2 = *(_DWORD *)(a2 + 16);
      v3 = *(_DWORD *)(a2 + 8);
      if ( v2 == v3 )
      {
        *(_DWORD *)(a2 + 12) = 0;
      }
      else
      {
        if ( v2 != *(_DWORD *)(a2 + 4) )
        {
          v4 = v2 + 1;
          *(_DWORD *)(a2 + 12) = v4;
          *(_DWORD *)(a2 + 16) = v4;
        }
        if ( *(_DWORD *)(a2 + 16) != v3 )
        {
          v5 = *(_BYTE *)(a2 + 20);
          do
          {
            v6 = *(_BYTE **)(a2 + 16);
            if ( *v6 == v5 )
              break;
            v7 = v6 + 1;
            *(_DWORD *)(a2 + 16) = v7;
          }
          while ( v7 != *(_BYTE **)(a2 + 8) );
        }
      }
    }
  }
}
