void __thiscall vostok::render::effect_debug_tracer::compile(
        vostok::render::effect_debug_tracer *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  const char *v5; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration *v6; // [esp+4h] [ebp-1Ch]
  vostok::render::shader_configuration configuration; // [esp+10h] [ebp-10h] BYREF

  *(_DWORD *)&configuration.0 = 0;
  *(unsigned __int64 *)((char *)configuration.configuration + 4) = 0x400000000LL;
  HIDWORD(configuration.configuration[1]) = 0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)"tracer",
    (const char *)&configuration,
    v5,
    v6);
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
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::end_pass(
    v3,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v4, (int)compiler);
}
