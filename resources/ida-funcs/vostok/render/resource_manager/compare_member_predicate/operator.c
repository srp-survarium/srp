bool __usercall vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>::operator()@<al>(
        const vostok::render::res_geometry *const left@<ecx>,
        const vostok::render::res_geometry *const right@<eax>)
{
  vostok::render::untyped_buffer *m_object; // edx
  vostok::render::untyped_buffer *v3; // esi
  int v4; // eax
  vostok::render::untyped_buffer *v5; // edx
  vostok::render::untyped_buffer *v6; // esi
  vostok::render::res_declaration *v7; // edx
  vostok::render::res_declaration *v8; // esi
  unsigned int m_vb_stride; // ecx
  unsigned int v10; // eax

  m_object = left->m_vb.m_object;
  v3 = right->m_vb.m_object;
  if ( m_object < v3 )
    goto LABEL_2;
  if ( m_object > v3 )
  {
LABEL_4:
    v4 = 1;
    return v4 < 0;
  }
  v5 = left->m_ib.m_object;
  v6 = right->m_ib.m_object;
  if ( v5 >= v6 )
  {
    if ( v5 > v6 )
      goto LABEL_4;
    v7 = left->m_dcl.m_object;
    v8 = right->m_dcl.m_object;
    if ( v7 >= v8 )
    {
      if ( v7 <= v8 )
      {
        m_vb_stride = left->m_vb_stride;
        v10 = right->m_vb_stride;
        if ( v10 <= m_vb_stride )
        {
          v4 = v10 < m_vb_stride;
          return v4 < 0;
        }
        goto LABEL_2;
      }
      goto LABEL_4;
    }
  }
LABEL_2:
  v4 = -1;
  return v4 < 0;
}
