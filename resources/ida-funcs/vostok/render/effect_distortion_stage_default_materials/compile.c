void __thiscall vostok::render::effect_distortion_stage_default_materials::compile(
        vostok::render::effect_distortion_stage_default_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  const vostok::render::custom_config_value *v3; // eax
  vostok::render::custom_config_value *v4; // ecx
  vostok::render::custom_config_value *v5; // ecx
  const vostok::render::custom_config_value *v6; // eax
  vostok::strings::shared::manager *v7; // ecx
  vostok::strings::shared::profile *v8; // eax
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  const char *v11; // [esp+0h] [ebp-30h]
  D3D11_STENCIL_OP v12; // [esp+0h] [ebp-30h]
  bool v13; // [esp+0h] [ebp-30h]
  bool v14; // [esp+0h] [ebp-30h]
  D3D11_BLEND_OP v15; // [esp+0h] [ebp-30h]
  vostok::render::shader_configuration *v16; // [esp+4h] [ebp-2Ch]
  vostok::render::shader_configuration shader_config; // [esp+10h] [ebp-20h] BYREF
  vostok::math::float3 distortion_scale; // [esp+24h] [ebp-Ch] BYREF

  v3 = vostok::render::custom_config_value::operator[](
         (vostok::render::custom_config_value *)this,
         (int)config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"distortion_scale");
  vostok::render::custom_config_value::operator<vostok::math::float3> vostok::math::float3(
    v4,
    (vostok::math::float3 *)&shader_config,
    (int)v3);
  distortion_scale = (vostok::math::float3)shader_config.0;
  *(_DWORD *)&shader_config.0 = 0;
  *(unsigned __int64 *)((char *)shader_config.configuration + 4) = 0x400000000LL;
  HIDWORD(shader_config.configuration[1]) = 0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)"distortion_base",
    (const char *)&shader_config,
    v11,
    v16);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    0,
    0x80u,
    0xFFu,
    0xFFu,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_REPLACE,
    v12);
  v6 = vostok::render::custom_config_value::operator[](
         v5,
         (int)config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_distortion");
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &stru_963F84.m_name.m_string.m_buffer[116],
    (char *)v6->data,
    0,
    v13);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v14);
  v8 = vostok::strings::shared::manager::string(v7, s_manager.m_variable, "distortion_scale");
  if ( v8 )
  {
    _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(
      &distortion_scale,
      compiler,
      (vostok::shared_string)v8);
  }
  else
  {
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(&distortion_scale, compiler, 0);
  }
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
    D3D11_BLEND_ONE,
    compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v15);
  vostok::render::effect_compiler::end_pass(
    v9,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v10, (int)compiler);
}
