void __thiscall vostok::render::effect_lighting_stage_skin_base_materials::compile(
        vostok::render::effect_lighting_stage_skin_base_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::custom_config_value *v5; // ecx
  vostok::render::custom_config_value *v6; // ecx
  const vostok::render::custom_config_value *v7; // eax
  vostok::render::custom_config_value *v8; // ecx
  char data; // al
  vostok::render::custom_config_value *v10; // ecx
  char v11; // al
  vostok::render::custom_config_value *v12; // ecx
  char v13; // al
  vostok::render::custom_config_value *v14; // ecx
  char v15; // al
  vostok::render::custom_config_value *v16; // ecx
  const vostok::render::custom_config_value *v17; // eax
  const vostok::render::custom_config_value *v18; // eax
  vostok::render::custom_config_value *v19; // ecx
  vostok::render::custom_config_value *v20; // ecx
  const vostok::render::custom_config_value *v21; // eax
  const vostok::render::custom_config_value *v22; // eax
  vostok::render::custom_config_value *v23; // ecx
  const vostok::render::custom_config_value *v24; // eax
  vostok::render::custom_config_value *v25; // ecx
  vostok::render::custom_config_value *v26; // ecx
  const vostok::render::custom_config_value *v27; // eax
  vostok::render::custom_config_value *v28; // ecx
  vostok::strings::shared::manager *v29; // ecx
  vostok::strings::shared::profile *v30; // eax
  vostok::strings::shared::profile *v31; // eax
  vostok::render::custom_config_value *v32; // ecx
  const vostok::render::custom_config_value *v33; // eax
  vostok::render::custom_config_value *v34; // ecx
  const vostok::render::custom_config_value *v35; // eax
  vostok::render::custom_config_value *v36; // ecx
  vostok::strings::shared::profile *v37; // eax
  vostok::render::effect_constant_storage *v38; // ecx
  vostok::strings::shared::manager *v39; // ecx
  vostok::strings::shared::profile *v40; // eax
  vostok::render::effect_constant_storage *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::custom_config_value *v44; // ecx
  char v45; // al
  vostok::render::effect_compiler *v46; // ecx
  vostok::render::custom_config_value *v47; // ecx
  const vostok::render::custom_config_value *v48; // eax
  vostok::render::custom_config_value *v49; // ecx
  vostok::render::custom_config_value *v50; // ecx
  const vostok::render::custom_config_value *v51; // eax
  vostok::render::custom_config_value *v52; // ecx
  vostok::render::custom_config_value *v53; // ecx
  const vostok::render::custom_config_value *v54; // eax
  vostok::strings::shared::profile *v55; // eax
  vostok::render::effect_compiler *v56; // ecx
  vostok::render::effect_compiler *v57; // ecx
  vostok::render::custom_config_value *v58; // ecx
  char v59; // al
  vostok::render::custom_config_value *v60; // ecx
  char v61; // al
  vostok::render::custom_config_value *v62; // ecx
  char v63; // al
  vostok::render::custom_config_value *v64; // ecx
  char v65; // al
  vostok::render::custom_config_value *v66; // ecx
  char v67; // al
  vostok::render::custom_config_value *v68; // ecx
  char v69; // al
  vostok::render::custom_config_value *v70; // ecx
  char v71; // al
  vostok::render::custom_config_value *v72; // ecx
  const vostok::render::custom_config_value *v73; // eax
  const vostok::render::custom_config_value *v74; // eax
  vostok::render::custom_config_value *v75; // ecx
  vostok::render::custom_config_value *v76; // ecx
  const vostok::render::custom_config_value *v77; // eax
  const vostok::render::custom_config_value *v78; // eax
  const vostok::render::custom_config_value *v79; // eax
  const vostok::render::custom_config_value *v80; // eax
  const vostok::render::custom_config_value *v81; // eax
  const vostok::render::custom_config_value *v82; // eax
  vostok::render::custom_config_value *v83; // ecx
  const vostok::render::custom_config_value *v84; // eax
  vostok::render::custom_config_value *v85; // ecx
  vostok::render::custom_config_value *v86; // ecx
  const vostok::render::custom_config_value *v87; // eax
  vostok::render::custom_config_value *v88; // ecx
  vostok::strings::shared::manager *v89; // ecx
  vostok::strings::shared::profile *v90; // eax
  vostok::render::custom_config_value *v91; // ecx
  const vostok::render::custom_config_value *v92; // eax
  vostok::render::custom_config_value *v93; // ecx
  vostok::strings::shared::manager *v94; // ecx
  vostok::strings::shared::profile *v95; // eax
  vostok::render::effect_constant_storage *v96; // ecx
  vostok::render::custom_config_value *v97; // ecx
  const vostok::render::custom_config_value *v98; // eax
  vostok::render::custom_config_value *v99; // ecx
  vostok::strings::shared::manager *v100; // ecx
  vostok::strings::shared::profile *v101; // eax
  vostok::render::effect_constant_storage *v102; // ecx
  vostok::strings::shared::profile *v103; // eax
  vostok::render::effect_compiler *v104; // ecx
  vostok::render::effect_compiler *v105; // ecx
  vostok::shared_string v106; // [esp+1B4h] [ebp-54h]
  vostok::shared_string v107; // [esp+1B4h] [ebp-54h]
  vostok::shared_string v108; // [esp+1B4h] [ebp-54h]
  vostok::shared_string v109; // [esp+1B4h] [ebp-54h]
  vostok::shared_string v110; // [esp+1B4h] [ebp-54h]
  vostok::shared_string v111; // [esp+1B4h] [ebp-54h]
  vostok::shared_string v112; // [esp+1B4h] [ebp-54h]
  vostok::shared_string v113; // [esp+1B4h] [ebp-54h]
  vostok::shared_string v114; // [esp+1B4h] [ebp-54h]
  const char *v115; // [esp+1B8h] [ebp-50h]
  D3D11_BLEND_OP v116; // [esp+1B8h] [ebp-50h]
  const char *v117; // [esp+1B8h] [ebp-50h]
  const char *v118; // [esp+1B8h] [ebp-50h]
  const char *v119; // [esp+1B8h] [ebp-50h]
  const char *v120; // [esp+1B8h] [ebp-50h]
  const char *v121; // [esp+1B8h] [ebp-50h]
  D3D11_BLEND_OP v122; // [esp+1B8h] [ebp-50h]
  const char *v123; // [esp+1B8h] [ebp-50h]
  const char *v124; // [esp+1B8h] [ebp-50h]
  const char *v125; // [esp+1B8h] [ebp-50h]
  D3D11_BLEND_OP v126; // [esp+1B8h] [ebp-50h]
  bool v127; // [esp+1B8h] [ebp-50h]
  bool v128; // [esp+1B8h] [ebp-50h]
  bool v129; // [esp+1B8h] [ebp-50h]
  const char *v130; // [esp+1B8h] [ebp-50h]
  const char *v131; // [esp+1B8h] [ebp-50h]
  const char *v132; // [esp+1B8h] [ebp-50h]
  const char *v133; // [esp+1B8h] [ebp-50h]
  const char *v134; // [esp+1B8h] [ebp-50h]
  const char *v135; // [esp+1B8h] [ebp-50h]
  const char *v136; // [esp+1B8h] [ebp-50h]
  const char *v137; // [esp+1B8h] [ebp-50h]
  const char *v138; // [esp+1B8h] [ebp-50h]
  const char *v139; // [esp+1B8h] [ebp-50h]
  D3D11_BLEND_OP v140; // [esp+1B8h] [ebp-50h]
  const char *v141; // [esp+1B8h] [ebp-50h]
  const char *v142; // [esp+1B8h] [ebp-50h]
  const char *v143; // [esp+1B8h] [ebp-50h]
  const char *v144; // [esp+1B8h] [ebp-50h]
  bool v145; // [esp+1B8h] [ebp-50h]
  bool v146; // [esp+1B8h] [ebp-50h]
  bool v147; // [esp+1B8h] [ebp-50h]
  bool v148; // [esp+1B8h] [ebp-50h]
  bool v149; // [esp+1B8h] [ebp-50h]
  vostok::render::shader_configuration *v150; // [esp+1BCh] [ebp-4Ch]
  vostok::render::shader_configuration *v151; // [esp+1BCh] [ebp-4Ch]
  vostok::render::shader_configuration *v152; // [esp+1BCh] [ebp-4Ch]
  vostok::command_line::key_initializator predicate[4]; // [esp+1C4h] [ebp-44h] BYREF
  vostok::math::float3 source; // [esp+1C8h] [ebp-40h] BYREF
  int v155; // [esp+1D4h] [ebp-34h]
  char geometry_shader_name[16]; // [esp+1D8h] [ebp-30h] BYREF
  vostok::math::float4 v157; // [esp+1E8h] [ebp-20h] BYREF
  vostok::math::float4 si128; // [esp+1F8h] [ebp-10h] BYREF

  *(_DWORD *)&geometry_shader_name[8] = 4;
  *(_DWORD *)geometry_shader_name = 0;
  *(_DWORD *)&geometry_shader_name[4] = 0;
  *(_DWORD *)&geometry_shader_name[12] = 0;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_9681F4,
    "skin_position_pass",
    geometry_shader_name,
    v115,
    compiler,
    v150,
    custom_config);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v116);
  vostok::render::effect_compiler::end_pass(v3);
  vostok::render::effect_compiler::end_technique(v4);
  *(_DWORD *)&geometry_shader_name[8] = 4;
  *(_DWORD *)geometry_shader_name = 0;
  *(_DWORD *)&geometry_shader_name[4] = 0;
  *(_DWORD *)&geometry_shader_name[12] = 0;
  geometry_shader_name[0] = (int)vostok::render::custom_config_value::operator[](v5, (const char *)&stru_9667A8)->data
                          & 1;
  v7 = vostok::render::custom_config_value::operator[](v6, (const char *)&stru_967F04);
  geometry_shader_name[0] ^= (geometry_shader_name[0] ^ (8 * LOBYTE(v7->data))) & 8;
  if ( vostok::render::custom_config_value::value_exists(&stru_960A44, v117) )
    data = (char)vostok::render::custom_config_value::operator[](v8, (const char *)&stru_960A44)->data;
  else
    data = 0;
  geometry_shader_name[0] ^= (geometry_shader_name[0] ^ (2 * data)) & 2;
  if ( vostok::render::custom_config_value::value_exists((vostok::render::custom_config_value *)&stru_967F04.type, v118) )
    v11 = (char)vostok::render::custom_config_value::operator[](v10, (const char *)&stru_967F04.type)->data;
  else
    v11 = 0;
  geometry_shader_name[0] = geometry_shader_name[0] & 0x7F | (v11 << 7);
  if ( vostok::render::custom_config_value::value_exists(&stru_967F28, v119) )
    v13 = (char)vostok::render::custom_config_value::operator[](v12, (const char *)&stru_967F28)->data;
  else
    v13 = 0;
  geometry_shader_name[1] ^= (geometry_shader_name[1] ^ v13) & 1;
  if ( vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)&stru_967F28.destroyer,
         v120) )
  {
    v15 = (char)vostok::render::custom_config_value::operator[](v14, (const char *)&stru_967F28.destroyer)->data;
  }
  else
  {
    v15 = 0;
  }
  geometry_shader_name[2] &= 0xFu;
  geometry_shader_name[1] = (geometry_shader_name[1] ^ (2 * v15)) & 2 ^ geometry_shader_name[1] | 0x40;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_9681F4,
    "skin_forward_lighting",
    geometry_shader_name,
    v121,
    compiler,
    v151,
    custom_config);
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 0;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::set_fill_mode(compiler, D3D11_FILL_SOLID);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v122);
  if ( (geometry_shader_name[0] & 1) != 0 )
  {
    v17 = vostok::render::custom_config_value::operator[](v16, "texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (const char *)v17->data,
      0,
      (bool)v123,
      0xFFFFFFFF);
  }
  v18 = vostok::render::custom_config_value::operator[](v16, (const char *)&stru_967F74);
  vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v19, &si128, (int)v18);
  si128 = (vostok::math::float4)_mm_load_si128((const __m128i *)&si128);
  si128.w = 0.0;
  if ( (geometry_shader_name[0] & 8) != 0 )
  {
    v21 = vostok::render::custom_config_value::operator[](v20, "texture_normal");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_normal",
      (const char *)v21->data,
      0,
      (bool)v123,
      0xFFFFFFFF);
  }
  if ( geometry_shader_name[0] < 0 )
  {
    v22 = vostok::render::custom_config_value::operator[](v20, "texture_specular_intensity");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_specular_intensity",
      (const char *)v22->data,
      0,
      (bool)v123,
      0xFFFFFFFF);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_968028, v123)
    && vostok::render::custom_config_value::value_exists(&stru_968040, v124) )
  {
    v24 = vostok::render::custom_config_value::operator[](v23, (const char *)&stru_968040);
    vostok::render::custom_config_value::operator<vostok::math::float3> vostok::math::float3(v25, &source, (int)v24);
    v27 = vostok::render::custom_config_value::operator[](v26, (const char *)&stru_968028);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v28, &v157, (int)v27);
    source.x = v157.x * source.x;
    source.y = source.y * v157.y;
    source.z = source.z * v157.z;
    v30 = vostok::strings::shared::manager::string(v29, (const char *)s_manager.m_variable);
    v106.m_pointer.m_object = 0;
    if ( v30 )
    {
      v106.m_pointer.m_object = v30;
      _InterlockedExchangeAdd(&v30->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(&source, compiler, v106);
  }
  v31 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v23,
          (const char *)s_manager.m_variable);
  v107.m_pointer.m_object = 0;
  if ( v31 )
  {
    v107.m_pointer.m_object = v31;
    _InterlockedExchangeAdd(&v31->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&si128,
    compiler,
    v107);
  *(float *)predicate = 50.0;
  if ( (geometry_shader_name[1] & 2) != 0 )
  {
    v33 = vostok::render::custom_config_value::operator[](v32, "texture_specular_power");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_specular_power",
      (const char *)v33->data,
      0,
      (bool)v124,
      0xFFFFFFFF);
  }
  else if ( vostok::render::custom_config_value::value_exists(&stru_968244, v124) )
  {
    v35 = vostok::render::custom_config_value::operator[](v34, (const char *)&stru_968244);
    *(float *)predicate = vostok::render::custom_config_value::operator<float> float(v36, (int)v35);
  }
  v37 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v34,
          (const char *)s_manager.m_variable);
  v108.m_pointer.m_object = 0;
  if ( v37 )
  {
    v108.m_pointer.m_object = v37;
    v38 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v37->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>((const float *)predicate, v38, compiler, v108);
  *(float *)predicate = *(float *)&clear_value;
  v40 = vostok::strings::shared::manager::string(v39, (const char *)s_manager.m_variable);
  v109.m_pointer.m_object = 0;
  if ( v40 )
  {
    v109.m_pointer.m_object = v40;
    v41 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v40->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>((const float *)predicate, v41, compiler, v109);
  vostok::render::effect_compiler::end_pass(v42);
  vostok::render::effect_compiler::end_technique(v43);
  source.x = 0.0;
  *(_QWORD *)&source.elements[1] = 0x400000000LL;
  v155 = 0;
  if ( vostok::render::custom_config_value::value_exists(&stru_968278, v125) )
    v45 = (char)vostok::render::custom_config_value::operator[](v44, (const char *)&stru_968278)->data;
  else
    v45 = 0;
  BYTE2(source.elements[1]) = 8 * (v45 & 1);
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)v44);
  vostok::render::effect_compiler::begin_pass(
    v46,
    (const char *)compiler,
    "blur_irradiance_texture",
    0,
    &stru_968298,
    (vostok::render::shader_include_getter *)&source);
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 0;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::set_fill_mode(compiler, D3D11_FILL_SOLID);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v126);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering",
    "$user$skin_scattering",
    0,
    v127,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering_temp",
    "$user$skin_scattering_temp",
    0,
    v128,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_blurring_stretch",
    "$user$skin_scattering_stretch",
    0,
    v129,
    0xFFFFFFFF);
  *(_DWORD *)geometry_shader_name = 1067030938;
  *(float *)&geometry_shader_name[4] = s_aim_transition_time;
  *(float *)&geometry_shader_name[8] = FLOAT_0_1;
  *(_DWORD *)&geometry_shader_name[12] = clear_value;
  if ( vostok::render::custom_config_value::value_exists(&stru_968318, v130) )
  {
    v48 = vostok::render::custom_config_value::operator[](v47, (const char *)&stru_968318);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v49, &si128, (int)v48);
    *(__m128i *)geometry_shader_name = _mm_load_si128((const __m128i *)&si128);
  }
  *(float *)&geometry_shader_name[8] = *(float *)&geometry_shader_name[8] * *(float *)&geometry_shader_name[12];
  *(float *)geometry_shader_name = *(float *)geometry_shader_name * *(float *)&geometry_shader_name[12];
  *(float *)&geometry_shader_name[4] = *(float *)&geometry_shader_name[4] * *(float *)&geometry_shader_name[12];
  *(float *)&geometry_shader_name[12] = *(float *)&geometry_shader_name[12] * *(float *)&geometry_shader_name[12];
  if ( vostok::render::custom_config_value::value_exists(&stru_968340, v131) )
  {
    v51 = vostok::render::custom_config_value::operator[](v50, (const char *)&stru_968340);
    *(float *)&geometry_shader_name[12] = vostok::render::custom_config_value::operator<float> float(v52, (int)v51);
  }
  if ( (BYTE2(source.elements[1]) & 8) != 0 && vostok::render::custom_config_value::value_exists(&stru_96835C, v132) )
  {
    v54 = vostok::render::custom_config_value::operator[](v53, (const char *)&stru_96835C);
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_scattering_depth",
      (const char *)v54->data,
      0,
      (bool)v132,
      0xFFFFFFFF);
  }
  v55 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v110.m_pointer.m_object = 0;
  if ( v55 )
  {
    v110.m_pointer.m_object = v55;
    _InterlockedExchangeAdd(&v55->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)geometry_shader_name,
    compiler,
    v110);
  vostok::render::effect_compiler::end_pass(v56);
  vostok::render::effect_compiler::end_technique(v57);
  source.x = 0.0;
  *(_QWORD *)&source.elements[1] = 0x400000000LL;
  v155 = 0;
  if ( vostok::render::custom_config_value::value_exists(&stru_9667A8, v132) )
    v59 = (char)vostok::render::custom_config_value::operator[](v58, (const char *)&stru_9667A8)->data;
  else
    v59 = 0;
  LOBYTE(source.x) = v59 & 1;
  if ( vostok::render::custom_config_value::value_exists(&stru_967F04, v133) )
    v61 = (char)vostok::render::custom_config_value::operator[](v60, (const char *)&stru_967F04)->data;
  else
    v61 = 0;
  LOBYTE(source.x) ^= (LOBYTE(source.x) ^ (8 * v61)) & 8;
  if ( vostok::render::custom_config_value::value_exists((vostok::render::custom_config_value *)&stru_967F04.type, v134) )
    v63 = (char)vostok::render::custom_config_value::operator[](v62, (const char *)&stru_967F04.type)->data;
  else
    v63 = 0;
  LOBYTE(source.x) = LOBYTE(source.x) & 0x7F | (v63 << 7);
  if ( vostok::render::custom_config_value::value_exists(&stru_9683C8, v135) )
    v65 = (char)vostok::render::custom_config_value::operator[](v64, (const char *)&stru_9683C8)->data;
  else
    v65 = 0;
  BYTE2(source.elements[1]) ^= (BYTE2(source.elements[1]) ^ (2 * v65)) & 2;
  if ( vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)&stru_9683C8.destroyer,
         v136) )
  {
    v67 = (char)vostok::render::custom_config_value::operator[](v66, (const char *)&stru_9683C8.destroyer)->data;
  }
  else
  {
    v67 = 0;
  }
  BYTE2(source.elements[1]) ^= (BYTE2(source.elements[1]) ^ (4 * v67)) & 4;
  if ( vostok::render::custom_config_value::value_exists(&stru_9683F4, v137) )
    v69 = (char)vostok::render::custom_config_value::operator[](v68, (const char *)&stru_9683F4)->data;
  else
    v69 = 0;
  BYTE2(source.elements[1]) ^= (BYTE2(source.elements[1]) ^ (16 * v69)) & 0x10;
  if ( vostok::render::custom_config_value::value_exists(&stru_968414, v138) )
    v71 = (char)vostok::render::custom_config_value::operator[](v70, (const char *)&stru_968414)->data;
  else
    v71 = 0;
  BYTE2(source.elements[1]) ^= (BYTE2(source.elements[1]) ^ (32 * v71)) & 0x20;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_966284,
    "skin_combine",
    (const char *)&source,
    v139,
    compiler,
    v152,
    custom_config);
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
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v140);
  if ( (LOBYTE(source.x) & 1) != 0 )
  {
    v73 = vostok::render::custom_config_value::operator[](v72, "texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (const char *)v73->data,
      0,
      (bool)v141,
      0xFFFFFFFF);
  }
  v74 = vostok::render::custom_config_value::operator[](v72, (const char *)&stru_967F74);
  vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v75, &si128, (int)v74);
  si128 = (vostok::math::float4)_mm_load_si128((const __m128i *)&si128);
  if ( (LOBYTE(source.x) & 8) != 0 )
  {
    v77 = vostok::render::custom_config_value::operator[](v76, "texture_normal");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_normal",
      (const char *)v77->data,
      0,
      (bool)v141,
      0xFFFFFFFF);
  }
  if ( (BYTE2(source.elements[1]) & 4) != 0 && vostok::render::custom_config_value::value_exists(&stru_96843C, v141) )
  {
    v78 = vostok::render::custom_config_value::operator[](v76, (const char *)&stru_96843C);
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_sss_amount",
      (const char *)v78->data,
      0,
      (bool)v141,
      0xFFFFFFFF);
  }
  if ( (BYTE2(source.elements[1]) & 0x10) != 0 && vostok::render::custom_config_value::value_exists(&stru_968468, v141) )
  {
    v79 = vostok::render::custom_config_value::operator[](v76, (const char *)&stru_968468);
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_back_color",
      (const char *)v79->data,
      0,
      (bool)v141,
      0xFFFFFFFF);
  }
  if ( (BYTE2(source.elements[1]) & 0x20) != 0 && vostok::render::custom_config_value::value_exists(&stru_968494, v141) )
  {
    v80 = vostok::render::custom_config_value::operator[](v76, (const char *)&stru_968494);
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_subdermal",
      (const char *)v80->data,
      0,
      (bool)v141,
      0xFFFFFFFF);
  }
  if ( (BYTE2(source.elements[1]) & 2) != 0 && vostok::render::custom_config_value::value_exists(&stru_9684B4, v141) )
  {
    v81 = vostok::render::custom_config_value::operator[](v76, (const char *)&stru_9684B4);
    vostok::render::effect_compiler::set_texture(
      compiler,
      (const char *)&stru_9684B4.type,
      (const char *)v81->data,
      0,
      (bool)v141,
      0xFFFFFFFF);
  }
  if ( SLOBYTE(source.x) < 0 )
  {
    v82 = vostok::render::custom_config_value::operator[](v76, "texture_specular_intensity");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_specular_intensity",
      (const char *)v82->data,
      0,
      (bool)v141,
      0xFFFFFFFF);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_968028, v141)
    && vostok::render::custom_config_value::value_exists(&stru_968040, v142) )
  {
    v84 = vostok::render::custom_config_value::operator[](v83, (const char *)&stru_968040);
    vostok::render::custom_config_value::operator<vostok::math::float3> vostok::math::float3(v85, &source, (int)v84);
    v87 = vostok::render::custom_config_value::operator[](v86, (const char *)&stru_968028);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v88, &v157, (int)v87);
    source.x = v157.x * source.x;
    source.y = source.y * v157.y;
    source.z = source.z * v157.z;
    v90 = vostok::strings::shared::manager::string(v89, (const char *)s_manager.m_variable);
    v111.m_pointer.m_object = 0;
    if ( v90 )
    {
      v111.m_pointer.m_object = v90;
      _InterlockedExchangeAdd(&v90->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(&source, compiler, v111);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_9684C8, v142)
    && vostok::render::custom_config_value::value_exists(&stru_9684C8, v143) )
  {
    v92 = vostok::render::custom_config_value::operator[](v91, (const char *)&stru_9684C8);
    *(float *)predicate = vostok::render::custom_config_value::operator<float> float(v93, (int)v92);
    v95 = vostok::strings::shared::manager::string(v94, (const char *)s_manager.m_variable);
    v112.m_pointer.m_object = 0;
    if ( v95 )
    {
      v112.m_pointer.m_object = v95;
      v96 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v95->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<float>((const float *)predicate, v96, compiler, v112);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_968340, v143)
    && vostok::render::custom_config_value::value_exists(&stru_968340, v144) )
  {
    v98 = vostok::render::custom_config_value::operator[](v97, (const char *)&stru_968340);
    *(float *)predicate = vostok::render::custom_config_value::operator<float> float(v99, (int)v98);
    v101 = vostok::strings::shared::manager::string(v100, (const char *)s_manager.m_variable);
    v113.m_pointer.m_object = 0;
    if ( v101 )
    {
      v113.m_pointer.m_object = v101;
      v102 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v101->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<float>((const float *)predicate, v102, compiler, v113);
  }
  v103 = vostok::strings::shared::manager::string(
           (vostok::strings::shared::manager *)v97,
           (const char *)s_manager.m_variable);
  v114.m_pointer.m_object = 0;
  if ( v103 )
  {
    v114.m_pointer.m_object = v103;
    _InterlockedExchangeAdd(&v103->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&si128,
    compiler,
    v114);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering",
    "$user$skin_scattering",
    0,
    (bool)v144,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering_blurred_0",
    "$user$skin_scattering_blurred0",
    0,
    v145,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering_blurred_1",
    "$user$skin_scattering_blurred1",
    0,
    v146,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering_blurred_2",
    "$user$skin_scattering_blurred2",
    0,
    v147,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering_blurred_3",
    "$user$skin_scattering_blurred3",
    0,
    v148,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering_blurred_4",
    "$user$skin_scattering_blurred4",
    0,
    v149,
    0xFFFFFFFF);
  vostok::render::effect_compiler::end_pass(v104);
  vostok::render::effect_compiler::end_technique(v105);
}
