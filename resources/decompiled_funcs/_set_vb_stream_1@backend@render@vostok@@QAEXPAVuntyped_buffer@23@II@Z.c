void __usercall vostok::render::backend::set_vb_stream_1(
        vostok::render::backend *this@<eax>,
        vostok::render::untyped_buffer *vb@<edx>,
        unsigned int vb_stride@<esi>)
{
  bool v3; // cl

  v3 = this->m_vb_stream_1 != vb || vb_stride != this->m_vb_stride_stream_1 || this->m_vb_offset_stream_1;
  this->m_dirty_objects.vertex_buffer_stream_1 |= v3;
  this->m_vb_stream_1 = vb;
  this->m_vb_stride_stream_1 = vb_stride;
  this->m_vb_offset_stream_1 = 0;
}
