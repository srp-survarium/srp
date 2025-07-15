void __userpurge vostok::render::signature_layout_pair::signature_layout_pair(
        vostok::render::signature_layout_pair *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> *a2@<esi>,
        const vostok::render::res_declaration *decl,
        const vostok::render::res_signature *signature)
{
  stlp_std::priv::_Rb_tree_node_base *input_layout; // eax
  const vostok::render::res_signature *v5; // ecx
  vostok::render::res_pass *m_object; // eax

  a2->m_object = 0;
  a2[1].m_object = 0;
  if ( signature )
  {
    vostok::intrusive_ptr<vostok::render::res_signature const,vostok::render::res_signature const,vostok::threading::single_threading_policy>::dec(a2 + 1);
    a2[1].m_object = signature;
    ++signature->m_reference_count;
  }
  input_layout = vostok::render::resource_manager::create_input_layout(
                   (vostok::render::resource_manager *)this,
                   (stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<vostok::render::res_input_layout *,stlp_std::priv::_SetTraitsT<vostok::render::res_input_layout *> >,bool> *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                   decl,
                   signature);
  v5 = 0;
  if ( input_layout )
  {
    ++*(_DWORD *)&input_layout->_M_color;
    v5 = (const vostok::render::res_signature *)input_layout;
  }
  m_object = (vostok::render::res_pass *)a2->m_object;
  a2->m_object = v5;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        m_object);
  }
}
