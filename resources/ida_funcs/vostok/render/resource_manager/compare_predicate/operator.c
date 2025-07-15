bool __usercall vostok::render::resource_manager::compare_predicate<vostok::render::res_input_layout>::operator()@<al>(
        const vostok::render::res_input_layout *const left@<esi>,
        const vostok::render::res_input_layout *const right@<edx>,
        vostok::render::resource_manager::compare_predicate<vostok::render::res_input_layout> *this)
{
  const vostok::render::res_declaration *m_declaration; // eax
  const vostok::render::res_declaration *v4; // ecx

  m_declaration = left->m_declaration;
  v4 = right->m_declaration;
  if ( m_declaration < v4 )
    return 1;
  if ( m_declaration > v4 )
    return 0;
  return right->m_signature.m_object > left->m_signature.m_object;
}


bool __usercall vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>::operator()@<al>(
        const vostok::render::res_signature *const left@<eax>,
        const vostok::render::res_signature *const right@<ecx>,
        vostok::render::resource_manager::compare_predicate<vostok::render::res_signature> *this)
{
  return right->m_signature > left->m_signature;
}
