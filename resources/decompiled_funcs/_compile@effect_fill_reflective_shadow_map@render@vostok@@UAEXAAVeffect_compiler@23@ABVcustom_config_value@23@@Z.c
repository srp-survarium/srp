void __thiscall vostok::render::effect_fill_reflective_shadow_map::compile(
        vostok::render::effect_fill_reflective_shadow_map *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  const char *v9; // [esp+0h] [ebp-20h]
  const char *v10; // [esp+0h] [ebp-20h]
  const char *v11; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration *v12; // [esp+4h] [ebp-1Ch]
  vostok::render::shader_configuration *v13; // [esp+4h] [ebp-1Ch]
  vostok::render::shader_configuration *v14; // [esp+4h] [ebp-1Ch]
  vostok::render::shader_configuration configuration; // [esp+10h] [ebp-10h] BYREF

  *(_DWORD *)&configuration.0 = 0;
  *(unsigned __int64 *)((char *)configuration.configuration + 4) = 0x400000000LL;
  HIDWORD(configuration.configuration[1]) = 0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966A14.m_name.m_string.m_buffer[92],
    (vostok::render::shader_configuration *)"fill_reflective_shadow_map",
    (const char *)&configuration,
    v9,
    v12);
  vostok::render::effect_compiler::end_pass(
    v3,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v4, (int)compiler);
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)&stru_966A14.m_name.m_string.m_buffer[108],
    (const char *)&configuration,
    v10,
    v13);
  vostok::render::effect_compiler::end_pass(
    v5,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v6, (int)compiler);
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)&stru_966A14.m_name.m_string.m_buffer[144],
    (const char *)&configuration,
    v11,
    v14);
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::end_pass(
    v7,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v8, (int)compiler);
}
