void __thiscall vostok::render::effect_resolve_lighting::compile(
        vostok::render::effect_resolve_lighting *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  bool v6; // [esp+0h] [ebp-20h]
  bool v7; // [esp+0h] [ebp-20h]
  bool v8; // [esp+0h] [ebp-20h]
  bool v9; // [esp+0h] [ebp-20h]
  bool v10; // [esp+0h] [ebp-20h]
  bool v11; // [esp+0h] [ebp-20h]
  bool v12; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v13; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration include_getter; // [esp+10h] [ebp-10h] BYREF

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    compiler,
    &texture.m_name.m_string.m_buffer[88],
    0,
    (vostok::render::shader_configuration *)&texture.m_name.m_string.m_buffer[88],
    &include_getter);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v6);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_normal", "$user$normal", 0, v7);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v8);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &texture.m_name.m_string.m_buffer[108],
    "$user$accum_diffuse",
    0,
    v9);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &texture.m_name.m_string.m_buffer[132],
    "$user$accum_specular",
    0,
    v10);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_lpv_accumulation",
    "$user$lpv_accumulation",
    0,
    v11);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_sun_translucensy_help_data",
    "$user$sun_translucensy_help_data",
    0,
    v12);
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
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v13);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::set_fill_mode(compiler, D3D11_FILL_SOLID);
  vostok::render::effect_compiler::end_pass(
    v4,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v5, (int)compiler);
}
