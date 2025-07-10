void __usercall vostok::render::hw_hiz_point_list::hw_hiz_point_list(
        vostok::render::hw_hiz_point_list *this@<ecx>,
        vostok::render::res_declaration **a2@<edi>)
{
  vostok::render::resource_manager *v2; // ecx
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v4; // ecx
  vostok::render::res_declaration *v5; // eax
  D3D11_INPUT_ELEMENT_DESC point_list_layout[2]; // [esp+8h] [ebp-3Ch] BYREF

  v2 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  point_list_layout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
  point_list_layout[1].AlignedByteOffset = 16;
  *a2 = 0;
  a2[1] = 0;
  a2[2] = 0;
  point_list_layout[0].SemanticName = "POSITION";
  point_list_layout[0].SemanticIndex = 0;
  point_list_layout[0].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
  point_list_layout[0].InputSlot = 0;
  point_list_layout[0].AlignedByteOffset = 0;
  point_list_layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  point_list_layout[0].InstanceDataStepRate = 0;
  point_list_layout[1].SemanticName = "TEXCOORD";
  point_list_layout[1].SemanticIndex = 0;
  point_list_layout[1].InputSlot = 0;
  point_list_layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  point_list_layout[1].InstanceDataStepRate = 0;
  declaration = vostok::render::resource_manager::create_declaration(
                  2u,
                  v2,
                  (stlp_std::forward_iterator_tag *)point_list_layout);
  v4 = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v4 = declaration;
  }
  v5 = *a2;
  *a2 = v4;
  if ( v5 )
  {
    if ( v5->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v5);
  }
}
