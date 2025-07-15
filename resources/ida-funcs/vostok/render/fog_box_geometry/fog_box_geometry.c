void __userpurge vostok::render::fog_box_geometry::fog_box_geometry(
        vostok::render::fog_box_geometry *this@<ecx>,
        bool a2@<dil>,
        vostok::render::fog_box_geometry *thisa)
{
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v4; // esi
  vostok::render::untyped_buffer *v5; // eax
  vostok::render::untyped_buffer *v6; // edi
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v8; // ecx
  vostok::render::res_geometry *m_object; // eax
  bool v10; // zf
  vostok::render::resource_manager *v11; // [esp-14h] [ebp-44h]
  D3D11_INPUT_ELEMENT_DESC layout[1]; // [esp+14h] [ebp-1Ch] BYREF

  v11 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  thisa->m_geometry.m_object = 0;
  buffer = vostok::render::resource_manager::create_buffer(
             0x60u,
             a2,
             v11,
             du_box_vertices,
             enum_buffer_type_vertex,
             0,
             0);
  v4 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v4 = buffer;
  }
  v5 = vostok::render::resource_manager::create_buffer(
         0x48u,
         a2,
         (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
         du_box_faces,
         enum_buffer_type_index,
         0,
         0);
  v6 = 0;
  if ( v5 )
  {
    ++v5->m_reference_count;
    v6 = v5;
  }
  layout[0].SemanticName = "POSITION";
  layout[0].SemanticIndex = 0;
  layout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
  layout[0].InputSlot = 0;
  layout[0].AlignedByteOffset = 0;
  layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  layout[0].InstanceDataStepRate = 0;
  geometry = vostok::render::resource_manager::create_geometry(
               (stlp_std::forward_iterator_tag *)layout,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               1u,
               0xCu,
               v4,
               v6);
  v8 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v8 = geometry;
  }
  m_object = thisa->m_geometry.m_object;
  thisa->m_geometry.m_object = v8;
  if ( m_object )
  {
    v10 = m_object->m_reference_count-- == 1;
    if ( v10 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  if ( v6 )
  {
    v10 = v6->m_reference_count-- == 1;
    if ( v10 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v6,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  if ( v4 )
  {
    v10 = v4->m_reference_count-- == 1;
    if ( v10 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v4,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
}
