bool __usercall vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>::operator()@<al>(
        const vostok::render::res_geometry *const left@<ecx>,
        const vostok::render::res_geometry *const right@<eax>,
        vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry> *this)
{
  vostok::render::untyped_buffer *m_object; // edx
  vostok::render::untyped_buffer *v4; // esi
  vostok::render::untyped_buffer *v6; // edx
  vostok::render::untyped_buffer *v7; // esi
  vostok::render::res_declaration *v8; // edx
  vostok::render::res_declaration *v9; // esi

  m_object = left->m_vb.m_object;
  v4 = right->m_vb.m_object;
  if ( m_object < v4 )
    return 1;
  if ( m_object > v4 )
    return 0;
  v6 = left->m_ib.m_object;
  v7 = right->m_ib.m_object;
  if ( v6 < v7 )
    return 1;
  if ( v6 > v7 )
    return 0;
  v8 = left->m_dcl.m_object;
  v9 = right->m_dcl.m_object;
  if ( v8 < v9 )
    return 1;
  if ( v8 > v9 )
    return 0;
  return right->m_vb_stride > left->m_vb_stride;
}
