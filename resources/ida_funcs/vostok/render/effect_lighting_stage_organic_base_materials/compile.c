void __thiscall vostok::render::effect_lighting_stage_organic_base_materials::compile(
        vostok::render::effect_lighting_stage_organic_base_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::custom_config_value *v5; // ecx
  vostok::render::custom_config_value *v6; // ecx
  vostok::render::custom_config_value *v7; // ecx
  char data; // al
  vostok::render::custom_config_value *v9; // ecx
  char v10; // al
  vostok::render::custom_config_value *v11; // ecx
  char v12; // al
  vostok::render::custom_config_value *v13; // ecx
  char v14; // al
  vostok::render::custom_config_value *v15; // ecx
  char v16; // al
  vostok::render::custom_config_value *v17; // ecx
  const vostok::render::custom_config_value *v18; // eax
  vostok::render::custom_config_value *v19; // ecx
  vostok::strings::shared::profile *v20; // eax
  vostok::render::effect_constant_storage *v21; // ecx
  vostok::strings::shared::manager *v22; // ecx
  vostok::strings::shared::profile *v23; // eax
  vostok::render::effect_constant_storage *v24; // ecx
  vostok::render::custom_config_value *v25; // ecx
  const vostok::render::custom_config_value *v26; // eax
  vostok::render::custom_config_value *v27; // ecx
  vostok::strings::shared::profile *v28; // eax
  vostok::render::effect_constant_storage *v29; // ecx
  vostok::render::custom_config_value *v30; // ecx
  const vostok::render::custom_config_value *v31; // eax
  vostok::render::custom_config_value *v32; // ecx
  vostok::strings::shared::profile *v33; // eax
  vostok::render::effect_constant_storage *v34; // ecx
  vostok::render::custom_config_value *v35; // ecx
  const vostok::render::custom_config_value *v36; // eax
  const vostok::render::custom_config_value *v37; // eax
  vostok::render::custom_config_value *v38; // ecx
  vostok::render::custom_config_value *v39; // ecx
  const vostok::render::custom_config_value *v40; // eax
  const vostok::render::custom_config_value *v41; // eax
  vostok::render::custom_config_value *v42; // ecx
  const vostok::render::custom_config_value *v43; // eax
  vostok::render::custom_config_value *v44; // ecx
  vostok::render::custom_config_value *v45; // ecx
  const vostok::render::custom_config_value *v46; // eax
  vostok::render::custom_config_value *v47; // ecx
  vostok::strings::shared::manager *v48; // ecx
  vostok::strings::shared::profile *v49; // eax
  vostok::strings::shared::profile *v50; // eax
  vostok::render::custom_config_value *v51; // ecx
  const vostok::render::custom_config_value *v52; // eax
  vostok::render::custom_config_value *v53; // ecx
  const vostok::render::custom_config_value *v54; // eax
  vostok::render::custom_config_value *v55; // ecx
  const vostok::render::custom_config_value *v56; // eax
  vostok::render::custom_config_value *v57; // ecx
  vostok::strings::shared::profile *v58; // eax
  vostok::strings::shared::manager *v59; // ecx
  vostok::strings::shared::profile *v60; // eax
  vostok::render::effect_constant_storage *v61; // ecx
  vostok::render::effect_compiler *v62; // ecx
  vostok::render::effect_compiler *v63; // ecx
  vostok::render::custom_config_value *v64; // ecx
  char v65; // al
  vostok::render::effect_compiler *v66; // ecx
  vostok::render::custom_config_value *v67; // ecx
  const vostok::render::custom_config_value *v68; // eax
  vostok::render::custom_config_value *v69; // ecx
  vostok::render::custom_config_value *v70; // ecx
  const vostok::render::custom_config_value *v71; // eax
  vostok::render::custom_config_value *v72; // ecx
  const vostok::render::custom_config_value *v73; // eax
  vostok::strings::shared::profile *v74; // eax
  vostok::render::effect_compiler *v75; // ecx
  vostok::render::effect_compiler *v76; // ecx
  vostok::render::custom_config_value *v77; // ecx
  char v78; // al
  vostok::render::custom_config_value *v79; // ecx
  char v80; // al
  vostok::render::custom_config_value *v81; // ecx
  char v82; // al
  vostok::render::custom_config_value *v83; // ecx
  char v84; // al
  vostok::render::custom_config_value *v85; // ecx
  char v86; // al
  vostok::render::custom_config_value *v87; // ecx
  char v88; // al
  vostok::render::custom_config_value *v89; // ecx
  char v90; // al
  vostok::render::custom_config_value *v91; // ecx
  const vostok::render::custom_config_value *v92; // eax
  const vostok::render::custom_config_value *v93; // eax
  vostok::render::custom_config_value *v94; // ecx
  vostok::render::custom_config_value *v95; // ecx
  const vostok::render::custom_config_value *v96; // eax
  const vostok::render::custom_config_value *v97; // eax
  const vostok::render::custom_config_value *v98; // eax
  const vostok::render::custom_config_value *v99; // eax
  const vostok::render::custom_config_value *v100; // eax
  const vostok::render::custom_config_value *v101; // eax
  vostok::render::custom_config_value *v102; // ecx
  const vostok::render::custom_config_value *v103; // eax
  vostok::render::custom_config_value *v104; // ecx
  vostok::render::custom_config_value *v105; // ecx
  const vostok::render::custom_config_value *v106; // eax
  vostok::render::custom_config_value *v107; // ecx
  vostok::strings::shared::profile *v108; // eax
  vostok::strings::shared::profile *v109; // eax
  vostok::render::effect_compiler *v110; // ecx
  vostok::render::effect_compiler *v111; // ecx
  vostok::shared_string v112; // [esp+284h] [ebp-64h]
  vostok::shared_string v113; // [esp+284h] [ebp-64h]
  vostok::shared_string v114; // [esp+284h] [ebp-64h]
  vostok::shared_string v115; // [esp+284h] [ebp-64h]
  vostok::shared_string v116; // [esp+284h] [ebp-64h]
  vostok::shared_string v117; // [esp+284h] [ebp-64h]
  vostok::shared_string v118; // [esp+284h] [ebp-64h]
  vostok::shared_string v119; // [esp+284h] [ebp-64h]
  vostok::shared_string v120; // [esp+284h] [ebp-64h]
  vostok::shared_string v121; // [esp+284h] [ebp-64h]
  vostok::shared_string v122; // [esp+284h] [ebp-64h]
  const char *v123; // [esp+288h] [ebp-60h]
  const char *v124; // [esp+288h] [ebp-60h]
  const char *v125; // [esp+288h] [ebp-60h]
  const char *v126; // [esp+288h] [ebp-60h]
  const char *v127; // [esp+288h] [ebp-60h]
  const char *v128; // [esp+288h] [ebp-60h]
  const char *v129; // [esp+288h] [ebp-60h]
  D3D11_BLEND_OP v130; // [esp+288h] [ebp-60h]
  const char *v131; // [esp+288h] [ebp-60h]
  const char *v132; // [esp+288h] [ebp-60h]
  const char *v133; // [esp+288h] [ebp-60h]
  const char *v134; // [esp+288h] [ebp-60h]
  const char *v135; // [esp+288h] [ebp-60h]
  const char *v136; // [esp+288h] [ebp-60h]
  D3D11_BLEND_OP v137; // [esp+288h] [ebp-60h]
  bool v138; // [esp+288h] [ebp-60h]
  const char *v139; // [esp+288h] [ebp-60h]
  const char *v140; // [esp+288h] [ebp-60h]
  const char *v141; // [esp+288h] [ebp-60h]
  const char *v142; // [esp+288h] [ebp-60h]
  const char *v143; // [esp+288h] [ebp-60h]
  const char *v144; // [esp+288h] [ebp-60h]
  const char *v145; // [esp+288h] [ebp-60h]
  const char *v146; // [esp+288h] [ebp-60h]
  const char *v147; // [esp+288h] [ebp-60h]
  const char *v148; // [esp+288h] [ebp-60h]
  D3D11_BLEND_OP v149; // [esp+288h] [ebp-60h]
  const char *v150; // [esp+288h] [ebp-60h]
  const char *v151; // [esp+288h] [ebp-60h]
  bool v152; // [esp+288h] [ebp-60h]
  bool v153; // [esp+288h] [ebp-60h]
  bool v154; // [esp+288h] [ebp-60h]
  bool v155; // [esp+288h] [ebp-60h]
  bool v156; // [esp+288h] [ebp-60h]
  vostok::render::shader_configuration *v157; // [esp+28Ch] [ebp-5Ch]
  vostok::render::shader_configuration *v158; // [esp+28Ch] [ebp-5Ch]
  vostok::render::shader_configuration *v159; // [esp+28Ch] [ebp-5Ch]
  float v160; // [esp+2A0h] [ebp-48h] BYREF
  float source; // [esp+2A4h] [ebp-44h] BYREF
  vostok::render::effect_constant_storage v162; // [esp+2A8h] [ebp-40h] BYREF
  vostok::render::shader_include_getter include_getter; // [esp+2B8h] [ebp-30h] BYREF
  int v164; // [esp+2BCh] [ebp-2Ch]
  int v165; // [esp+2C0h] [ebp-28h]
  int v166; // [esp+2C4h] [ebp-24h]
  vostok::math::float4 geometry_shader_name; // [esp+2C8h] [ebp-20h] BYREF
  vostok::math::float4 si128; // [esp+2D8h] [ebp-10h] BYREF

  geometry_shader_name.x = 0.0;
  *(_QWORD *)&geometry_shader_name.elements[1] = 0x400000000LL;
  geometry_shader_name.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_966284,
    "skin_position_pass",
    (const char *)&geometry_shader_name,
    v123,
    compiler,
    v157,
    custom_config);
  vostok::render::effect_compiler::end_pass(v3);
  vostok::render::effect_compiler::end_technique(v4);
  v165 = 4;
  include_getter.__vftable = 0;
  v164 = 0;
  v166 = 0;
  LOBYTE(include_getter.__vftable) = (int)vostok::render::custom_config_value::operator[](
                                            v5,
                                            (const char *)&stru_9667A8)->data
                                   & 1;
  LOBYTE(include_getter.__vftable) ^= (LOBYTE(include_getter.__vftable)
                                     ^ (8
                                      * LOBYTE(vostok::render::custom_config_value::operator[](
                                                 v6,
                                                 (const char *)&stru_967F04)->data)))
                                    & 8;
  if ( vostok::render::custom_config_value::value_exists(&stru_960A44, v124) )
    data = (char)vostok::render::custom_config_value::operator[](v7, (const char *)&stru_960A44)->data;
  else
    data = 0;
  LOBYTE(include_getter.__vftable) ^= (LOBYTE(include_getter.__vftable) ^ (2 * data)) & 2;
  if ( vostok::render::custom_config_value::value_exists((vostok::render::custom_config_value *)&stru_967F04.type, v125) )
    v10 = (char)vostok::render::custom_config_value::operator[](v9, (const char *)&stru_967F04.type)->data;
  else
    v10 = 0;
  LOBYTE(include_getter.__vftable) = (int)include_getter.__vftable & 0x7F | (v10 << 7);
  if ( vostok::render::custom_config_value::value_exists(&stru_967F28, v126) )
    v12 = (char)vostok::render::custom_config_value::operator[](v11, (const char *)&stru_967F28)->data;
  else
    v12 = 0;
  BYTE1(include_getter.__vftable) ^= (BYTE1(include_getter.__vftable) ^ v12) & 1;
  if ( vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)&stru_967F28.destroyer,
         v127) )
  {
    v14 = (char)vostok::render::custom_config_value::operator[](v13, (const char *)&stru_967F28.destroyer)->data;
  }
  else
  {
    v14 = 0;
  }
  BYTE1(include_getter.__vftable) ^= (BYTE1(include_getter.__vftable) ^ (2 * v14)) & 2;
  if ( vostok::render::custom_config_value::value_exists(&stru_967F48, v128) )
    v16 = (char)vostok::render::custom_config_value::operator[](v15, (const char *)&stru_967F48)->data;
  else
    v16 = 0;
  BYTE1(include_getter.__vftable) |= 0x40u;
  BYTE2(v164) ^= (BYTE2(v164) ^ v16) & 1;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_9681F4,
    "organic_forward_lighting",
    (const char *)&include_getter,
    v129,
    compiler,
    v158,
    custom_config);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v130);
  if ( vostok::render::custom_config_value::value_exists(&stru_969464, v131) )
  {
    v18 = vostok::render::custom_config_value::operator[](v17, (const char *)&stru_969464);
    source = vostok::render::custom_config_value::operator<float> float(v19, (int)v18);
  }
  else
  {
    source = 0.039999999;
  }
  v20 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v17,
          (const char *)s_manager.m_variable);
  v112.m_pointer.m_object = 0;
  if ( v20 )
  {
    v112.m_pointer.m_object = v20;
    v21 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v20->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&source, v21, compiler, v112);
  source = 0.0;
  v23 = vostok::strings::shared::manager::string(v22, (const char *)s_manager.m_variable);
  v113.m_pointer.m_object = 0;
  if ( v23 )
  {
    v113.m_pointer.m_object = v23;
    v24 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v23->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&source, v24, compiler, v113);
  if ( vostok::render::custom_config_value::value_exists(&stru_969490, v132) )
  {
    v26 = vostok::render::custom_config_value::operator[](v25, (const char *)&stru_969490);
    v160 = vostok::render::custom_config_value::operator<float> float(v27, (int)v26);
  }
  else
  {
    v160 = 0.0;
  }
  v28 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v25,
          (const char *)s_manager.m_variable);
  v114.m_pointer.m_object = 0;
  if ( v28 )
  {
    v114.m_pointer.m_object = v28;
    v29 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v28->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&v160, v29, compiler, v114);
  if ( vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)&stru_969490.destroyer,
         v133) )
  {
    v31 = vostok::render::custom_config_value::operator[](v30, (const char *)&stru_969490.destroyer);
    source = vostok::render::custom_config_value::operator<float> float(v32, (int)v31);
  }
  else
  {
    source = *(float *)&clear_value;
  }
  v33 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v30,
          (const char *)s_manager.m_variable);
  v115.m_pointer.m_object = 0;
  if ( v33 )
  {
    v115.m_pointer.m_object = v33;
    v34 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v33->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&source, v34, compiler, v115);
  if ( ((int)include_getter.__vftable & 1) != 0 )
  {
    v36 = vostok::render::custom_config_value::operator[](v35, "texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (const char *)v36->data,
      0,
      (bool)v134,
      0xFFFFFFFF);
  }
  v37 = vostok::render::custom_config_value::operator[](v35, (const char *)&stru_967F74);
  vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v38, &si128, (int)v37);
  si128 = (vostok::math::float4)_mm_load_si128((const __m128i *)&si128);
  si128.w = 0.0;
  if ( ((int)include_getter.__vftable & 8) != 0 )
  {
    v40 = vostok::render::custom_config_value::operator[](v39, "texture_normal");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_normal",
      (const char *)v40->data,
      0,
      (bool)v134,
      0xFFFFFFFF);
  }
  if ( SLOBYTE(include_getter.__vftable) < 0 )
  {
    v41 = vostok::render::custom_config_value::operator[](v39, "texture_specular_intensity");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_specular_intensity",
      (const char *)v41->data,
      0,
      (bool)v134,
      0xFFFFFFFF);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_968028, v134)
    && vostok::render::custom_config_value::value_exists(&stru_968040, v135) )
  {
    v43 = vostok::render::custom_config_value::operator[](v42, (const char *)&stru_968040);
    vostok::render::custom_config_value::operator<vostok::math::float3> vostok::math::float3(
      v44,
      (vostok::math::float3 *)&v162,
      (int)v43);
    v46 = vostok::render::custom_config_value::operator[](v45, (const char *)&stru_968028);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(
      v47,
      &geometry_shader_name,
      (int)v46);
    *(float *)&v162.m_indexers._M_impl._M_start = geometry_shader_name.x * *(float *)&v162.m_indexers._M_impl._M_start;
    *(float *)&v162.m_indexers._M_impl._M_finish = *(float *)&v162.m_indexers._M_impl._M_finish * geometry_shader_name.y;
    *(float *)&v162.m_indexers._M_impl._M_end_of_storage._M_data = *(float *)&v162.m_indexers._M_impl._M_end_of_storage._M_data
                                                                 * geometry_shader_name.z;
    v49 = vostok::strings::shared::manager::string(v48, (const char *)s_manager.m_variable);
    v116.m_pointer.m_object = 0;
    if ( v49 )
    {
      v116.m_pointer.m_object = v49;
      _InterlockedExchangeAdd(&v49->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(
      (const vostok::math::float3 *)&v162,
      compiler,
      v116);
  }
  v50 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v42,
          (const char *)s_manager.m_variable);
  v117.m_pointer.m_object = 0;
  if ( v50 )
  {
    v117.m_pointer.m_object = v50;
    _InterlockedExchangeAdd(&v50->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&si128,
    compiler,
    v117);
  *(_QWORD *)&v162.m_indexers._M_impl._M_start = 0;
  *(float *)&v162.m_indexers._M_impl._M_end_of_storage._M_data = v160;
  *(float *)&v162.m_constant_buffer = source;
  if ( (BYTE1(include_getter.__vftable) & 2) != 0 )
  {
    v52 = vostok::render::custom_config_value::operator[](v51, "texture_specular_power");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_roughness",
      (const char *)v52->data,
      0,
      (bool)v135,
      0xFFFFFFFF);
  }
  else
  {
    if ( vostok::render::custom_config_value::value_exists(&stru_968244, v135) )
    {
      v54 = vostok::render::custom_config_value::operator[](v53, (const char *)&stru_968244);
      *(float *)&v162.m_indexers._M_impl._M_start = vostok::render::custom_config_value::operator<float> float(
                                                      v55,
                                                      (int)v54);
    }
    if ( (v164 & 0x10000) != 0 )
    {
      if ( vostok::render::custom_config_value::value_exists(&stru_9694B0, v136) )
      {
        v56 = vostok::render::custom_config_value::operator[](v53, (const char *)&stru_9694B0);
        *(float *)&v162.m_indexers._M_impl._M_finish = vostok::render::custom_config_value::operator<float> float(
                                                         v57,
                                                         (int)v56);
      }
    }
    else
    {
      v162.m_indexers._M_impl._M_finish = v162.m_indexers._M_impl._M_start;
    }
  }
  v58 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v53,
          (const char *)s_manager.m_variable);
  v118.m_pointer.m_object = 0;
  if ( v58 )
  {
    v118.m_pointer.m_object = v58;
    _InterlockedExchangeAdd(&v58->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v162, compiler, v118);
  source = *(float *)&clear_value;
  v60 = vostok::strings::shared::manager::string(v59, (const char *)s_manager.m_variable);
  v119.m_pointer.m_object = 0;
  if ( v60 )
  {
    v119.m_pointer.m_object = v60;
    v61 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v60->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&source, v61, compiler, v119);
  vostok::render::effect_compiler::end_pass(v62);
  vostok::render::effect_compiler::end_technique(v63);
  v165 = 4;
  include_getter.__vftable = 0;
  v164 = 0;
  v166 = 0;
  if ( vostok::render::custom_config_value::value_exists(&stru_968278, v136) )
    v65 = (char)vostok::render::custom_config_value::operator[](v64, (const char *)&stru_968278)->data;
  else
    v65 = 0;
  BYTE2(v164) = 8 * (v65 & 1);
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)v64);
  vostok::render::effect_compiler::begin_pass(
    v66,
    (const char *)compiler,
    "blur_irradiance_texture",
    0,
    &stru_9694E8,
    &include_getter);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      LOBYTE(source) = 0;
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
    v137);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering",
    "$user$skin_scattering",
    0,
    v138,
    0xFFFFFFFF);
  geometry_shader_name.x = 1.2;
  *(_QWORD *)&geometry_shader_name.elements[1] = __PAIR64__(LODWORD(FLOAT_0_1), LODWORD(s_aim_transition_time));
  LODWORD(geometry_shader_name.w) = clear_value;
  if ( vostok::render::custom_config_value::value_exists(&stru_968318, v139) )
  {
    v68 = vostok::render::custom_config_value::operator[](v67, (const char *)&stru_968318);
    vostok::render::custom_config_value::operator<vostok::math::float3> vostok::math::float3(
      v69,
      (vostok::math::float3 *)&v162,
      (int)v68);
    *(_QWORD *)&geometry_shader_name.x = *(_QWORD *)&v162.m_indexers._M_impl._M_start;
    LODWORD(geometry_shader_name.z) = v162.m_indexers._M_impl._M_end_of_storage._M_data;
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_968340, v140) )
  {
    v71 = vostok::render::custom_config_value::operator[](v70, (const char *)&stru_968340);
    geometry_shader_name.w = vostok::render::custom_config_value::operator<float> float(v72, (int)v71);
  }
  if ( (v164 & 0x80000) != 0 && vostok::render::custom_config_value::value_exists(&stru_96835C, v141) )
  {
    v73 = vostok::render::custom_config_value::operator[](v70, (const char *)&stru_96835C);
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_scattering_depth",
      (const char *)v73->data,
      0,
      (bool)v141,
      0xFFFFFFFF);
  }
  v74 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v70,
          (const char *)s_manager.m_variable);
  v120.m_pointer.m_object = 0;
  if ( v74 )
  {
    v120.m_pointer.m_object = v74;
    _InterlockedExchangeAdd(&v74->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&geometry_shader_name,
    compiler,
    v120);
  vostok::render::effect_compiler::end_pass(v75);
  vostok::render::effect_compiler::end_technique(v76);
  v165 = 4;
  include_getter.__vftable = 0;
  v164 = 0;
  v166 = 0;
  if ( vostok::render::custom_config_value::value_exists(&stru_9667A8, v141) )
    v78 = (char)vostok::render::custom_config_value::operator[](v77, (const char *)&stru_9667A8)->data;
  else
    v78 = 0;
  LOBYTE(include_getter.__vftable) = v78 & 1;
  if ( vostok::render::custom_config_value::value_exists(&stru_967F04, v142) )
    v80 = (char)vostok::render::custom_config_value::operator[](v79, (const char *)&stru_967F04)->data;
  else
    v80 = 0;
  LOBYTE(include_getter.__vftable) ^= (LOBYTE(include_getter.__vftable) ^ (8 * v80)) & 8;
  if ( vostok::render::custom_config_value::value_exists((vostok::render::custom_config_value *)&stru_967F04.type, v143) )
    v82 = (char)vostok::render::custom_config_value::operator[](v81, (const char *)&stru_967F04.type)->data;
  else
    v82 = 0;
  LOBYTE(include_getter.__vftable) = (int)include_getter.__vftable & 0x7F | (v82 << 7);
  if ( vostok::render::custom_config_value::value_exists(&stru_9683C8, v144) )
    v84 = (char)vostok::render::custom_config_value::operator[](v83, (const char *)&stru_9683C8)->data;
  else
    v84 = 0;
  BYTE2(v164) ^= (BYTE2(v164) ^ (2 * v84)) & 2;
  if ( vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)&stru_9683C8.destroyer,
         v145) )
  {
    v86 = (char)vostok::render::custom_config_value::operator[](v85, (const char *)&stru_9683C8.destroyer)->data;
  }
  else
  {
    v86 = 0;
  }
  BYTE2(v164) ^= (BYTE2(v164) ^ (4 * v86)) & 4;
  if ( vostok::render::custom_config_value::value_exists(&stru_9683F4, v146) )
    v88 = (char)vostok::render::custom_config_value::operator[](v87, (const char *)&stru_9683F4)->data;
  else
    v88 = 0;
  BYTE2(v164) ^= (BYTE2(v164) ^ (16 * v88)) & 0x10;
  if ( vostok::render::custom_config_value::value_exists(&stru_968414, v147) )
    v90 = (char)vostok::render::custom_config_value::operator[](v89, (const char *)&stru_968414)->data;
  else
    v90 = 0;
  BYTE2(v164) ^= (BYTE2(v164) ^ (32 * v90)) & 0x20;
  vostok::render::effect_material_base::compile_begin(
    (vostok::render::effect_material_base *)&stru_966284,
    "organic_combine",
    (const char *)&include_getter,
    v148,
    compiler,
    v159,
    custom_config);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      LOBYTE(source) = 0;
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
    v149);
  if ( ((int)include_getter.__vftable & 1) != 0 )
  {
    v92 = vostok::render::custom_config_value::operator[](v91, "texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (const char *)v92->data,
      0,
      (bool)v150,
      0xFFFFFFFF);
  }
  v93 = vostok::render::custom_config_value::operator[](v91, (const char *)&stru_967F74);
  vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v94, &si128, (int)v93);
  si128 = (vostok::math::float4)_mm_load_si128((const __m128i *)&si128);
  if ( ((int)include_getter.__vftable & 8) != 0 )
  {
    v96 = vostok::render::custom_config_value::operator[](v95, "texture_normal");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_normal",
      (const char *)v96->data,
      0,
      (bool)v150,
      0xFFFFFFFF);
  }
  if ( (v164 & 0x40000) != 0 && vostok::render::custom_config_value::value_exists(&stru_96843C, v150) )
  {
    v97 = vostok::render::custom_config_value::operator[](v95, (const char *)&stru_96843C);
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_sss_amount",
      (const char *)v97->data,
      0,
      (bool)v150,
      0xFFFFFFFF);
  }
  if ( (v164 & 0x100000) != 0 && vostok::render::custom_config_value::value_exists(&stru_968468, v150) )
  {
    v98 = vostok::render::custom_config_value::operator[](v95, (const char *)&stru_968468);
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_back_color",
      (const char *)v98->data,
      0,
      (bool)v150,
      0xFFFFFFFF);
  }
  if ( (v164 & 0x200000) != 0 && vostok::render::custom_config_value::value_exists(&stru_968494, v150) )
  {
    v99 = vostok::render::custom_config_value::operator[](v95, (const char *)&stru_968494);
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_subdermal",
      (const char *)v99->data,
      0,
      (bool)v150,
      0xFFFFFFFF);
  }
  if ( (v164 & 0x20000) != 0 && vostok::render::custom_config_value::value_exists(&stru_9684B4, v150) )
  {
    v100 = vostok::render::custom_config_value::operator[](v95, (const char *)&stru_9684B4);
    vostok::render::effect_compiler::set_texture(
      compiler,
      (const char *)&stru_9684B4.type,
      (const char *)v100->data,
      0,
      (bool)v150,
      0xFFFFFFFF);
  }
  if ( SLOBYTE(include_getter.__vftable) < 0 )
  {
    v101 = vostok::render::custom_config_value::operator[](v95, "texture_specular_intensity");
    vostok::render::effect_compiler::set_texture(
      compiler,
      "t_specular_intensity",
      (const char *)v101->data,
      0,
      (bool)v150,
      0xFFFFFFFF);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_968028, v150)
    && vostok::render::custom_config_value::value_exists(&stru_968040, v151) )
  {
    v103 = vostok::render::custom_config_value::operator[](v102, (const char *)&stru_968040);
    vostok::render::custom_config_value::operator<vostok::math::float3> vostok::math::float3(
      v104,
      (vostok::math::float3 *)&v162,
      (int)v103);
    v106 = vostok::render::custom_config_value::operator[](v105, (const char *)&stru_968028);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(
      v107,
      &geometry_shader_name,
      (int)v106);
    *(float *)&v162.m_indexers._M_impl._M_start = geometry_shader_name.x * *(float *)&v162.m_indexers._M_impl._M_start;
    *(float *)&v162.m_indexers._M_impl._M_finish = *(float *)&v162.m_indexers._M_impl._M_finish * geometry_shader_name.y;
    *(float *)&v162.m_indexers._M_impl._M_end_of_storage._M_data = *(float *)&v162.m_indexers._M_impl._M_end_of_storage._M_data
                                                                 * geometry_shader_name.z;
    v108 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
    v121.m_pointer.m_object = 0;
    if ( v108 )
    {
      v121.m_pointer.m_object = v108;
      _InterlockedExchangeAdd(&v108->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(
      (const vostok::math::float3 *)&v162,
      compiler,
      v121);
  }
  v109 = vostok::strings::shared::manager::string(
           (vostok::strings::shared::manager *)v102,
           (const char *)s_manager.m_variable);
  v122.m_pointer.m_object = 0;
  if ( v109 )
  {
    v122.m_pointer.m_object = v109;
    _InterlockedExchangeAdd(&v109->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&si128,
    compiler,
    v122);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering",
    "$user$skin_scattering",
    0,
    (bool)v151,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering_blurred_0",
    "$user$skin_scattering_blurred0",
    0,
    v152,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering_blurred_1",
    "$user$skin_scattering_blurred1",
    0,
    v153,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering_blurred_2",
    "$user$skin_scattering_blurred2",
    0,
    v154,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering_blurred_3",
    "$user$skin_scattering_blurred3",
    0,
    v155,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_skin_scattering_blurred_4",
    "$user$skin_scattering_blurred4",
    0,
    v156,
    0xFFFFFFFF);
  vostok::render::effect_compiler::end_pass(v110);
  vostok::render::effect_compiler::end_technique(v111);
}
