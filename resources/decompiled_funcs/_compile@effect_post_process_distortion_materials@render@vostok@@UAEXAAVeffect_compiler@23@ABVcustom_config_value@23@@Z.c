void __thiscall vostok::render::effect_post_process_distortion_materials::compile(
        vostok::render::effect_post_process_distortion_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  const vostok::render::custom_config_value *v3; // eax
  vostok::render::custom_config_value *v4; // ecx
  vostok::render::custom_config_value *v5; // ecx
  const vostok::render::custom_config_value *v6; // eax
  vostok::strings::shared::profile *v7; // eax
  vostok::render::effect_constant_storage *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  const char *v11; // [esp+0h] [ebp-20h]
  bool v12; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v13; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration *v14; // [esp+4h] [ebp-1Ch]
  float distortion_scale; // [esp+Ch] [ebp-14h] BYREF
  vostok::render::shader_configuration shader_config; // [esp+10h] [ebp-10h] BYREF

  v3 = vostok::render::custom_config_value::operator[](
         (vostok::render::custom_config_value *)this,
         (int)custom_config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_distortion_scale");
  distortion_scale = vostok::render::custom_config_value::operator<float> float(v4, (int)v3);
  *(_DWORD *)&shader_config.0 = 0;
  *(unsigned __int64 *)((char *)shader_config.configuration + 4) = 0x400000000LL;
  HIDWORD(shader_config.configuration[1]) = 0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    custom_config,
    (vostok::render::effect_material_base *)&stru_95F7AC,
    (vostok::render::shader_configuration *)&stru_966430.m_shaders._M_t._M_header._M_data._M_parent,
    (const char *)&shader_config,
    v11,
    v14);
  v6 = vostok::render::custom_config_value::operator[](
         v5,
         (int)custom_config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_base");
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &stru_963F84.m_name.m_string.m_buffer[116],
    (char *)v6->data,
    0,
    v12);
  v7 = vostok::strings::shared::manager::string(s_manager.m_variable, s_manager.m_variable, "distortion_scale");
  if ( v7 )
  {
    _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
    vostok::render::effect_compiler::set_constant<float>(&distortion_scale, v8, compiler, (vostok::shared_string)v7);
  }
  else
  {
    vostok::render::effect_compiler::set_constant<float>(&distortion_scale, v8, compiler, 0);
  }
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      LOBYTE(distortion_scale) = 0;
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
    v13);
  vostok::render::effect_compiler::end_pass(
    v9,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v10, (int)compiler);
}
