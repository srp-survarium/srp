int __usercall vostok::render::res_buffer_list::compare@<eax>(
        vostok::render::res_buffer_list *this@<esi>,
        const vostok::fixed_vector<vostok::render::buffer_slot,128> *base@<eax>)
{
  vostok::render::buffer_slot *m_begin; // edi
  unsigned int v3; // eax
  int v4; // ecx
  bool v5; // cf
  int *v6; // eax
  unsigned int v7; // ebx
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v8; // ecx
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_buffer; // edx
  int v11; // [esp+8h] [ebp-10h] BYREF
  unsigned int v12; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v13; // [esp+10h] [ebp-8h]
  unsigned int v14; // [esp+14h] [ebp-4h]

  m_begin = base->m_begin;
  v3 = base->m_end - base->m_begin;
  v4 = (char *)this->m_container.m_end - (char *)this->m_container.m_begin;
  v14 = 0;
  v11 = v4 >> 2;
  v13 = v3;
  v12 = v3;
  v5 = v3 < v4 >> 2;
  v6 = (int *)&v12;
  if ( !v5 )
    v6 = &v11;
  v7 = *v6;
  if ( *v6 )
  {
    v8 = this->m_container.m_begin;
    p_buffer = &m_begin->buffer;
    while ( v8->m_object >= p_buffer->m_object )
    {
      if ( v8->m_object > p_buffer->m_object )
        return 1;
      ++v14;
      ++v8;
      p_buffer += 21;
      if ( v14 >= v7 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    if ( this->m_container.m_end - this->m_container.m_begin >= v13 )
      return v13 < this->m_container.m_end - this->m_container.m_begin;
  }
  return -1;
}
