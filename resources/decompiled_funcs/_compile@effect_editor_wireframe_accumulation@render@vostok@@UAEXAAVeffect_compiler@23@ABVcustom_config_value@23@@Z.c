void __userpurge vostok::render::effect_editor_wireframe_accumulation::compile(
        vostok::render::effect_editor_wireframe_accumulation *this@<ecx>,
        const char *a2@<edi>,
        vostok::render::shader_configuration *a3@<esi>,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  const void *data; // edi
  vostok::math::float3 *v6; // eax
  int v7; // ecx
  vostok::render::custom_config_value *v8; // ecx
  bool v9; // zf
  vostok::strings::shared::profile *v10; // eax
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::strings::shared::manager *v13; // ecx
  vostok::strings::shared::profile *v14; // eax
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::shared_string v17; // [esp-10h] [ebp-ECh]
  const char *v19; // [esp-Ch] [ebp-E8h]
  vostok::render::shader_configuration *v20; // [esp-8h] [ebp-E4h]
  __int64 v21; // [esp+0h] [ebp-DCh]
  __int64 v22; // [esp+0h] [ebp-DCh]
  const vostok::math::float3 *predicate; // [esp+10h] [ebp-CCh]
  vostok::render::shader_configuration configuration; // [esp+14h] [ebp-C8h] BYREF
  vostok::math::float3 wireframe_colors[15]; // [esp+24h] [ebp-B8h] BYREF

  data = 0;
  LODWORD(v21) = 0;
  *((float *)&v21 + 1) = FLOAT_0_5;
  *(_DWORD *)&configuration.0 = 0;
  *(unsigned __int64 *)((char *)configuration.configuration + 4) = 0x400000000LL;
  HIDWORD(configuration.configuration[1]) = 0;
  v6 = wireframe_colors;
  v7 = 15;
  do
  {
    *(_QWORD *)&v6->x = v21;
    v6->z = FLOAT_0_5;
    ++v6;
    --v7;
  }
  while ( v7 );
  *(_QWORD *)&wireframe_colors[3].x = 0x3E80000000000000LL;
  *(_QWORD *)&wireframe_colors[4].x = 0x3E80000000000000LL;
  wireframe_colors[3].z = 0.75;
  *(_QWORD *)&wireframe_colors[6].x = 0x3E80000000000000LL;
  *(_QWORD *)&wireframe_colors[9].x = (unsigned int)clear_value | 0x3E80000000000000LL;
  *(_QWORD *)&wireframe_colors[8].x = *(_QWORD *)&wireframe_colors[9].x;
  *(_QWORD *)&wireframe_colors[7].x = *(_QWORD *)&wireframe_colors[9].x;
  wireframe_colors[6].z = 0.75;
  wireframe_colors[4].z = 0.75;
  *(_QWORD *)&wireframe_colors[11].x = LODWORD(FLOAT_0_1) | 0x3F40000000000000LL;
  wireframe_colors[5].z = 0.75;
  wireframe_colors[9].z = 0.25;
  wireframe_colors[8].z = 0.25;
  wireframe_colors[7].z = 0.25;
  wireframe_colors[11].z = FLOAT_0_1;
  LODWORD(v22) = 1060320051;
  *((float *)&v22 + 1) = FLOAT_0_5;
  *(_QWORD *)&wireframe_colors[5].x = 0x3E80000000000000LL;
  *(_QWORD *)&wireframe_colors[13].x = v22;
  wireframe_colors[13].z = FLOAT_0_1;
  if ( vostok::render::custom_config_value::value_exists(&key, (int)config) )
    data = vostok::render::custom_config_value::operator[](
             v8,
             (int)config,
             (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&key)->data;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)&stru_967C04.m_desc.MiscFlags,
    (const char *)&configuration,
    a2,
    a3);
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
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      v9 = compiler->m_state_descriptor.m_rasterizer_desc.FillMode == D3D11_FILL_WIREFRAME;
      compiler->m_state_descriptor.m_rasterizer_desc.FillMode = D3D11_FILL_WIREFRAME;
      compiler->m_state_descriptor.m_rasterizer_desc_updated |= !v9;
    }
  }
  predicate = &wireframe_colors[(_DWORD)data];
  v10 = vostok::strings::shared::manager::string(
          s_manager.m_variable,
          s_manager.m_variable,
          (const char *)&stru_967C04.m_desc_3d.CPUAccessFlags);
  if ( v10 )
  {
    _InterlockedExchangeAdd(&v10->m_reference_count, 1u);
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(predicate, compiler, (vostok::shared_string)v10);
  }
  else
  {
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(predicate, compiler, 0);
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
      v9 = compiler->m_state_descriptor.m_rasterizer_desc.CullMode == D3D11_CULL_BACK;
      compiler->m_state_descriptor.m_rasterizer_desc.CullMode = D3D11_CULL_BACK;
      LOBYTE(v11) = !v9;
      compiler->m_state_descriptor.m_rasterizer_desc_updated |= !v9;
    }
  }
  vostok::render::effect_compiler::end_pass(
    v11,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v12, (int)compiler);
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)&stru_967C04.m_desc.MiscFlags,
    (const char *)&configuration,
    v19,
    v20);
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
    if ( !compiler->m_shaders_cache_mode )
    {
      if ( s_no_effect_result.m_type == type_unset )
      {
        s_no_effect_result.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      }
      if ( s_no_effect_result.m_type == type_recursive )
      {
        v9 = compiler->m_state_descriptor.m_rasterizer_desc.FillMode == D3D11_FILL_WIREFRAME;
        compiler->m_state_descriptor.m_rasterizer_desc.FillMode = D3D11_FILL_WIREFRAME;
        compiler->m_state_descriptor.m_rasterizer_desc_updated |= !v9;
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
          v9 = compiler->m_state_descriptor.m_rasterizer_desc.CullMode == D3D11_CULL_NONE;
          compiler->m_state_descriptor.m_rasterizer_desc.CullMode = D3D11_CULL_NONE;
          LOBYTE(v13) = !v9;
          compiler->m_state_descriptor.m_rasterizer_desc_updated |= !v9;
        }
      }
    }
  }
  v14 = vostok::strings::shared::manager::string(
          v13,
          s_manager.m_variable,
          (const char *)&stru_967C04.m_desc_3d.CPUAccessFlags);
  v17.m_pointer.m_object = 0;
  if ( v14 )
  {
    v17.m_pointer.m_object = v14;
    _InterlockedExchangeAdd(&v14->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(predicate, compiler, v17);
  vostok::render::effect_compiler::end_pass(
    v15,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v16, (int)compiler);
}
