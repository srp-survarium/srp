void __userpurge vostok::buffer_vector<vostok::render::sampler_slot>::assign<vostok::render::sampler_slot const *>(
        const vostok::render::sampler_slot *begin@<eax>,
        vostok::buffer_vector<vostok::render::sampler_slot> *this,
        const vostok::render::sampler_slot *const *end)
{
  const vostok::render::sampler_slot *const *v3; // ebx
  const vostok::render::sampler_slot *v4; // edi
  vostok::render::sampler_slot *m_begin; // esi
  vostok::render::sampler_slot *v6; // edx
  char *m_buffer; // esi
  unsigned int v8; // ebp
  unsigned __int8 *v9; // [esp-8h] [ebp-18h]
  vostok::render::sampler_slot *I; // [esp+14h] [ebp+4h]

  v3 = end;
  v4 = begin;
  m_begin = this->m_begin;
  this->m_end = &this->m_begin[*end - begin];
  v6 = m_begin;
  I = m_begin;
  if ( begin != *end )
  {
    m_buffer = m_begin->name.m_buffer;
    do
    {
      if ( v6 )
      {
        v8 = v4->name.m_end - v4->name.m_begin;
        v9 = (unsigned __int8 *)v4->name.m_begin;
        v6->name.m_begin = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 64;
        memcpy((unsigned __int8 *)m_buffer, v9, v8);
        *((_DWORD *)m_buffer - 2) += v8;
        **((_BYTE **)m_buffer - 2) = 0;
        *((_DWORD *)m_buffer + 16) = v4->slot_id;
        v3 = end;
        *((_DWORD *)m_buffer + 17) = v4->state;
        v6 = I;
      }
      ++v4;
      ++v6;
      m_buffer += 84;
      I = v6;
    }
    while ( v4 != *v3 );
  }
}
