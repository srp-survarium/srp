void __usercall vostok::render::backend::set_vb(
        vostok::render::backend *this@<eax>,
        vostok::render::untyped_buffer *vb@<edx>,
        unsigned int vb_stride@<esi>)
{
  bool v3; // cl

  v3 = this->m_vb != vb || vb_stride != this->m_vb_stride || this->m_vb_offset;
  this->m_dirty_objects.vertex_buffer |= v3;
  this->m_vb = vb;
  this->m_vb_stride = vb_stride;
  this->m_vb_offset = 0;
}
