char *__userpurge vostok::render::vertex_buffer::lock@<eax>(
        vostok::render::vertex_buffer *this@<esi>,
        unsigned int *v_offset@<edi>,
        unsigned int v_count,
        unsigned int v_stride)
{
  unsigned int v4; // eax
  vostok::render::untyped_buffer *v5; // ecx
  char *v6; // eax

  v4 = this->m_position / v_stride;
  this->m_lock_stride = v_stride;
  this->m_lock_count = v_count;
  v5 = (vostok::render::untyped_buffer *)(v4 + 1);
  if ( v4 + 1 + v_count < this->m_size / v_stride )
  {
    this->m_position = v_stride * (_DWORD)v5;
    *v_offset = (unsigned int)v5;
    v6 = (char *)vostok::render::untyped_buffer::map(
                   v5,
                   (D3D11_MAP)this->m_buffer.m_object,
                   D3D11_MAP_WRITE_NO_OVERWRITE);
  }
  else
  {
    this->m_position = 0;
    *v_offset = 0;
    ++this->m_discard_id;
    v6 = (char *)vostok::render::untyped_buffer::map(v5, (D3D11_MAP)this->m_buffer.m_object, D3D11_MAP_WRITE_DISCARD);
  }
  return &v6[this->m_position];
}
