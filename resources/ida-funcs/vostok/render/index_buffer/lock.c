char *__userpurge vostok::render::index_buffer::lock@<eax>(
        vostok::render::index_buffer *this@<esi>,
        unsigned int *i_offset@<edi>,
        unsigned int i_count)
{
  unsigned int m_position; // eax
  D3D11_MAP v4; // ecx
  char *v5; // eax
  unsigned int v6; // ecx

  m_position = this->m_position;
  *i_offset = 0;
  v4 = D3D11_MAP_WRITE_NO_OVERWRITE;
  if ( 2 * (i_count + m_position) >= this->m_size )
  {
    this->m_position = 0;
    ++this->m_discard_id;
    v4 = D3D11_MAP_WRITE_DISCARD;
  }
  v5 = (char *)vostok::render::untyped_buffer::map(
                 (vostok::render::untyped_buffer *)v4,
                 (D3D11_MAP)this->m_buffer.m_object,
                 v4);
  v6 = this->m_position;
  this->m_lock_size = i_count;
  *i_offset = v6;
  return &v5[2 * v6];
}
