void __userpurge vostok::render::res_geometry::res_geometry(
        vostok::render::untyped_buffer *vb@<ecx>,
        vostok::render::untyped_buffer *ib@<edx>,
        vostok::render::res_declaration *dcl@<esi>,
        vostok::render::res_geometry *this,
        unsigned int stride)
{
  this->m_reference_count = 0;
  this->m_vb.m_object = 0;
  if ( vb )
  {
    this->m_vb.m_object = vb;
    ++vb->m_reference_count;
  }
  this->m_ib.m_object = 0;
  if ( ib )
  {
    this->m_ib.m_object = ib;
    ++ib->m_reference_count;
  }
  this->m_vb_stride = stride;
  this->m_dcl.m_object = 0;
  if ( dcl )
  {
    this->m_dcl.m_object = dcl;
    ++dcl->m_reference_count;
  }
  this->m_is_registered = 0;
}
