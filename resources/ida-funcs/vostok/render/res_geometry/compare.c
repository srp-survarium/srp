int __usercall vostok::render::res_geometry::compare@<eax>(
        vostok::render::res_geometry *this@<ecx>,
        const vostok::render::res_geometry *other@<eax>)
{
  vostok::render::untyped_buffer *m_object; // edx
  vostok::render::untyped_buffer *v3; // esi
  vostok::render::untyped_buffer *v5; // edx
  vostok::render::untyped_buffer *v6; // esi
  vostok::render::res_declaration *v7; // edx
  vostok::render::res_declaration *v8; // esi
  unsigned int m_vb_stride; // ecx
  unsigned int v10; // eax

  m_object = other->m_vb.m_object;
  v3 = this->m_vb.m_object;
  if ( v3 < m_object )
    return -1;
  if ( v3 > m_object )
    return 1;
  v5 = other->m_ib.m_object;
  v6 = this->m_ib.m_object;
  if ( v6 < v5 )
    return -1;
  if ( v6 > v5 )
    return 1;
  v7 = other->m_dcl.m_object;
  v8 = this->m_dcl.m_object;
  if ( v8 < v7 )
    return -1;
  if ( v8 > v7 )
    return 1;
  m_vb_stride = this->m_vb_stride;
  v10 = other->m_vb_stride;
  if ( v10 > m_vb_stride )
    return -1;
  return v10 < m_vb_stride;
}
