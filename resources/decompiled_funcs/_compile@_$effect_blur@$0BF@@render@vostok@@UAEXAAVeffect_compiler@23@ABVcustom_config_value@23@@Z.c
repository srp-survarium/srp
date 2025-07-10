void __thiscall vostok::render::effect_blur<21>::compile(
        vostok::render::effect_blur<21> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
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
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  D3D11_BLEND_OP v24; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v25; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v27; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v28; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration config; // [esp+10h] [ebp-10h] BYREF

  config.configuration[1] = 4;
  config.configuration[0] = 0x540000000000LL;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this);
  vostok::render::effect_compiler::begin_pass(
    v3,
    (const char *)compiler,
    (const char *)&stru_9656C8.m_name,
    0,
    (const vostok::render::shader_configuration *)&stru_9656C8.m_desc_3d.Format,
    (vostok::render::shader_include_getter *)&config);
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
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::set_fill_mode(compiler, D3D11_FILL_SOLID);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v24);
  vostok::render::effect_compiler::end_pass(v4);
  vostok::render::effect_compiler::end_technique(v5);
  vostok::render::effect_compiler::begin_technique(v6);
  vostok::render::effect_compiler::begin_pass(
    v7,
    (const char *)compiler,
    (const char *)&stru_9656C8.m_name,
    0,
    (const vostok::render::shader_configuration *)&stru_9656C8.m_name.m_string.m_max_end,
    (vostok::render::shader_include_getter *)&config);
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
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::set_fill_mode(compiler, D3D11_FILL_SOLID);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v25);
  vostok::render::effect_compiler::end_pass(v8);
  vostok::render::effect_compiler::end_technique(v9);
  vostok::render::effect_compiler::begin_technique(v10);
  vostok::render::effect_compiler::begin_pass(
    (vostok::render::effect_compiler *)&config,
    (const char *)compiler,
    (const char *)&stru_9656C8.m_name,
    0,
    (const vostok::render::shader_configuration *)&stru_9656C8.m_name.m_string.m_buffer[12],
    (vostok::render::shader_include_getter *)&config);
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
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::set_fill_mode(compiler, D3D11_FILL_SOLID);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v26);
  vostok::render::effect_compiler::end_pass(v11);
  vostok::render::effect_compiler::end_technique(v12);
  vostok::render::effect_compiler::begin_technique(v13);
  vostok::render::effect_compiler::begin_pass(
    v14,
    (const char *)compiler,
    (const char *)&stru_9656C8.m_name,
    0,
    (const vostok::render::shader_configuration *)&stru_9656C8.m_name.m_string.m_buffer[28],
    (vostok::render::shader_include_getter *)&config);
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
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::set_fill_mode(compiler, D3D11_FILL_SOLID);
  vostok::render::effect_compiler::end_pass(v15);
  vostok::render::effect_compiler::end_technique(v16);
  vostok::render::effect_compiler::begin_technique(v17);
  vostok::render::effect_compiler::begin_pass(
    v18,
    (const char *)compiler,
    (const char *)&stru_9656C8.m_name,
    0,
    (const vostok::render::shader_configuration *)&stru_9656C8.m_name.m_string.m_buffer[44],
    (vostok::render::shader_include_getter *)&config);
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
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::set_fill_mode(compiler, D3D11_FILL_SOLID);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v27);
  vostok::render::effect_compiler::end_pass(v19);
  vostok::render::effect_compiler::end_technique(v20);
  vostok::render::effect_compiler::begin_technique(v21);
  vostok::render::effect_compiler::begin_pass(
    (vostok::render::effect_compiler *)&config,
    (const char *)compiler,
    (const char *)&stru_9656C8.m_name,
    0,
    (const vostok::render::shader_configuration *)&stru_9656C8.m_name.m_string.m_buffer[60],
    (vostok::render::shader_include_getter *)&config);
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
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::set_fill_mode(compiler, D3D11_FILL_SOLID);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v28);
  vostok::render::effect_compiler::end_pass(v22);
  vostok::render::effect_compiler::end_technique(v23);
}
