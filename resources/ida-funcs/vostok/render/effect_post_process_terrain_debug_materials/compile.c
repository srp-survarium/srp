void __thiscall vostok::render::effect_post_process_terrain_debug_materials::compile(
        vostok::render::effect_post_process_terrain_debug_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::custom_config_value *v4; // ecx
  const vostok::render::custom_config_value *v5; // eax
  vostok::render::custom_config_value *v6; // ecx
  const vostok::render::custom_config_value *v7; // eax
  vostok::render::custom_config_value *v8; // ecx
  vostok::render::custom_config_value *v9; // ecx
  const vostok::render::custom_config_value *v10; // eax
  vostok::render::custom_config_value *v11; // ecx
  vostok::strings::shared::manager *v12; // ecx
  vostok::strings::shared::profile *v13; // eax
  vostok::render::custom_config_value *v14; // ecx
  const vostok::render::custom_config_value *v15; // eax
  vostok::render::custom_config_value *v16; // ecx
  vostok::render::custom_config_value *v17; // ecx
  const vostok::render::custom_config_value *v18; // eax
  vostok::render::custom_config_value *v19; // ecx
  vostok::render::custom_config_value *v20; // ecx
  const vostok::render::custom_config_value *v21; // eax
  vostok::render::custom_config_value *v22; // ecx
  vostok::strings::shared::manager *v23; // ecx
  vostok::strings::shared::profile *v24; // eax
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::shared_string v27; // [esp-4h] [ebp-3Ch]
  vostok::shared_string v28; // [esp-4h] [ebp-3Ch]
  D3D11_STENCIL_OP v29; // [esp+0h] [ebp-38h]
  bool v30; // [esp+0h] [ebp-38h]
  bool v31; // [esp+0h] [ebp-38h]
  bool v32; // [esp+0h] [ebp-38h]
  bool v33; // [esp+0h] [ebp-38h]
  bool v34; // [esp+0h] [ebp-38h]
  D3D11_BLEND_OP v35; // [esp+0h] [ebp-38h]
  float predicate; // [esp+10h] [ebp-28h]
  float v37; // [esp+14h] [ebp-24h]
  vostok::render::effect_constant_storage include_getter; // [esp+18h] [ebp-20h] BYREF
  vostok::math::float4 v39; // [esp+28h] [ebp-10h] BYREF

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  include_getter.m_indexers._M_impl._M_end_of_storage._M_data = (vostok::render::data_indexer *)4;
  include_getter.m_indexers._M_impl._M_start = 0;
  include_getter.m_indexers._M_impl._M_finish = 0;
  include_getter.m_constant_buffer = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    compiler,
    &stru_9656C8.m_name.m_string.m_buffer[100],
    0,
    (vostok::render::shader_configuration *)&stru_96927C,
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
    0x80u,
    0x80u,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v29);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::set_fill_mode(compiler, D3D11_FILL_SOLID);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v30);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_normal", "$user$normal", 0, v31);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_decals_diffuse", "$user$decals_diffuse", 0, v32);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_decals_normal", "$user$decals_normal", 0, v33);
  v5 = vostok::render::custom_config_value::operator[](
         v4,
         (int)custom_config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_gradient");
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_gradient", (char *)v5->data, 0, v34);
  v7 = vostok::render::custom_config_value::operator[](
         v6,
         (int)custom_config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_deepening_color");
  vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v8, &v39, (int)v7);
  v10 = vostok::render::custom_config_value::operator[](
          v9,
          (int)custom_config,
          (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_deepening_range");
  *(float *)&include_getter.m_constant_buffer = vostok::render::custom_config_value::operator<float> float(
                                                  v11,
                                                  (int)v10);
  *(_QWORD *)&include_getter.m_indexers._M_impl._M_start = *(_QWORD *)&v39.x;
  include_getter.m_indexers._M_impl._M_end_of_storage._M_data = (vostok::render::data_indexer *)LODWORD(v39.z);
  v13 = vostok::strings::shared::manager::string(v12, s_manager.m_variable, "deepening_color_and_range");
  v27.m_pointer.m_object = 0;
  if ( v13 )
  {
    v27.m_pointer.m_object = v13;
    _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&include_getter, compiler, v27);
  v15 = vostok::render::custom_config_value::operator[](
          v14,
          (int)custom_config,
          (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_deepening_power");
  v37 = vostok::render::custom_config_value::operator<float> float(v16, (int)v15);
  v18 = vostok::render::custom_config_value::operator[](
          v17,
          (int)custom_config,
          (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_deepening_scale");
  predicate = vostok::render::custom_config_value::operator<float> float(v19, (int)v18);
  v21 = vostok::render::custom_config_value::operator[](
          v20,
          (int)custom_config,
          (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_deepening_clip_dist");
  *(float *)&include_getter.m_indexers._M_impl._M_start = vostok::render::custom_config_value::operator<float> float(
                                                            v22,
                                                            (int)v21);
  *(float *)&include_getter.m_indexers._M_impl._M_finish = predicate;
  *(float *)&include_getter.m_indexers._M_impl._M_end_of_storage._M_data = v37;
  include_getter.m_constant_buffer = 0;
  v24 = vostok::strings::shared::manager::string(v23, s_manager.m_variable, "deepening_parameters");
  v28.m_pointer.m_object = 0;
  if ( v24 )
  {
    v28.m_pointer.m_object = v24;
    _InterlockedExchangeAdd(&v24->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&include_getter, compiler, v28);
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_ZERO,
    compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v35);
  vostok::render::effect_compiler::end_pass(
    v25,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v26, (int)compiler);
}
