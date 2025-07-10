void __thiscall vostok::render::effect_exponential_volume_fog::compile(
        vostok::render::effect_exponential_volume_fog *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  bool v6; // [esp+0h] [ebp-20h]
  bool v7; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v8; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration include_getter; // [esp+10h] [ebp-10h] BYREF

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    compiler,
    (char *)&stru_96775C,
    0,
    (vostok::render::shader_configuration *)&stru_96775C,
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
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_FRONT);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v6);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_fog_noise",
    (char *)&stru_96775C.configuration[1] + 4,
    0,
    v7);
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_INV_SRC_ALPHA,
    compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v8);
  vostok::render::effect_compiler::end_pass(
    v4,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v5, (int)compiler);
}
