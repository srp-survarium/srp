vostok::render::texture_slot *__userpurge vostok::render::texture_slot::operator=@<eax>(
        vostok::render::texture_slot *this@<ecx>,
        const vostok::render::texture_slot *a2@<edi>,
        const vostok::render::texture_slot *__that)
{
  char *m_begin; // eax
  unsigned int v4; // esi
  vostok::render::res_texture *m_object; // ebx
  vostok::render::res_texture *v6; // eax
  vostok::render::res_texture *v7; // esi

  if ( a2 != __that )
  {
    m_begin = a2->name.m_begin;
    a2->name.m_end = a2->name.m_begin;
    *m_begin = 0;
    v4 = __that->name.m_end - __that->name.m_begin;
    memcpy((unsigned __int8 *)a2->name.m_end, (unsigned __int8 *)__that->name.m_begin, v4);
    a2->name.m_end += v4;
    *a2->name.m_end = 0;
  }
  a2->slot_id = __that->slot_id;
  m_object = __that->texture.m_object;
  v6 = 0;
  if ( m_object )
  {
    v6 = __that->texture.m_object;
    ++m_object->m_reference_count;
  }
  v7 = a2->texture.m_object;
  a2->texture.m_object = v6;
  if ( v7 )
  {
    if ( v7->m_reference_count-- == 1 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this);
  }
  return (vostok::render::texture_slot *)a2;
}
