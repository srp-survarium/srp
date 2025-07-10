void __thiscall vostok::render::effect_shadow_map::compile(
        vostok::render::effect_shadow_map *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *__formal)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::strings::shared::profile *v4; // eax
  vostok::render::effect_constant_storage *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::strings::shared::manager *v10; // ecx
  vostok::strings::shared::profile *v11; // eax
  vostok::render::effect_constant_storage *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  const vostok::math::float4x4 *source; // [esp+Ch] [ebp-14h] BYREF
  vostok::render::shader_configuration configuration; // [esp+10h] [ebp-10h] BYREF

  *(_DWORD *)&configuration.0 = 0;
  *(unsigned __int64 *)((char *)configuration.configuration + 4) = 0x400000000LL;
  HIDWORD(configuration.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  vostok::render::effect_compiler::begin_pass(
    v3,
    compiler,
    (char *)&stru_966860,
    0,
    (vostok::render::shader_configuration *)&stru_96684C,
    &configuration);
  source = clear_value;
  v4 = vostok::strings::shared::manager::string(s_manager.m_variable, s_manager.m_variable, (const char *)&stru_966874);
  if ( v4 )
  {
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
    vostok::render::effect_compiler::set_constant<float>(
      (const float *)&source,
      v5,
      compiler,
      (vostok::shared_string)v4);
  }
  else
  {
    vostok::render::effect_compiler::set_constant<float>((const float *)&source, v5, compiler, 0);
  }
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      LOBYTE(source) = 0;
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
  vostok::render::effect_compiler::color_write_enable(v6, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::end_pass(
    v7,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v8, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v9, (int)compiler);
  vostok::render::effect_compiler::begin_pass(
    (vostok::render::effect_compiler *)&configuration,
    compiler,
    (char *)&stru_96689C,
    0,
    (vostok::render::shader_configuration *)&stru_966874.type,
    &configuration);
  source = clear_value;
  v11 = vostok::strings::shared::manager::string(v10, s_manager.m_variable, (const char *)&stru_966874);
  if ( v11 )
    vostok::render::effect_compiler::set_constant<float>(
      (const float *)&source,
      (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v11->m_reference_count, 1u),
      compiler,
      (vostok::shared_string)v11);
  else
    vostok::render::effect_compiler::set_constant<float>((const float *)&source, v12, compiler, 0);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      LOBYTE(source) = 0;
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
  vostok::render::effect_compiler::color_write_enable(v13, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::end_pass(
    v14,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v15, (int)compiler);
}
