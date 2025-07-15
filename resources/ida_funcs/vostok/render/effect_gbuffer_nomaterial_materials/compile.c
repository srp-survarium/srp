void __thiscall vostok::render::effect_gbuffer_nomaterial_materials::compile(
        vostok::render::effect_gbuffer_nomaterial_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::strings::shared::manager *v7; // ecx
  vostok::strings::shared::profile *v8; // eax
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::strings::shared::manager *v11; // ecx
  vostok::strings::shared::profile *v12; // eax
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::custom_config_value *v15; // ecx
  char v16; // al
  const vostok::render::custom_config_value *v17; // eax
  vostok::render::custom_config_value *v18; // ecx
  vostok::render::custom_config_value *v19; // ecx
  const vostok::render::custom_config_value *v20; // eax
  vostok::render::custom_config_value *v21; // ecx
  __m128i si128; // xmm0
  vostok::strings::shared::profile *v23; // eax
  const vostok::render::custom_config_value *v24; // eax
  vostok::render::effect_compiler *v25; // ecx
  const vostok::render::custom_config_value *v26; // edi
  vostok::render::custom_config_value *v27; // ecx
  char data; // al
  vostok::render::custom_config_value *v29; // ecx
  char v30; // al
  vostok::render::effect_compiler *v31; // ecx
  bool v32; // zf
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::custom_config_value *v34; // ecx
  char v35; // al
  vostok::render::custom_config_value *v36; // ecx
  char v37; // al
  vostok::render::custom_config_value *v38; // ecx
  const vostok::render::custom_config_value *v39; // eax
  const vostok::render::custom_config_value *v40; // eax
  vostok::render::custom_config_value *v41; // ecx
  vostok::strings::shared::profile *v42; // eax
  vostok::render::effect_constant_storage *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::render::effect_compiler *v45; // ecx
  int v46; // ecx
  unsigned __int8 *p_RenderTargetWriteMask; // eax
  vostok::render::effect_compiler *v48; // ecx
  vostok::shared_string v49; // [esp+190h] [ebp-44h]
  vostok::shared_string v50; // [esp+190h] [ebp-44h]
  vostok::shared_string v51; // [esp+190h] [ebp-44h]
  const char *v52; // [esp+194h] [ebp-40h]
  D3D11_STENCIL_OP v53; // [esp+194h] [ebp-40h]
  bool v54; // [esp+194h] [ebp-40h]
  const char *v55; // [esp+194h] [ebp-40h]
  bool v56; // [esp+194h] [ebp-40h]
  const char *v57; // [esp+194h] [ebp-40h]
  bool v58; // [esp+194h] [ebp-40h]
  const char *v59; // [esp+194h] [ebp-40h]
  D3D11_STENCIL_OP v60; // [esp+194h] [ebp-40h]
  const char *v61; // [esp+194h] [ebp-40h]
  const char *v62; // [esp+194h] [ebp-40h]
  bool v63; // [esp+194h] [ebp-40h]
  bool v64; // [esp+194h] [ebp-40h]
  const char *v65; // [esp+194h] [ebp-40h]
  vostok::render::shader_configuration *v66; // [esp+198h] [ebp-3Ch]
  vostok::render::shader_configuration *v67; // [esp+198h] [ebp-3Ch]
  vostok::render::shader_configuration *v68; // [esp+198h] [ebp-3Ch]
  vostok::render::shader_configuration *v69; // [esp+198h] [ebp-3Ch]
  vostok::render::shader_configuration *v70; // [esp+198h] [ebp-3Ch]
  vostok::render::shader_configuration *v71; // [esp+198h] [ebp-3Ch]
  vostok::render::shader_configuration *v72; // [esp+198h] [ebp-3Ch]
  char v73; // [esp+1ABh] [ebp-29h]
  float source; // [esp+1ACh] [ebp-28h] BYREF
  vostok::command_line::key_initializator predicate[4]; // [esp+1B0h] [ebp-24h]
  char geometry_shader_name[16]; // [esp+1B4h] [ebp-20h] BYREF
  vostok::math::float4 v77; // [esp+1C4h] [ebp-10h] BYREF

  source = 0.0;
  do
  {
    geometry_shader_name[11] = 0;
    *(_DWORD *)geometry_shader_name = 1;
    *(_DWORD *)&geometry_shader_name[4] = 0;
    *(_DWORD *)&geometry_shader_name[12] = 0;
    *(_WORD *)&geometry_shader_name[9] = LOBYTE(source) & 7;
    geometry_shader_name[8] = 4;
    vostok::render::effect_material_base::compile_begin(
      compiler,
      config,
      (vostok::render::effect_material_base *)&stru_966284,
      (vostok::render::shader_configuration *)"gbuffer_nomaterial_pass",
      geometry_shader_name,
      v52,
      v66);
    vostok::render::effect_compiler::set_stencil(
      compiler,
      D3D11_STENCIL_OP_KEEP,
      1,
      0x82u,
      0xFFu,
      0xFFu,
      D3D11_COMPARISON_ALWAYS,
      D3D11_STENCIL_OP_REPLACE,
      v53);
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
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_default_texture", "no_texture", 0, v54);
    vostok::render::effect_compiler::end_pass(
      v3,
      (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
    vostok::render::effect_compiler::end_technique(v4, (int)compiler);
    ++LODWORD(source);
  }
  while ( LODWORD(source) < 2 );
  *(_DWORD *)&geometry_shader_name[8] = 4;
  *(_DWORD *)geometry_shader_name = 0;
  *(_DWORD *)&geometry_shader_name[4] = 0;
  *(_DWORD *)&geometry_shader_name[12] = 0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)"fill_reflective_shadow_map_backed",
    geometry_shader_name,
    v52,
    v66);
  vostok::render::effect_compiler::end_pass(
    v5,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v6, (int)compiler);
  *(_DWORD *)&geometry_shader_name[8] = 4;
  *(_DWORD *)geometry_shader_name = 0;
  *(_DWORD *)&geometry_shader_name[4] = 0;
  *(_DWORD *)&geometry_shader_name[12] = 0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_9666F4,
    (vostok::render::shader_configuration *)&stru_9666F4,
    geometry_shader_name,
    v55,
    v67);
  *(_DWORD *)geometry_shader_name = clear_value;
  *(_DWORD *)&geometry_shader_name[4] = clear_value;
  *(_DWORD *)&geometry_shader_name[8] = clear_value;
  v8 = vostok::strings::shared::manager::string(v7, s_manager.m_variable, "diffuse_color_parameter");
  v49.m_pointer.m_object = 0;
  if ( v8 )
  {
    v49.m_pointer.m_object = v8;
    _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(
    (const vostok::math::float3 *)geometry_shader_name,
    compiler,
    v49);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &stru_963F84.m_name.m_string.m_buffer[116],
    "no_texture",
    0,
    v56);
  vostok::render::effect_compiler::end_pass(
    v9,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v10, (int)compiler);
  *(_DWORD *)&geometry_shader_name[8] = 4;
  *(_DWORD *)geometry_shader_name = 0;
  *(_DWORD *)&geometry_shader_name[4] = 0;
  *(_DWORD *)&geometry_shader_name[12] = 0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)"fill_reflective_shadow_map",
    geometry_shader_name,
    v57,
    v68);
  *(_DWORD *)geometry_shader_name = clear_value;
  *(_DWORD *)&geometry_shader_name[4] = clear_value;
  *(_DWORD *)&geometry_shader_name[8] = clear_value;
  v12 = vostok::strings::shared::manager::string(v11, s_manager.m_variable, "diffuse_color_parameter");
  v50.m_pointer.m_object = 0;
  if ( v12 )
  {
    v50.m_pointer.m_object = v12;
    _InterlockedExchangeAdd(&v12->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(
    (const vostok::math::float3 *)geometry_shader_name,
    compiler,
    v50);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &stru_963F84.m_name.m_string.m_buffer[116],
    "no_texture",
    0,
    v58);
  vostok::render::effect_compiler::end_pass(
    v13,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v14, (int)compiler);
  *(_DWORD *)&geometry_shader_name[8] = 4;
  *(_DWORD *)geometry_shader_name = 0;
  *(_DWORD *)&geometry_shader_name[4] = 0;
  *(_DWORD *)&geometry_shader_name[12] = 0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)"gbuffer_emissive_pass",
    geometry_shader_name,
    v59,
    v69);
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    v60);
  v16 = ((unsigned __int8)geometry_shader_name[4] >> 2) & 3;
  v73 = v16;
  if ( v16 )
  {
    v17 = vostok::render::custom_config_value::operator[](
            v15,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966754);
    *(float *)predicate = vostok::render::custom_config_value::operator<float> float(v18, (int)v17);
    v20 = vostok::render::custom_config_value::operator[](
            v19,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966774);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v21, &v77, (int)v20);
    si128 = _mm_load_si128((const __m128i *)&v77);
    *(_DWORD *)&geometry_shader_name[12] = si128.m128i_i32[3];
    *(float *)geometry_shader_name = v77.x * *(float *)predicate;
    *(float *)&geometry_shader_name[4] = *(float *)&si128.m128i_i32[1] * *(float *)predicate;
    *(float *)&geometry_shader_name[8] = *(float *)predicate * *(float *)&si128.m128i_i32[2];
    v23 = vostok::strings::shared::manager::string(s_manager.m_variable, s_manager.m_variable, "solid_emission_color");
    v51.m_pointer.m_object = 0;
    if ( v23 )
    {
      v51.m_pointer.m_object = v23;
      _InterlockedExchangeAdd(&v23->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)geometry_shader_name,
      compiler,
      v51);
    v16 = v73;
  }
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      predicate[0] = 0;
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      v16 = v73;
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      vostok::render::state_descriptor::set_alpha_blend(
        D3D11_BLEND_ONE,
        D3D11_BLEND_OP_ADD,
        D3D11_BLEND_ZERO,
        D3D11_BLEND_OP_ADD,
        &compiler->m_state_descriptor,
        1,
        D3D11_BLEND_ONE,
        (D3D11_BLEND)v61);
      v16 = v73;
    }
  }
  if ( v16 == 2 )
  {
    v24 = vostok::render::custom_config_value::operator[](
            v15,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_emissive");
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_emission", (char *)v24->data, 0, (bool)v61);
  }
  vostok::render::effect_compiler::end_pass(
    (vostok::render::effect_compiler *)v15,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v25, (int)compiler);
  *(_DWORD *)&geometry_shader_name[8] = 4;
  *(_DWORD *)geometry_shader_name = 0;
  *(_DWORD *)&geometry_shader_name[4] = 0;
  *(_DWORD *)&geometry_shader_name[12] = 0;
  v26 = config;
  if ( vostok::render::custom_config_value::value_exists(&stru_960A44, (int)config) )
    data = (char)vostok::render::custom_config_value::operator[](
                   v27,
                   (int)config,
                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_960A44)->data;
  else
    data = 0;
  geometry_shader_name[0] = 2 * (data & 1);
  if ( vostok::render::custom_config_value::value_exists(&stru_9667A8, (int)config) )
    v30 = (char)vostok::render::custom_config_value::operator[](
                  v29,
                  (int)config,
                  (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9667A8)->data;
  else
    v30 = 0;
  geometry_shader_name[0] ^= (geometry_shader_name[0] ^ v30) & 1;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)&stru_9667A8.destroyer,
    geometry_shader_name,
    v61,
    v70);
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
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
        v32 = compiler->m_state_descriptor.m_rasterizer_desc.CullMode == D3D11_CULL_NONE;
        compiler->m_state_descriptor.m_rasterizer_desc.CullMode = D3D11_CULL_NONE;
        compiler->m_state_descriptor.m_rasterizer_desc_updated |= !v32;
      }
    }
  }
  vostok::render::effect_compiler::end_pass(
    v31,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v33, (int)compiler);
  *(_DWORD *)&geometry_shader_name[8] = 4;
  *(_DWORD *)geometry_shader_name = 0;
  *(_DWORD *)&geometry_shader_name[4] = 0;
  *(_DWORD *)&geometry_shader_name[12] = 0;
  if ( vostok::render::custom_config_value::value_exists(&stru_960A44, (int)config) )
    v35 = (char)vostok::render::custom_config_value::operator[](
                  v34,
                  (int)config,
                  (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_960A44)->data;
  else
    v35 = 0;
  geometry_shader_name[0] = 2 * (v35 & 1);
  if ( vostok::render::custom_config_value::value_exists(&stru_9667A8, (int)config) )
    v37 = (char)vostok::render::custom_config_value::operator[](
                  v36,
                  (int)config,
                  (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9667A8)->data;
  else
    v37 = 0;
  geometry_shader_name[0] ^= (geometry_shader_name[0] ^ v37) & 1;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)"subsurface_scattering",
    geometry_shader_name,
    v62,
    v71);
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  source = 0.25;
  if ( (geometry_shader_name[0] & 1) != 0 )
  {
    v39 = vostok::render::custom_config_value::operator[](
            v38,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (char *)v39->data,
      0,
      v63);
  }
  if ( (geometry_shader_name[0] & 2) != 0
    && vostok::render::custom_config_value::value_exists(&stru_9667FC, (int)config) )
  {
    v40 = vostok::render::custom_config_value::operator[](
            v38,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9667FC);
    source = vostok::render::custom_config_value::operator<float> float(v41, (int)v40);
    v26 = config;
  }
  v42 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v38,
          s_manager.m_variable,
          (const char *)&stru_9667FC.type);
  if ( v42 )
    vostok::render::effect_compiler::set_constant<float>(
      &source,
      (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v42->m_reference_count, 1u),
      compiler,
      (vostok::shared_string)v42);
  else
    vostok::render::effect_compiler::set_constant<float>(&source, v43, compiler, 0);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_diffuse_lighting",
    "$user$accum_diffuse",
    0,
    v63);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_specular_lighting",
    "$user$accum_specular",
    0,
    v64);
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
      v32 = compiler->m_state_descriptor.m_rasterizer_desc.CullMode == D3D11_CULL_NONE;
      compiler->m_state_descriptor.m_rasterizer_desc.CullMode = D3D11_CULL_NONE;
      compiler->m_state_descriptor.m_rasterizer_desc_updated |= !v32;
    }
  }
  vostok::render::effect_compiler::end_pass(
    v44,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v45, (int)compiler);
  *(_DWORD *)&geometry_shader_name[8] = 4;
  *(_DWORD *)geometry_shader_name = 0;
  *(_DWORD *)&geometry_shader_name[4] = 0;
  *(_DWORD *)&geometry_shader_name[12] = 0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    v26,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)"z_only",
    geometry_shader_name,
    v65,
    v72);
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
        p_RenderTargetWriteMask = &compiler->m_state_descriptor.m_effect_desc.RenderTarget[0].RenderTargetWriteMask;
        compiler->m_state_descriptor.m_effect_desc_updated |= compiler->m_state_descriptor.m_effect_desc.RenderTarget[0].RenderTargetWriteMask != 0;
        v46 = 8;
        do
        {
          *p_RenderTargetWriteMask = 0;
          p_RenderTargetWriteMask += 32;
          --v46;
        }
        while ( v46 );
      }
    }
  }
  vostok::render::effect_compiler::end_pass(
    (vostok::render::effect_compiler *)v46,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v48, (int)compiler);
}
