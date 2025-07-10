void __thiscall vostok::render::effect_lighting_stage_default_materials::compile(
        vostok::render::effect_lighting_stage_default_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  vostok::render::custom_config_value *v3; // ecx
  vostok::render::custom_config_value *v4; // ecx
  vostok::render::custom_config_value *v5; // ecx
  vostok::render::custom_config_value *v6; // ecx
  char data; // al
  vostok::render::custom_config_value *v8; // ecx
  char v9; // al
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
  char v20; // al
  vostok::render::custom_config_value *v21; // ecx
  const vostok::render::custom_config_value *v22; // eax
  const vostok::render::custom_config_value *v23; // eax
  vostok::render::custom_config_value *v24; // ecx
  const vostok::render::custom_config_value *v25; // eax
  vostok::render::custom_config_value *v26; // ecx
  vostok::render::custom_config_value *v27; // ecx
  const vostok::render::custom_config_value *v28; // eax
  vostok::render::custom_config_value *v29; // ecx
  vostok::strings::shared::manager *v30; // ecx
  vostok::strings::shared::profile *v31; // eax
  vostok::render::custom_config_value *v32; // ecx
  const vostok::render::custom_config_value *v33; // eax
  vostok::render::custom_config_value *v34; // ecx
  vostok::render::custom_config_value *v35; // ecx
  const vostok::render::custom_config_value *v36; // eax
  vostok::render::custom_config_value *v37; // ecx
  vostok::strings::shared::manager *v38; // ecx
  vostok::strings::shared::profile *v39; // eax
  vostok::strings::shared::profile *v40; // eax
  vostok::strings::shared::profile *v41; // ecx
  vostok::render::custom_config_value *v42; // ecx
  const vostok::render::custom_config_value *v43; // eax
  vostok::render::custom_config_value *v44; // ecx
  const vostok::render::custom_config_value *v45; // eax
  vostok::render::custom_config_value *v46; // ecx
  vostok::render::custom_config_value *v47; // ecx
  const vostok::render::custom_config_value *v48; // eax
  vostok::render::custom_config_value *v49; // ecx
  double v50; // st7
  const vostok::render::custom_config_value *v51; // eax
  vostok::render::custom_config_value *v52; // ecx
  const vostok::render::custom_config_value *v53; // eax
  vostok::render::custom_config_value *v54; // ecx
  const vostok::render::custom_config_value *v55; // eax
  vostok::render::custom_config_value *v56; // ecx
  vostok::render::custom_config_value *v57; // ecx
  const vostok::render::custom_config_value *v58; // eax
  vostok::render::custom_config_value *v59; // ecx
  double v60; // st7
  const vostok::render::custom_config_value *v61; // eax
  vostok::render::custom_config_value *v62; // ecx
  vostok::strings::shared::profile *v63; // eax
  vostok::render::custom_config_value *v64; // ecx
  const vostok::render::custom_config_value *v65; // eax
  vostok::render::custom_config_value *v66; // ecx
  const vostok::render::custom_config_value *v67; // eax
  vostok::render::custom_config_value *v68; // ecx
  vostok::strings::shared::profile *v69; // eax
  vostok::render::effect_constant_storage *v70; // ecx
  vostok::strings::shared::profile *v71; // ecx
  vostok::strings::shared::profile *v72; // eax
  vostok::strings::shared::profile *v73; // ecx
  vostok::render::effect_compiler *v74; // ecx
  vostok::render::effect_compiler *v75; // ecx
  vostok::render::custom_config_value *v76; // ecx
  vostok::render::custom_config_value *v77; // ecx
  const vostok::render::custom_config_value *v78; // eax
  vostok::render::custom_config_value *v79; // ecx
  const vostok::render::custom_config_value *v80; // eax
  vostok::render::custom_config_value *v81; // ecx
  const vostok::render::custom_config_value *v82; // eax
  vostok::render::custom_config_value *v83; // ecx
  char v84; // al
  vostok::render::custom_config_value *v85; // ecx
  char v86; // al
  vostok::render::custom_config_value *v87; // ecx
  char v88; // al
  vostok::render::custom_config_value *v89; // ecx
  const vostok::render::custom_config_value *v90; // eax
  const vostok::render::custom_config_value *v91; // eax
  vostok::render::custom_config_value *v92; // ecx
  vostok::math::float4 v93; // xmm0
  vostok::strings::shared::profile *v94; // ecx
  vostok::strings::shared::profile *v95; // eax
  vostok::render::custom_config_value *v96; // ecx
  const vostok::render::custom_config_value *v97; // eax
  const vostok::render::custom_config_value *v98; // eax
  vostok::render::custom_config_value *v99; // ecx
  const vostok::render::custom_config_value *v100; // eax
  vostok::render::custom_config_value *v101; // ecx
  vostok::strings::shared::profile *v102; // eax
  vostok::render::effect_constant_storage *v103; // ecx
  vostok::render::custom_config_value *v104; // ecx
  const vostok::render::custom_config_value *v105; // eax
  vostok::render::custom_config_value *v106; // ecx
  const vostok::render::custom_config_value *v107; // eax
  vostok::render::custom_config_value *v108; // ecx
  vostok::render::custom_config_value *v109; // ecx
  const vostok::render::custom_config_value *v110; // eax
  vostok::render::custom_config_value *v111; // ecx
  double v112; // st7
  const vostok::render::custom_config_value *v113; // eax
  vostok::render::custom_config_value *v114; // ecx
  const vostok::render::custom_config_value *v115; // eax
  vostok::render::custom_config_value *v116; // ecx
  const vostok::render::custom_config_value *v117; // eax
  vostok::render::custom_config_value *v118; // ecx
  vostok::render::custom_config_value *v119; // ecx
  const vostok::render::custom_config_value *v120; // eax
  vostok::render::custom_config_value *v121; // ecx
  double v122; // st7
  const vostok::render::custom_config_value *v123; // eax
  vostok::render::custom_config_value *v124; // ecx
  vostok::strings::shared::profile *v125; // eax
  vostok::render::custom_config_value *v126; // ecx
  const vostok::render::custom_config_value *v127; // eax
  const vostok::render::custom_config_value *v128; // eax
  vostok::render::custom_config_value *v129; // ecx
  vostok::render::custom_config_value *v130; // ecx
  const vostok::render::custom_config_value *v131; // eax
  vostok::render::custom_config_value *v132; // ecx
  double v133; // st7
  vostok::strings::shared::profile *v134; // eax
  vostok::render::custom_config_value *v135; // ecx
  const vostok::render::custom_config_value *v136; // eax
  vostok::render::custom_config_value *v137; // ecx
  vostok::render::custom_config_value *v138; // ecx
  const vostok::render::custom_config_value *v139; // eax
  vostok::render::custom_config_value *v140; // ecx
  vostok::strings::shared::profile *v141; // ecx
  vostok::strings::shared::profile *v142; // eax
  vostok::strings::shared::profile *v143; // eax
  vostok::render::effect_compiler *v144; // ecx
  vostok::render::effect_compiler *v145; // ecx
  vostok::shared_string v146; // [esp+204h] [ebp-64h] BYREF
  const char *v147; // [esp+208h] [ebp-60h]
  vostok::render::shader_configuration *v148; // [esp+20Ch] [ebp-5Ch]
  char v149; // [esp+21Ch] [ebp-4Ch]
  char v150; // [esp+21Dh] [ebp-4Bh]
  bool v151; // [esp+21Eh] [ebp-4Ah]
  bool v152; // [esp+21Fh] [ebp-49h]
  bool v153; // [esp+220h] [ebp-48h]
  bool v154; // [esp+221h] [ebp-47h]
  char v155; // [esp+222h] [ebp-46h]
  char v156; // [esp+223h] [ebp-45h]
  vostok::command_line::key_initializator predicate[4]; // [esp+224h] [ebp-44h] BYREF
  vostok::math::float4 source; // [esp+228h] [ebp-40h] BYREF
  vostok::render::effect_constant_storage geometry_shader_name; // [esp+238h] [ebp-30h] BYREF
  vostok::math::float4 v160; // [esp+248h] [ebp-20h] BYREF
  vostok::math::float4 si128; // [esp+258h] [ebp-10h] BYREF

  geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data = (vostok::render::data_indexer *)4;
  geometry_shader_name.m_indexers._M_impl._M_start = 0;
  geometry_shader_name.m_indexers._M_impl._M_finish = 0;
  geometry_shader_name.m_constant_buffer = 0;
  LOBYTE(geometry_shader_name.m_indexers._M_impl._M_start) = (int)vostok::render::custom_config_value::operator[](
                                                                    (vostok::render::custom_config_value *)this,
                                                                    (const char *)&stru_9667A8)->data
                                                           & 1;
  LOBYTE(v4) = (LOBYTE(geometry_shader_name.m_indexers._M_impl._M_start)
              ^ (8 * LOBYTE(vostok::render::custom_config_value::operator[](v3, (const char *)&stru_967F04)->data)))
             & 8
             ^ LOBYTE(geometry_shader_name.m_indexers._M_impl._M_start);
  LOBYTE(geometry_shader_name.m_indexers._M_impl._M_start) = ((unsigned __int8)v4
                                                            ^ (2
                                                             * LOBYTE(vostok::render::custom_config_value::operator[](
                                                                        v4,
                                                                        (const char *)&stru_960A44)->data)))
                                                           & 2
                                                           ^ (unsigned __int8)v4;
  LOBYTE(v5) = geometry_shader_name.m_indexers._M_impl._M_start;
  BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) = (16
                                                           * LOBYTE(vostok::render::custom_config_value::operator[](
                                                                      v5,
                                                                      (const char *)&stru_967DE4.destroyer)->data))
                                                          & 0x10;
  if ( vostok::render::custom_config_value::value_exists((vostok::render::custom_config_value *)&stru_967F04.type, v147) )
    data = (char)vostok::render::custom_config_value::operator[](v6, (const char *)&stru_967F04.type)->data;
  else
    data = 0;
  LOBYTE(geometry_shader_name.m_indexers._M_impl._M_start) = (int)geometry_shader_name.m_indexers._M_impl._M_start
                                                           & 0x7F
                                                           | (data << 7);
  if ( vostok::render::custom_config_value::value_exists(&stru_967F28, v147) )
    v9 = (char)vostok::render::custom_config_value::operator[](v8, (const char *)&stru_967F28)->data;
  else
    v9 = 0;
  BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) ^= (BYTE1(geometry_shader_name.m_indexers._M_impl._M_start)
                                                            ^ v9)
                                                           & 1;
  if ( vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)&stru_967F28.destroyer,
         v147) )
  {
    v11 = (char)vostok::render::custom_config_value::operator[](v10, (const char *)&stru_967F28.destroyer)->data;
  }
  else
  {
    v11 = 0;
  }
  BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) ^= (BYTE1(geometry_shader_name.m_indexers._M_impl._M_start)
                                                            ^ (2 * v11))
                                                           & 2;
  if ( vostok::render::custom_config_value::value_exists(&stru_967F48, v147) )
    v13 = (char)vostok::render::custom_config_value::operator[](v12, (const char *)&stru_967F48)->data;
  else
    v13 = 0;
  BYTE2(geometry_shader_name.m_indexers._M_impl._M_finish) ^= (BYTE2(geometry_shader_name.m_indexers._M_impl._M_finish)
                                                             ^ v13)
                                                            & 1;
  if ( vostok::render::custom_config_value::value_exists(&stru_967E08, v147) )
    v15 = (char)vostok::render::custom_config_value::operator[](v14, (const char *)&stru_967E08)->data;
  else
    v15 = 0;
  BYTE2(geometry_shader_name.m_indexers._M_impl._M_start) &= 0xFu;
  HIBYTE(geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data) ^= (HIBYTE(geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data)
                                                                              ^ (4 * v15))
                                                                             & 4;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_966284,
    "forward_lighting",
    (const char *)&geometry_shader_name,
    v147,
    compiler,
    v148,
    custom_config);
  v150 = (int)geometry_shader_name.m_indexers._M_impl._M_start & 1;
  if ( ((int)geometry_shader_name.m_indexers._M_impl._M_start & 1) != 0 )
  {
    v17 = vostok::render::custom_config_value::operator[](v16, "texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (const char *)v17->data,
      0,
      (bool)v147,
      0xFFFFFFFF);
  }
  v18 = vostok::render::custom_config_value::operator[](v16, (const char *)&stru_967F74);
  vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v19, &si128, (int)v18);
  v20 = HIBYTE(geometry_shader_name.m_indexers._M_impl._M_start) >> 2;
  si128 = (vostok::math::float4)_mm_load_si128((const __m128i *)&si128);
  si128.w = 0.0;
  v149 = HIBYTE(geometry_shader_name.m_indexers._M_impl._M_start) >> 2;
  if ( (HIBYTE(geometry_shader_name.m_indexers._M_impl._M_start) >> 2 == 7 || v20 == 8 || v20 == 9)
    && !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      predicate[0] = 0;
      v146.m_pointer.m_object = *(vostok::strings::shared::profile **)predicate;
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
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_jitter_lookup",
    "$user$jitter_lookup",
    0,
    (bool)v147,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    (D3D11_BLEND_OP)v147);
  v151 = ((int)geometry_shader_name.m_indexers._M_impl._M_start & 8) != 0;
  if ( ((int)geometry_shader_name.m_indexers._M_impl._M_start & 8) != 0 )
  {
    v22 = vostok::render::custom_config_value::operator[](v21, "texture_normal");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_normal",
      (const char *)v22->data,
      0,
      (bool)v147,
      0xFFFFFFFF);
  }
  source.x = 0.0;
  *(_QWORD *)&source.elements[1] = (unsigned int)clear_value;
  source.w = 0.0;
  v156 = LOBYTE(geometry_shader_name.m_indexers._M_impl._M_start) >> 7;
  if ( SLOBYTE(geometry_shader_name.m_indexers._M_impl._M_start) < 0 )
  {
    v23 = vostok::render::custom_config_value::operator[](v21, "texture_specular_intensity");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_specular_intensity",
      (const char *)v23->data,
      0,
      (bool)v147,
      0xFFFFFFFF);
    if ( vostok::render::custom_config_value::value_exists(&stru_967FCC, v147) )
    {
      v25 = vostok::render::custom_config_value::operator[](v24, (const char *)&stru_967FCC);
      source.x = vostok::render::custom_config_value::operator<float> float(v26, (int)v25);
      v28 = vostok::render::custom_config_value::operator[](v27, "constant_specular_intensity_max");
      source.y = vostok::render::custom_config_value::operator<float> float(v29, (int)v28) - source.x;
    }
  }
  v153 = (HIBYTE(geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data) & 4) != 0;
  if ( (HIBYTE(geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data) & 4) != 0 )
    vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, (bool)v147, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_jitter_lookup",
    "$user$jitter_lookup",
    0,
    (bool)v147,
    0xFFFFFFFF);
  v31 = vostok::strings::shared::manager::string(v30, (const char *)s_manager.m_variable);
  v146.m_pointer.m_object = 0;
  if ( v31 )
  {
    v146.m_pointer.m_object = v31;
    _InterlockedExchangeAdd(&v31->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&source,
    compiler,
    v146);
  if ( vostok::render::custom_config_value::value_exists(&stru_968028, v147)
    && vostok::render::custom_config_value::value_exists(&stru_968040, v147) )
  {
    v33 = vostok::render::custom_config_value::operator[](v32, (const char *)&stru_968040);
    vostok::render::custom_config_value::operator<vostok::math::float3> vostok::math::float3(
      v34,
      (vostok::math::float3 *)&source,
      (int)v33);
    v36 = vostok::render::custom_config_value::operator[](v35, (const char *)&stru_968028);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v37, &v160, (int)v36);
    source.x = v160.x * source.x;
    source.y = source.y * v160.y;
    source.z = source.z * v160.z;
    v39 = vostok::strings::shared::manager::string(v38, (const char *)s_manager.m_variable);
    v146.m_pointer.m_object = 0;
    if ( v39 )
    {
      v146.m_pointer.m_object = v39;
      _InterlockedExchangeAdd(&v39->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(
      (const vostok::math::float3 *)&source,
      compiler,
      v146);
  }
  v146.m_pointer.m_object = (vostok::strings::shared::profile *)v32;
  *(float *)predicate = COERCE_FLOAT(&v146);
  v40 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v32,
          (const char *)s_manager.m_variable);
  v41 = *(vostok::strings::shared::profile **)predicate;
  **(_DWORD **)predicate = 0;
  if ( v40 )
  {
    v41->m_reference_count = (volatile int)v40;
    _InterlockedExchangeAdd(&v40->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&si128,
    compiler,
    v146);
  v154 = (BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) & 2) != 0;
  memset(&v160, 0, sizeof(v160));
  memset(&source, 0, sizeof(source));
  if ( (BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) & 2) != 0 )
  {
    v43 = vostok::render::custom_config_value::operator[](v42, "texture_roughness");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_roughness",
      (const char *)v43->data,
      0,
      (bool)v147,
      0xFFFFFFFF);
    if ( vostok::render::custom_config_value::value_exists(&stru_9680A0, v147) )
    {
      v45 = vostok::render::custom_config_value::operator[](v44, (const char *)&stru_9680A0);
      source.z = vostok::render::custom_config_value::operator<float> float(v46, (int)v45);
      v48 = vostok::render::custom_config_value::operator[](v47, "constant_roughness_max");
      v50 = vostok::render::custom_config_value::operator<float> float(v49, (int)v48);
      source.w = v50 - source.z;
    }
  }
  else if ( vostok::render::custom_config_value::value_exists(&stru_9680D0, v147) )
  {
    v51 = vostok::render::custom_config_value::operator[](v44, (const char *)&stru_9680D0);
    source.z = vostok::render::custom_config_value::operator<float> float(v52, (int)v51);
  }
  v155 = BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) & 1;
  if ( (BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) & 1) != 0 )
  {
    v53 = vostok::render::custom_config_value::operator[](v44, "texture_fresnel");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_fresnel",
      (const char *)v53->data,
      0,
      (bool)v147,
      0xFFFFFFFF);
    if ( vostok::render::custom_config_value::value_exists(&stru_968100, v147) )
    {
      v55 = vostok::render::custom_config_value::operator[](v54, (const char *)&stru_968100);
      source.x = vostok::render::custom_config_value::operator<float> float(v56, (int)v55);
      v58 = vostok::render::custom_config_value::operator[](v57, "constant_fresnel_max");
      v60 = vostok::render::custom_config_value::operator<float> float(v59, (int)v58);
      source.y = v60 - source.x;
    }
  }
  else if ( vostok::render::custom_config_value::value_exists(&stru_968130, v147) )
  {
    v61 = vostok::render::custom_config_value::operator[](v54, (const char *)&stru_968130);
    source.x = vostok::render::custom_config_value::operator<float> float(v62, (int)v61);
  }
  v146.m_pointer.m_object = (vostok::strings::shared::profile *)v54;
  v63 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v54,
          (const char *)s_manager.m_variable);
  v146.m_pointer.m_object = 0;
  if ( v63 )
  {
    v146.m_pointer.m_object = v63;
    _InterlockedExchangeAdd(&v63->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&source,
    compiler,
    v146);
  v152 = (BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) & 0x10) != 0;
  if ( (BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) & 0x10) != 0 )
  {
    v65 = vostok::render::custom_config_value::operator[](v64, (const char *)&stru_967E3C);
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_transparency",
      (const char *)v65->data,
      0,
      (bool)v147,
      0xFFFFFFFF);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_967E64, v147) )
  {
    v67 = vostok::render::custom_config_value::operator[](v66, (const char *)&stru_967E64);
    *(float *)predicate = vostok::render::custom_config_value::operator<float> float(v68, (int)v67);
  }
  else
  {
    *(float *)predicate = *(float *)&clear_value;
  }
  v146.m_pointer.m_object = (vostok::strings::shared::profile *)v66;
  v69 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v66,
          (const char *)s_manager.m_variable);
  v146.m_pointer.m_object = 0;
  if ( v69 )
  {
    v146.m_pointer.m_object = v69;
    v70 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v69->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>((const float *)predicate, v70, compiler, v146);
  v146.m_pointer.m_object = v71;
  *(float *)predicate = COERCE_FLOAT(&v146);
  v72 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v71,
          (const char *)s_manager.m_variable);
  v73 = *(vostok::strings::shared::profile **)predicate;
  **(_DWORD **)predicate = 0;
  if ( v72 )
  {
    v73->m_reference_count = (volatile int)v72;
    _InterlockedExchangeAdd(&v72->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&v160,
    compiler,
    v146);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_cascaded_shadow_map",
    "$user$cascaded_shadow_map",
    0,
    (bool)v147,
    0xFFFFFFFF);
  v146.m_pointer.m_object = (vostok::strings::shared::profile *)compiler;
  vostok::render::effect_compiler::end_pass(v74);
  vostok::render::effect_compiler::end_technique(v75);
  geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data = (vostok::render::data_indexer *)4;
  geometry_shader_name.m_indexers._M_impl._M_start = 0;
  geometry_shader_name.m_indexers._M_impl._M_finish = 0;
  geometry_shader_name.m_constant_buffer = 0;
  BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) = 16
                                                          * ((int)vostok::render::custom_config_value::operator[](
                                                                    v76,
                                                                    (const char *)&stru_967DE4.destroyer)->data
                                                           & 1);
  v78 = vostok::render::custom_config_value::operator[](v77, (const char *)&stru_9667A8);
  LOBYTE(geometry_shader_name.m_indexers._M_impl._M_start) ^= (LOBYTE(v78->data)
                                                             ^ LOBYTE(geometry_shader_name.m_indexers._M_impl._M_start))
                                                            & 1;
  LOBYTE(v79) = geometry_shader_name.m_indexers._M_impl._M_start;
  v80 = vostok::render::custom_config_value::operator[](v79, (const char *)&stru_967F04);
  LOBYTE(geometry_shader_name.m_indexers._M_impl._M_start) ^= (LOBYTE(geometry_shader_name.m_indexers._M_impl._M_start)
                                                             ^ (8 * LOBYTE(v80->data)))
                                                            & 8;
  LOBYTE(v81) = geometry_shader_name.m_indexers._M_impl._M_start;
  v82 = vostok::render::custom_config_value::operator[](v81, (const char *)&stru_960A44);
  LOBYTE(geometry_shader_name.m_indexers._M_impl._M_start) ^= (LOBYTE(geometry_shader_name.m_indexers._M_impl._M_start)
                                                             ^ (2 * LOBYTE(v82->data)))
                                                            & 2;
  if ( vostok::render::custom_config_value::value_exists(&stru_967F28, v147) )
    v84 = (char)vostok::render::custom_config_value::operator[](v83, (const char *)&stru_967F28)->data;
  else
    v84 = 0;
  BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) ^= (BYTE1(geometry_shader_name.m_indexers._M_impl._M_start)
                                                            ^ v84)
                                                           & 1;
  if ( vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)&stru_967F28.destroyer,
         v147) )
  {
    v86 = (char)vostok::render::custom_config_value::operator[](v85, (const char *)&stru_967F28.destroyer)->data;
  }
  else
  {
    v86 = 0;
  }
  BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) ^= (BYTE1(geometry_shader_name.m_indexers._M_impl._M_start)
                                                            ^ (2 * v86))
                                                           & 2;
  if ( vostok::render::custom_config_value::value_exists(&stru_967E08, v147) )
    v88 = (char)vostok::render::custom_config_value::operator[](v87, (const char *)&stru_967E08)->data;
  else
    v88 = 0;
  HIBYTE(geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data) ^= (HIBYTE(geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data)
                                                                              ^ (4 * v88))
                                                                             & 4;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_966284,
    "forward_probe_lighting",
    (const char *)&geometry_shader_name,
    v147,
    compiler,
    v148,
    custom_config);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    (D3D11_BLEND_OP)v147);
  if ( (v149 == 7 || v149 == 8 || v149 == 9) && !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      predicate[0] = 0;
      v146.m_pointer.m_object = *(vostok::strings::shared::profile **)predicate;
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
  if ( v150 )
  {
    v90 = vostok::render::custom_config_value::operator[](v89, "texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (const char *)v90->data,
      0,
      (bool)v147,
      0xFFFFFFFF);
  }
  v91 = vostok::render::custom_config_value::operator[](v89, (const char *)&stru_967F74);
  vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v92, &si128, (int)v91);
  v93 = (vostok::math::float4)_mm_load_si128((const __m128i *)&si128);
  v146.m_pointer.m_object = v94;
  si128 = v93;
  si128.w = 0.0;
  v95 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v94,
          (const char *)s_manager.m_variable);
  v146.m_pointer.m_object = 0;
  if ( v95 )
  {
    v146.m_pointer.m_object = v95;
    _InterlockedExchangeAdd(&v95->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&si128,
    compiler,
    v146);
  if ( v151 )
  {
    v97 = vostok::render::custom_config_value::operator[](v96, "texture_normal");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_normal",
      (const char *)v97->data,
      0,
      (bool)v147,
      0xFFFFFFFF);
  }
  if ( v152 )
  {
    v98 = vostok::render::custom_config_value::operator[](v96, (const char *)&stru_967E3C);
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_transparency",
      (const char *)v98->data,
      0,
      (bool)v147,
      0xFFFFFFFF);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_967E64, v147) )
  {
    v100 = vostok::render::custom_config_value::operator[](v99, (const char *)&stru_967E64);
    *(float *)predicate = vostok::render::custom_config_value::operator<float> float(v101, (int)v100);
  }
  else
  {
    *(float *)predicate = *(float *)&clear_value;
  }
  v146.m_pointer.m_object = (vostok::strings::shared::profile *)v99;
  v102 = vostok::strings::shared::manager::string(
           (vostok::strings::shared::manager *)v99,
           (const char *)s_manager.m_variable);
  v146.m_pointer.m_object = 0;
  if ( v102 )
  {
    v146.m_pointer.m_object = v102;
    v103 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v102->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>((const float *)predicate, v103, compiler, v146);
  if ( v153 )
    vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, (bool)v147, 0xFFFFFFFF);
  memset(&geometry_shader_name, 0, sizeof(geometry_shader_name));
  if ( v154 )
  {
    v105 = vostok::render::custom_config_value::operator[](v104, "texture_roughness");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_roughness",
      (const char *)v105->data,
      0,
      (bool)v147,
      0xFFFFFFFF);
    if ( vostok::render::custom_config_value::value_exists(&stru_9680A0, v147) )
    {
      v107 = vostok::render::custom_config_value::operator[](v106, (const char *)&stru_9680A0);
      *(float *)&geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data = vostok::render::custom_config_value::operator<float> float(
                                                                                       v108,
                                                                                       (int)v107);
      v110 = vostok::render::custom_config_value::operator[](v109, "constant_roughness_max");
      v112 = vostok::render::custom_config_value::operator<float> float(v111, (int)v110);
      *(float *)&geometry_shader_name.m_constant_buffer = v112
                                                        - *(float *)&geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data;
    }
  }
  else if ( vostok::render::custom_config_value::value_exists(&stru_9680D0, v147) )
  {
    v113 = vostok::render::custom_config_value::operator[](v106, (const char *)&stru_9680D0);
    *(float *)&geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data = vostok::render::custom_config_value::operator<float> float(
                                                                                     v114,
                                                                                     (int)v113);
  }
  if ( v155 )
  {
    v115 = vostok::render::custom_config_value::operator[](v106, "texture_fresnel");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_fresnel",
      (const char *)v115->data,
      0,
      (bool)v147,
      0xFFFFFFFF);
    if ( vostok::render::custom_config_value::value_exists(&stru_968100, v147) )
    {
      v117 = vostok::render::custom_config_value::operator[](v116, (const char *)&stru_968100);
      *(float *)&geometry_shader_name.m_indexers._M_impl._M_start = vostok::render::custom_config_value::operator<float> float(
                                                                      v118,
                                                                      (int)v117);
      v120 = vostok::render::custom_config_value::operator[](v119, "constant_fresnel_max");
      v122 = vostok::render::custom_config_value::operator<float> float(v121, (int)v120);
      *(float *)&geometry_shader_name.m_indexers._M_impl._M_finish = v122
                                                                   - *(float *)&geometry_shader_name.m_indexers._M_impl._M_start;
    }
  }
  else if ( vostok::render::custom_config_value::value_exists(&stru_968130, v147) )
  {
    v123 = vostok::render::custom_config_value::operator[](v116, (const char *)&stru_968130);
    *(float *)&geometry_shader_name.m_indexers._M_impl._M_start = vostok::render::custom_config_value::operator<float> float(
                                                                    v124,
                                                                    (int)v123);
  }
  v146.m_pointer.m_object = (vostok::strings::shared::profile *)v116;
  v125 = vostok::strings::shared::manager::string(
           (vostok::strings::shared::manager *)v116,
           (const char *)s_manager.m_variable);
  v146.m_pointer.m_object = 0;
  if ( v125 )
  {
    v146.m_pointer.m_object = v125;
    _InterlockedExchangeAdd(&v125->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&geometry_shader_name, compiler, v146);
  geometry_shader_name.m_indexers._M_impl._M_start = 0;
  geometry_shader_name.m_indexers._M_impl._M_finish = (vostok::render::data_indexer *)clear_value;
  geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data = 0;
  geometry_shader_name.m_constant_buffer = 0;
  if ( v156 )
  {
    v127 = vostok::render::custom_config_value::operator[](v126, "texture_specular_intensity");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_specular_intensity",
      (const char *)v127->data,
      0,
      (bool)v147,
      0xFFFFFFFF);
    if ( vostok::render::custom_config_value::value_exists(&stru_967FCC, v147) )
    {
      v128 = vostok::render::custom_config_value::operator[](v126, (const char *)&stru_967FCC);
      *(float *)&geometry_shader_name.m_indexers._M_impl._M_start = vostok::render::custom_config_value::operator<float> float(
                                                                      v129,
                                                                      (int)v128);
      v131 = vostok::render::custom_config_value::operator[](v130, "constant_specular_intensity_max");
      v133 = vostok::render::custom_config_value::operator<float> float(v132, (int)v131);
      *(float *)&geometry_shader_name.m_indexers._M_impl._M_finish = v133
                                                                   - *(float *)&geometry_shader_name.m_indexers._M_impl._M_start;
    }
  }
  v146.m_pointer.m_object = (vostok::strings::shared::profile *)v126;
  v134 = vostok::strings::shared::manager::string(
           (vostok::strings::shared::manager *)v126,
           (const char *)s_manager.m_variable);
  v146.m_pointer.m_object = 0;
  if ( v134 )
  {
    v146.m_pointer.m_object = v134;
    _InterlockedExchangeAdd(&v134->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&geometry_shader_name, compiler, v146);
  if ( vostok::render::custom_config_value::value_exists(&stru_968028, v147)
    && vostok::render::custom_config_value::value_exists(&stru_968040, v147) )
  {
    v136 = vostok::render::custom_config_value::operator[](v135, (const char *)&stru_968040);
    vostok::render::custom_config_value::operator<vostok::math::float3> vostok::math::float3(
      v137,
      (vostok::math::float3 *)&source,
      (int)v136);
    v139 = vostok::render::custom_config_value::operator[](v138, (const char *)&stru_968028);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v140, &v160, (int)v139);
    v146.m_pointer.m_object = v141;
    source.x = v160.x * source.x;
    source.y = source.y * v160.y;
    source.z = source.z * v160.z;
    v142 = vostok::strings::shared::manager::string(
             (vostok::strings::shared::manager *)v141,
             (const char *)s_manager.m_variable);
    v146.m_pointer.m_object = 0;
    if ( v142 )
    {
      v146.m_pointer.m_object = v142;
      _InterlockedExchangeAdd(&v142->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(
      (const vostok::math::float3 *)&source,
      compiler,
      v146);
  }
  v146.m_pointer.m_object = (vostok::strings::shared::profile *)v135;
  v143 = vostok::strings::shared::manager::string(
           (vostok::strings::shared::manager *)v135,
           (const char *)s_manager.m_variable);
  v146.m_pointer.m_object = 0;
  if ( v143 )
  {
    v146.m_pointer.m_object = v143;
    _InterlockedExchangeAdd(&v143->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&si128,
    compiler,
    v146);
  v146.m_pointer.m_object = (vostok::strings::shared::profile *)compiler;
  vostok::render::effect_compiler::end_pass(v144);
  vostok::render::effect_compiler::end_technique(v145);
}
