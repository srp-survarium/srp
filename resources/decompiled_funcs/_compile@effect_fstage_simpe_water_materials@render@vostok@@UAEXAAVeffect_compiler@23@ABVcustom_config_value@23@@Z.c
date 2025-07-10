void __thiscall vostok::render::effect_fstage_simpe_water_materials::compile(
        vostok::render::effect_fstage_simpe_water_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  char *v3; // eax
  vostok::render::custom_config_value *v4; // ecx
  const vostok::render::custom_config_value *v5; // eax
  vostok::render::custom_config_value *v6; // ecx
  const vostok::render::custom_config_value *v7; // eax
  vostok::render::custom_config_value *v8; // ecx
  vostok::render::custom_config_value *v9; // ecx
  const vostok::render::custom_config_value *v10; // eax
  vostok::render::custom_config_value *v11; // ecx
  double v12; // st7
  vostok::strings::shared::profile *v13; // eax
  vostok::render::effect_compiler *v14; // ecx
  bool v15; // zf
  vostok::render::effect_compiler *v16; // ecx
  const char *v17; // [esp+DCh] [ebp-80h]
  bool v18; // [esp+DCh] [ebp-80h]
  bool v19; // [esp+DCh] [ebp-80h]
  bool v20; // [esp+DCh] [ebp-80h]
  bool v21; // [esp+DCh] [ebp-80h]
  bool v22; // [esp+DCh] [ebp-80h]
  bool v23; // [esp+DCh] [ebp-80h]
  bool v24; // [esp+DCh] [ebp-80h]
  bool v25; // [esp+DCh] [ebp-80h]
  bool v26; // [esp+DCh] [ebp-80h]
  bool v27; // [esp+DCh] [ebp-80h]
  vostok::render::shader_configuration *v28; // [esp+E0h] [ebp-7Ch]
  unsigned int i; // [esp+F0h] [ebp-6Ch]
  int v30; // [esp+F4h] [ebp-68h]
  int v31; // [esp+F8h] [ebp-64h]
  float v32; // [esp+110h] [ebp-4Ch]
  char geometry_shader_name[4]; // [esp+11Ch] [ebp-40h] BYREF
  int v34; // [esp+120h] [ebp-3Ch]
  int v35; // [esp+124h] [ebp-38h]
  int v36; // [esp+128h] [ebp-34h]
  vostok::math::float4 source; // [esp+12Ch] [ebp-30h] BYREF
  __m128i v38; // [esp+13Ch] [ebp-20h] BYREF
  vostok::math::float4 _X; // [esp+14Ch] [ebp-10h] BYREF

  *(_DWORD *)geometry_shader_name = 8;
  v35 = 4;
  v34 = 0;
  v36 = 0;
  for ( i = 0; i < 2; ++i )
  {
    v3 = "forward_simple_water";
    if ( i )
      v3 = "forward_simple_water_local_reflections";
    vostok::render::effect_material_base::compile_begin(
      compiler,
      custom_config,
      (vostok::render::effect_material_base *)&stru_966284,
      (vostok::render::shader_configuration *)v3,
      geometry_shader_name,
      v17,
      v28);
    v5 = vostok::render::custom_config_value::operator[](
           v4,
           (int)custom_config,
           (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_reflection");
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_reflection", (char *)v5->data, 0, v18);
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      (const char *)&stru_96940C.destroyer,
      "engine/water_waves2",
      0,
      v19);
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v20);
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_normal", "$user$normal", 0, v21);
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      (const char *)&stru_9642F8.m_desc.ArraySize,
      "$user$albedo",
      0,
      v22);
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_frame_color", "$user$generic1", 0, v23);
    *(_QWORD *)&source.x = __PAIR64__((unsigned int)clear_value, LODWORD(FLOAT_0_5));
    *(_QWORD *)&source.elements[2] = __PAIR64__((unsigned int)clear_value, LODWORD(FLOAT_0_5));
    if ( vostok::render::custom_config_value::value_exists(&stru_96983C, (int)custom_config) )
    {
      v7 = vostok::render::custom_config_value::operator[](
             v6,
             (int)custom_config,
             (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_96983C);
      vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v8, &_X, (int)v7);
      *(float *)&v31 = powf(_X.z, 2.2);
      *(float *)&v30 = powf(_X.y, 2.2);
      v32 = powf(_X.x, 2.2);
      v10 = vostok::render::custom_config_value::operator[](
              v9,
              (int)custom_config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_96983C.destroyer);
      v12 = vostok::render::custom_config_value::operator<float> float(v11, (int)v10);
      *(float *)v38.m128i_i32 = v32;
      v38.m128i_i32[1] = v30;
      v38.m128i_i32[2] = v31;
      *(float *)&v38.m128i_i32[3] = v12;
      source = (vostok::math::float4)_mm_load_si128(&v38);
    }
    v13 = vostok::strings::shared::manager::string(
            (vostok::strings::shared::manager *)v6,
            s_manager.m_variable,
            "packed_water_parameters_0");
    if ( v13 )
    {
      _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        (vostok::render::effect_constant_storage *)&source,
        compiler,
        (vostok::shared_string)v13);
    }
    else
    {
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        (vostok::render::effect_constant_storage *)&source,
        compiler,
        0);
    }
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      "t_rain_shadow_map",
      &stru_963F84.m_name.m_string.m_buffer[92],
      0,
      v24);
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      "t_puddle_rings",
      "engine/rain_puddle_rings",
      0,
      v25);
    if ( i )
    {
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
        if ( !compiler->m_shaders_cache_mode )
        {
          if ( s_no_effect_result.m_type == type_unset )
          {
            s_no_effect_result.m_type = type_recursive;
            vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
          }
          if ( s_no_effect_result.m_type == type_recursive )
            vostok::render::state_descriptor::set_alpha_blend(
              D3D11_BLEND_ZERO,
              D3D11_BLEND_OP_ADD,
              D3D11_BLEND_ZERO,
              D3D11_BLEND_OP_ADD,
              &compiler->m_state_descriptor,
              0,
              D3D11_BLEND_ONE,
              (D3D11_BLEND)v17);
          goto LABEL_30;
        }
      }
    }
    else
    {
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        "t_local_reflections_result",
        "$user$local_reflection_result",
        0,
        (bool)v17);
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        "t_local_reflections_result_params",
        "$user$local_reflection_result_params",
        0,
        v26);
      vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_water_waves", "engine/water_waves", 0, v27);
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
        if ( !compiler->m_shaders_cache_mode )
        {
          if ( s_no_effect_result.m_type == type_unset )
          {
            s_no_effect_result.m_type = type_recursive;
            vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
          }
          if ( s_no_effect_result.m_type == type_recursive )
            vostok::render::state_descriptor::set_alpha_blend(
              D3D11_BLEND_INV_SRC_ALPHA,
              D3D11_BLEND_OP_ADD,
              D3D11_BLEND_ZERO,
              D3D11_BLEND_OP_ADD,
              &compiler->m_state_descriptor,
              0,
              D3D11_BLEND_SRC_ALPHA,
              (D3D11_BLEND)v17);
LABEL_30:
          if ( !compiler->m_shaders_cache_mode )
          {
            if ( s_no_effect_result.m_type == type_unset )
            {
              s_no_effect_result.m_type = type_recursive;
              vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
            }
            if ( s_no_effect_result.m_type == type_recursive )
            {
              v15 = compiler->m_state_descriptor.m_rasterizer_desc.CullMode == D3D11_CULL_BACK;
              compiler->m_state_descriptor.m_rasterizer_desc.CullMode = D3D11_CULL_BACK;
              LOBYTE(v14) = !v15;
              compiler->m_state_descriptor.m_rasterizer_desc_updated |= !v15;
            }
          }
        }
      }
    }
    vostok::render::effect_compiler::end_pass(
      v14,
      (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
    vostok::render::effect_compiler::end_technique(v16, (int)compiler);
  }
}
