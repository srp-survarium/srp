void __thiscall vostok::render::effect_lighting_stage_skin_base_materials::compile(
        vostok::render::effect_lighting_stage_skin_base_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_material_base *v5; // ecx
  vostok::configs::binary_config_value *v6; // eax
  vostok::configs::binary_config_value *v7; // eax
  const vostok::configs::binary_config_value *v8; // eax
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // ecx
  vostok::configs::binary_config_value *v11; // eax
  bool v12; // al
  vostok::configs::binary_config_value *v13; // ecx
  vostok::configs::binary_config_value *v14; // eax
  bool v15; // al
  vostok::configs::binary_config_value *v16; // ecx
  vostok::configs::binary_config_value *v17; // eax
  bool v18; // al
  vostok::configs::binary_config_value *v19; // ecx
  vostok::configs::binary_config_value *v20; // eax
  bool v21; // al
  vostok::render::effect_compiler *v22; // ecx
  vostok::command_line::key *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::configs::binary_config_value *v25; // eax
  char **v26; // eax
  vostok::render::effect_compiler *v27; // ecx
  vostok::configs::binary_config_value *v28; // eax
  const vostok::configs::binary_config_value *v29; // eax
  float *pointer; // esi
  double v31; // xmm0_8
  double v32; // xmm0_8
  double v33; // xmm0_8
  vostok::configs::binary_config_value *v34; // ecx
  vostok::configs::binary_config_value *v35; // eax
  char **v36; // eax
  vostok::render::effect_compiler *v37; // ecx
  vostok::configs::binary_config_value *v38; // eax
  char **v39; // eax
  vostok::render::effect_compiler *v40; // ecx
  vostok::configs::binary_config_value *v41; // ecx
  vostok::configs::binary_config_value *v42; // eax
  float **v43; // eax
  float *v44; // esi
  vostok::configs::binary_config_value *v45; // eax
  const vostok::configs::binary_config_value *v46; // eax
  float *v47; // esi
  double v48; // xmm0_8
  double v49; // xmm0_8
  double v50; // xmm0_8
  float v51; // xmm1_4
  vostok::render::effect_constant_storage *v52; // ecx
  vostok::configs::binary_config_value *v53; // ecx
  vostok::configs::binary_config_value *v54; // eax
  char **v55; // eax
  vostok::render::effect_compiler *v56; // ecx
  vostok::render::effect_constant_storage *v57; // ecx
  vostok::configs::binary_config_value *v58; // eax
  const vostok::configs::binary_config_value *v59; // eax
  float v60; // xmm0_4
  vostok::render::effect_constant_storage *v61; // ecx
  vostok::render::effect_material_base *v62; // ecx
  vostok::configs::binary_config_value *v63; // ecx
  vostok::render::effect_compiler *v64; // ecx
  vostok::configs::binary_config_value *v65; // eax
  bool v66; // al
  vostok::render::effect_compiler *v67; // ecx
  vostok::render::effect_compiler *v68; // ecx
  vostok::command_line::key *v69; // ecx
  vostok::render::effect_compiler *v70; // ecx
  vostok::render::effect_compiler *v71; // ecx
  vostok::render::effect_compiler *v72; // ecx
  vostok::render::effect_compiler *v73; // ecx
  vostok::configs::binary_config_value *v74; // esi
  vostok::configs::binary_config_value *v75; // ecx
  vostok::configs::binary_config_value *v76; // ecx
  vostok::configs::binary_config_value *v77; // eax
  float **v78; // eax
  float *v79; // esi
  vostok::configs::binary_config_value *v80; // ecx
  vostok::configs::binary_config_value *v81; // eax
  const vostok::configs::binary_config_value *v82; // eax
  float v83; // xmm0_4
  vostok::configs::binary_config_value *v84; // eax
  char **v85; // eax
  vostok::render::effect_compiler *v86; // ecx
  vostok::render::effect_compiler *v87; // ecx
  vostok::render::effect_compiler *v88; // ecx
  vostok::configs::binary_config_value *v89; // ecx
  vostok::configs::binary_config_value *v90; // ecx
  vostok::configs::binary_config_value *v91; // eax
  bool v92; // al
  vostok::configs::binary_config_value *v93; // ecx
  vostok::configs::binary_config_value *v94; // eax
  char v95; // al
  vostok::configs::binary_config_value *v96; // ecx
  vostok::configs::binary_config_value *v97; // eax
  bool v98; // al
  vostok::configs::binary_config_value *v99; // ecx
  vostok::configs::binary_config_value *v100; // eax
  char v101; // al
  vostok::configs::binary_config_value *v102; // ecx
  vostok::configs::binary_config_value *v103; // eax
  bool v104; // al
  vostok::configs::binary_config_value *v105; // ecx
  vostok::configs::binary_config_value *v106; // eax
  bool v107; // al
  vostok::configs::binary_config_value *v108; // ecx
  vostok::configs::binary_config_value *v109; // eax
  bool v110; // al
  vostok::render::effect_compiler *v111; // ecx
  vostok::render::effect_compiler *v112; // ecx
  vostok::configs::binary_config_value *v113; // eax
  char **v114; // eax
  vostok::render::effect_compiler *v115; // ecx
  vostok::configs::binary_config_value *v116; // eax
  const vostok::configs::binary_config_value *v117; // eax
  float *v118; // esi
  double v119; // xmm0_8
  double v120; // xmm0_8
  double v121; // xmm0_8
  vostok::configs::binary_config_value *v122; // ecx
  vostok::configs::binary_config_value *v123; // eax
  char **v124; // eax
  vostok::render::effect_compiler *v125; // ecx
  vostok::configs::binary_config_value *v126; // eax
  char **v127; // eax
  vostok::render::effect_compiler *v128; // ecx
  vostok::configs::binary_config_value *v129; // eax
  char **v130; // eax
  vostok::render::effect_compiler *v131; // ecx
  vostok::configs::binary_config_value *v132; // eax
  char **v133; // eax
  vostok::render::effect_compiler *v134; // ecx
  vostok::configs::binary_config_value *v135; // eax
  char **v136; // eax
  vostok::render::effect_compiler *v137; // ecx
  vostok::configs::binary_config_value *v138; // eax
  char **v139; // eax
  vostok::render::effect_compiler *v140; // ecx
  vostok::configs::binary_config_value *v141; // ecx
  vostok::configs::binary_config_value *v142; // eax
  const vostok::configs::binary_config_value *v143; // eax
  _DWORD *v144; // esi
  vostok::configs::binary_config_value *v145; // eax
  const vostok::configs::binary_config_value *v146; // eax
  float *v147; // esi
  double v148; // xmm0_8
  double v149; // xmm0_8
  double v150; // xmm0_8
  float v151; // xmm1_4
  vostok::render::effect_constant_storage *v152; // ecx
  vostok::configs::binary_config_value *v153; // ecx
  vostok::configs::binary_config_value *v154; // eax
  const vostok::configs::binary_config_value *v155; // eax
  vostok::render::effect_constant_storage *v156; // ecx
  float v157; // xmm0_4
  vostok::configs::binary_config_value *v158; // ecx
  vostok::configs::binary_config_value *v159; // eax
  const vostok::configs::binary_config_value *v160; // eax
  vostok::render::effect_constant_storage *v161; // ecx
  float v162; // xmm0_4
  vostok::render::effect_compiler *v163; // ecx
  vostok::render::effect_compiler *v164; // ecx
  vostok::render::effect_compiler *v165; // ecx
  vostok::render::effect_compiler *v166; // ecx
  vostok::render::effect_compiler *v167; // ecx
  vostok::render::effect_compiler *v168; // ecx
  vostok::render::effect_material_base *v169; // ecx
  vostok::render::shader_configuration v170; // [esp-10h] [ebp-74h]
  vostok::render::shader_configuration *v171; // [esp+4h] [ebp-60h]
  D3D11_BLEND_OP v172; // [esp+4h] [ebp-60h]
  vostok::render::shader_configuration *v173; // [esp+4h] [ebp-60h]
  long double v174; // [esp+4h] [ebp-60h]
  long double v175; // [esp+4h] [ebp-60h]
  long double v176; // [esp+4h] [ebp-60h]
  long double v177; // [esp+4h] [ebp-60h]
  long double v178; // [esp+4h] [ebp-60h]
  long double v179; // [esp+4h] [ebp-60h]
  D3D11_BLEND_OP v180; // [esp+4h] [ebp-60h]
  long double v181; // [esp+4h] [ebp-60h]
  long double v182; // [esp+4h] [ebp-60h]
  long double v183; // [esp+4h] [ebp-60h]
  long double v184; // [esp+4h] [ebp-60h]
  long double v185; // [esp+4h] [ebp-60h]
  long double v186; // [esp+4h] [ebp-60h]
  const vostok::configs::binary_config_value *v187; // [esp+8h] [ebp-5Ch]
  const vostok::configs::binary_config_value *v188; // [esp+8h] [ebp-5Ch]
  long double v189; // [esp+Ch] [ebp-58h]
  long double v190; // [esp+Ch] [ebp-58h]
  long double v191; // [esp+Ch] [ebp-58h]
  long double v192; // [esp+Ch] [ebp-58h]
  long double v193; // [esp+Ch] [ebp-58h]
  long double v194; // [esp+Ch] [ebp-58h]
  long double v195; // [esp+Ch] [ebp-58h]
  long double v196; // [esp+Ch] [ebp-58h]
  long double v197; // [esp+Ch] [ebp-58h]
  long double v198; // [esp+Ch] [ebp-58h]
  long double v199; // [esp+Ch] [ebp-58h]
  float v200; // [esp+14h] [ebp-50h] BYREF
  vostok::math::float3 v201; // [esp+18h] [ebp-4Ch] BYREF
  unsigned __int64 v202; // [esp+24h] [ebp-40h] BYREF
  __int64 v203; // [esp+2Ch] [ebp-38h]
  vostok::math::float4 v204; // [esp+34h] [ebp-30h] BYREF
  float v205; // [esp+44h] [ebp-20h]
  float v206; // [esp+48h] [ebp-1Ch]
  vostok::math::float4 v207; // [esp+54h] [ebp-10h] BYREF

  *(_QWORD *)&v204.elements[2] = 0x80000;
  *(_QWORD *)&v204.x = 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)&stru_8129B8,
    "skin_position_pass",
    compiler,
    (const char *)&v204,
    config,
    v171,
    v187);
  vostok::render::effect_compiler::set_alpha_blend(
    v4,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v172);
  vostok::render::effect_material_base::compile_end(v5, compiler);
  *(_QWORD *)&v204.elements[2] = 0x80000;
  *(_QWORD *)&v204.x = 0;
  v6 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
  HIBYTE(v189) = vostok::configs::binary_config_value::operator[](v6, "value")->data.pointer != 0;
  v7 = vostok::configs::binary_config_value::operator[](config, "use_nmap");
  v8 = vostok::configs::binary_config_value::operator[](v7, "value");
  LOBYTE(v9) = HIBYTE(v189) & 1;
  BYTE2(v204.elements[0]) = 8 * (HIBYTE(v189) & 1 | (16 * (v8->data.pointer != 0)));
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)config, (unsigned int)"use_alpha_test") )
  {
    v11 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
    v12 = vostok::configs::binary_config_value::operator[](v11, "value")->data.pointer != 0;
  }
  else
  {
    v12 = 0;
  }
  BYTE2(v204.elements[0]) ^= (BYTE2(v204.elements[0]) ^ (16 * v12)) & 0x10;
  if ( vostok::configs::binary_config_value::value_exists(v10, (int)config, (unsigned int)"use_tspecular_inensity") )
  {
    v14 = vostok::configs::binary_config_value::operator[](config, "use_tspecular_inensity");
    v15 = vostok::configs::binary_config_value::operator[](v14, "value")->data.pointer != 0;
  }
  else
  {
    v15 = 0;
  }
  HIBYTE(v204.elements[0]) ^= (HIBYTE(v204.elements[0]) ^ (8 * v15)) & 8;
  if ( vostok::configs::binary_config_value::value_exists(v13, (int)config, (unsigned int)"use_tfresnel") )
  {
    v17 = vostok::configs::binary_config_value::operator[](config, "use_tfresnel");
    v18 = vostok::configs::binary_config_value::operator[](v17, "value")->data.pointer != 0;
  }
  else
  {
    v18 = 0;
  }
  HIBYTE(v204.elements[0]) ^= (HIBYTE(v204.elements[0]) ^ (16 * v18)) & 0x10;
  if ( vostok::configs::binary_config_value::value_exists(v16, (int)config, (unsigned int)"use_troughness") )
  {
    v20 = vostok::configs::binary_config_value::operator[](config, "use_troughness");
    v21 = vostok::configs::binary_config_value::operator[](v20, "value")->data.pointer != 0;
  }
  else
  {
    v21 = 0;
  }
  BYTE1(v204.elements[1]) &= 0xF0u;
  LOBYTE(v204.elements[1]) |= 4u;
  HIBYTE(v204.elements[0]) ^= (HIBYTE(v204.elements[0]) ^ (32 * v21)) & 0x20;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v19,
    (vostok::render::effect_material_base *)&stru_8129B8,
    "skin_forward_lighting",
    compiler,
    (const char *)&v204,
    config,
    v173,
    v188);
  vostok::render::effect_compiler::set_depth(v22, (int)compiler, 0, 0, SLODWORD(v174));
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v23);
  vostok::render::effect_compiler::set_alpha_blend(
    v24,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    SLODWORD(v174));
  if ( (BYTE2(v204.elements[0]) & 8) != 0 )
  {
    v25 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v26 = (char **)vostok::configs::binary_config_value::operator[](v25, "value");
    vostok::render::effect_compiler::set_texture(v27, (const char *)compiler, "t_base", *v26, 0, 0xFFFFFFFF, 0, 1.0);
  }
  v28 = vostok::configs::binary_config_value::operator[](config, "constant_diffuse");
  v29 = vostok::configs::binary_config_value::operator[](v28, "value");
  pointer = (float *)v29->data.pointer;
  v31 = *(float *)v29->data.pointer;
  __libm_sse2_pow(v174, v189);
  *(float *)&v31 = v31;
  LODWORD(v202) = LODWORD(v31);
  v32 = pointer[1];
  __libm_sse2_pow(v175, v190);
  *(float *)&v32 = v32;
  HIDWORD(v202) = LODWORD(v32);
  v33 = pointer[2];
  __libm_sse2_pow(v176, v191);
  *(float *)&v33 = v33;
  LODWORD(v203) = LODWORD(v33);
  *((float *)&v203 + 1) = pointer[3];
  *(_QWORD *)&v207.x = v202;
  *(_QWORD *)&v207.elements[2] = LODWORD(v33);
  if ( SBYTE2(v204.elements[0]) < 0 )
  {
    v35 = vostok::configs::binary_config_value::operator[](config, "texture_normal");
    v36 = (char **)vostok::configs::binary_config_value::operator[](v35, "value");
    vostok::render::effect_compiler::set_texture(v37, (const char *)compiler, "t_normal", *v36, 0, 0xFFFFFFFF, 0, 1.0);
  }
  if ( (HIBYTE(v204.elements[0]) & 8) != 0 )
  {
    v38 = vostok::configs::binary_config_value::operator[](config, "texture_specular_intensity");
    v39 = (char **)vostok::configs::binary_config_value::operator[](v38, "value");
    vostok::render::effect_compiler::set_texture(
      v40,
      (const char *)compiler,
      "t_specular_intensity",
      *v39,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v34, (int)config, (unsigned int)"constant_specular_color")
    && vostok::configs::binary_config_value::value_exists(
         v41,
         (int)config,
         (unsigned int)"constant_specular_color_multiplier") )
  {
    v42 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color_multiplier");
    v43 = (float **)vostok::configs::binary_config_value::operator[](v42, "value");
    v44 = *v43;
    v201.x = **v43;
    *(_QWORD *)&v201.elements[1] = *(_QWORD *)(v44 + 1);
    v45 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color");
    v46 = vostok::configs::binary_config_value::operator[](v45, "value");
    v47 = (float *)v46->data.pointer;
    v48 = *(float *)v46->data.pointer;
    __libm_sse2_pow(v177, v192);
    *(float *)&v48 = v48;
    v205 = *(float *)&v48;
    v49 = v47[1];
    __libm_sse2_pow(v178, v193);
    *(float *)&v49 = v49;
    v206 = *(float *)&v49;
    v50 = v47[2];
    __libm_sse2_pow(v179, v194);
    v51 = v50;
    *(float *)&v202 = v205 * v201.x;
    *((float *)&v202 + 1) = v201.y * v206;
    *(float *)&v203 = v201.z * v51;
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(
      (const vostok::math::float3 *)&v202,
      v52,
      compiler,
      "specular_color_parameter");
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v207,
    (vostok::render::effect_constant_storage *)v41,
    compiler,
    "solid_color_specular");
  v200 = FLOAT_50_0;
  if ( (HIBYTE(v204.elements[0]) & 0x20) != 0 )
  {
    v54 = vostok::configs::binary_config_value::operator[](config, "texture_specular_power");
    v55 = (char **)vostok::configs::binary_config_value::operator[](v54, "value");
    vostok::render::effect_compiler::set_texture(
      v56,
      (const char *)compiler,
      "t_specular_power",
      *v55,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  else if ( vostok::configs::binary_config_value::value_exists(
              v53,
              (int)config,
              (unsigned int)"constant_specular_power") )
  {
    v58 = vostok::configs::binary_config_value::operator[](config, "constant_specular_power");
    v59 = vostok::configs::binary_config_value::operator[](v58, "value");
    if ( v59->type == 2 )
      v60 = *(float *)&v59->data.pointer;
    else
      v60 = (float)(int)v59->data.pointer;
    v200 = v60;
  }
  vostok::render::effect_compiler::set_constant<float>(v57, &v200, compiler, "specular_power_parameter");
  v200 = s_bm_current_air_resistance;
  vostok::render::effect_compiler::set_constant<float>(v61, &v200, compiler, "solid_transparency");
  vostok::render::effect_material_base::compile_end(v62, compiler);
  v203 = 0x80000;
  v202 = 0;
  if ( vostok::configs::binary_config_value::value_exists(v63, (int)config, (unsigned int)&stru_8145D8) )
  {
    v65 = vostok::configs::binary_config_value::operator[](config, (char *)&stru_8145D8);
    v66 = vostok::configs::binary_config_value::operator[](v65, "value")->data.pointer != 0;
  }
  else
  {
    v66 = 0;
  }
  BYTE1(v203) ^= (BYTE1(v203) ^ (2 * v66)) & 2;
  vostok::render::effect_compiler::begin_technique(v64, (int)compiler);
  *(_DWORD *)&v170.0 = "blur_skin_irradiance_texture";
  *(unsigned __int64 *)((char *)v170.configuration + 4) = v202;
  HIDWORD(v170.configuration[1]) = v203;
  vostok::render::effect_compiler::begin_pass(
    v67,
    (int)compiler,
    "blur_irradiance_texture",
    0,
    v170,
    (vostok::render::shader_include_getter *)HIDWORD(v203));
  vostok::render::effect_compiler::set_depth(v68, (int)compiler, 0, 0, SLODWORD(v177));
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v69);
  vostok::render::effect_compiler::set_alpha_blend(
    v70,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v180);
  vostok::render::effect_compiler::set_texture(
    v71,
    (const char *)compiler,
    "t_skin_scattering",
    "$user$skin_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v72,
    (const char *)compiler,
    "t_skin_scattering_temp",
    "$user$skin_scattering_temp",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v73,
    (const char *)compiler,
    "t_blurring_stretch",
    "$user$skin_scattering_stretch",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  v74 = config;
  *(_QWORD *)&v204.x = __PAIR64__(LODWORD(s_aim_transition_time), LODWORD(FLOAT_1_2));
  *(_QWORD *)&v204.elements[2] = __PAIR64__(LODWORD(s_bm_current_air_resistance), LODWORD(FLOAT_0_1));
  if ( vostok::configs::binary_config_value::value_exists(
         v75,
         (int)config,
         (unsigned int)"scattering_component_blurring_weights") )
  {
    v77 = vostok::configs::binary_config_value::operator[](config, "scattering_component_blurring_weights");
    v78 = (float **)vostok::configs::binary_config_value::operator[](v77, "value");
    v79 = *v78;
    v204.x = **v78;
    v204.y = *++v79;
    *(_QWORD *)&v204.elements[2] = *(_QWORD *)(v79 + 1);
    v74 = config;
  }
  v204.z = v204.z * v204.w;
  v204.x = v204.x * v204.w;
  v204.y = v204.y * v204.w;
  v204.w = v204.w * v204.w;
  if ( vostok::configs::binary_config_value::value_exists(v76, (int)v74, (unsigned int)"scattering_color_multiplier") )
  {
    v81 = vostok::configs::binary_config_value::operator[](v74, "scattering_color_multiplier");
    v82 = vostok::configs::binary_config_value::operator[](v81, "value");
    if ( v82->type == 2 )
      v83 = *(float *)&v82->data.pointer;
    else
      v83 = (float)(int)v82->data.pointer;
    v204.w = v83;
  }
  if ( (v203 & 0x200) != 0
    && vostok::configs::binary_config_value::value_exists(v80, (int)v74, (unsigned int)"texture_scattering_depth") )
  {
    v84 = vostok::configs::binary_config_value::operator[](v74, "texture_scattering_depth");
    v85 = (char **)vostok::configs::binary_config_value::operator[](v84, "value");
    vostok::render::effect_compiler::set_texture(
      v86,
      (const char *)compiler,
      "t_scattering_depth",
      *v85,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v204,
    (vostok::render::effect_constant_storage *)v80,
    compiler,
    "scattering_component_blurring_weights_and_color_multiplier");
  vostok::render::effect_compiler::end_pass(v87, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v88,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  v203 = 0x80000;
  v202 = 0;
  if ( vostok::configs::binary_config_value::value_exists(v89, (int)v74, (unsigned int)"use_tdiffuse") )
  {
    v91 = vostok::configs::binary_config_value::operator[](v74, "use_tdiffuse");
    v92 = vostok::configs::binary_config_value::operator[](v91, "value")->data.pointer != 0;
  }
  else
  {
    v92 = 0;
  }
  BYTE2(v202) = 8 * v92;
  if ( vostok::configs::binary_config_value::value_exists(v90, (int)v74, (unsigned int)"use_nmap") )
  {
    v94 = vostok::configs::binary_config_value::operator[](v74, "use_nmap");
    v95 = vostok::configs::binary_config_value::operator[](v94, "value")->data.pointer != 0;
  }
  else
  {
    v95 = 0;
  }
  LOBYTE(v93) = BYTE2(v202) & 0x7F;
  BYTE2(v202) = BYTE2(v202) & 0x7F | (v95 << 7);
  if ( vostok::configs::binary_config_value::value_exists(v93, (int)v74, (unsigned int)"use_tspecular_inensity") )
  {
    v97 = vostok::configs::binary_config_value::operator[](v74, "use_tspecular_inensity");
    v98 = vostok::configs::binary_config_value::operator[](v97, "value")->data.pointer != 0;
  }
  else
  {
    v98 = 0;
  }
  BYTE3(v202) ^= (BYTE3(v202) ^ (8 * v98)) & 8;
  if ( vostok::configs::binary_config_value::value_exists(v96, (int)v74, (unsigned int)"use_ao_texture") )
  {
    v100 = vostok::configs::binary_config_value::operator[](v74, "use_ao_texture");
    v101 = vostok::configs::binary_config_value::operator[](v100, "value")->data.pointer != 0;
  }
  else
  {
    v101 = 0;
  }
  LOBYTE(v99) = v203 & 0x7F;
  LOBYTE(v203) = v203 & 0x7F | (v101 << 7);
  if ( vostok::configs::binary_config_value::value_exists(v99, (int)v74, (unsigned int)"use_scattering_amount_mask") )
  {
    v103 = vostok::configs::binary_config_value::operator[](v74, "use_scattering_amount_mask");
    v104 = vostok::configs::binary_config_value::operator[](v103, "value")->data.pointer != 0;
  }
  else
  {
    v104 = 0;
  }
  BYTE1(v203) ^= (BYTE1(v203) ^ v104) & 1;
  if ( vostok::configs::binary_config_value::value_exists(v102, (int)v74, (unsigned int)"use_back_illumination_texture") )
  {
    v106 = vostok::configs::binary_config_value::operator[](v74, "use_back_illumination_texture");
    v107 = vostok::configs::binary_config_value::operator[](v106, "value")->data.pointer != 0;
  }
  else
  {
    v107 = 0;
  }
  BYTE1(v203) ^= (BYTE1(v203) ^ (4 * v107)) & 4;
  if ( vostok::configs::binary_config_value::value_exists(v105, (int)v74, (unsigned int)"use_subdermal_texture") )
  {
    v109 = vostok::configs::binary_config_value::operator[](v74, "use_subdermal_texture");
    v110 = vostok::configs::binary_config_value::operator[](v109, "value")->data.pointer != 0;
  }
  else
  {
    v110 = 0;
  }
  BYTE1(v203) ^= (BYTE1(v203) ^ (8 * v110)) & 8;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v108,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "skin_combine",
    compiler,
    (const char *)&v202,
    v74,
    (vostok::render::shader_configuration *)LODWORD(v177),
    (const vostok::configs::binary_config_value *)HIDWORD(v177));
  vostok::render::effect_compiler::set_depth(v111, (int)compiler, 1, 0, SLODWORD(v181));
  vostok::render::effect_compiler::set_alpha_blend(
    v112,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    SLODWORD(v181));
  if ( (v202 & 0x80000) != 0 )
  {
    v113 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v114 = (char **)vostok::configs::binary_config_value::operator[](v113, "value");
    vostok::render::effect_compiler::set_texture(v115, (const char *)compiler, "t_base", *v114, 0, 0xFFFFFFFF, 0, 1.0);
  }
  v116 = vostok::configs::binary_config_value::operator[](config, "constant_diffuse");
  v117 = vostok::configs::binary_config_value::operator[](v116, "value");
  v118 = (float *)v117->data.pointer;
  v119 = *(float *)v117->data.pointer;
  __libm_sse2_pow(v181, v192);
  *(float *)&v119 = v119;
  v204.x = *(float *)&v119;
  v120 = v118[1];
  __libm_sse2_pow(v182, v195);
  *(float *)&v120 = v120;
  v204.y = *(float *)&v120;
  v121 = v118[2];
  __libm_sse2_pow(v183, v196);
  *(float *)&v121 = v121;
  v204.z = *(float *)&v121;
  v204.w = v118[3];
  *(_QWORD *)&v207.x = *(_QWORD *)&v204.x;
  *(_QWORD *)&v207.elements[2] = __PAIR64__(LODWORD(v204.w), LODWORD(v121));
  if ( (v202 & 0x800000) != 0 )
  {
    v123 = vostok::configs::binary_config_value::operator[](config, "texture_normal");
    v124 = (char **)vostok::configs::binary_config_value::operator[](v123, "value");
    vostok::render::effect_compiler::set_texture(v125, (const char *)compiler, "t_normal", *v124, 0, 0xFFFFFFFF, 0, 1.0);
  }
  if ( (v203 & 0x100) != 0
    && vostok::configs::binary_config_value::value_exists(v122, (int)config, (unsigned int)"texture_scattering_amount") )
  {
    v126 = vostok::configs::binary_config_value::operator[](config, "texture_scattering_amount");
    v127 = (char **)vostok::configs::binary_config_value::operator[](v126, "value");
    vostok::render::effect_compiler::set_texture(
      v128,
      (const char *)compiler,
      "t_sss_amount",
      *v127,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( (v203 & 0x400) != 0
    && vostok::configs::binary_config_value::value_exists(v122, (int)config, (unsigned int)"texture_back_illumination") )
  {
    v129 = vostok::configs::binary_config_value::operator[](config, "texture_back_illumination");
    v130 = (char **)vostok::configs::binary_config_value::operator[](v129, "value");
    vostok::render::effect_compiler::set_texture(
      v131,
      (const char *)compiler,
      "t_back_color",
      *v130,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( (v203 & 0x800) != 0
    && vostok::configs::binary_config_value::value_exists(v122, (int)config, (unsigned int)"texture_subdermal") )
  {
    v132 = vostok::configs::binary_config_value::operator[](config, "texture_subdermal");
    v133 = (char **)vostok::configs::binary_config_value::operator[](v132, "value");
    vostok::render::effect_compiler::set_texture(
      v134,
      (const char *)compiler,
      "t_subdermal",
      *v133,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( (v203 & 0x80u) != 0LL
    && vostok::configs::binary_config_value::value_exists(v122, (int)config, (unsigned int)"texture_ao") )
  {
    v135 = vostok::configs::binary_config_value::operator[](config, "texture_ao");
    v136 = (char **)vostok::configs::binary_config_value::operator[](v135, "value");
    vostok::render::effect_compiler::set_texture(v137, (const char *)compiler, "t_ao", *v136, 0, 0xFFFFFFFF, 0, 1.0);
  }
  if ( (v202 & 0x8000000) != 0 )
  {
    v138 = vostok::configs::binary_config_value::operator[](config, "texture_specular_intensity");
    v139 = (char **)vostok::configs::binary_config_value::operator[](v138, "value");
    vostok::render::effect_compiler::set_texture(
      v140,
      (const char *)compiler,
      "t_specular_intensity",
      *v139,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v122, (int)config, (unsigned int)"constant_specular_color")
    && vostok::configs::binary_config_value::value_exists(
         v141,
         (int)config,
         (unsigned int)"constant_specular_color_multiplier") )
  {
    v142 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color_multiplier");
    v143 = vostok::configs::binary_config_value::operator[](v142, "value");
    v144 = v143->data.pointer;
    LODWORD(v202) = *(_DWORD *)v143->data.pointer;
    HIDWORD(v202) = *++v144;
    LODWORD(v203) = v144[1];
    v145 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color");
    v146 = vostok::configs::binary_config_value::operator[](v145, "value");
    v147 = (float *)v146->data.pointer;
    v148 = *(float *)v146->data.pointer;
    __libm_sse2_pow(v184, v197);
    *(float *)&v148 = v148;
    v205 = *(float *)&v148;
    v149 = v147[1];
    __libm_sse2_pow(v185, v198);
    *(float *)&v149 = v149;
    v206 = *(float *)&v149;
    v150 = v147[2];
    __libm_sse2_pow(v186, v199);
    v151 = v150;
    v201.x = v205 * *(float *)&v202;
    v201.y = *((float *)&v202 + 1) * v206;
    v201.z = *(float *)&v203 * v151;
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(
      &v201,
      v152,
      compiler,
      "specular_color_parameter");
  }
  if ( vostok::configs::binary_config_value::value_exists(v141, (int)config, (unsigned int)"subdermal_weight")
    && vostok::configs::binary_config_value::value_exists(v153, (int)config, (unsigned int)"subdermal_weight") )
  {
    v154 = vostok::configs::binary_config_value::operator[](config, "subdermal_weight");
    v155 = vostok::configs::binary_config_value::operator[](v154, "value");
    if ( v155->type == 2 )
      v157 = *(float *)&v155->data.pointer;
    else
      v157 = (float)(int)v155->data.pointer;
    v200 = v157;
    vostok::render::effect_compiler::set_constant<float>(v156, &v200, compiler, "subdermal_weight");
  }
  if ( vostok::configs::binary_config_value::value_exists(
         v153,
         (int)config,
         (unsigned int)"scattering_color_multiplier")
    && vostok::configs::binary_config_value::value_exists(
         v158,
         (int)config,
         (unsigned int)"scattering_color_multiplier") )
  {
    v159 = vostok::configs::binary_config_value::operator[](config, "scattering_color_multiplier");
    v160 = vostok::configs::binary_config_value::operator[](v159, "value");
    if ( v160->type == 2 )
      v162 = *(float *)&v160->data.pointer;
    else
      v162 = (float)(int)v160->data.pointer;
    v200 = v162;
    vostok::render::effect_compiler::set_constant<float>(v161, &v200, compiler, "scattering_color_multiplier");
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v207,
    (vostok::render::effect_constant_storage *)v158,
    compiler,
    "solid_color_specular");
  vostok::render::effect_compiler::set_texture(
    v163,
    (const char *)compiler,
    "t_skin_scattering",
    "$user$skin_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v164,
    (const char *)compiler,
    "t_skin_scattering_blurred_0",
    "$user$skin_scattering_blurred0",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v165,
    (const char *)compiler,
    "t_skin_scattering_blurred_1",
    "$user$skin_scattering_blurred1",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v166,
    (const char *)compiler,
    "t_skin_scattering_blurred_2",
    "$user$skin_scattering_blurred2",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v167,
    (const char *)compiler,
    "t_skin_scattering_blurred_3",
    "$user$skin_scattering_blurred3",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v168,
    (const char *)compiler,
    "t_skin_scattering_blurred_4",
    "$user$skin_scattering_blurred4",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_material_base::compile_end(v169, compiler);
}
