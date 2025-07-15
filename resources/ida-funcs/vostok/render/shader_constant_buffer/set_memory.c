void __userpurge vostok::render::shader_constant_buffer::set_memory(
        vostok::render::shader_constant_buffer *this@<edi>,
        const unsigned int offset@<eax>,
        char *src_ptr,
        unsigned int size)
{
  char *m_buffer_data; // ecx
  unsigned int v6; // eax
  char *v7; // eax
  char *v8; // ecx
  char i; // dl

  m_buffer_data = (char *)this->m_buffer_data;
  v6 = this->m_buffer_size - offset;
  if ( size <= v6 )
    v6 = size;
  v7 = &m_buffer_data[v6 + offset];
  v8 = &m_buffer_data[offset];
  for ( i = 0; v8 != v7; ++src_ptr )
  {
    if ( !i )
      i = *v8 ^ *src_ptr;
    *v8++ = *src_ptr;
  }
  this->m_changed = 1;
}
