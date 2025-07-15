void __thiscall vostok::render::effect_lighting_stage_organic_base_materials::compile(
        vostok::render::effect_lighting_stage_organic_base_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_material_base *v4; // ecx
  vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  const vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // eax
  bool v11; // al
  vostok::configs::binary_config_value *v12; // ecx
  vostok::configs::binary_config_value *v13; // eax
  bool v14; // al
  vostok::configs::binary_config_value *v15; // ecx
  vostok::configs::binary_config_value *v16; // eax
  bool v17; // al
  vostok::configs::binary_config_value *v18; // ecx
  vostok::configs::binary_config_value *v19; // eax
  bool v20; // al
  vostok::configs::binary_config_value *v21; // ecx
  vostok::configs::binary_config_value *v22; // eax
  char v23; // al
  vostok::render::effect_compiler *v24; // ecx
  vostok::configs::binary_config_value *v25; // ecx
  vostok::render::effect_constant_storage *v26; // ecx
  vostok::configs::binary_config_value *v27; // eax
  const vostok::configs::binary_config_value *v28; // eax
  float pointer; // xmm0_4
  vostok::render::effect_constant_storage *v30; // ecx
  vostok::configs::binary_config_value *v31; // ecx
  vostok::render::effect_constant_storage *v32; // ecx
  vostok::configs::binary_config_value *v33; // eax
  const vostok::configs::binary_config_value *v34; // eax
  float v35; // xmm0_4
  vostok::configs::binary_config_value *v36; // ecx
  vostok::render::effect_constant_storage *v37; // ecx
  vostok::configs::binary_config_value *v38; // eax
  const vostok::configs::binary_config_value *v39; // eax
  float v40; // xmm0_4
  vostok::configs::binary_config_value *v41; // eax
  char **v42; // eax
  vostok::render::effect_compiler *v43; // ecx
  vostok::configs::binary_config_value *v44; // eax
  const vostok::configs::binary_config_value *v45; // eax
  float *v46; // esi
  double v47; // xmm0_8
  double v48; // xmm0_8
  double v49; // xmm0_8
  vostok::configs::binary_config_value *v50; // ecx
  vostok::configs::binary_config_value *v51; // esi
  vostok::configs::binary_config_value *v52; // eax
  char **v53; // eax
  vostok::render::effect_compiler *v54; // ecx
  vostok::configs::binary_config_value *v55; // eax
  char **v56; // eax
  vostok::render::effect_compiler *v57; // ecx
  vostok::configs::binary_config_value *v58; // ecx
  vostok::configs::binary_config_value *v59; // eax
  float **v60; // eax
  float *v61; // esi
  vostok::configs::binary_config_value *v62; // eax
  const vostok::configs::binary_config_value *v63; // eax
  float *v64; // esi
  double v65; // xmm0_8
  double v66; // xmm0_8
  double v67; // xmm0_8
  float v68; // xmm1_4
  vostok::render::effect_constant_storage *v69; // ecx
  vostok::configs::binary_config_value *v70; // ecx
  vostok::configs::binary_config_value *v71; // eax
  char **v72; // eax
  vostok::render::effect_compiler *v73; // ecx
  vostok::configs::binary_config_value *v74; // ecx
  vostok::configs::binary_config_value *v75; // eax
  const vostok::configs::binary_config_value *v76; // eax
  float v77; // xmm0_4
  vostok::configs::binary_config_value *v78; // eax
  const vostok::configs::binary_config_value *v79; // eax
  float x; // xmm0_4
  vostok::render::effect_constant_storage *v81; // ecx
  vostok::render::effect_material_base *v82; // ecx
  vostok::configs::binary_config_value *v83; // ecx
  vostok::render::effect_compiler *v84; // ecx
  vostok::configs::binary_config_value *v85; // eax
  bool v86; // al
  vostok::render::effect_compiler *v87; // ecx
  vostok::render::effect_compiler *v88; // ecx
  vostok::command_line::key *v89; // ecx
  vostok::render::effect_compiler *v90; // ecx
  vostok::render::effect_compiler *v91; // ecx
  vostok::configs::binary_config_value *v92; // ecx
  vostok::configs::binary_config_value *v93; // ecx
  vostok::configs::binary_config_value *v94; // eax
  float **v95; // eax
  float *v96; // esi
  vostok::configs::binary_config_value *v97; // ecx
  vostok::configs::binary_config_value *v98; // eax
  const vostok::configs::binary_config_value *v99; // eax
  float v100; // xmm0_4
  vostok::configs::binary_config_value *v101; // eax
  char **v102; // eax
  vostok::render::effect_compiler *v103; // ecx
  vostok::render::effect_compiler *v104; // ecx
  vostok::render::effect_compiler *v105; // ecx
  vostok::configs::binary_config_value *v106; // ecx
  vostok::configs::binary_config_value *v107; // ecx
  vostok::configs::binary_config_value *v108; // eax
  bool v109; // al
  vostok::configs::binary_config_value *v110; // ecx
  vostok::configs::binary_config_value *v111; // eax
  char v112; // al
  vostok::configs::binary_config_value *v113; // ecx
  vostok::configs::binary_config_value *v114; // eax
  bool v115; // al
  vostok::configs::binary_config_value *v116; // ecx
  vostok::configs::binary_config_value *v117; // eax
  char v118; // al
  vostok::configs::binary_config_value *v119; // ecx
  vostok::configs::binary_config_value *v120; // eax
  bool v121; // al
  vostok::configs::binary_config_value *v122; // ecx
  vostok::configs::binary_config_value *v123; // eax
  bool v124; // al
  vostok::configs::binary_config_value *v125; // ecx
  vostok::configs::binary_config_value *v126; // eax
  bool v127; // al
  vostok::render::effect_compiler *v128; // ecx
  vostok::render::effect_compiler *v129; // ecx
  vostok::configs::binary_config_value *v130; // eax
  char **v131; // eax
  vostok::render::effect_compiler *v132; // ecx
  vostok::configs::binary_config_value *v133; // eax
  const vostok::configs::binary_config_value *v134; // eax
  float *v135; // esi
  double v136; // xmm0_8
  double v137; // xmm0_8
  double v138; // xmm0_8
  vostok::configs::binary_config_value *v139; // ecx
  vostok::configs::binary_config_value *v140; // eax
  char **v141; // eax
  vostok::render::effect_compiler *v142; // ecx
  vostok::configs::binary_config_value *v143; // eax
  char **v144; // eax
  vostok::render::effect_compiler *v145; // ecx
  vostok::configs::binary_config_value *v146; // eax
  char **v147; // eax
  vostok::render::effect_compiler *v148; // ecx
  vostok::configs::binary_config_value *v149; // eax
  char **v150; // eax
  vostok::render::effect_compiler *v151; // ecx
  vostok::configs::binary_config_value *v152; // eax
  char **v153; // eax
  vostok::render::effect_compiler *v154; // ecx
  vostok::configs::binary_config_value *v155; // eax
  char **v156; // eax
  vostok::render::effect_compiler *v157; // ecx
  vostok::configs::binary_config_value *v158; // ecx
  vostok::configs::binary_config_value *v159; // eax
  float **v160; // eax
  float *v161; // esi
  vostok::configs::binary_config_value *v162; // eax
  const vostok::configs::binary_config_value *v163; // eax
  float *v164; // esi
  double v165; // xmm0_8
  double v166; // xmm0_8
  double v167; // xmm0_8
  float v168; // xmm1_4
  vostok::render::effect_constant_storage *v169; // ecx
  vostok::render::effect_compiler *v170; // ecx
  vostok::render::effect_compiler *v171; // ecx
  vostok::render::effect_compiler *v172; // ecx
  vostok::render::effect_compiler *v173; // ecx
  vostok::render::effect_compiler *v174; // ecx
  vostok::render::effect_compiler *v175; // ecx
  vostok::render::effect_material_base *v176; // ecx
  vostok::render::shader_configuration v177; // [esp-10h] [ebp-7Ch]
  vostok::render::shader_configuration *v178; // [esp+4h] [ebp-68h]
  vostok::render::shader_configuration *v179; // [esp+4h] [ebp-68h]
  long double v180; // [esp+4h] [ebp-68h]
  long double v181; // [esp+4h] [ebp-68h]
  long double v182; // [esp+4h] [ebp-68h]
  long double v183; // [esp+4h] [ebp-68h]
  long double v184; // [esp+4h] [ebp-68h]
  long double v185; // [esp+4h] [ebp-68h]
  D3D11_BLEND_OP v186; // [esp+4h] [ebp-68h]
  long double v187; // [esp+4h] [ebp-68h]
  long double v188; // [esp+4h] [ebp-68h]
  long double v189; // [esp+4h] [ebp-68h]
  long double v190; // [esp+4h] [ebp-68h]
  long double v191; // [esp+4h] [ebp-68h]
  long double v192; // [esp+4h] [ebp-68h]
  const vostok::configs::binary_config_value *v193; // [esp+8h] [ebp-64h]
  const vostok::configs::binary_config_value *v194; // [esp+8h] [ebp-64h]
  long double v195; // [esp+Ch] [ebp-60h]
  long double v196; // [esp+Ch] [ebp-60h]
  long double v197; // [esp+Ch] [ebp-60h]
  long double v198; // [esp+Ch] [ebp-60h]
  long double v199; // [esp+Ch] [ebp-60h]
  long double v200; // [esp+Ch] [ebp-60h]
  long double v201; // [esp+Ch] [ebp-60h]
  long double v202; // [esp+Ch] [ebp-60h]
  long double v203; // [esp+Ch] [ebp-60h]
  long double v204; // [esp+Ch] [ebp-60h]
  long double v205; // [esp+Ch] [ebp-60h]
  bool v206; // [esp+17h] [ebp-55h]
  __int64 v207; // [esp+18h] [ebp-54h] BYREF
  vostok::math::float3 v208; // [esp+20h] [ebp-4Ch] BYREF
  vostok::math::float4 v209; // [esp+2Ch] [ebp-40h] BYREF
  unsigned __int64 v210; // [esp+3Ch] [ebp-30h] BYREF
  __int64 v211; // [esp+44h] [ebp-28h]
  float v212; // [esp+4Ch] [ebp-20h]
  float v213; // [esp+50h] [ebp-1Ch]
  vostok::math::float4 v214; // [esp+5Ch] [ebp-10h] BYREF

  v211 = 0x80000;
  v210 = 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "skin_position_pass",
    compiler,
    (const char *)&v210,
    config,
    v178,
    v193);
  vostok::render::effect_material_base::compile_end(v4, compiler);
  v211 = 0x80000;
  v210 = 0;
  v5 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
  v206 = vostok::configs::binary_config_value::operator[](v5, "value")->data.pointer != 0;
  v6 = vostok::configs::binary_config_value::operator[](config, "use_nmap");
  v7 = vostok::configs::binary_config_value::operator[](v6, "value");
  LOBYTE(v8) = v206;
  BYTE2(v210) = 8 * (v206 | (16 * (v7->data.pointer != 0)));
  if ( vostok::configs::binary_config_value::value_exists(v8, (int)config, (unsigned int)"use_alpha_test") )
  {
    v10 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
    v11 = vostok::configs::binary_config_value::operator[](v10, "value")->data.pointer != 0;
  }
  else
  {
    v11 = 0;
  }
  BYTE2(v210) ^= (BYTE2(v210) ^ (16 * v11)) & 0x10;
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)config, (unsigned int)"use_tspecular_inensity") )
  {
    v13 = vostok::configs::binary_config_value::operator[](config, "use_tspecular_inensity");
    v14 = vostok::configs::binary_config_value::operator[](v13, "value")->data.pointer != 0;
  }
  else
  {
    v14 = 0;
  }
  BYTE3(v210) ^= (BYTE3(v210) ^ (8 * v14)) & 8;
  if ( vostok::configs::binary_config_value::value_exists(v12, (int)config, (unsigned int)"use_tfresnel") )
  {
    v16 = vostok::configs::binary_config_value::operator[](config, "use_tfresnel");
    v17 = vostok::configs::binary_config_value::operator[](v16, "value")->data.pointer != 0;
  }
  else
  {
    v17 = 0;
  }
  BYTE3(v210) ^= (BYTE3(v210) ^ (16 * v17)) & 0x10;
  if ( vostok::configs::binary_config_value::value_exists(v15, (int)config, (unsigned int)"use_troughness") )
  {
    v19 = vostok::configs::binary_config_value::operator[](config, "use_troughness");
    v20 = vostok::configs::binary_config_value::operator[](v19, "value")->data.pointer != 0;
  }
  else
  {
    v20 = 0;
  }
  BYTE3(v210) ^= (BYTE3(v210) ^ (32 * v20)) & 0x20;
  if ( vostok::configs::binary_config_value::value_exists(v18, (int)config, (unsigned int)"is_anisotropic_material") )
  {
    v22 = vostok::configs::binary_config_value::operator[](config, "is_anisotropic_material");
    v23 = vostok::configs::binary_config_value::operator[](v22, "value")->data.pointer != 0;
  }
  else
  {
    v23 = 0;
  }
  BYTE5(v210) &= 0xF0u;
  BYTE4(v210) |= 4u;
  LOBYTE(v211) = (v211 ^ (v23 << 6)) & 0x40 ^ v211;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v21,
    (vostok::render::effect_material_base *)&stru_8129B8,
    "organic_forward_lighting",
    compiler,
    (const char *)&v210,
    config,
    v179,
    v194);
  vostok::render::effect_compiler::set_alpha_blend(
    v24,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    SLODWORD(v180));
  if ( vostok::configs::binary_config_value::value_exists(v25, (int)config, (unsigned int)"fresnel_at_0_degree") )
  {
    v27 = vostok::configs::binary_config_value::operator[](config, "fresnel_at_0_degree");
    v28 = vostok::configs::binary_config_value::operator[](v27, "value");
    if ( v28->type == 2 )
      pointer = *(float *)&v28->data.pointer;
    else
      pointer = (float)(int)v28->data.pointer;
  }
  else
  {
    pointer = FLOAT_0_039999999;
  }
  *((float *)&v207 + 1) = pointer;
  vostok::render::effect_compiler::set_constant<float>(v26, (float *)&v207 + 1, compiler, "fresnel_at_0_degree");
  HIDWORD(v207) = 0;
  vostok::render::effect_compiler::set_constant<float>(v30, (float *)&v207 + 1, compiler, "alpha_model_parameter");
  if ( vostok::configs::binary_config_value::value_exists(v31, (int)config, (unsigned int)"min_roughness") )
  {
    v33 = vostok::configs::binary_config_value::operator[](config, "min_roughness");
    v34 = vostok::configs::binary_config_value::operator[](v33, "value");
    if ( v34->type == 2 )
      v35 = *(float *)&v34->data.pointer;
    else
      v35 = (float)(int)v34->data.pointer;
  }
  else
  {
    v35 = 0.0;
  }
  *(float *)&v207 = v35;
  vostok::render::effect_compiler::set_constant<float>(v32, (float *)&v207, compiler, "min_roughness");
  if ( vostok::configs::binary_config_value::value_exists(v36, (int)config, (unsigned int)"max_roughness") )
  {
    v38 = vostok::configs::binary_config_value::operator[](config, "max_roughness");
    v39 = vostok::configs::binary_config_value::operator[](v38, "value");
    if ( v39->type == 2 )
      v40 = *(float *)&v39->data.pointer;
    else
      v40 = (float)(int)v39->data.pointer;
  }
  else
  {
    v40 = s_bm_current_air_resistance;
  }
  *((float *)&v207 + 1) = v40;
  vostok::render::effect_compiler::set_constant<float>(v37, (float *)&v207 + 1, compiler, "max_roughness");
  if ( (v210 & 0x80000) != 0 )
  {
    v41 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v42 = (char **)vostok::configs::binary_config_value::operator[](v41, "value");
    vostok::render::effect_compiler::set_texture(v43, (const char *)compiler, "t_base", *v42, 0, 0xFFFFFFFF, 0, 1.0);
  }
  v44 = vostok::configs::binary_config_value::operator[](config, "constant_diffuse");
  v45 = vostok::configs::binary_config_value::operator[](v44, "value");
  v46 = (float *)v45->data.pointer;
  v47 = *(float *)v45->data.pointer;
  __libm_sse2_pow(v180, v195);
  *(float *)&v47 = v47;
  v209.x = *(float *)&v47;
  v48 = v46[1];
  __libm_sse2_pow(v181, v196);
  *(float *)&v48 = v48;
  v209.y = *(float *)&v48;
  v49 = v46[2];
  __libm_sse2_pow(v182, v197);
  *(float *)&v49 = v49;
  v209.z = *(float *)&v49;
  v209.w = v46[3];
  *(_QWORD *)&v214.x = *(_QWORD *)&v209.x;
  *(_QWORD *)&v214.elements[2] = LODWORD(v49);
  v51 = config;
  if ( (v210 & 0x800000) != 0 )
  {
    v52 = vostok::configs::binary_config_value::operator[](config, "texture_normal");
    v53 = (char **)vostok::configs::binary_config_value::operator[](v52, "value");
    vostok::render::effect_compiler::set_texture(v54, (const char *)compiler, "t_normal", *v53, 0, 0xFFFFFFFF, 0, 1.0);
  }
  if ( (v210 & 0x8000000) != 0 )
  {
    v55 = vostok::configs::binary_config_value::operator[](config, "texture_specular_intensity");
    v56 = (char **)vostok::configs::binary_config_value::operator[](v55, "value");
    vostok::render::effect_compiler::set_texture(
      v57,
      (const char *)compiler,
      "t_specular_intensity",
      *v56,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v50, (int)config, (unsigned int)"constant_specular_color")
    && vostok::configs::binary_config_value::value_exists(
         v58,
         (int)config,
         (unsigned int)"constant_specular_color_multiplier") )
  {
    v59 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color_multiplier");
    v60 = (float **)vostok::configs::binary_config_value::operator[](v59, "value");
    v61 = *v60;
    v208.x = **v60;
    *(_QWORD *)&v208.elements[1] = *(_QWORD *)(v61 + 1);
    v62 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color");
    v63 = vostok::configs::binary_config_value::operator[](v62, "value");
    v64 = (float *)v63->data.pointer;
    v65 = *(float *)v63->data.pointer;
    __libm_sse2_pow(v183, v198);
    *(float *)&v65 = v65;
    v212 = *(float *)&v65;
    v66 = v64[1];
    __libm_sse2_pow(v184, v199);
    *(float *)&v66 = v66;
    v213 = *(float *)&v66;
    v67 = v64[2];
    __libm_sse2_pow(v185, v200);
    v68 = v67;
    v209.x = v212 * v208.x;
    v209.y = v208.y * v213;
    v209.z = v208.z * v68;
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(
      (const vostok::math::float3 *)&v209,
      v69,
      compiler,
      "specular_color_parameter");
    v51 = config;
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v214,
    (vostok::render::effect_constant_storage *)v58,
    compiler,
    "solid_color_specular");
  *(_QWORD *)&v209.x = 0;
  *(_QWORD *)&v209.elements[2] = v207;
  if ( (v210 & 0x20000000) != 0 )
  {
    v71 = vostok::configs::binary_config_value::operator[](v51, "texture_specular_power");
    v72 = (char **)vostok::configs::binary_config_value::operator[](v71, "value");
    vostok::render::effect_compiler::set_texture(
      v73,
      (const char *)compiler,
      "t_roughness",
      *v72,
      0,
      0xFFFFFFFF,
      0,
      1.0);
    goto LABEL_54;
  }
  if ( vostok::configs::binary_config_value::value_exists(v70, (int)v51, (unsigned int)"constant_specular_power") )
  {
    v75 = vostok::configs::binary_config_value::operator[](v51, "constant_specular_power");
    v76 = vostok::configs::binary_config_value::operator[](v75, "value");
    if ( v76->type == 2 )
      v77 = *(float *)&v76->data.pointer;
    else
      v77 = (float)(int)v76->data.pointer;
    v209.x = v77;
  }
  if ( (v211 & 0x40) != 0 )
  {
    if ( !vostok::configs::binary_config_value::value_exists(
            v74,
            (int)v51,
            (unsigned int)"constant_roughness_v_direction") )
      goto LABEL_54;
    v78 = vostok::configs::binary_config_value::operator[](v51, "constant_roughness_v_direction");
    v79 = vostok::configs::binary_config_value::operator[](v78, "value");
    if ( v79->type == 2 )
      x = *(float *)&v79->data.pointer;
    else
      x = (float)(int)v79->data.pointer;
  }
  else
  {
    x = v209.x;
  }
  v209.y = x;
