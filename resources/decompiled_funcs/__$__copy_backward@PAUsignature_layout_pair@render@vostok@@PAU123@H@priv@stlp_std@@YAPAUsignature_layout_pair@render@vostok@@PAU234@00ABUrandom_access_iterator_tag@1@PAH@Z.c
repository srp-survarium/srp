vostok::render::signature_layout_pair *__usercall stlp_std::priv::__copy_backward<vostok::render::signature_layout_pair *,vostok::render::signature_layout_pair *,int>@<eax>(
        vostok::render::signature_layout_pair *__last@<ecx>,
        vostok::render::signature_layout_pair *__result@<eax>,
        vostok::render::signature_layout_pair *__first)
{
  vostok::render::signature_layout_pair *v3; // edi
  vostok::render::signature_layout_pair *v4; // esi
  int v5; // ebx
  vostok::render::res_input_layout *m_object; // ecx
  vostok::render::res_input_layout *v7; // eax
  const vostok::render::res_input_layout *v8; // ecx
  bool v9; // zf
  const vostok::render::res_signature *v10; // ecx
  const vostok::render::res_signature *v11; // eax
  const vostok::render::res_signature *v12; // ecx

  v3 = __last;
  v4 = __result;
  v5 = __last - __first;
  if ( v5 > 0 )
  {
    do
    {
      m_object = v3[-1].input_layout.m_object;
      --v3;
      --v4;
      v7 = 0;
      if ( m_object )
      {
        v7 = m_object;
        ++m_object->m_reference_count;
      }
      v8 = v4->input_layout.m_object;
      v4->input_layout.m_object = v7;
      if ( v8 )
      {
        v9 = v8->m_reference_count-- == 1;
        if ( v9 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v8);
      }
      v10 = v3->signature.m_object;
      v11 = 0;
      if ( v10 )
      {
        v11 = v3->signature.m_object;
        ++v10->m_reference_count;
      }
      v12 = v4->signature.m_object;
      v4->signature.m_object = v11;
      if ( v12 )
      {
        v9 = v12->m_reference_count-- == 1;
        if ( v9 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v12);
      }
      --v5;
    }
    while ( v5 > 0 );
    return v4;
  }
  return __result;
}
