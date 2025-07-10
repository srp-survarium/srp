void __thiscall vostok::render::static_render_surface::create_shadow_pass_geometry(
        vostok::render::static_render_surface *this,
        vostok::render::static_render_surface *data,
        const unsigned __int8 *num_vertices,
        unsigned int stride)
{
  vostok::render::enum_vertex_input_type m_vertex_input_type; // edx
  D3D11_INPUT_ELEMENT_DESC layout[3]; // [esp+8h] [ebp-C8h] BYREF
  D3D11_INPUT_ELEMENT_DESC colored_layout[4]; // [esp+60h] [ebp-70h] BYREF

  layout[0].SemanticIndex = 0;
  layout[0].InputSlot = 0;
  layout[0].AlignedByteOffset = 0;
  layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  layout[0].InstanceDataStepRate = 0;
  layout[1].SemanticIndex = 0;
  layout[1].InputSlot = 0;
  layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  layout[1].InstanceDataStepRate = 0;
  layout[2].SemanticIndex = 0;
  layout[2].InputSlot = 0;
  layout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  layout[2].InstanceDataStepRate = 0;
  colored_layout[0].SemanticIndex = 0;
  colored_layout[0].InputSlot = 0;
  colored_layout[0].AlignedByteOffset = 0;
  colored_layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  colored_layout[0].InstanceDataStepRate = 0;
  colored_layout[1].SemanticIndex = 0;
  colored_layout[1].InputSlot = 0;
  colored_layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  colored_layout[1].InstanceDataStepRate = 0;
  colored_layout[2].SemanticIndex = 0;
  colored_layout[2].InputSlot = 0;
  colored_layout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  colored_layout[2].InstanceDataStepRate = 0;
  colored_layout[3].SemanticIndex = 0;
  colored_layout[3].InputSlot = 0;
  colored_layout[3].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  colored_layout[3].InstanceDataStepRate = 0;
  m_vertex_input_type = data->m_vertex_input_type;
  layout[0].SemanticName = "POSITION";
  layout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
  layout[1].SemanticName = "NORMAL";
  layout[1].Format = DXGI_FORMAT_R8G8B8A8_UNORM;
  layout[1].AlignedByteOffset = 12;
  layout[2].SemanticName = "TEXCOORD";
  layout[2].Format = DXGI_FORMAT_R32G32_FLOAT;
  layout[2].AlignedByteOffset = 16;
  colored_layout[0].SemanticName = "POSITION";
  colored_layout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
  colored_layout[1].SemanticName = "NORMAL";
  colored_layout[1].Format = DXGI_FORMAT_R8G8B8A8_UNORM;
  colored_layout[1].AlignedByteOffset = 12;
  colored_layout[2].SemanticName = "TEXCOORD";
  colored_layout[2].Format = DXGI_FORMAT_R32G32_FLOAT;
  colored_layout[2].AlignedByteOffset = 16;
  colored_layout[3].SemanticName = "COLOR";
  colored_layout[3].Format = DXGI_FORMAT_R8G8B8A8_UNORM;
  colored_layout[3].AlignedByteOffset = 24;
  if ( m_vertex_input_type == static_mesh_vertex_input_type )
  {
    vostok::render::create_shadow_pass_geometry_type__vostok::render::static_render_surface::create_shadow_pass_geometry_::_2_::static_vertex0__vostok::render::static_render_surface::create_shadow_pass_geometry_::_2_::opt_static_vertex_(
      num_vertices,
      stride,
      &data->m_render_geometry,
      (stlp_std::forward_iterator_tag *)layout,
      (const D3D11_INPUT_ELEMENT_DESC *)3);
  }
  else if ( m_vertex_input_type == static_mesh_vertex_colored_input_type )
  {
    vostok::render::create_shadow_pass_geometry_type__vostok::render::static_render_surface::create_shadow_pass_geometry_::_2_::colored_static_vertex__vostok::render::static_render_surface::create_shadow_pass_geometry_::_3_::colored_opt_static_vertex_(
      num_vertices,
      &data->m_render_geometry,
      stride,
      (stlp_std::forward_iterator_tag *)colored_layout,
      (const D3D11_INPUT_ELEMENT_DESC *)4);
  }
}
