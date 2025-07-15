int __usercall vostok::render::shader_constant_table::compare@<eax>(
        vostok::render::shader_constant_table *this@<edi>,
        const vostok::render::shader_constant_table *other@<eax>)
{
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // eax
  vostok::render::shader_constant *m_begin; // ebx
  char *v7; // eax
  int v8; // eax
  unsigned int v10; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v12; // [esp+10h] [ebp-4h] BYREF

  v12 = other->m_table.m_end - other->m_table.m_begin;
  v3 = v12 < this->m_table.m_end - this->m_table.m_begin;
  i = this->m_table.m_end - this->m_table.m_begin;
  v4 = &v12;
  if ( !v3 )
    v4 = (unsigned int *)&i;
  v5 = *v4;
  v12 = 0;
  v10 = v5;
  if ( v5 )
  {
    m_begin = this->m_table.m_begin;
    v7 = (char *)((char *)other->m_table.m_begin - (char *)m_begin);
    for ( i = (int)v7; ; v7 = (char *)i )
    {
      v8 = vostok::render::compare(m_begin, (const vostok::render::shader_constant *)&v7[(_DWORD)m_begin]);
      if ( v8 == -1 )
        break;
      if ( v8 )
        return 1;
      ++v12;
      ++m_begin;
      if ( v12 >= v10 )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    if ( this->m_table.m_end - this->m_table.m_begin >= (unsigned int)(other->m_table.m_end - other->m_table.m_begin) )
      return other->m_table.m_end - other->m_table.m_begin < (unsigned int)(this->m_table.m_end - this->m_table.m_begin);
  }
  return -1;
}
