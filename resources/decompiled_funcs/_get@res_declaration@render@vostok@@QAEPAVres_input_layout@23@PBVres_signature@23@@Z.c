vostok::render::res_input_layout *__thiscall vostok::render::res_declaration::get(
        vostok::render::res_declaration *this,
        const vostok::render::res_signature *signature)
{
  const vostok::render::res_signature *v2; // eax
  vostok::render::vector<vostok::render::signature_layout_pair> *p_vs_to_layout; // ebx
  vostok::render::signature_layout_pair *M_start; // edi
  int v6; // ecx
  int v7; // edx
  const vostok::render::signature_layout_pair *v9; // eax
  vostok::render::res_input_layout *m_object; // esi
  const vostok::render::res_signature *v11; // eax
  vostok::render::res_input_layout *v12; // eax
  vostok::render::signature_layout_pair v13; // [esp+10h] [ebp-8h] BYREF

  v2 = signature;
  p_vs_to_layout = &this->vs_to_layout;
  M_start = this->vs_to_layout._M_impl._M_start;
  v6 = this->vs_to_layout._M_impl._M_finish - M_start;
  while ( v6 > 0 )
  {
    v7 = v6 >> 1;
    if ( M_start[v6 >> 1].signature.m_object >= v2 )
    {
      v6 >>= 1;
    }
    else
    {
      v6 += -1 - v7;
      v2 = signature;
      M_start += v7 + 1;
    }
  }
  if ( M_start != this->vs_to_layout._M_impl._M_finish && M_start->signature.m_object == v2 )
    return M_start->input_layout.m_object;
  vostok::render::signature_layout_pair::signature_layout_pair(&v13, this, v2);
  m_object = stlp_std::vector<vostok::render::signature_layout_pair,vostok::render::std_allocator<vostok::render::signature_layout_pair>>::insert(
               p_vs_to_layout,
               M_start,
               v9)->input_layout.m_object;
  v11 = v13.signature.m_object;
  if ( v13.signature.m_object )
  {
    --v13.signature.m_object->m_reference_count;
    if ( !v11->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v13.signature.m_object);
  }
  v12 = v13.input_layout.m_object;
  if ( v13.input_layout.m_object )
  {
    --v13.input_layout.m_object->m_reference_count;
    if ( !v12->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v13.input_layout.m_object);
  }
  return m_object;
}
