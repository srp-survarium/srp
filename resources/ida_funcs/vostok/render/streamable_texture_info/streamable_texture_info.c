void __usercall vostok::render::streamable_texture_info::streamable_texture_info(
        vostok::render::streamable_texture_info *this@<ecx>,
        const vostok::render::streamable_texture_info *__that@<eax>)
{
  char *m_begin; // edx
  char *v5; // ecx
  char *v6; // ebx
  vostok::render::res_texture *m_object; // edi

  stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance>>::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance>>(
    &this->instances._M_impl,
    &__that->instances._M_impl);
  m_begin = __that->path.m_begin;
  v5 = (char *)(__that->path.m_end - m_begin);
  this->path.m_max_end = (char *)&this->texture;
  v6 = v5;
  this->path.m_begin = this->path.m_buffer;
  this->path.m_end = this->path.m_buffer;
  memcpy((unsigned __int8 *)this->path.m_buffer, (unsigned __int8 *)m_begin, (unsigned int)v5);
  this->path.m_end += (unsigned int)v6;
  *this->path.m_end = 0;
  this->texture.m_object = 0;
  m_object = __that->texture.m_object;
  if ( m_object )
  {
    this->texture.m_object = m_object;
    ++m_object->m_reference_count;
  }
}