LABEL_54:
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v209,
    (vostok::render::effect_constant_storage *)v74,
    compiler,
    "roughness_uv_parameters");
  *((float *)&v207 + 1) = s_bm_current_air_resistance;
  vostok::render::effect_compiler::set_constant<float>(v81, (float *)&v207 + 1, compiler, "solid_transparency");
  vostok::render::effect_material_base::compile_end(v82, compiler);
  v211 = 0x80000;
  v210 = 0;
  if ( vostok::configs::binary_config_value::value_exists(v83, (int)v51, (unsigned int)&stru_8145D8) )
  {
    v85 = vostok::configs::binary_config_value::operator[](v51, (char *)&stru_8145D8);
    v86 = vostok::configs::binary_config_value::operator[](v85, "value")->data.pointer != 0;
  }
  else
  {
    v86 = 0;
  }
  BYTE1(v211) ^= (BYTE1(v211) ^ (2 * v86)) & 2;
  vostok::render::effect_compiler::begin_technique(v84, (int)compiler);
  *(_DWORD *)&v177.0 = "blur_organic_irradiance_texture";
  *(unsigned __int64 *)((char *)v177.configuration + 4) = v210;
  HIDWORD(v177.configuration[1]) = v211;
  vostok::render::effect_compiler::begin_pass(
    v87,
    (int)compiler,
    "blur_irradiance_texture",
    0,
    v177,
    (vostok::render::shader_include_getter *)HIDWORD(v211));
  vostok::render::effect_compiler::set_depth(v88, (int)compiler, 0, 0, SLODWORD(v183));
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v89);
  vostok::render::effect_compiler::set_alpha_blend(
    v90,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v186);
  vostok::render::effect_compiler::set_texture(
    v91,
    (const char *)compiler,
    "t_skin_scattering",
    "$user$skin_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  *(_QWORD *)&v209.x = __PAIR64__(LODWORD(s_aim_transition_time), LODWORD(FLOAT_1_2));
  *(_QWORD *)&v209.elements[2] = __PAIR64__(LODWORD(s_bm_current_air_resistance), LODWORD(FLOAT_0_1));
  if ( vostok::configs::binary_config_value::value_exists(
         v92,
         (int)config,
         (unsigned int)"scattering_component_blurring_weights") )
  {
    v94 = vostok::configs::binary_config_value::operator[](config, "scattering_component_blurring_weights");
    v95 = (float **)vostok::configs::binary_config_value::operator[](v94, "value");
    v96 = *v95;
    v209.x = **v95;
    *(_QWORD *)&v209.elements[1] = *(_QWORD *)(v96 + 1);
  }
  if ( vostok::configs::binary_config_value::value_exists(v93, (int)config, (unsigned int)"scattering_color_multiplier") )
  {
    v98 = vostok::configs::binary_config_value::operator[](config, "scattering_color_multiplier");
    v99 = vostok::configs::binary_config_value::operator[](v98, "value");
    if ( v99->type == 2 )
      v100 = *(float *)&v99->data.pointer;
    else
      v100 = (float)(int)v99->data.pointer;
    v209.w = v100;
  }
  if ( (v211 & 0x200) != 0
    && vostok::configs::binary_config_value::value_exists(v97, (int)config, (unsigned int)"texture_scattering_depth") )
  {
    v101 = vostok::configs::binary_config_value::operator[](config, "texture_scattering_depth");
    v102 = (char **)vostok::configs::binary_config_value::operator[](v101, "value");
    vostok::render::effect_compiler::set_texture(
      v103,
      (const char *)compiler,
      "t_scattering_depth",
      *v102,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v209,
    (vostok::render::effect_constant_storage *)v97,
    compiler,
    "scattering_component_blurring_weights_and_color_multiplier");
  vostok::render::effect_compiler::end_pass(v104, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v105,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  v211 = 0x80000;
  v210 = 0;
  if ( vostok::configs::binary_config_value::value_exists(v106, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v108 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v109 = vostok::configs::binary_config_value::operator[](v108, "value")->data.pointer != 0;
  }
  else
  {
    v109 = 0;
  }
  BYTE2(v210) = 8 * v109;
  if ( vostok::configs::binary_config_value::value_exists(v107, (int)config, (unsigned int)"use_nmap") )
  {
    v111 = vostok::configs::binary_config_value::operator[](config, "use_nmap");
    v112 = vostok::configs::binary_config_value::operator[](v111, "value")->data.pointer != 0;
  }
  else
  {
    v112 = 0;
  }
  LOBYTE(v110) = BYTE2(v210) & 0x7F;
  BYTE2(v210) = BYTE2(v210) & 0x7F | (v112 << 7);
  if ( vostok::configs::binary_config_value::value_exists(v110, (int)config, (unsigned int)"use_tspecular_inensity") )
  {
    v114 = vostok::configs::binary_config_value::operator[](config, "use_tspecular_inensity");
    v115 = vostok::configs::binary_config_value::operator[](v114, "value")->data.pointer != 0;
  }
  else
  {
    v115 = 0;
  }
  BYTE3(v210) ^= (BYTE3(v210) ^ (8 * v115)) & 8;
  if ( vostok::configs::binary_config_value::value_exists(v113, (int)config, (unsigned int)"use_ao_texture") )
  {
    v117 = vostok::configs::binary_config_value::operator[](config, "use_ao_texture");
    v118 = vostok::configs::binary_config_value::operator[](v117, "value")->data.pointer != 0;
  }
  else
  {
    v118 = 0;
  }
  LOBYTE(v116) = v211 & 0x7F;
  LOBYTE(v211) = v211 & 0x7F | (v118 << 7);
  if ( vostok::configs::binary_config_value::value_exists(v116, (int)config, (unsigned int)"use_scattering_amount_mask") )
  {
    v120 = vostok::configs::binary_config_value::operator[](config, "use_scattering_amount_mask");
    v121 = vostok::configs::binary_config_value::operator[](v120, "value")->data.pointer != 0;
  }
  else
  {
    v121 = 0;
  }
  BYTE1(v211) ^= (BYTE1(v211) ^ v121) & 1;
  if ( vostok::configs::binary_config_value::value_exists(
         v119,
         (int)config,
         (unsigned int)"use_back_illumination_texture") )
  {
    v123 = vostok::configs::binary_config_value::operator[](config, "use_back_illumination_texture");
    v124 = vostok::configs::binary_config_value::operator[](v123, "value")->data.pointer != 0;
  }
  else
  {
    v124 = 0;
  }
  BYTE1(v211) ^= (BYTE1(v211) ^ (4 * v124)) & 4;
  if ( vostok::configs::binary_config_value::value_exists(v122, (int)config, (unsigned int)"use_subdermal_texture") )
  {
    v126 = vostok::configs::binary_config_value::operator[](config, "use_subdermal_texture");
    v127 = vostok::configs::binary_config_value::operator[](v126, "value")->data.pointer != 0;
  }
  else
  {
    v127 = 0;
  }
  BYTE1(v211) ^= (BYTE1(v211) ^ (8 * v127)) & 8;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v125,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "organic_combine",
    compiler,
    (const char *)&v210,
    config,
    (vostok::render::shader_configuration *)LODWORD(v183),
    (const vostok::configs::binary_config_value *)HIDWORD(v183));
  vostok::render::effect_compiler::set_depth(v128, (int)compiler, 1, 0, SLODWORD(v187));
  vostok::render::effect_compiler::set_alpha_blend(
    v129,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    SLODWORD(v187));
  if ( (v210 & 0x80000) != 0 )
  {
    v130 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v131 = (char **)vostok::configs::binary_config_value::operator[](v130, "value");
    vostok::render::effect_compiler::set_texture(v132, (const char *)compiler, "t_base", *v131, 0, 0xFFFFFFFF, 0, 1.0);
  }
  v133 = vostok::configs::binary_config_value::operator[](config, "constant_diffuse");
  v134 = vostok::configs::binary_config_value::operator[](v133, "value");
  v135 = (float *)v134->data.pointer;
  v136 = *(float *)v134->data.pointer;
  __libm_sse2_pow(v187, v198);
  *(float *)&v136 = v136;
  v209.x = *(float *)&v136;
  v137 = v135[1];
  __libm_sse2_pow(v188, v201);
  *(float *)&v137 = v137;
  v209.y = *(float *)&v137;
  v138 = v135[2];
  __libm_sse2_pow(v189, v202);
  *(float *)&v138 = v138;
  v209.z = *(float *)&v138;
  v209.w = v135[3];
  *(_QWORD *)&v214.x = *(_QWORD *)&v209.x;
  *(_QWORD *)&v214.elements[2] = __PAIR64__(LODWORD(v209.w), LODWORD(v138));
  if ( (v210 & 0x800000) != 0 )
  {
    v140 = vostok::configs::binary_config_value::operator[](config, "texture_normal");
    v141 = (char **)vostok::configs::binary_config_value::operator[](v140, "value");
    vostok::render::effect_compiler::set_texture(v142, (const char *)compiler, "t_normal", *v141, 0, 0xFFFFFFFF, 0, 1.0);
  }
  if ( (v211 & 0x100) != 0
    && vostok::configs::binary_config_value::value_exists(v139, (int)config, (unsigned int)"texture_scattering_amount") )
  {
    v143 = vostok::configs::binary_config_value::operator[](config, "texture_scattering_amount");
    v144 = (char **)vostok::configs::binary_config_value::operator[](v143, "value");
    vostok::render::effect_compiler::set_texture(
      v145,
      (const char *)compiler,
      "t_sss_amount",
      *v144,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( (v211 & 0x400) != 0
    && vostok::configs::binary_config_value::value_exists(v139, (int)config, (unsigned int)"texture_back_illumination") )
  {
    v146 = vostok::configs::binary_config_value::operator[](config, "texture_back_illumination");
    v147 = (char **)vostok::configs::binary_config_value::operator[](v146, "value");
    vostok::render::effect_compiler::set_texture(
      v148,
      (const char *)compiler,
      "t_back_color",
      *v147,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( (v211 & 0x800) != 0
    && vostok::configs::binary_config_value::value_exists(v139, (int)config, (unsigned int)"texture_subdermal") )
  {
    v149 = vostok::configs::binary_config_value::operator[](config, "texture_subdermal");
    v150 = (char **)vostok::configs::binary_config_value::operator[](v149, "value");
    vostok::render::effect_compiler::set_texture(
      v151,
      (const char *)compiler,
      "t_subdermal",
      *v150,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( (v211 & 0x80u) != 0LL
    && vostok::configs::binary_config_value::value_exists(v139, (int)config, (unsigned int)"texture_ao") )
  {
    v152 = vostok::configs::binary_config_value::operator[](config, "texture_ao");
    v153 = (char **)vostok::configs::binary_config_value::operator[](v152, "value");
    vostok::render::effect_compiler::set_texture(v154, (const char *)compiler, "t_ao", *v153, 0, 0xFFFFFFFF, 0, 1.0);
  }
  if ( (v210 & 0x8000000) != 0 )
  {
    v155 = vostok::configs::binary_config_value::operator[](config, "texture_specular_intensity");
    v156 = (char **)vostok::configs::binary_config_value::operator[](v155, "value");
    vostok::render::effect_compiler::set_texture(
      v157,
      (const char *)compiler,
      "t_specular_intensity",
      *v156,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v139, (int)config, (unsigned int)"constant_specular_color")
    && vostok::configs::binary_config_value::value_exists(
         v158,
         (int)config,
         (unsigned int)"constant_specular_color_multiplier") )
  {
    v159 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color_multiplier");
    v160 = (float **)vostok::configs::binary_config_value::operator[](v159, "value");
    v161 = *v160;
    v209.x = **v160;
    *(_QWORD *)&v209.elements[1] = *(_QWORD *)(v161 + 1);
    v162 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color");
    v163 = vostok::configs::binary_config_value::operator[](v162, "value");
    v164 = (float *)v163->data.pointer;
    v165 = *(float *)v163->data.pointer;
    __libm_sse2_pow(v190, v203);
    *(float *)&v165 = v165;
    v212 = *(float *)&v165;
    v166 = v164[1];
    __libm_sse2_pow(v191, v204);
    *(float *)&v166 = v166;
    v213 = *(float *)&v166;
    v167 = v164[2];
    __libm_sse2_pow(v192, v205);
    v168 = v167;
    v208.x = v212 * v209.x;
    v208.y = v209.y * v213;
    v208.z = v209.z * v168;
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(
      &v208,
      v169,
      compiler,
      "specular_color_parameter");
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v214,
    (vostok::render::effect_constant_storage *)v158,
    compiler,
    "solid_color_specular");
  vostok::render::effect_compiler::set_texture(
    v170,
    (const char *)compiler,
    "t_skin_scattering",
    "$user$skin_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v171,
    (const char *)compiler,
    "t_skin_scattering_blurred_0",
    "$user$skin_scattering_blurred0",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v172,
    (const char *)compiler,
    "t_skin_scattering_blurred_1",
    "$user$skin_scattering_blurred1",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v173,
    (const char *)compiler,
    "t_skin_scattering_blurred_2",
    "$user$skin_scattering_blurred2",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v174,
    (const char *)compiler,
    "t_skin_scattering_blurred_3",
    "$user$skin_scattering_blurred3",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v175,
    (const char *)compiler,
    "t_skin_scattering_blurred_4",
    "$user$skin_scattering_blurred4",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_material_base::compile_end(v176, compiler);
}
