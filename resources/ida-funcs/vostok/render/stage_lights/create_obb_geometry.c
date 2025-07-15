void __usercall vostok::render::stage_lights::create_obb_geometry(
        vostok::render::stage_lights *this@<ecx>,
        bool a2@<dil>,
        _DWORD *a3@<esi>)
{
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v4; // ecx
  vostok::render::res_state *v5; // edi
  bool v6; // zf
  void *v7; // esp
  vostok::render::untyped_buffer *v8; // eax
  vostok::render::untyped_buffer *v9; // ecx
  vostok::render::res_state *v10; // edi
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v12; // ecx
  vostok::render::res_geometry *v13; // eax
  vostok::render::untyped_buffer *v14; // [esp-50h] [ebp-78h]
  vostok::render::untyped_buffer *v15; // [esp-4Ch] [ebp-74h]
  unsigned __int8 v16[84]; // [esp-48h] [ebp-70h] BYREF
  D3D11_INPUT_ELEMENT_DESC desc[1]; // [esp+Ch] [ebp-1Ch] BYREF

  buffer = vostok::render::resource_manager::create_buffer(
             0x60u,
             a2,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             vostok::geometry_utils::cube_solid::vertices,
             enum_buffer_type_vertex,
             0,
             0);
  v4 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v4 = buffer;
  }
  v5 = (vostok::render::res_state *)a3[544];
  a3[544] = v4;
  if ( v5 )
  {
    v6 = v5->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::resource_manager::release(
        v5,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v7 = alloca(72);
  memmove(v16, (unsigned __int8 *)vostok::geometry_utils::cube_solid::faces, 0x48u);
  v8 = vostok::render::resource_manager::create_buffer(
         0x48u,
         (bool)v16,
         (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
         v16,
         enum_buffer_type_index,
         0,
         0);
  v9 = 0;
  if ( v8 )
  {
    ++v8->m_reference_count;
    v9 = v8;
  }
  v10 = (vostok::render::res_state *)a3[545];
  a3[545] = v9;
  if ( v10 )
  {
    v6 = v10->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::resource_manager::release(
        v10,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v15 = (vostok::render::untyped_buffer *)a3[545];
  v14 = (vostok::render::untyped_buffer *)a3[544];
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
               v14,
               v15);
  v12 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v12 = geometry;
  }
  v13 = (vostok::render::res_geometry *)a3[546];
  a3[546] = v12;
  if ( v13 )
  {
    v6 = v13->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v13);
  }
}
