void __thiscall vostok::render::effect_distortion_stage_panner_materials::compile(
        vostok::render::effect_distortion_stage_panner_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  const vostok::render::custom_config_value *v3; // eax
  vostok::render::custom_config_value *v4; // ecx
  vostok::render::custom_config_value *v5; // ecx
  const vostok::render::custom_config_value *v6; // eax
  vostok::render::custom_config_value *v7; // ecx
  vostok::render::custom_config_value *v8; // ecx
  const vostok::render::custom_config_value *v9; // eax
  vostok::strings::shared::manager *v10; // ecx
  vostok::strings::shared::profile *v11; // eax
  vostok::strings::shared::manager *v12; // ecx
  vostok::strings::shared::profile *v13; // eax
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::shared_string v16; // [esp-4h] [ebp-3Ch]
  const char *v17; // [esp+0h] [ebp-38h]
  D3D11_STENCIL_OP v18; // [esp+0h] [ebp-38h]
  bool v19; // [esp+0h] [ebp-38h]
  bool v20; // [esp+0h] [ebp-38h]
  D3D11_BLEND_OP v21; // [esp+0h] [ebp-38h]
  vostok::render::shader_configuration *v22; // [esp+4h] [ebp-34h]
  vostok::render::shader_configuration shader_config; // [esp+10h] [ebp-28h] BYREF
  vostok::math::float3 distortion_scale; // [esp+20h] [ebp-18h] BYREF
  vostok::math::float3 panner; // [esp+2Ch] [ebp-Ch] BYREF

  v3 = vostok::render::custom_config_value::operator[](
         (vostok::render::custom_config_value *)this,
         (int)custom_config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"distortion_scale");
  vostok::render::custom_config_value::operator<vostok::math::float3> vostok::math::float3(
    v4,
    (vostok::math::float3 *)&shader_config,
    (int)v3);
  distortion_scale = (vostok::math::float3)shader_config.0;
  v6 = vostok::render::custom_config_value::operator[](
         v5,
         (int)custom_config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"panner");
  vostok::render::custom_config_value::operator<vostok::math::float3> vostok::math::float3(
    v7,
    (vostok::math::float3 *)&shader_config,
    (int)v6);
  panner = (vostok::math::float3)shader_config.0;
  *(_DWORD *)&shader_config.0 = 0;
  *(unsigned __int64 *)((char *)shader_config.configuration + 4) = 0x400000000LL;
  HIDWORD(shader_config.configuration[1]) = 0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    custom_config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)&stru_966378.m_techniques._M_t._M_node_count,
    (const char *)&shader_config,
    v17,
    v22);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    0,
    0x80u,
    0xFFu,
    0xFFu,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_REPLACE,
    v18);
  v9 = vostok::render::custom_config_value::operator[](
         v8,
         (int)custom_config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_distortion");
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &stru_963F84.m_name.m_string.m_buffer[116],
    (char *)v9->data,
    0,
    v19);
  v11 = vostok::strings::shared::manager::string(v10, s_manager.m_variable, "distortion_scale");
  v16.m_pointer.m_object = 0;
  if ( v11 )
  {
    v16.m_pointer.m_object = v11;
    _InterlockedExchangeAdd(&v11->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(&distortion_scale, compiler, v16);
  v13 = vostok::strings::shared::manager::string(v12, s_manager.m_variable, "move_direction");
  if ( v13 )
  {
    _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(&panner, compiler, (vostok::shared_string)v13);
  }
  else
  {
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(&panner, compiler, 0);
  }
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v20);
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
    v21);
  vostok::render::effect_compiler::end_pass(
    v14,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v15, (int)compiler);
}
