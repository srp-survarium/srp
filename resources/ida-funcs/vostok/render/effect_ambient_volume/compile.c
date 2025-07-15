void __thiscall vostok::render::effect_ambient_volume::compile(
        vostok::render::effect_ambient_volume *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  D3D11_BLEND_OP v10; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v11; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v12; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v13; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration configuration; // [esp+10h] [ebp-10h] BYREF

  *(_DWORD *)&configuration.0 = 0;
  *(unsigned __int64 *)((char *)configuration.configuration + 4) = 0x400000000LL;
  HIDWORD(configuration.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  vostok::render::effect_compiler::begin_pass(
    v3,
    compiler,
    (char *)&stru_966F54.configuration[1] + 4,
    0,
    (vostok::render::shader_configuration *)((char *)&stru_966F54.configuration[1] + 4),
    &configuration);
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
  }
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_SRC_COLOR,
    compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v10);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_INVERT,
    1,
    0xFFu,
    0x40u,
    0xFFu,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    v11);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_BACK);
  vostok::render::effect_compiler::end_pass(
    v4,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v5, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v6, (int)compiler);
  vostok::render::effect_compiler::begin_pass(
    v7,
    compiler,
    (char *)&stru_966F54.configuration[1] + 4,
    0,
    (vostok::render::shader_configuration *)((char *)&stru_966F54.configuration[1] + 4),
    &configuration);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 0;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0xFFu,
    0x40u,
    0xFFu,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    v12);
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_SRC_COLOR,
    compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v13);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_FRONT);
  vostok::render::effect_compiler::end_pass(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v9, (int)compiler);
}
