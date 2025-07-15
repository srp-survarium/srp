void __thiscall vostok::render::effect_sky_sphere_default_materials::compile(
        vostok::render::effect_sky_sphere_default_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::custom_config_value *v4; // ecx
  const vostok::render::custom_config_value *v5; // eax
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::custom_config_value *v9; // ecx
  const vostok::render::custom_config_value *v10; // eax
  vostok::render::custom_config_value *v11; // ecx
  const vostok::render::custom_config_value *v12; // eax
  vostok::render::custom_config_value *v13; // ecx
  vostok::strings::shared::profile *v14; // eax
  vostok::render::custom_config_value *v15; // ecx
  const vostok::render::custom_config_value *v16; // eax
  vostok::render::custom_config_value *v17; // ecx
  vostok::render::custom_config_value *v18; // ecx
  const vostok::render::custom_config_value *v19; // eax
  vostok::render::custom_config_value *v20; // ecx
  double v21; // st7
  vostok::strings::shared::profile *v22; // eax
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::shared_string _X; // [esp+0h] [ebp-2Ch]
  vostok::shared_string _Xa; // [esp+0h] [ebp-2Ch]
  bool v27; // [esp+4h] [ebp-28h]
  D3D11_STENCIL_OP v28; // [esp+4h] [ebp-28h]
  D3D11_BLEND_OP v29; // [esp+4h] [ebp-28h]
  bool v30; // [esp+4h] [ebp-28h]
  float angle_in_rad; // [esp+14h] [ebp-18h]
  float fog_power; // [esp+18h] [ebp-14h]
  float fog_powera; // [esp+18h] [ebp-14h]
  vostok::render::effect_constant_storage include_getter; // [esp+1Ch] [ebp-10h] BYREF

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  include_getter.m_indexers._M_impl._M_end_of_storage._M_data = (vostok::render::data_indexer *)4;
  include_getter.m_indexers._M_impl._M_start = 0;
  include_getter.m_indexers._M_impl._M_finish = 0;
  include_getter.m_constant_buffer = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    compiler,
    (char *)&stru_966284,
    0,
    (vostok::render::shader_configuration *)&stru_9698E0,
    (const vostok::render::shader_configuration *)&include_getter);
  v5 = vostok::render::custom_config_value::operator[](
         v4,
         (int)config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"sky_texture");
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_sky_sphere", (char *)v5->data, 0, v27);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_FRONT);
  vostok::render::effect_compiler::end_pass(
    v6,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v7, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v8, (int)compiler);
  include_getter.m_indexers._M_impl._M_end_of_storage._M_data = (vostok::render::data_indexer *)4;
  include_getter.m_indexers._M_impl._M_start = 0;
  include_getter.m_indexers._M_impl._M_finish = 0;
  include_getter.m_constant_buffer = 0;
  vostok::render::effect_compiler::begin_pass(
    (vostok::render::effect_compiler *)&include_getter,
    compiler,
    (char *)&stru_969904,
    0,
    (vostok::render::shader_configuration *)&stru_969904,
    (const vostok::render::shader_configuration *)&include_getter);
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
    v28);
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_ZERO,
    compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v29);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  v10 = vostok::render::custom_config_value::operator[](
          v9,
          (int)config,
          (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"sky_texture");
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_sky_sphere", (char *)v10->data, 0, v30);
  if ( vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)((char *)&stru_969904.configuration[1] + 4),
         (int)config) )
  {
    v12 = vostok::render::custom_config_value::operator[](
            v11,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)((char *)&stru_969904.configuration[1] + 4));
    angle_in_rad = vostok::render::custom_config_value::operator<float> float(v13, (int)v12) * 0.0055555557 * 3.1415927;
    fog_power = sinf(angle_in_rad);
    *(float *)&include_getter.m_indexers._M_impl._M_start = cosf(angle_in_rad);
    *(float *)&include_getter.m_indexers._M_impl._M_finish = fog_power;
  }
  else
  {
    include_getter.m_indexers._M_impl._M_start = (vostok::render::data_indexer *)clear_value;
    include_getter.m_indexers._M_impl._M_finish = 0;
  }
  include_getter.m_indexers._M_impl._M_end_of_storage._M_data = 0;
  include_getter.m_constant_buffer = 0;
  v14 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v11,
          s_manager.m_variable,
          "sky_cos_sin");
  _X.m_pointer.m_object = 0;
  if ( v14 )
  {
    _X.m_pointer.m_object = v14;
    _InterlockedExchangeAdd(&v14->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&include_getter, compiler, _X);
  if ( vostok::render::custom_config_value::value_exists(&stru_9681A8, (int)config)
    && vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)&stru_9681A8.destroyer,
         (int)config) )
  {
    v16 = vostok::render::custom_config_value::operator[](
            v15,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9681A8);
    fog_powera = vostok::render::custom_config_value::operator<float> float(v17, (int)v16);
    v19 = vostok::render::custom_config_value::operator[](
            v18,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9681A8.destroyer);
    v21 = vostok::render::custom_config_value::operator<float> float(v20, (int)v19);
    *(float *)&include_getter.m_indexers._M_impl._M_start = fog_powera;
    *(float *)&include_getter.m_indexers._M_impl._M_finish = v21;
  }
  else
  {
    include_getter.m_indexers._M_impl._M_start = (vostok::render::data_indexer *)clear_value;
    include_getter.m_indexers._M_impl._M_finish = (vostok::render::data_indexer *)1048576000;
  }
  include_getter.m_indexers._M_impl._M_end_of_storage._M_data = 0;
  include_getter.m_constant_buffer = 0;
  v22 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v15,
          s_manager.m_variable,
          "fog_power_and_range");
  _Xa.m_pointer.m_object = 0;
  if ( v22 )
  {
    _Xa.m_pointer.m_object = v22;
    _InterlockedExchangeAdd(&v22->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&include_getter, compiler, _Xa);
  vostok::render::effect_compiler::end_pass(
    v23,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v24, (int)compiler);
}
