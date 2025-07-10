void __thiscall vostok::render::effect_environment_probe_lighting<1,1,0>::compile(
        vostok::render::effect_environment_probe_lighting<1,1,0> *this,
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
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  D3D11_BLEND_OP v12; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v13; // [esp+0h] [ebp-20h]
  bool v14; // [esp+0h] [ebp-20h]
  bool v15; // [esp+0h] [ebp-20h]
  bool v16; // [esp+0h] [ebp-20h]
  bool v17; // [esp+0h] [ebp-20h]
  bool v18; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v19; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v20; // [esp+0h] [ebp-20h]
  bool v21; // [esp+0h] [ebp-20h]
  bool v22; // [esp+0h] [ebp-20h]
  bool v23; // [esp+0h] [ebp-20h]
  bool v24; // [esp+0h] [ebp-20h]
  bool v25; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration configuration; // [esp+10h] [ebp-10h] BYREF

  *(_DWORD *)&configuration.0 = 0;
  *(unsigned __int64 *)((char *)configuration.configuration + 4) = 0x600400000000LL;
  HIDWORD(configuration.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this);
  vostok::render::effect_compiler::begin_pass(
    v3,
    (const char *)compiler,
    (const char *)&stru_9642F8.m_desc.Height,
    0,
    (const vostok::render::shader_configuration *)&stru_9642F8.m_rescale_max.elements[2],
    (vostok::render::shader_include_getter *)&configuration);
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
    compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v12);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    1,
    0xFFu,
    0x40u,
    0xFFu,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    v13,
    D3D11_STENCIL_OP_INVERT);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_BACK);
  vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, v14, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_normal", "$user$normal", 0, v15, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v16,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8,
    (const char *)&stru_9642F8.m_desc.SampleDesc.Quality,
    0,
    v17,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8.m_desc_3d.Usage,
    "$user$ssao_accumulator_full_x",
    0,
    v18,
    0xFFFFFFFF);
  vostok::render::effect_compiler::color_write_enable(
    v4,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v5);
  vostok::render::effect_compiler::end_technique(v6);
  vostok::render::effect_compiler::begin_technique(v7);
  vostok::render::effect_compiler::begin_pass(
    v8,
    (const char *)compiler,
    (const char *)&stru_9642F8.m_desc.Height,
    0,
    (const vostok::render::shader_configuration *)&stru_9642F8.m_rescale_max.elements[2],
    (vostok::render::shader_include_getter *)&configuration);
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
    1,
    0xFFu,
    0x40u,
    0xFFu,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    v19,
    D3D11_STENCIL_OP_KEEP);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v20);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_FRONT);
  vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, v21, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_normal", "$user$normal", 0, v22, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v23,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8,
    (const char *)&stru_9642F8.m_desc.SampleDesc.Quality,
    0,
    v24,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8.m_desc_3d.Usage,
    "$user$ssao_accumulator_full_x",
    0,
    v25,
    0xFFFFFFFF);
  vostok::render::effect_compiler::color_write_enable(
    v9,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v10);
  vostok::render::effect_compiler::end_technique(v11);
}
