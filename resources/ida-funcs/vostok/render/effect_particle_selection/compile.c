void __thiscall vostok::render::effect_particle_selection::compile(
        vostok::render::effect_particle_selection *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  char v3; // cl
  vostok::render::effect_compiler *v4; // ecx
  bool v5; // zf
  vostok::render::effect_compiler *v6; // ecx
  const char *v7; // [esp+0h] [ebp-40h]
  vostok::render::shader_configuration *v8; // [esp+4h] [ebp-3Ch]
  unsigned int index; // [esp+10h] [ebp-30h]
  vostok::render::enum_vertex_input_type vertex_types[3]; // [esp+24h] [ebp-1Ch]
  vostok::render::shader_configuration configuration; // [esp+30h] [ebp-10h] BYREF

  vertex_types[0] = particle_vertex_input_type;
  vertex_types[1] = particle_subuv_vertex_input_type;
  vertex_types[2] = particle_beamtrail_vertex_input_type;
  for ( index = 0; index < 3; ++index )
  {
    v3 = 2 * LOBYTE(vertex_types[index]);
    *(_DWORD *)&configuration.0 = 0;
    *((_BYTE *)&configuration.0 + 3) = 2 * v3;
    *(unsigned __int64 *)((char *)configuration.configuration + 4) = 0x400000000LL;
    HIDWORD(configuration.configuration[1]) = 0;
    vostok::render::effect_material_base::compile_begin(
      compiler,
      custom_config,
      (vostok::render::effect_material_base *)&stru_966284,
      (vostok::render::shader_configuration *)"particle_selected",
      (const char *)&configuration,
      v7,
      v8);
    if ( !compiler->m_shaders_cache_mode )
    {
      if ( s_no_effect_result.m_type == type_unset )
      {
        s_no_effect_result.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      }
      if ( s_no_effect_result.m_type == type_recursive )
      {
        compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
        compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
        compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
        compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
      }
      if ( !compiler->m_shaders_cache_mode )
      {
        if ( s_no_effect_result.m_type == type_unset )
        {
          s_no_effect_result.m_type = type_recursive;
          vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
        }
        if ( s_no_effect_result.m_type == type_recursive )
        {
          v5 = compiler->m_state_descriptor.m_rasterizer_desc.CullMode == D3D11_CULL_NONE;
          compiler->m_state_descriptor.m_rasterizer_desc.CullMode = D3D11_CULL_NONE;
          compiler->m_state_descriptor.m_rasterizer_desc_updated |= !v5;
        }
        if ( !compiler->m_shaders_cache_mode )
        {
          if ( s_no_effect_result.m_type == type_unset )
          {
            s_no_effect_result.m_type = type_recursive;
            vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
          }
          if ( s_no_effect_result.m_type == type_recursive )
            vostok::render::state_descriptor::set_alpha_blend(
              D3D11_BLEND_ONE,
              D3D11_BLEND_OP_ADD,
              D3D11_BLEND_ZERO,
              D3D11_BLEND_OP_ADD,
              &compiler->m_state_descriptor,
              1,
              D3D11_BLEND_ONE,
              (D3D11_BLEND)v7);
          if ( !compiler->m_shaders_cache_mode )
          {
            if ( s_no_effect_result.m_type == type_unset )
            {
              s_no_effect_result.m_type = type_recursive;
              vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
            }
            if ( s_no_effect_result.m_type == type_recursive )
            {
              v5 = compiler->m_state_descriptor.m_rasterizer_desc.FillMode == D3D11_FILL_WIREFRAME;
              compiler->m_state_descriptor.m_rasterizer_desc.FillMode = D3D11_FILL_WIREFRAME;
              LOBYTE(v4) = !v5;
              compiler->m_state_descriptor.m_rasterizer_desc_updated |= !v5;
            }
          }
        }
      }
    }
    vostok::render::effect_compiler::end_pass(
      v4,
      (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
    vostok::render::effect_compiler::end_technique(v6, (int)compiler);
  }
}
