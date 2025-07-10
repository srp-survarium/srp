void __usercall vostok::render::box_geometry::box_geometry(
        vostok::render::box_geometry *this@<ecx>,
        bool a2@<dil>,
        vostok::render::res_declaration **a3@<esi>)
{
  vostok::render::resource_manager *v3; // eax
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v5; // ecx
  vostok::render::res_state *v6; // edi
  bool v7; // zf
  void *v8; // esp
  vostok::render::untyped_buffer *v9; // eax
  vostok::render::untyped_buffer *v10; // ecx
  vostok::render::res_state *v11; // edi
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v13; // ecx
  vostok::render::res_declaration *v14; // eax
  unsigned __int8 v15[52]; // [esp-48h] [ebp-70h] BYREF
  vostok::render::resource_manager *v16; // [esp-14h] [ebp-3Ch]
  const float *v17; // [esp-10h] [ebp-38h]
  vostok::render::enum_buffer_type v18; // [esp-Ch] [ebp-34h]
  vostok::render::untyped_buffer *v19; // [esp-8h] [ebp-30h]
  bool v20; // [esp-4h] [ebp-2Ch]
  D3D11_INPUT_ELEMENT_DESC desc[1]; // [esp+Ch] [ebp-1Ch] BYREF

  v3 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  v20 = 0;
  v19 = 0;
  v18 = enum_buffer_type_vertex;
  *a3 = 0;
  v17 = vostok::geometry_utils::cube_solid::vertices;
  a3[1] = 0;
  v16 = v3;
  a3[2] = 0;
  a3[3] = (vostok::render::res_declaration *)12;
  buffer = vostok::render::resource_manager::create_buffer(0x60u, a2, v16, v17, v18, v19, v20);
  v5 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v5 = buffer;
  }
  v6 = (vostok::render::res_state *)a3[1];
  a3[1] = (vostok::render::res_declaration *)v5;
  if ( v6 )
  {
    v7 = v6->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        v6,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v8 = alloca(72);
  memmove(v15, (unsigned __int8 *)vostok::geometry_utils::cube_solid::faces, 0x48u);
  v9 = vostok::render::resource_manager::create_buffer(
         0x48u,
         (bool)v15,
         (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
         v15,
         enum_buffer_type_index,
         0,
         0);
  v10 = 0;
  if ( v9 )
  {
    ++v9->m_reference_count;
    v10 = v9;
  }
  v11 = (vostok::render::res_state *)a3[2];
  a3[2] = (vostok::render::res_declaration *)v10;
  if ( v11 )
  {
    v7 = v11->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        v11,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  desc[0].SemanticName = "POSITION";
  desc[0].SemanticIndex = 0;
  desc[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
  desc[0].InputSlot = 0;
  desc[0].AlignedByteOffset = 0;
  desc[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  desc[0].InstanceDataStepRate = 0;
  declaration = vostok::render::resource_manager::create_declaration(
                  1u,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  (stlp_std::forward_iterator_tag *)desc);
  v13 = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v13 = declaration;
  }
  v14 = *a3;
  *a3 = v13;
  if ( v14 )
  {
    v7 = v14->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v14);
  }
}
