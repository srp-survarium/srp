void __userpurge vostok::buffer_vector<vostok::render::texture_slot>::assign<vostok::render::texture_slot const *>(
        vostok::buffer_vector<vostok::render::texture_slot> *this@<ecx>,
        const vostok::render::texture_slot *begin@<eax>,
        const vostok::render::texture_slot *const *end)
{
  vostok::render::texture_slot **p_m_end; // ebx
  vostok::render::texture_slot *m_begin; // esi
  vostok::render::texture_slot *v7; // edx
  char *m_buffer; // esi
  unsigned int v9; // ebx
  vostok::render::res_texture *m_object; // eax
  unsigned __int8 *v11; // [esp-8h] [ebp-1Ch]
  vostok::render::texture_slot *I; // [esp+10h] [ebp-4h]

  p_m_end = &this->m_end;
  vostok::buffer_vector<vostok::render::texture_slot>::destroy(this->m_begin, &this->m_end);
  m_begin = this->m_begin;
  *p_m_end = &m_begin[*end - begin];
  v7 = m_begin;
  I = m_begin;
  if ( begin != *end )
  {
    m_buffer = m_begin->name.m_buffer;
    do
    {
      if ( v7 )
      {
        v9 = begin->name.m_end - begin->name.m_begin;
        v11 = (unsigned __int8 *)begin->name.m_begin;
        v7->name.m_begin = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 64;
        memcpy((unsigned __int8 *)m_buffer, v11, v9);
        *((_DWORD *)m_buffer - 2) += v9;
        **((_BYTE **)m_buffer - 2) = 0;
        *((_DWORD *)m_buffer + 16) = begin->slot_id;
        v7 = I;
        *((_DWORD *)m_buffer + 17) = 0;
        m_object = begin->texture.m_object;
        if ( m_object )
        {
          *((_DWORD *)m_buffer + 17) = m_object;
          ++m_object->m_reference_count;
        }
      }
      ++begin;
      ++v7;
      m_buffer += 84;
      I = v7;
    }
    while ( begin != *end );
  }
}
