void __usercall stlp_std::priv::__fill<vostok::render::signature_layout_pair *,vostok::render::signature_layout_pair,int>(
        vostok::render::signature_layout_pair *__first@<ecx>,
        vostok::render::signature_layout_pair *__last@<eax>,
        const vostok::render::signature_layout_pair *__val)
{
  vostok::render::signature_layout_pair *v3; // esi
  int i; // edi
  vostok::render::res_input_layout *m_object; // eax
  const vostok::render::res_input_layout *v6; // ecx
  bool v7; // zf
  const vostok::render::res_signature *v8; // ecx
  const vostok::render::res_signature *v9; // eax
  const vostok::render::res_signature *v10; // ecx

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    m_object = 0;
    if ( __val->input_layout.m_object )
    {
      m_object = __val->input_layout.m_object;
      ++__val->input_layout.m_object->m_reference_count;
    }
    v6 = v3->input_layout.m_object;
    v3->input_layout.m_object = m_object;
    if ( v6 )
    {
      v7 = v6->m_reference_count-- == 1;
      if ( v7 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v6);
    }
    v8 = __val->signature.m_object;
    v9 = 0;
    if ( v8 )
    {
      v9 = __val->signature.m_object;
      ++v8->m_reference_count;
    }
    v10 = v3->signature.m_object;
    v3->signature.m_object = v9;
    if ( v10 )
    {
      v7 = v10->m_reference_count-- == 1;
      if ( v7 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v10);
    }
    --i;
  }
}
