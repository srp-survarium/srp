void __fastcall vostok::render::shader_constant_buffer::set_memory(
        const unsigned int offset,
        const unsigned int size,
        vostok::render::shader_constant_buffer *this,
        const char *src_ptr)
{
  char *m_buffer_data; // eax
  char *v6; // esi
  char *v7; // eax
  char i; // dl
  char v9; // bl

  if ( size > this->m_buffer_size - offset )
    size = this->m_buffer_size - offset;
  m_buffer_data = (char *)this->m_buffer_data;
  v6 = &m_buffer_data[size + offset];
  v7 = &m_buffer_data[offset];
  for ( i = 0; v7 != v6; ++src_ptr )
  {
    v9 = *src_ptr ^ *v7;
    *v7++ = *src_ptr;
    i |= v9;
  }
  this->m_changed |= i != 0;
}
