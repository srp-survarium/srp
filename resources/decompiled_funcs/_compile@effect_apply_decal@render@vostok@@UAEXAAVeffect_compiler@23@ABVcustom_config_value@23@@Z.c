void __thiscall vostok::render::effect_apply_decal::compile(
        vostok::render::effect_apply_decal *this,
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
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  bool v14; // [esp+0h] [ebp-20h]
  bool v15; // [esp+0h] [ebp-20h]
  bool v16; // [esp+0h] [ebp-20h]
  bool v17; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v18; // [esp+0h] [ebp-20h]
  bool v19; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v20; // [esp+0h] [ebp-20h]
  bool v21; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v22; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v23; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration include_getter; // [esp+10h] [ebp-10h] BYREF

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    compiler,
    &stru_966A14.m_name.m_string.m_buffer[216],
    0,
    (vostok::render::shader_configuration *)&stru_966A14.m_name.m_string.m_buffer[188],
    &include_getter);
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
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &stru_966A14.m_name.m_string.m_buffer[228],
    "$user$decals_smoothness",
    0,
    v14);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_decals_normal", "$user$decals_normal", 0, v15);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_normal", "$user$normal", 0, v16);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v17);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v18);
  vostok::render::effect_compiler::end_pass(
    v4,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v5, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v6, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v7,
    compiler,
    &stru_966A14.m_name.m_string.m_buffer[216],
    0,
    (vostok::render::shader_configuration *)&stru_966A14.m_name.m_string.m_buffer[248],
    &include_getter);
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
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    (const char *)&stru_966A14.m_mip_level_cut,
    "$user$decals_blend_result",
    0,
    v19);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v20);
  vostok::render::effect_compiler::end_pass(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v9, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v10, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    (vostok::render::effect_compiler *)&include_getter,
    compiler,
    &stru_966A14.m_name.m_string.m_buffer[216],
    0,
    (vostok::render::shader_configuration *)&stru_966BDC,
    &include_getter);
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
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_decals_diffuse", "$user$decals_diffuse", 0, v21);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v22);
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_INV_SRC_ALPHA,
    compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v23);
  vostok::render::effect_compiler::color_write_enable(
    v11,
    (int)compiler,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v13, (int)compiler);
}
