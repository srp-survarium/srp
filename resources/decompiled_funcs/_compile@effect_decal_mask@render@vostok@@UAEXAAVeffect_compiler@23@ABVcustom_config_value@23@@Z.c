void __thiscall vostok::render::effect_decal_mask::compile(
        vostok::render::effect_decal_mask *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *__formal)
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
  D3D11_STENCIL_OP v12; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v13; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration include_getter; // [esp+10h] [ebp-10h] BYREF

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    compiler,
    &stru_966A14.m_name.m_string.m_buffer[176],
    0,
    (vostok::render::shader_configuration *)&stru_966A14.m_name.m_string.m_buffer[168],
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_INVERT,
    1,
    0x80u,
    0xFFu,
    0xFFu,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v12);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_FRONT);
  vostok::render::effect_compiler::color_write_enable(v4, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::end_pass(
    v5,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v6, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v7, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v8,
    compiler,
    &stru_966A14.m_name.m_string.m_buffer[176],
    0,
    (vostok::render::shader_configuration *)&stru_966A14.m_name.m_string.m_buffer[168],
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_INVERT,
    1,
    0x80u,
    0xFFu,
    0xFFu,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    v13);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_FRONT);
  vostok::render::effect_compiler::color_write_enable(v9, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::end_pass(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v11, (int)compiler);
}
