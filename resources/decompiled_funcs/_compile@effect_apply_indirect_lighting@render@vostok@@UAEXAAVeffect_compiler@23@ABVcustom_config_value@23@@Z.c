void __thiscall vostok::render::effect_apply_indirect_lighting::compile(
        vostok::render::effect_apply_indirect_lighting *this,
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
  bool v10; // [esp+0h] [ebp-20h]
  bool v11; // [esp+0h] [ebp-20h]
  bool v12; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v13; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v14; // [esp+0h] [ebp-20h]
  bool v15; // [esp+0h] [ebp-20h]
  bool v16; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v17; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration include_getter; // [esp+10h] [ebp-10h] BYREF

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    compiler,
    &texture.m_name.m_string.m_buffer[28],
    0,
    (vostok::render::shader_configuration *)&texture.m_name.m_string.m_max_end,
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
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_normal", "$user$normal", 0, v10);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v11);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    (const char *)&stru_9642F8.m_desc_3d.Usage,
    "$user$ssao_accumulator_full_x",
    0,
    v12);
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_ONE,
    compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    v13);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v14);
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
    &texture.m_name.m_string.m_buffer[28],
    0,
    (vostok::render::shader_configuration *)&texture.m_name.m_string.m_buffer[52],
    &include_getter);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_normal", "$user$normal", 0, v15);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v16);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v17);
  vostok::render::effect_compiler::end_pass(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v9, (int)compiler);
}
