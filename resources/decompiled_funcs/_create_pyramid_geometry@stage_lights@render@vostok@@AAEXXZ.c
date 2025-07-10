void __usercall vostok::render::stage_lights::create_pyramid_geometry(
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
  vostok::render::untyped_buffer *v13; // [esp-10h] [ebp-8Ch]
  vostok::render::untyped_buffer *v14; // [esp-Ch] [ebp-88h]
  D3D11_INPUT_ELEMENT_DESC desc[1]; // [esp+0h] [ebp-7Ch] BYREF
  unsigned __int16 indices[18]; // [esp+1Ch] [ebp-60h] BYREF
  vostok::math::float3 vertices[5]; // [esp+40h] [ebp-3Ch] BYREF

  indices[1] = 1;
  indices[2] = 2;
  indices[4] = 2;
  indices[5] = 4;
  indices[7] = 4;
  indices[8] = 3;
  indices[0] = 0;
  indices[3] = 0;
  indices[6] = 0;
  indices[9] = 0;
  indices[11] = 1;
  indices[12] = 1;
  indices[15] = 2;
  indices[10] = 3;
  indices[13] = 3;
  indices[14] = 2;
  indices[16] = 3;
  memset(vertices, 0, 12);
  *(_QWORD *)&vertices[1].x = 0xBF800000BF800000uLL;
  LODWORD(vertices[1].z) = clear_value;
  vertices[2].x = -1.0;
  LODWORD(vertices[2].y) = clear_value;
  LODWORD(vertices[2].z) = clear_value;
  *(_QWORD *)&vertices[3].x = (unsigned int)clear_value | 0xBF80000000000000uLL;
  LODWORD(vertices[3].z) = clear_value;
  LODWORD(vertices[4].x) = clear_value;
  LODWORD(vertices[4].y) = clear_value;
  LODWORD(vertices[4].z) = clear_value;
  indices[17] = 4;
  buffer = vostok::render::resource_manager::create_buffer(
             0x3Cu,
             a2,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             vertices,
             enum_buffer_type_vertex,
             0,
             0);
  v4 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v4 = buffer;
  }
  v5 = (vostok::render::res_state *)a3[541];
  a3[541] = v4;
  if ( v5 )
  {
    v6 = v5->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::resource_manager::release(
        v5,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v7 = vostok::render::resource_manager::create_buffer(
         0x24u,
         (bool)v5,
         (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
         indices,
         enum_buffer_type_index,
         0,
         0);
  v8 = 0;
  if ( v7 )
  {
    ++v7->m_reference_count;
    v8 = v7;
  }
  v9 = (vostok::render::res_state *)a3[542];
  a3[542] = v8;
  if ( v9 )
  {
    v6 = v9->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::resource_manager::release(
        v9,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v14 = (vostok::render::untyped_buffer *)a3[542];
  v13 = (vostok::render::untyped_buffer *)a3[541];
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
  v12 = (vostok::render::res_geometry *)a3[543];
  a3[543] = v11;
  if ( v12 )
  {
    v6 = v12->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v12);
  }
}
