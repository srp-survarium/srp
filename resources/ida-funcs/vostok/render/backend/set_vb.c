void __usercall vostok::render::backend::set_vb(
        vostok::render::backend *this@<eax>,
        vostok::render::untyped_buffer *vb@<ecx>,
        unsigned int vb_stride@<esi>)
{
  bool v3; // dl
  unsigned int *p_m_vb_offset; // eax

  v3 = this->m_vb != vb || vb_stride != this->m_vb_stride || this->m_vb_offset;
  this->m_dirty_objects.vertex_buffer |= v3;
  this->m_vb = vb;
  this->m_vb_stride = vb_stride;
  p_m_vb_offset = &this->m_vb_offset;
  *p_m_vb_offset = 0;
  if ( vb )
    vb = (vostok::render::untyped_buffer *)vb->pool_range.begin_offset;
  *p_m_vb_offset = (unsigned int)vb;
}
