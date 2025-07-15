void __thiscall vostok::render::effect_fstage_sky_materials::compile(
        vostok::render::effect_fstage_sky_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::custom_config_value *v3; // ecx
  const vostok::render::custom_config_value *v4; // eax
  vostok::render::custom_config_value *v5; // ecx
  __int64 *data; // eax
  __int64 v7; // xmm0_8
  __int64 v8; // xmm1_8
  const vostok::render::custom_config_value *v9; // eax
  vostok::render::custom_config_value *v10; // ecx
  double v11; // st7
  vostok::strings::shared::manager *v12; // ecx
  vostok::strings::shared::profile *v13; // eax
  vostok::render::custom_config_value *v14; // ecx
  const vostok::render::custom_config_value *v15; // eax
  bool v16; // zf
  vostok::strings::shared::manager *v17; // ecx
  const vostok::render::custom_config_value *v18; // eax
  vostok::render::custom_config_value *v19; // ecx
  vostok::render::custom_config_value *v20; // ecx
  const vostok::render::custom_config_value *v21; // eax
  vostok::render::custom_config_value *v22; // ecx
  double v23; // st7
  vostok::strings::shared::profile *v24; // eax
  vostok::render::effect_compiler *v25; // ecx
  vostok::strings::shared::profile *v26; // eax
  vostok::render::effect_compiler *v27; // ecx
  vostok::shared_string v28; // [esp-4h] [ebp-34h]
  const char *v29; // [esp+0h] [ebp-30h]
  bool v30; // [esp+0h] [ebp-30h]
  D3D11_STENCIL_OP v31; // [esp+0h] [ebp-30h]
  vostok::render::shader_configuration *v32; // [esp+4h] [ebp-2Ch]
  float fog_power; // [esp+Ch] [ebp-24h]
  vostok::math::float4 sky_color; // [esp+10h] [ebp-20h] BYREF
  float v35[4]; // [esp+20h] [ebp-10h]

  *(_QWORD *)&sky_color.elements[2] = 4;
  *(_QWORD *)&sky_color.x = 0x800000000LL;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_960AE0,
    (vostok::render::shader_configuration *)&stru_960AE0,
    (const char *)&sky_color,
    v29,
    v32);
  v4 = vostok::render::custom_config_value::operator[](
         v3,
         (int)config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"sky_color");
  if ( (`vostok::render::static_type::get_type_id<char const *>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::static_type::get_type_id<char const *>'::`2'::`local static guard' |= 1u;
    LOWORD(`vostok::render::static_type::get_type_id<char const *>'::`2'::current_id) = ++vostok::render::static_type::type_id_counter;
  }
  LOWORD(v5) = (_WORD)`vostok::render::static_type::get_type_id<char const *>'::`2'::current_id;
  if ( v4->type == (_WORD)`vostok::render::static_type::get_type_id<char const *>'::`2'::current_id )
  {
    v7 = *(_QWORD *)&v4->data;
    v8 = *(_QWORD *)&v4->type;
  }
  else
  {
    data = (__int64 *)v4->data;
    v7 = *data;
    v8 = data[1];
  }
  *(_QWORD *)v35 = v7;
  *(_QWORD *)&sky_color.x = v7;
  *(_QWORD *)&sky_color.elements[2] = v8;
  v9 = vostok::render::custom_config_value::operator[](
         v5,
         (int)config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"sky_color_multiplier");
  v11 = vostok::render::custom_config_value::operator<float> float(v10, (int)v9);
  sky_color.x = v35[0] * v11;
  sky_color.y = sky_color.y * v11;
  sky_color.z = v11 * sky_color.z;
  v13 = vostok::strings::shared::manager::string(v12, s_manager.m_variable, "sky_color");
  if ( v13 )
  {
    _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&sky_color,
      compiler,
      (vostok::shared_string)v13);
  }
  else
  {
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&sky_color,
      compiler,
      0);
  }
  v15 = vostok::render::custom_config_value::operator[](
          v14,
          (int)config,
          (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_emissive");
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &stru_963F84.m_name.m_string.m_buffer[116],
    (char *)v15->data,
    0,
    v30);
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
          D3D11_BLEND_SRC_COLOR,
          D3D11_BLEND_OP_ADD,
          D3D11_BLEND_ZERO,
          D3D11_BLEND_OP_ADD,
          &compiler->m_state_descriptor,
          1,
          D3D11_BLEND_ZERO,
          (D3D11_BLEND)v31);
    }
  }
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v31);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      v16 = compiler->m_state_descriptor.m_rasterizer_desc.CullMode == D3D11_CULL_NONE;
      compiler->m_state_descriptor.m_rasterizer_desc.CullMode = D3D11_CULL_NONE;
      compiler->m_state_descriptor.m_rasterizer_desc_updated |= !v16;
    }
  }
  if ( !vostok::render::custom_config_value::value_exists(&stru_9681A8, (int)config)
    || !vostok::render::custom_config_value::value_exists(
          (vostok::render::custom_config_value *)&stru_9681A8.destroyer,
          (int)config) )
  {
    LODWORD(sky_color.x) = clear_value;
    *(_QWORD *)&sky_color.elements[1] = 1048576000;
    sky_color.w = 0.0;
    v26 = vostok::strings::shared::manager::string(v17, s_manager.m_variable, "fog_power_and_range");
    v28.m_pointer.m_object = 0;
    if ( v26 )
    {
      v28.m_pointer.m_object = v26;
      _InterlockedExchangeAdd(&v26->m_reference_count, 1u);
    }
    goto LABEL_30;
  }
  v18 = vostok::render::custom_config_value::operator[](
          (vostok::render::custom_config_value *)v17,
          (int)config,
          (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9681A8);
  fog_power = vostok::render::custom_config_value::operator<float> float(v19, (int)v18);
  v21 = vostok::render::custom_config_value::operator[](
          v20,
          (int)config,
          (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9681A8.destroyer);
  v23 = vostok::render::custom_config_value::operator<float> float(v22, (int)v21);
  sky_color.x = fog_power;
  sky_color.y = v23;
  *(_QWORD *)&sky_color.elements[2] = 0;
  v24 = vostok::strings::shared::manager::string(s_manager.m_variable, s_manager.m_variable, "fog_power_and_range");
  v28.m_pointer.m_object = 0;
  if ( !v24 )
  {
LABEL_30:
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&sky_color,
      compiler,
      v28);
    goto LABEL_31;
  }
  _InterlockedExchangeAdd(&v24->m_reference_count, 1u);
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&sky_color,
    compiler,
    (vostok::shared_string)v24);
LABEL_31:
  vostok::render::effect_compiler::end_pass(
    v25,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v27, (int)compiler);
}
