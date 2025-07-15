bool __usercall vostok::render::resource_manager::compare_predicate<vostok::render::res_input_layout>::operator()@<al>(
        const vostok::render::res_input_layout *const left@<ecx>,
        const vostok::render::res_input_layout *const right@<eax>)
{
  const vostok::render::res_declaration *m_declaration; // edx
  const vostok::render::res_declaration *v3; // esi
  int v4; // eax
  const vostok::render::res_signature *m_object; // ecx
  const vostok::render::res_signature *v6; // eax

  m_declaration = left->m_declaration;
  v3 = right->m_declaration;
  if ( m_declaration >= v3 )
  {
    if ( m_declaration > v3 )
    {
      v4 = 1;
      return v4 < 0;
    }
    m_object = left->m_signature.m_object;
    v6 = right->m_signature.m_object;
    if ( v6 <= m_object )
    {
      v4 = v6 < m_object;
      return v4 < 0;
    }
  }
  v4 = -1;
  return v4 < 0;
}


bool __usercall vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>::operator()@<al>(
        const vostok::render::res_signature *const left@<eax>,
        const vostok::render::res_signature *const right@<ecx>,
        vostok::render::resource_manager::compare_predicate<vostok::render::res_signature> *this)
{
  ID3D10Blob *m_signature; // eax
  ID3D10Blob *v4; // ecx
  int v5; // eax

  m_signature = left->m_signature;
  v4 = right->m_signature;
  if ( v4 <= m_signature )
    v5 = v4 < m_signature;
  else
    v5 = -1;
  return v5 < 0;
}
