void __usercall vostok::render::stage_lights::new_sphere_geometry(
        vostok::render::stage_lights *this@<ecx>,
        bool a2@<dil>,
        _DWORD *a3@<esi>)
{
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v4; // ecx
  vostok::render::res_state *v5; // edi
  bool v6; // zf
  vostok::render::untyped_buffer *v7; // eax
  vostok::render::untyped_buffer *v8; // ecx
  vostok::render::res_state *v9; // edi
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v11; // ecx
  vostok::render::res_geometry *v12; // eax
  vostok::render::untyped_buffer *v13; // [esp-8h] [ebp-2Ch]
  vostok::render::untyped_buffer *v14; // [esp-4h] [ebp-28h]
  D3D11_INPUT_ELEMENT_DESC desc[1]; // [esp+8h] [ebp-1Ch] BYREF

  buffer = vostok::render::resource_manager::create_buffer(
             0x450u,
             a2,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             du_sphere_vertices,
             enum_buffer_type_vertex,
             0,
             0);
  v4 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v4 = buffer;
  }
  v5 = (vostok::render::res_state *)a3[538];
  a3[538] = v4;
  if ( v5 )
  {
    v6 = v5->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::resource_manager::release(
        v5,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v7 = vostok::render::resource_manager::create_buffer(
         0x438u,
         (bool)v5,
         (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
         du_sphere_faces,
         enum_buffer_type_index,
         0,
         0);
  v8 = 0;
  if ( v7 )
  {
    ++v7->m_reference_count;
    v8 = v7;
  }
  v9 = (vostok::render::res_state *)a3[539];
  a3[539] = v8;
  if ( v9 )
  {
    v6 = v9->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::resource_manager::release(
        v9,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v14 = (vostok::render::untyped_buffer *)a3[539];
  v13 = (vostok::render::untyped_buffer *)a3[538];
  desc[0].SemanticName = "POSITION";
  desc[0].SemanticIndex = 0;
  desc[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
  desc[0].InputSlot = 0;
  desc[0].AlignedByteOffset = 0;
  desc[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  desc[0].InstanceDataStepRate = 0;
  geometry = vostok::render::resource_manager::create_geometry(
               (stlp_std::forward_iterator_tag *)desc,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               1u,
               0xCu,
               v13,
               v14);
  v11 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v11 = geometry;
  }
  v12 = (vostok::render::res_geometry *)a3[540];
  a3[540] = v11;
  if ( v12 )
  {
    v6 = v12->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v12);
  }
}
