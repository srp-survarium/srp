void __usercall vostok::render::streaming_ready_texture::streaming_ready_texture(
        vostok::render::streaming_ready_texture *this@<esi>,
        const vostok::render::streaming_ready_texture *__that@<edi>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  vostok::render::res_texture *m_object; // eax

  m_begin = (unsigned __int8 *)__that->name.m_begin;
  v3 = __that->name.m_end - __that->name.m_begin;
  this->name.m_max_end = (char *)&this->texture;
  v4 = v3;
  this->name.m_begin = this->name.m_buffer;
  this->name.m_end = this->name.m_buffer;
  memcpy((unsigned __int8 *)this->name.m_buffer, m_begin, v3);
  this->name.m_end += v4;
  *this->name.m_end = 0;
  this->texture.m_object = 0;
  m_object = __that->texture.m_object;
  if ( m_object )
  {
    this->texture.m_object = m_object;
    ++m_object->m_reference_count;
  }
  this->data.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &this->data,
    &__that->data);
  this->num_mips = __that->num_mips;
  this->distance = __that->distance;
}
