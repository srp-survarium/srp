void __thiscall vostok::render::effect_motion_vectors_accumulation::compile(
        vostok::render::effect_motion_vectors_accumulation *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::custom_config_value *v3; // ecx
  char data; // al
  char v5; // bl
  vostok::render::custom_config_value *v6; // ecx
  char v7; // al
  vostok::render::custom_config_value *v8; // ecx
  char v9; // bl
  const vostok::render::custom_config_value *v10; // eax
  const vostok::render::custom_config_value *v11; // eax
  vostok::render::custom_config_value *v12; // ecx
  vostok::strings::shared::profile *v13; // eax
  vostok::render::effect_constant_storage *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::shared_string v17; // [esp-4h] [ebp-24h]
  const char *v18; // [esp+0h] [ebp-20h]
  bool v19; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration *v20; // [esp+4h] [ebp-1Ch]
  float alpha_ref; // [esp+Ch] [ebp-14h] BYREF
  vostok::render::shader_configuration configuration; // [esp+10h] [ebp-10h] BYREF

  *(_DWORD *)&configuration.0 = 0;
  *(unsigned __int64 *)((char *)configuration.configuration + 4) = 0x400000000LL;
  HIDWORD(configuration.configuration[1]) = 0;
  if ( vostok::render::custom_config_value::value_exists(&stru_960A44, (int)config) )
    data = (char)vostok::render::custom_config_value::operator[](
                   v3,
                   (int)config,
                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_960A44)->data;
  else
    data = 0;
  v5 = 2 * (data & 1);
  if ( vostok::render::custom_config_value::value_exists(&stru_9667A8, (int)config) )
    v7 = (char)vostok::render::custom_config_value::operator[](
                 v6,
                 (int)config,
                 (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9667A8)->data;
  else
    v7 = 0;
  *(_BYTE *)&configuration.0 = (v5 ^ v7) & 1 ^ v5;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)&stru_9667A8.destroyer,
    (const char *)&configuration,
    v18,
    v20);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      LOBYTE(alpha_ref) = 0;
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
  v9 = (char)configuration.0;
  alpha_ref = 0.25;
  if ( (*(_BYTE *)&configuration.0 & 1) != 0 )
  {
    v10 = vostok::render::custom_config_value::operator[](
            v8,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (char *)v10->data,
      0,
      v19);
  }
  if ( (v9 & 2) != 0 && vostok::render::custom_config_value::value_exists(&stru_9667FC, (int)config) )
  {
    v11 = vostok::render::custom_config_value::operator[](
            v8,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9667FC);
    alpha_ref = vostok::render::custom_config_value::operator<float> float(v12, (int)v11);
  }
  v13 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v8,
          s_manager.m_variable,
          (const char *)&stru_9667FC.type);
  v17.m_pointer.m_object = 0;
  if ( v13 )
  {
    v17.m_pointer.m_object = v13;
    v14 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v13->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&alpha_ref, v14, compiler, v17);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::end_pass(
    v15,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v16, (int)compiler);
}
