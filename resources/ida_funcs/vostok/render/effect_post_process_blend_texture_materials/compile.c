void __thiscall vostok::render::effect_post_process_blend_texture_materials::compile(
        vostok::render::effect_post_process_blend_texture_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  const vostok::render::custom_config_value *v3; // eax
  vostok::render::custom_config_value *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::custom_config_value *v7; // ecx
  const vostok::render::custom_config_value *v8; // eax
  vostok::strings::shared::profile *v9; // eax
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  bool v12; // [esp+10h] [ebp-30h]
  D3D11_BLEND_OP v13; // [esp+10h] [ebp-30h]
  vostok::render::shader_include_getter include_getter[4]; // [esp+20h] [ebp-20h] BYREF
  vostok::math::float4 source; // [esp+30h] [ebp-10h] BYREF

  v3 = vostok::render::custom_config_value::operator[](
         (vostok::render::custom_config_value *)this,
         (int)custom_config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_modulate_color");
  vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(
    v4,
    (vostok::math::float4 *)include_getter,
    (int)v3);
  source = (vostok::math::float4)_mm_load_si128((const __m128i *)include_getter);
  vostok::render::effect_compiler::begin_technique(v5, (int)compiler);
  include_getter[2].__vftable = (vostok::render::shader_include_getter_vtbl *)4;
  include_getter[0].__vftable = 0;
  include_getter[1].__vftable = 0;
  include_getter[3].__vftable = 0;
  vostok::render::effect_compiler::begin_pass(
    v6,
    compiler,
    &stru_9656C8.m_name.m_string.m_buffer[100],
    0,
    (vostok::render::shader_configuration *)&stru_969230,
    (const vostok::render::shader_configuration *)include_getter);
  v8 = vostok::render::custom_config_value::operator[](
         v7,
         (int)custom_config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_base");
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &stru_963F84.m_name.m_string.m_buffer[116],
    (char *)v8->data,
    0,
    v12);
  v9 = vostok::strings::shared::manager::string(s_manager.m_variable, s_manager.m_variable, "modulate_color");
  if ( v9 )
  {
    _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&source,
      compiler,
      (vostok::shared_string)v9);
  }
  else
  {
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&source,
      compiler,
      0);
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
    D3D11_BLEND_INV_SRC_ALPHA,
    compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v13);
  vostok::render::effect_compiler::end_pass(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v11, (int)compiler);
}
