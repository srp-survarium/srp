void __thiscall vostok::render::depth_accumulate_material_effect::compile(
        vostok::render::depth_accumulate_material_effect *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::custom_config_value *v3; // ecx
  vostok::render::custom_config_value *v4; // ecx
  char data; // al
  vostok::render::custom_config_value *v6; // ecx
  vostok::render::custom_config_value *v7; // ecx
  const vostok::render::custom_config_value *v8; // eax
  vostok::strings::shared::profile *v9; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v10; // edx
  int v11; // ecx
  const vostok::render::custom_config_value *v12; // eax
  vostok::render::custom_config_value *v13; // ecx
  vostok::strings::shared::manager *v14; // ecx
  vostok::strings::shared::profile *v15; // eax
  vostok::render::effect_constant_storage *v16; // ecx
  vostok::render::custom_config_value *v17; // ecx
  const vostok::render::custom_config_value *v18; // eax
  vostok::render::custom_config_value *v19; // ecx
  vostok::strings::shared::profile *v20; // eax
  vostok::render::effect_constant_storage *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::custom_config_value *v25; // ecx
  bool v26; // al
  const vostok::render::custom_config_value *v27; // eax
  vostok::strings::shared::profile *v28; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v29; // edx
  int v30; // ecx
  const vostok::render::custom_config_value *v31; // eax
  vostok::render::custom_config_value *v32; // ecx
  vostok::strings::shared::profile *v33; // eax
  vostok::render::effect_constant_storage *v34; // ecx
  vostok::render::custom_config_value *v35; // ecx
  const vostok::render::custom_config_value *v36; // eax
  vostok::render::custom_config_value *v37; // ecx
  vostok::strings::shared::manager *v38; // ecx
  vostok::strings::shared::profile *v39; // eax
  vostok::render::effect_constant_storage *v40; // ecx
  vostok::strings::shared::profile *v41; // eax
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::shared_string v45; // [esp-8h] [ebp-38h]
  vostok::shared_string v46; // [esp-8h] [ebp-38h]
  vostok::shared_string v47; // [esp-4h] [ebp-34h]
  unsigned int v48; // [esp-4h] [ebp-34h]
  vostok::shared_string v49; // [esp-4h] [ebp-34h]
  vostok::shared_string v50; // [esp-4h] [ebp-34h]
  const char *v51; // [esp+0h] [ebp-30h]
  const char *v52; // [esp+0h] [ebp-30h]
  vostok::render::shader_configuration *v53; // [esp+4h] [ebp-2Ch]
  vostok::render::shader_configuration *v54; // [esp+4h] [ebp-2Ch]
  bool is_static_mesh; // [esp+12h] [ebp-1Eh]
  bool v56; // [esp+13h] [ebp-1Dh]
  bool v57; // [esp+13h] [ebp-1Dh]
  float alpha_ref; // [esp+14h] [ebp-1Ch] BYREF
  vostok::command_line::key_initializator predicate[4]; // [esp+18h] [ebp-18h]
  unsigned int debug_last_mips; // [esp+1Ch] [ebp-14h] BYREF
  vostok::render::shader_configuration configuration; // [esp+20h] [ebp-10h] BYREF

  is_static_mesh = 0;
  if ( vostok::render::custom_config_value::value_exists(&key, (int)config) )
    is_static_mesh = vostok::render::custom_config_value::operator[](
                       v3,
                       (int)config,
                       (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&key)->data != (const void *)11;
  *(_DWORD *)&configuration.0 = 0;
  *(unsigned __int64 *)((char *)configuration.configuration + 4) = 0x400000000LL;
  HIDWORD(configuration.configuration[1]) = 0;
  debug_last_mips = is_static_mesh ? 5 : -1;
  if ( vostok::render::custom_config_value::value_exists(&stru_960A44, (int)config) )
    data = (char)vostok::render::custom_config_value::operator[](
                   v4,
                   (int)config,
                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_960A44)->data;
  else
    data = 0;
  *(_BYTE *)&configuration.0 = 2 * (data & 1);
  if ( vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)&stru_960A44.destroyer,
         (int)config) )
  {
    *((_BYTE *)&configuration.0 + 4) ^= (*((_BYTE *)&configuration.0 + 4)
                                       ^ (16
                                        * (int)vostok::render::custom_config_value::operator[](
                                                 v6,
                                                 (int)config,
                                                 (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_960A44.destroyer)->data))
                                      & 0x70;
  }
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966860,
    (vostok::render::shader_configuration *)&stru_96684C,
    (const char *)&configuration,
    v51,
    v53);
  v56 = (*(_BYTE *)&configuration.0 & 2) != 0;
  if ( (*(_BYTE *)&configuration.0 & 2) != 0 )
  {
    v8 = vostok::render::custom_config_value::operator[](
           v7,
           (int)config,
           (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_diffuse");
    v9 = vostok::strings::shared::manager::string(s_manager.m_variable, s_manager.m_variable, (const char *)v8->data);
    v45.m_pointer.m_object = 0;
    if ( v9 )
    {
      v45.m_pointer.m_object = v9;
      v10 = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)_InterlockedExchangeAdd(&v9->m_reference_count, 1u);
    }
    LOBYTE(v10) = is_static_mesh;
    vostok::render::effect_compiler::set_texture(
      v11,
      v10,
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      v45,
      is_static_mesh ? 5 : -1);
  }
  if ( (*((_BYTE *)&configuration.0 + 4) & 0x70) != 0
    && vostok::render::custom_config_value::value_exists(&stru_966874, (int)config) )
  {
    v12 = vostok::render::custom_config_value::operator[](
            v7,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966874);
    alpha_ref = vostok::render::custom_config_value::operator<float> float(v13, (int)v12);
    v15 = vostok::strings::shared::manager::string(v14, s_manager.m_variable, (const char *)&stru_966874);
  }
  else
  {
    alpha_ref = *(float *)&clear_value;
    v15 = vostok::strings::shared::manager::string(
            (vostok::strings::shared::manager *)v7,
            s_manager.m_variable,
            (const char *)&stru_966874);
  }
  v47.m_pointer.m_object = 0;
  if ( v15 )
  {
    v47.m_pointer.m_object = v15;
    v16 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v15->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&alpha_ref, v16, compiler, v47);
  alpha_ref = 0.25;
  if ( v56 && vostok::render::custom_config_value::value_exists(&stru_9667FC, (int)config) )
  {
    v18 = vostok::render::custom_config_value::operator[](
            v17,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9667FC);
    alpha_ref = vostok::render::custom_config_value::operator<float> float(v19, (int)v18);
  }
  v20 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v17,
          s_manager.m_variable,
          (const char *)&stru_9667FC.type);
  if ( v20 )
    vostok::render::effect_compiler::set_constant<float>(
      &alpha_ref,
      (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v20->m_reference_count, 1u),
      compiler,
      (vostok::shared_string)v20);
  else
    vostok::render::effect_compiler::set_constant<float>(&alpha_ref, v21, compiler, 0);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      predicate[0] = 0;
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
  vostok::render::effect_compiler::color_write_enable(v22, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::end_pass(
    v23,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v24, (int)compiler);
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_96689C,
    (vostok::render::shader_configuration *)&stru_966874.type,
    (const char *)&configuration,
    v52,
    v54);
  v26 = (*(_BYTE *)&configuration.0 & 2) != 0;
  v57 = v26;
  if ( (*(_BYTE *)&configuration.0 & 2) != 0 )
  {
    v27 = vostok::render::custom_config_value::operator[](
            v25,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_diffuse");
    v48 = debug_last_mips;
    v28 = vostok::strings::shared::manager::string(
            (vostok::strings::shared::manager *)debug_last_mips,
            s_manager.m_variable,
            (const char *)v27->data);
    v46.m_pointer.m_object = 0;
    if ( v28 )
    {
      v46.m_pointer.m_object = v28;
      v30 = _InterlockedExchangeAdd(&v28->m_reference_count, 1u);
    }
    LOBYTE(v29) = is_static_mesh;
    vostok::render::effect_compiler::set_texture(
      v30,
      v29,
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      v46,
      v48);
    v26 = v57;
  }
  if ( v26 && vostok::render::custom_config_value::value_exists(&stru_9667FC, (int)config) )
  {
    v31 = vostok::render::custom_config_value::operator[](
            v25,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9667FC);
    alpha_ref = vostok::render::custom_config_value::operator<float> float(v32, (int)v31);
  }
  v33 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v25,
          s_manager.m_variable,
          (const char *)&stru_9667FC.type);
  v49.m_pointer.m_object = 0;
  if ( v33 )
  {
    v49.m_pointer.m_object = v33;
    v34 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v33->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&alpha_ref, v34, compiler, v49);
  if ( (*((_BYTE *)&configuration.0 + 4) & 0x70) != 0
    && vostok::render::custom_config_value::value_exists(&stru_966874, (int)config) )
  {
    v36 = vostok::render::custom_config_value::operator[](
            v35,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966874);
    *(float *)&debug_last_mips = vostok::render::custom_config_value::operator<float> float(v37, (int)v36);
    v39 = vostok::strings::shared::manager::string(v38, s_manager.m_variable, (const char *)&stru_966874);
    v50.m_pointer.m_object = 0;
    if ( v39 )
    {
      v50.m_pointer.m_object = v39;
      v40 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v39->m_reference_count, 1u);
    }
  }
  else
  {
    debug_last_mips = (unsigned int)clear_value;
    v41 = vostok::strings::shared::manager::string(
            (vostok::strings::shared::manager *)v35,
            s_manager.m_variable,
            (const char *)&stru_966874);
    v50.m_pointer.m_object = 0;
    if ( v41 )
    {
      vostok::render::effect_compiler::set_constant<float>(
        (const float *)&debug_last_mips,
        (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v41->m_reference_count, 1u),
        compiler,
        (vostok::shared_string)v41);
      goto LABEL_46;
    }
  }
  vostok::render::effect_compiler::set_constant<float>((const float *)&debug_last_mips, v40, compiler, v50);
LABEL_46:
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      LOBYTE(debug_last_mips) = 0;
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
  vostok::render::effect_compiler::color_write_enable(v42, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::end_pass(
    v43,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v44, (int)compiler);
}
