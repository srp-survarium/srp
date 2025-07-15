int __usercall vostok::render::shader_constant_table::compare@<eax>(
        vostok::render::shader_constant_table *this@<edi>,
        const vostok::render::shader_constant_table *other@<esi>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int v4; // ebp
  vostok::render::shader_constant *M_start; // ebx
  char *v6; // eax
  int v7; // eax
  unsigned int size; // [esp+0h] [ebp-8h] BYREF
  unsigned int i; // [esp+4h] [ebp-4h] BYREF

  v2 = other->m_table._M_impl._M_finish - other->m_table._M_impl._M_start;
  i = this->m_table._M_impl._M_finish - this->m_table._M_impl._M_start;
  size = v2;
  p_size = &size;
  if ( v2 >= i )
    p_size = &i;
  v4 = 0;
  size = *p_size;
  if ( size )
  {
    M_start = this->m_table._M_impl._M_start;
    v6 = (char *)((char *)other->m_table._M_impl._M_start - (char *)M_start);
    for ( i = (unsigned int)v6; ; v6 = (char *)i )
    {
      v7 = vostok::render::compare((const vostok::render::shader_constant *)&v6[(_DWORD)M_start], M_start);
      if ( v7 == -1 )
        break;
      if ( v7 )
        return 1;
      ++v4;
      ++M_start;
      if ( v4 >= size )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    if ( this->m_table._M_impl._M_finish - this->m_table._M_impl._M_start >= (unsigned int)(other->m_table._M_impl._M_finish
                                                                                          - other->m_table._M_impl._M_start) )
      return other->m_table._M_impl._M_finish - other->m_table._M_impl._M_start < (unsigned int)(this->m_table._M_impl._M_finish
                                                                                               - this->m_table._M_impl._M_start);
  }
  return -1;
}
