void __usercall vostok::render::requested_streamable_texture::requested_streamable_texture(
        vostok::render::requested_streamable_texture *this@<esi>,
        const vostok::render::requested_streamable_texture *__that@<edi>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  vostok::render::res_texture *m_object; // eax

  m_begin = (unsigned __int8 *)__that->path.m_begin;
  v3 = __that->path.m_end - __that->path.m_begin;
  this->path.m_max_end = (char *)&this->texture;
  v4 = v3;
  this->path.m_begin = this->path.m_buffer;
  this->path.m_end = this->path.m_buffer;
  memcpy((unsigned __int8 *)this->path.m_buffer, m_begin, v3);
  this->path.m_end += v4;
  *this->path.m_end = 0;
  this->texture.m_object = 0;
  m_object = __that->texture.m_object;
  if ( m_object )
  {
    this->texture.m_object = m_object;
    ++m_object->m_reference_count;
  }
  this->num_mips = __that->num_mips;
}
