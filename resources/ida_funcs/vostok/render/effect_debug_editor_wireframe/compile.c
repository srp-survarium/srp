void __thiscall vostok::render::effect_debug_editor_wireframe::compile(
        vostok::render::effect_debug_editor_wireframe *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::custom_config_value *v3; // ecx
  const void *data; // edi
  vostok::render::custom_config_value *v5; // ecx
  const vostok::render::custom_config_value *v6; // eax
  vostok::render::custom_config_value *v7; // ecx
  D3D11_FILL_MODE v8; // edi
  bool v9; // zf
  vostok::strings::shared::manager *v10; // ecx
  vostok::strings::shared::profile *v11; // eax
  vostok::render::effect_constant_storage *v12; // ecx
  vostok::strings::shared::manager *v13; // ecx
  vostok::strings::shared::profile *v14; // eax
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::shared_string configuration_12; // [esp+1Ch] [ebp-24h]
  vostok::shared_string configuration_12a; // [esp+1Ch] [ebp-24h]
  const char *v19; // [esp+20h] [ebp-20h]
  D3D11_BLEND_OP v20; // [esp+20h] [ebp-20h]
  bool v21; // [esp+20h] [ebp-20h]
  bool v22; // [esp+20h] [ebp-20h]
  vostok::render::shader_configuration *v23; // [esp+24h] [ebp-1Ch]
  char geometry_shader_name[16]; // [esp+30h] [ebp-10h] BYREF

  *(_DWORD *)&geometry_shader_name[8] = 4;
  *(_DWORD *)geometry_shader_name = 0;
  *(_DWORD *)&geometry_shader_name[4] = 0;
  *(_DWORD *)&geometry_shader_name[12] = 0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)&stru_967E08.destroyer,
    geometry_shader_name,
    v19,
    v23);
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
    v20);
  data = vostok::render::custom_config_value::operator[](
           v3,
           (int)config,
           (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"draw_mode")->data;
  v6 = vostok::render::custom_config_value::operator[](
         v5,
         (int)config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"draw_color");
  vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(
    v7,
    (vostok::math::float4 *)geometry_shader_name,
    (int)v6);
  *(__m128i *)geometry_shader_name = _mm_load_si128((const __m128i *)geometry_shader_name);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v21);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_particle_lighting",
    "$user$particle_lighting",
    0,
    v22);
  if ( data )
  {
    v9 = data == (const void *)1;
    v8 = D3D11_FILL_WIREFRAME;
    if ( !v9 )
      v8 = D3D11_FILL_SOLID;
  }
  else
  {
    v8 = D3D11_FILL_WIREFRAME;
  }
  vostok::render::effect_compiler::set_fill_mode(compiler, v8);
  v11 = vostok::strings::shared::manager::string(v10, s_manager.m_variable, (const char *)&stru_967E7C);
  configuration_12.m_pointer.m_object = 0;
  if ( v11 )
  {
    configuration_12.m_pointer.m_object = v11;
    v12 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v11->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(
    (const float *)&geometry_shader_name[12],
    v12,
    compiler,
    configuration_12);
  v14 = vostok::strings::shared::manager::string(v13, s_manager.m_variable, (const char *)&stru_961604);
  configuration_12a.m_pointer.m_object = 0;
  if ( v14 )
  {
    configuration_12a.m_pointer.m_object = v14;
    _InterlockedExchangeAdd(&v14->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)geometry_shader_name,
    compiler,
    configuration_12a);
  vostok::render::effect_compiler::end_pass(
    v15,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v16, (int)compiler);
}
