int __usercall vostok::render::res_texture_list::compare@<eax>(
        vostok::render::res_buffer_list *this@<esi>,
        const vostok::render::res_buffer_list *base@<edx>)
{
  int v2; // eax
  int v3; // ecx
  bool v4; // cf
  int *v5; // eax
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_begin; // eax
  char *v7; // ecx
  vostok::render::shader_buffer *v8; // edi
  unsigned int v10; // [esp+0h] [ebp-Ch] BYREF
  int v11; // [esp+4h] [ebp-8h] BYREF
  unsigned int v12; // [esp+8h] [ebp-4h]

  v2 = (char *)base->m_container.m_end - (char *)base->m_container.m_begin;
  v3 = (char *)this->m_container.m_end - (char *)this->m_container.m_begin;
  v12 = 0;
  v3 >>= 2;
  v11 = v2 >> 2;
  v4 = v2 >> 2 < (unsigned int)v3;
  v10 = v3;
  v5 = &v11;
  if ( !v4 )
    v5 = (int *)&v10;
  v10 = *v5;
  if ( v10 )
  {
    m_begin = this->m_container.m_begin;
    v7 = (char *)((char *)base->m_container.m_begin - (char *)m_begin);
    do
    {
      v8 = *(vostok::render::shader_buffer **)((char *)&m_begin->m_object + (_DWORD)v7);
      if ( m_begin->m_object < v8 )
        return -1;
      if ( m_begin->m_object > v8 )
        return 1;
      ++v12;
      ++m_begin;
    }
    while ( v12 < v10 );
  }
  if ( this->m_container.m_end - this->m_container.m_begin < (unsigned int)(base->m_container.m_end
                                                                          - base->m_container.m_begin) )
    return -1;
  return base->m_container.m_end - base->m_container.m_begin < (unsigned int)(this->m_container.m_end
                                                                            - this->m_container.m_begin);
}
