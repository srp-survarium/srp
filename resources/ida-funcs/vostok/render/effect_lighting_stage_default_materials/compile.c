void __thiscall vostok::render::effect_lighting_stage_default_materials::compile(
        vostok::render::effect_lighting_stage_default_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  vostok::configs::binary_config_value *v7; // eax
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
  char v20; // al
  vostok::configs::binary_config_value *v21; // ecx
  vostok::configs::binary_config_value *v22; // eax
  char v23; // al
  unsigned int v24; // ecx
  vostok::configs::binary_config_value *v25; // eax
  char **v26; // eax
  vostok::render::effect_compiler *v27; // ecx
  vostok::configs::binary_config_value *v28; // eax
  const vostok::configs::binary_config_value *v29; // eax
  float *pointer; // esi
  double v31; // xmm0_8
  double v32; // xmm0_8
  double v33; // xmm0_8
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::configs::binary_config_value *v37; // eax
  char **v38; // eax
  vostok::render::effect_compiler *v39; // ecx
  vostok::configs::binary_config_value *v40; // eax
  char **v41; // eax
  vostok::render::effect_compiler *v42; // ecx
  vostok::configs::binary_config_value *v43; // ecx
  vostok::configs::binary_config_value *v44; // eax
  const vostok::configs::binary_config_value *v45; // eax
  float v46; // xmm0_4
  vostok::configs::binary_config_value *v47; // eax
  const vostok::configs::binary_config_value *v48; // eax
  float v49; // xmm0_4
  vostok::configs::binary_config_value *v50; // ecx
  vostok::configs::binary_config_value *v51; // ecx
  vostok::configs::binary_config_value *v52; // eax
  float **v53; // eax
  float *v54; // esi
  vostok::configs::binary_config_value *v55; // eax
  const vostok::configs::binary_config_value *v56; // eax
  float *v57; // esi
  double v58; // xmm0_8
  double v59; // xmm0_8
  double v60; // xmm0_8
  float v61; // xmm1_4
  vostok::render::effect_constant_storage *v62; // ecx
  vostok::configs::binary_config_value *v63; // ecx
  vostok::configs::binary_config_value *v64; // eax
  char **v65; // eax
  vostok::render::effect_compiler *v66; // ecx
  vostok::configs::binary_config_value *v67; // ecx
  vostok::configs::binary_config_value *v68; // ecx
  vostok::configs::binary_config_value *v69; // eax
  const vostok::configs::binary_config_value *v70; // eax
  float v71; // xmm0_4
  vostok::configs::binary_config_value *v72; // eax
  const vostok::configs::binary_config_value *v73; // eax
  float v74; // xmm0_4
  vostok::configs::binary_config_value *v75; // eax
  const vostok::configs::binary_config_value *v76; // eax
  float v77; // xmm0_4
  vostok::configs::binary_config_value *v78; // eax
  char **v79; // eax
  vostok::render::effect_compiler *v80; // ecx
  vostok::configs::binary_config_value *v81; // ecx
  vostok::render::effect_constant_storage *v82; // ecx
  vostok::configs::binary_config_value *v83; // eax
  const vostok::configs::binary_config_value *v84; // eax
  float v85; // xmm0_4
  vostok::configs::binary_config_value *v86; // eax
  const vostok::configs::binary_config_value *v87; // eax
  float v88; // xmm0_4
  vostok::configs::binary_config_value *v89; // eax
  const vostok::configs::binary_config_value *v90; // eax
  float v91; // xmm0_4
  vostok::configs::binary_config_value *v92; // ecx
  vostok::configs::binary_config_value *v93; // eax
  char **v94; // eax
  vostok::render::effect_compiler *v95; // ecx
  vostok::render::effect_constant_storage *v96; // ecx
  vostok::configs::binary_config_value *v97; // eax
  const vostok::configs::binary_config_value *v98; // eax
  float v99; // xmm0_4
  vostok::render::effect_constant_storage *v100; // ecx
  vostok::render::effect_compiler *v101; // ecx
  vostok::render::effect_compiler *v102; // ecx
  vostok::render::effect_compiler *v103; // ecx
  vostok::render::effect_compiler *v104; // ecx
  vostok::render::effect_material_base *v105; // ecx
  vostok::configs::binary_config_value *v106; // eax
  vostok::configs::binary_config_value *v107; // eax
  vostok::configs::binary_config_value *v108; // eax
  vostok::configs::binary_config_value *v109; // eax
  const vostok::configs::binary_config_value *v110; // eax
  vostok::configs::binary_config_value *v111; // ecx
  vostok::configs::binary_config_value *v112; // ecx
  vostok::configs::binary_config_value *v113; // eax
  bool v114; // al
  vostok::configs::binary_config_value *v115; // ecx
  vostok::configs::binary_config_value *v116; // eax
  bool v117; // al
  vostok::configs::binary_config_value *v118; // ecx
  vostok::configs::binary_config_value *v119; // eax
  char v120; // al
  unsigned int v121; // ecx
  int v122; // eax
  vostok::render::effect_compiler *v123; // ecx
  vostok::configs::binary_config_value *v124; // eax
  char **v125; // eax
  vostok::render::effect_compiler *v126; // ecx
  vostok::configs::binary_config_value *v127; // eax
  const vostok::configs::binary_config_value *v128; // eax
  float *v129; // esi
  double v130; // xmm0_8
  double v131; // xmm0_8
  double v132; // xmm0_8
  vostok::render::effect_constant_storage *v133; // ecx
  vostok::configs::binary_config_value *v134; // ecx
  vostok::configs::binary_config_value *v135; // eax
  char **v136; // eax
  vostok::render::effect_compiler *v137; // ecx
  vostok::configs::binary_config_value *v138; // eax
  char **v139; // eax
  vostok::render::effect_compiler *v140; // ecx
  vostok::render::effect_constant_storage *v141; // ecx
  vostok::configs::binary_config_value *v142; // eax
  const vostok::configs::binary_config_value *v143; // eax
  float v144; // xmm0_4
  vostok::render::effect_compiler *v145; // ecx
  vostok::configs::binary_config_value *v146; // ecx
  vostok::configs::binary_config_value *v147; // eax
  char **v148; // eax
  vostok::render::effect_compiler *v149; // ecx
  vostok::configs::binary_config_value *v150; // ecx
  vostok::configs::binary_config_value *v151; // ecx
  vostok::configs::binary_config_value *v152; // eax
  const vostok::configs::binary_config_value *v153; // eax
  float v154; // xmm0_4
  vostok::configs::binary_config_value *v155; // eax
  const vostok::configs::binary_config_value *v156; // eax
  float v157; // xmm0_4
  vostok::configs::binary_config_value *v158; // eax
  const vostok::configs::binary_config_value *v159; // eax
  float v160; // xmm0_4
  vostok::configs::binary_config_value *v161; // eax
  char **v162; // eax
  vostok::render::effect_compiler *v163; // ecx
  vostok::configs::binary_config_value *v164; // ecx
  vostok::render::effect_constant_storage *v165; // ecx
  vostok::configs::binary_config_value *v166; // eax
  const vostok::configs::binary_config_value *v167; // eax
  float v168; // xmm0_4
  vostok::configs::binary_config_value *v169; // eax
  const vostok::configs::binary_config_value *v170; // eax
  float v171; // xmm0_4
  vostok::configs::binary_config_value *v172; // eax
  const vostok::configs::binary_config_value *v173; // eax
  float v174; // xmm0_4
  vostok::configs::binary_config_value *v175; // eax
  char **v176; // eax
  vostok::render::effect_compiler *v177; // ecx
  vostok::configs::binary_config_value *v178; // ecx
  vostok::configs::binary_config_value *v179; // eax
  const vostok::configs::binary_config_value *v180; // eax
  float v181; // xmm0_4
  vostok::configs::binary_config_value *v182; // eax
  const vostok::configs::binary_config_value *v183; // eax
  float v184; // xmm0_4
  vostok::configs::binary_config_value *v185; // ecx
  vostok::configs::binary_config_value *v186; // ecx
  vostok::configs::binary_config_value *v187; // eax
  float **v188; // eax
  float *v189; // esi
  vostok::configs::binary_config_value *v190; // eax
  const vostok::configs::binary_config_value *v191; // eax
  float *v192; // esi
  double v193; // xmm0_8
  double v194; // xmm0_8
  double v195; // xmm0_8
  float v196; // xmm1_4
  vostok::render::effect_constant_storage *v197; // ecx
  vostok::render::effect_material_base *v198; // ecx
  vostok::render::shader_configuration *v199; // [esp+4h] [ebp-68h]
  long double v200; // [esp+4h] [ebp-68h]
  long double v201; // [esp+4h] [ebp-68h]
  long double v202; // [esp+4h] [ebp-68h]
  long double v203; // [esp+4h] [ebp-68h]
  D3D11_BLEND_OP v204; // [esp+4h] [ebp-68h]
  long double v205; // [esp+4h] [ebp-68h]
  long double v206; // [esp+4h] [ebp-68h]
  long double v207; // [esp+4h] [ebp-68h]
  D3D11_BLEND_OP v208; // [esp+4h] [ebp-68h]
  long double v209; // [esp+4h] [ebp-68h]
  long double v210; // [esp+4h] [ebp-68h]
  long double v211; // [esp+4h] [ebp-68h]
  long double v212; // [esp+4h] [ebp-68h]
  long double v213; // [esp+4h] [ebp-68h]
  const vostok::configs::binary_config_value *v214; // [esp+8h] [ebp-64h]
  long double v215; // [esp+Ch] [ebp-60h]
  long double v216; // [esp+Ch] [ebp-60h]
  long double v217; // [esp+Ch] [ebp-60h]
  long double v218; // [esp+Ch] [ebp-60h]
  long double v219; // [esp+Ch] [ebp-60h]
  long double v220; // [esp+Ch] [ebp-60h]
  long double v221; // [esp+Ch] [ebp-60h]
  long double v222; // [esp+Ch] [ebp-60h]
  long double v223; // [esp+Ch] [ebp-60h]
  long double v224; // [esp+Ch] [ebp-60h]
  long double v225; // [esp+Ch] [ebp-60h]
  char v226; // [esp+14h] [ebp-58h]
  char v227; // [esp+15h] [ebp-57h]
  bool v228; // [esp+16h] [ebp-56h]
  bool v229; // [esp+17h] [ebp-55h]
  float v230; // [esp+18h] [ebp-54h] BYREF
  vostok::math::float4 v231; // [esp+1Ch] [ebp-50h] BYREF
  vostok::math::float4 v232; // [esp+2Ch] [ebp-40h] BYREF
  vostok::math::float4 v233; // [esp+3Ch] [ebp-30h] BYREF
  float v234; // [esp+4Ch] [ebp-20h]
  float v235; // [esp+50h] [ebp-1Ch]
  vostok::math::float4 v236; // [esp+5Ch] [ebp-10h] BYREF

  *(_QWORD *)&v233.elements[2] = 0x80000;
  *(_QWORD *)&v233.x = 0;
  v4 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
  BYTE5(v215) = vostok::configs::binary_config_value::operator[](v4, "value")->data.pointer != 0;
  v5 = vostok::configs::binary_config_value::operator[](config, "use_nmap");
  BYTE4(v215) = vostok::configs::binary_config_value::operator[](v5, "value")->data.pointer != 0;
  v6 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
  BYTE2(v233.elements[0]) = 8
                          * ((2 * (vostok::configs::binary_config_value::operator[](v6, "value")->data.pointer != 0))
                           ^ (BYTE5(v215) & 1 | (16 * BYTE4(v215))));
  v7 = vostok::configs::binary_config_value::operator[](config, "use_ttransparency");
  LOBYTE(v233.elements[1]) = vostok::configs::binary_config_value::operator[](v7, "value")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v8, (int)config, (unsigned int)"use_tspecular_inensity") )
  {
    v10 = vostok::configs::binary_config_value::operator[](config, "use_tspecular_inensity");
    v11 = vostok::configs::binary_config_value::operator[](v10, "value")->data.pointer != 0;
  }
  else
  {
    v11 = 0;
  }
  HIBYTE(v233.elements[0]) ^= (HIBYTE(v233.elements[0]) ^ (8 * v11)) & 8;
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)config, (unsigned int)"use_tfresnel") )
  {
    v13 = vostok::configs::binary_config_value::operator[](config, "use_tfresnel");
    v14 = vostok::configs::binary_config_value::operator[](v13, "value")->data.pointer != 0;
  }
  else
  {
    v14 = 0;
  }
  HIBYTE(v233.elements[0]) ^= (HIBYTE(v233.elements[0]) ^ (16 * v14)) & 0x10;
  if ( vostok::configs::binary_config_value::value_exists(v12, (int)config, (unsigned int)"use_troughness") )
  {
    v16 = vostok::configs::binary_config_value::operator[](config, "use_troughness");
    v17 = vostok::configs::binary_config_value::operator[](v16, "value")->data.pointer != 0;
  }
  else
  {
    v17 = 0;
  }
  HIBYTE(v233.elements[0]) ^= (HIBYTE(v233.elements[0]) ^ (32 * v17)) & 0x20;
  if ( vostok::configs::binary_config_value::value_exists(v15, (int)config, (unsigned int)"is_anisotropic_material") )
  {
    v19 = vostok::configs::binary_config_value::operator[](config, "is_anisotropic_material");
    v20 = vostok::configs::binary_config_value::operator[](v19, "value")->data.pointer != 0;
  }
  else
  {
    v20 = 0;
  }
  LOBYTE(v233.elements[2]) ^= (LOBYTE(v233.elements[2]) ^ (v20 << 6)) & 0x40;
  if ( vostok::configs::binary_config_value::value_exists(v18, (int)config, (unsigned int)"use_soft_edges") )
  {
    v22 = vostok::configs::binary_config_value::operator[](config, "use_soft_edges");
    v23 = vostok::configs::binary_config_value::operator[](v22, "value")->data.pointer != 0;
  }
  else
  {
    v23 = 0;
  }
  BYTE1(v233.elements[1]) = 0;
  LOBYTE(v21) = LOBYTE(v233.elements[3]) & 0x7F;
  LOBYTE(v233.elements[3]) = LOBYTE(v233.elements[3]) & 0x7F | (v23 << 7);
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v21,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "forward_lighting",
    compiler,
    (const char *)&v233,
    config,
    v199,
    v214);
  v24 = BYTE2(v233.elements[1]) & 0x3F;
  if ( v24 < 0xF )
    LODWORD(v230) = 1 << v24;
  else
    v230 = NAN;
  HIBYTE(v215) = (BYTE2(v233.elements[0]) & 8) != 0;
  if ( (BYTE2(v233.elements[0]) & 8) != 0 )
  {
    v25 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v26 = (char **)vostok::configs::binary_config_value::operator[](v25, "value");
    vostok::render::effect_compiler::set_texture(v27, (const char *)compiler, "t_base", *v26, 0, 0xFFFFFFFF, 0, 1.0);
  }
  v28 = vostok::configs::binary_config_value::operator[](config, "constant_diffuse");
  v29 = vostok::configs::binary_config_value::operator[](v28, "value");
  pointer = (float *)v29->data.pointer;
  v31 = *(float *)v29->data.pointer;
  __libm_sse2_pow(v200, v215);
  *(float *)&v31 = v31;
  v232.x = *(float *)&v31;
  v32 = pointer[1];
  __libm_sse2_pow(v201, v216);
  *(float *)&v32 = v32;
  v232.y = *(float *)&v32;
  v33 = pointer[2];
  __libm_sse2_pow(v202, v217);
  *(float *)&v33 = v33;
  v232.z = *(float *)&v33;
  v232.w = pointer[3];
  *(_QWORD *)&v236.x = *(_QWORD *)&v232.x;
  *(_QWORD *)&v236.elements[2] = LODWORD(v33);
  if ( LODWORD(v230) == 128 || LODWORD(v230) == 256 || LODWORD(v230) == 512 )
  {
    vostok::render::effect_compiler::set_depth(v34, (int)compiler, 0, 0, SLODWORD(v203));
    vostok::render::effect_compiler::set_alpha_blend(
      v36,
      (int)compiler,
      1,
      D3D11_BLEND_SRC_ALPHA,
      D3D11_BLEND_INV_SRC_ALPHA,
      D3D11_BLEND_OP_ADD,
      D3D11_BLEND_ZERO,
      D3D11_BLEND_INV_SRC_ALPHA,
      v204);
  }
  else
  {
    vostok::render::effect_compiler::set_alpha_blend(
      v34,
      (int)compiler,
      1,
      D3D11_BLEND_SRC_ALPHA,
      D3D11_BLEND_ONE,
      D3D11_BLEND_OP_ADD,
      D3D11_BLEND_ONE,
      D3D11_BLEND_ZERO,
      SLODWORD(v203));
  }
  v226 = BYTE2(v233.elements[0]) >> 7;
  if ( SBYTE2(v233.elements[0]) < 0 )
  {
    v37 = vostok::configs::binary_config_value::operator[](config, "texture_normal");
    v38 = (char **)vostok::configs::binary_config_value::operator[](v37, "value");
    vostok::render::effect_compiler::set_texture(v39, (const char *)compiler, "t_normal", *v38, 0, 0xFFFFFFFF, 0, 1.0);
  }
  v231.x = 0.0;
  v231.y = s_bm_current_air_resistance;
  v229 = (HIBYTE(v233.elements[0]) & 8) != 0;
  if ( (HIBYTE(v233.elements[0]) & 8) != 0 )
  {
    v40 = vostok::configs::binary_config_value::operator[](config, "texture_specular_intensity");
    v41 = (char **)vostok::configs::binary_config_value::operator[](v40, "value");
    vostok::render::effect_compiler::set_texture(
      v42,
      (const char *)compiler,
      "t_specular_intensity",
      *v41,
      0,
      0xFFFFFFFF,
      0,
      1.0);
    if ( vostok::configs::binary_config_value::value_exists(
           v43,
           (int)config,
           (unsigned int)"constant_specular_intensity_min") )
    {
      v44 = vostok::configs::binary_config_value::operator[](config, "constant_specular_intensity_min");
      v45 = vostok::configs::binary_config_value::operator[](v44, "value");
      if ( v45->type == 2 )
        v46 = *(float *)&v45->data.pointer;
      else
        v46 = (float)(int)v45->data.pointer;
      v230 = v46;
      v231.x = v46;
      v47 = vostok::configs::binary_config_value::operator[](config, "constant_specular_intensity_max");
      v48 = vostok::configs::binary_config_value::operator[](v47, "value");
      if ( v48->type == 2 )
        v49 = *(float *)&v48->data.pointer;
      else
        v49 = (float)(int)v48->data.pointer;
      v231.y = v49 - v230;
    }
  }
  vostok::render::effect_compiler::set_texture(
    v35,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_constant<vostok::math::float2>(
    (vostok::render::effect_constant_storage *)&v231,
    compiler,
    "specular_intensity_ranges");
  if ( vostok::configs::binary_config_value::value_exists(v50, (int)config, (unsigned int)"constant_specular_color")
    && vostok::configs::binary_config_value::value_exists(
         v51,
         (int)config,
         (unsigned int)"constant_specular_color_multiplier") )
  {
    v52 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color_multiplier");
    v53 = (float **)vostok::configs::binary_config_value::operator[](v52, "value");
    v54 = *v53;
    v231.x = **v53;
    *(_QWORD *)&v231.elements[1] = *(_QWORD *)(v54 + 1);
    v55 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color");
    v56 = vostok::configs::binary_config_value::operator[](v55, "value");
    v57 = (float *)v56->data.pointer;
    v58 = *(float *)v56->data.pointer;
    __libm_sse2_pow(v203, v218);
    *(float *)&v58 = v58;
    v234 = *(float *)&v58;
    v59 = v57[1];
    __libm_sse2_pow(v205, v219);
    *(float *)&v59 = v59;
    v235 = *(float *)&v59;
    v60 = v57[2];
    __libm_sse2_pow(v206, v220);
    v61 = v60;
    v232.x = v234 * v231.x;
    v232.y = v231.y * v235;
    v232.z = v231.z * v61;
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(
      (const vostok::math::float3 *)&v232,
      v62,
      compiler,
      "specular_color_parameter");
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v236,
    (vostok::render::effect_constant_storage *)v51,
    compiler,
    "solid_color_specular");
  v228 = (HIBYTE(v233.elements[0]) & 0x20) != 0;
  memset(&v231, 0, sizeof(v231));
  memset(&v232, 0, sizeof(v232));
  if ( (HIBYTE(v233.elements[0]) & 0x20) != 0 )
  {
    v64 = vostok::configs::binary_config_value::operator[](config, "texture_roughness");
    v65 = (char **)vostok::configs::binary_config_value::operator[](v64, "value");
    vostok::render::effect_compiler::set_texture(
      v66,
      (const char *)compiler,
      "t_roughness",
      *v65,
      0,
      0xFFFFFFFF,
      0,
      1.0);
    if ( vostok::configs::binary_config_value::value_exists(v67, (int)config, (unsigned int)"constant_roughness_min") )
    {
      v69 = vostok::configs::binary_config_value::operator[](config, "constant_roughness_min");
      v70 = vostok::configs::binary_config_value::operator[](v69, "value");
      if ( v70->type == 2 )
        v71 = *(float *)&v70->data.pointer;
      else
        v71 = (float)(int)v70->data.pointer;
      v230 = v71;
      v232.z = v71;
      v72 = vostok::configs::binary_config_value::operator[](config, "constant_roughness_max");
      v73 = vostok::configs::binary_config_value::operator[](v72, "value");
      if ( v73->type == 2 )
        v74 = *(float *)&v73->data.pointer;
      else
        v74 = (float)(int)v73->data.pointer;
      v232.w = v74 - v230;
    }
  }
  else if ( vostok::configs::binary_config_value::value_exists(v63, (int)config, (unsigned int)"constant_roughness") )
  {
    v75 = vostok::configs::binary_config_value::operator[](config, "constant_roughness");
    v76 = vostok::configs::binary_config_value::operator[](v75, "value");
    if ( v76->type == 2 )
      v77 = *(float *)&v76->data.pointer;
    else
      v77 = (float)(int)v76->data.pointer;
    v232.z = v77;
  }
  BYTE4(v218) = (HIBYTE(v233.elements[0]) & 0x10) != 0;
  if ( (HIBYTE(v233.elements[0]) & 0x10) != 0 )
  {
    v78 = vostok::configs::binary_config_value::operator[](config, "texture_fresnel");
    v79 = (char **)vostok::configs::binary_config_value::operator[](v78, "value");
    vostok::render::effect_compiler::set_texture(v80, (const char *)compiler, "t_fresnel", *v79, 0, 0xFFFFFFFF, 0, 1.0);
    if ( vostok::configs::binary_config_value::value_exists(v81, (int)config, (unsigned int)"constant_fresnel_min") )
    {
      v83 = vostok::configs::binary_config_value::operator[](config, "constant_fresnel_min");
      v84 = vostok::configs::binary_config_value::operator[](v83, "value");
      if ( v84->type == 2 )
        v85 = *(float *)&v84->data.pointer;
      else
        v85 = (float)(int)v84->data.pointer;
      v230 = v85;
      v232.x = v85;
      v86 = vostok::configs::binary_config_value::operator[](config, "constant_fresnel_max");
      v87 = vostok::configs::binary_config_value::operator[](v86, "value");
      if ( v87->type == 2 )
        v88 = *(float *)&v87->data.pointer;
      else
        v88 = (float)(int)v87->data.pointer;
      v232.y = v88 - v230;
    }
  }
  else if ( vostok::configs::binary_config_value::value_exists(v68, (int)config, (unsigned int)"constant_fresnel") )
  {
    v89 = vostok::configs::binary_config_value::operator[](config, "constant_fresnel");
    v90 = vostok::configs::binary_config_value::operator[](v89, "value");
    if ( v90->type == 2 )
      v91 = *(float *)&v90->data.pointer;
    else
      v91 = (float)(int)v90->data.pointer;
    v232.x = v91;
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v232,
    v82,
    compiler,
    "specular_fresnel_roughness_parameters");
  v227 = LOBYTE(v233.elements[1]) & 1;
  if ( (LOBYTE(v233.elements[1]) & 1) != 0 )
  {
    v93 = vostok::configs::binary_config_value::operator[](config, "texture_transparency");
    v94 = (char **)vostok::configs::binary_config_value::operator[](v93, "value");
    vostok::render::effect_compiler::set_texture(
      v95,
      (const char *)compiler,
      "t_transparency",
      *v94,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v92, (int)config, (unsigned int)"constant_transparency") )
  {
    v97 = vostok::configs::binary_config_value::operator[](config, "constant_transparency");
    v98 = vostok::configs::binary_config_value::operator[](v97, "value");
    if ( v98->type == 2 )
      v99 = *(float *)&v98->data.pointer;
    else
      v99 = (float)(int)v98->data.pointer;
  }
  else
  {
    v99 = s_bm_current_air_resistance;
  }
  v230 = v99;
  vostok::render::effect_compiler::set_constant<float>(v96, &v230, compiler, "solid_transparency");
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v231, v100, compiler, "solid_material_params");
  vostok::render::effect_compiler::set_texture(
    v101,
    (const char *)compiler,
    "t_cascaded_shadow_map0",
    "$user$cascaded_shadow_map0",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v102,
    (const char *)compiler,
    "t_cascaded_shadow_map1",
    "$user$cascaded_shadow_map1",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v103,
    (const char *)compiler,
    "t_cascaded_shadow_map2",
    "$user$cascaded_shadow_map2",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v104,
    (const char *)compiler,
    "t_cascaded_shadow_map3",
    "$user$cascaded_shadow_map3",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_material_base::compile_end(v105, compiler);
  *(_QWORD *)&v233.elements[2] = 0x80000;
  *(_QWORD *)&v233.x = 0;
  v106 = vostok::configs::binary_config_value::operator[](config, "use_ttransparency");
  LOBYTE(v233.elements[1]) = vostok::configs::binary_config_value::operator[](v106, "value")->data.pointer != 0;
  v107 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
  BYTE5(v218) = vostok::configs::binary_config_value::operator[](v107, "value")->data.pointer != 0;
  v108 = vostok::configs::binary_config_value::operator[](config, "use_nmap");
  BYTE6(v218) = vostok::configs::binary_config_value::operator[](v108, "value")->data.pointer != 0;
  v109 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
  v110 = vostok::configs::binary_config_value::operator[](v109, "value");
  BYTE2(v233.elements[0]) = BYTE2(v233.elements[0]) & 0x67
                          | (BYTE6(v218) << 7)
                          | (8 * (BYTE5(v218) & 1 | (2 * (v110->data.pointer != 0))));
  LOBYTE(v111) = BYTE2(v233.elements[0]);
  if ( vostok::configs::binary_config_value::value_exists(v111, (int)config, (unsigned int)"use_tfresnel") )
  {
    v113 = vostok::configs::binary_config_value::operator[](config, "use_tfresnel");
    v114 = vostok::configs::binary_config_value::operator[](v113, "value")->data.pointer != 0;
  }
  else
  {
    v114 = 0;
  }
  HIBYTE(v233.elements[0]) ^= (HIBYTE(v233.elements[0]) ^ (16 * v114)) & 0x10;
  if ( vostok::configs::binary_config_value::value_exists(v112, (int)config, (unsigned int)"use_troughness") )
  {
    v116 = vostok::configs::binary_config_value::operator[](config, "use_troughness");
    v117 = vostok::configs::binary_config_value::operator[](v116, "value")->data.pointer != 0;
  }
  else
  {
    v117 = 0;
  }
  HIBYTE(v233.elements[0]) ^= (HIBYTE(v233.elements[0]) ^ (32 * v117)) & 0x20;
  if ( vostok::configs::binary_config_value::value_exists(v115, (int)config, (unsigned int)"use_soft_edges") )
  {
    v119 = vostok::configs::binary_config_value::operator[](config, "use_soft_edges");
    v120 = vostok::configs::binary_config_value::operator[](v119, "value")->data.pointer != 0;
  }
  else
  {
    v120 = 0;
  }
  LOBYTE(v118) = LOBYTE(v233.elements[3]) & 0x7F;
  LOBYTE(v233.elements[3]) = LOBYTE(v233.elements[3]) & 0x7F | (v120 << 7);
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v118,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "forward_probe_lighting",
    compiler,
    (const char *)&v233,
    config,
    (vostok::render::shader_configuration *)LODWORD(v203),
    (const vostok::configs::binary_config_value *)HIDWORD(v203));
  v121 = BYTE2(v233.elements[1]) & 0x3F;
  if ( v121 < 0xF && ((v122 = 1 << v121, 1 << v121 == 128) || v122 == 256 || v122 == 512) )
  {
    vostok::render::effect_compiler::set_depth(
      (vostok::render::effect_compiler *)v121,
      (int)compiler,
      0,
      0,
      SLODWORD(v207));
    vostok::render::effect_compiler::set_alpha_blend(
      v123,
      (int)compiler,
      1,
      D3D11_BLEND_SRC_ALPHA,
      D3D11_BLEND_INV_SRC_ALPHA,
      D3D11_BLEND_OP_ADD,
      D3D11_BLEND_ZERO,
      D3D11_BLEND_INV_SRC_ALPHA,
      v208);
  }
  else
  {
    vostok::render::effect_compiler::set_alpha_blend(
      (vostok::render::effect_compiler *)v121,
      (int)compiler,
      1,
      D3D11_BLEND_SRC_ALPHA,
      D3D11_BLEND_ONE,
      D3D11_BLEND_OP_ADD,
      D3D11_BLEND_ONE,
      D3D11_BLEND_ZERO,
      SLODWORD(v207));
  }
  if ( HIBYTE(v218) )
  {
    v124 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v125 = (char **)vostok::configs::binary_config_value::operator[](v124, "value");
    vostok::render::effect_compiler::set_texture(v126, (const char *)compiler, "t_base", *v125, 0, 0xFFFFFFFF, 0, 1.0);
  }
  v127 = vostok::configs::binary_config_value::operator[](config, "constant_diffuse");
  v128 = vostok::configs::binary_config_value::operator[](v127, "value");
  v129 = (float *)v128->data.pointer;
  v130 = *(float *)v128->data.pointer;
  __libm_sse2_pow(v207, v218);
  *(float *)&v130 = v130;
  v233.x = *(float *)&v130;
  v131 = v129[1];
  __libm_sse2_pow(v209, v221);
  *(float *)&v131 = v131;
  v233.y = *(float *)&v131;
  v132 = v129[2];
  __libm_sse2_pow(v210, v222);
  *(float *)&v132 = v132;
  v233.z = *(float *)&v132;
  v233.w = v129[3];
  *(_QWORD *)&v236.x = *(_QWORD *)&v233.x;
  *(_QWORD *)&v236.elements[2] = LODWORD(v132);
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v236, v133, compiler, "solid_color_specular");
  if ( v226 )
  {
    v135 = vostok::configs::binary_config_value::operator[](config, "texture_normal");
    v136 = (char **)vostok::configs::binary_config_value::operator[](v135, "value");
    vostok::render::effect_compiler::set_texture(v137, (const char *)compiler, "t_normal", *v136, 0, 0xFFFFFFFF, 0, 1.0);
  }
  if ( v227 )
  {
    v138 = vostok::configs::binary_config_value::operator[](config, "texture_transparency");
    v139 = (char **)vostok::configs::binary_config_value::operator[](v138, "value");
    vostok::render::effect_compiler::set_texture(
      v140,
      (const char *)compiler,
      "t_transparency",
      *v139,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v134, (int)config, (unsigned int)"constant_transparency") )
  {
    v142 = vostok::configs::binary_config_value::operator[](config, "constant_transparency");
    v143 = vostok::configs::binary_config_value::operator[](v142, "value");
    if ( v143->type == 2 )
      v144 = *(float *)&v143->data.pointer;
    else
      v144 = (float)(int)v143->data.pointer;
  }
  else
  {
    v144 = s_bm_current_air_resistance;
  }
  v230 = v144;
  vostok::render::effect_compiler::set_constant<float>(v141, &v230, compiler, "solid_transparency");
  vostok::render::effect_compiler::set_texture(
    v145,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  memset(&v233, 0, sizeof(v233));
  if ( v228 )
  {
    v147 = vostok::configs::binary_config_value::operator[](config, "texture_roughness");
    v148 = (char **)vostok::configs::binary_config_value::operator[](v147, "value");
    vostok::render::effect_compiler::set_texture(
      v149,
      (const char *)compiler,
      "t_roughness",
      *v148,
      0,
      0xFFFFFFFF,
      0,
      1.0);
    if ( vostok::configs::binary_config_value::value_exists(v150, (int)config, (unsigned int)"constant_roughness_min") )
    {
      v152 = vostok::configs::binary_config_value::operator[](config, "constant_roughness_min");
      v153 = vostok::configs::binary_config_value::operator[](v152, "value");
      if ( v153->type == 2 )
        v154 = *(float *)&v153->data.pointer;
      else
        v154 = (float)(int)v153->data.pointer;
      v230 = v154;
      v233.z = v154;
      v155 = vostok::configs::binary_config_value::operator[](config, "constant_roughness_max");
      v156 = vostok::configs::binary_config_value::operator[](v155, "value");
      if ( v156->type == 2 )
        v157 = *(float *)&v156->data.pointer;
      else
        v157 = (float)(int)v156->data.pointer;
      v233.w = v157 - v230;
    }
  }
  else if ( vostok::configs::binary_config_value::value_exists(v146, (int)config, (unsigned int)"constant_roughness") )
  {
    v158 = vostok::configs::binary_config_value::operator[](config, "constant_roughness");
    v159 = vostok::configs::binary_config_value::operator[](v158, "value");
    if ( v159->type == 2 )
      v160 = *(float *)&v159->data.pointer;
    else
      v160 = (float)(int)v159->data.pointer;
    v233.z = v160;
  }
  if ( BYTE4(v223) )
  {
    v161 = vostok::configs::binary_config_value::operator[](config, "texture_fresnel");
    v162 = (char **)vostok::configs::binary_config_value::operator[](v161, "value");
    vostok::render::effect_compiler::set_texture(
      v163,
      (const char *)compiler,
      "t_fresnel",
      *v162,
      0,
      0xFFFFFFFF,
      0,
      1.0);
    if ( vostok::configs::binary_config_value::value_exists(v164, (int)config, (unsigned int)"constant_fresnel_min") )
    {
      v166 = vostok::configs::binary_config_value::operator[](config, "constant_fresnel_min");
      v167 = vostok::configs::binary_config_value::operator[](v166, "value");
      if ( v167->type == 2 )
        v168 = *(float *)&v167->data.pointer;
      else
        v168 = (float)(int)v167->data.pointer;
      v230 = v168;
      v233.x = v168;
      v169 = vostok::configs::binary_config_value::operator[](config, "constant_fresnel_max");
      v170 = vostok::configs::binary_config_value::operator[](v169, "value");
      if ( v170->type == 2 )
        v171 = *(float *)&v170->data.pointer;
      else
        v171 = (float)(int)v170->data.pointer;
      v233.y = v171 - v230;
    }
  }
  else if ( vostok::configs::binary_config_value::value_exists(v151, (int)config, (unsigned int)"constant_fresnel") )
  {
    v172 = vostok::configs::binary_config_value::operator[](config, "constant_fresnel");
    v173 = vostok::configs::binary_config_value::operator[](v172, "value");
    if ( v173->type == 2 )
      v174 = *(float *)&v173->data.pointer;
    else
      v174 = (float)(int)v173->data.pointer;
    v233.x = v174;
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v233,
    v165,
    compiler,
    "specular_fresnel_roughness_parameters");
  v231.x = 0.0;
  v231.y = s_bm_current_air_resistance;
  if ( v229 )
  {
    v175 = vostok::configs::binary_config_value::operator[](config, "texture_specular_intensity");
    v176 = (char **)vostok::configs::binary_config_value::operator[](v175, "value");
    vostok::render::effect_compiler::set_texture(
      v177,
      (const char *)compiler,
      "t_specular_intensity",
      *v176,
      0,
      0xFFFFFFFF,
      0,
      1.0);
    if ( vostok::configs::binary_config_value::value_exists(
           v178,
           (int)config,
           (unsigned int)"constant_specular_intensity_min") )
    {
      v179 = vostok::configs::binary_config_value::operator[](config, "constant_specular_intensity_min");
      v180 = vostok::configs::binary_config_value::operator[](v179, "value");
      if ( v180->type == 2 )
        v181 = *(float *)&v180->data.pointer;
      else
        v181 = (float)(int)v180->data.pointer;
      v230 = v181;
      v231.x = v181;
      v182 = vostok::configs::binary_config_value::operator[](config, "constant_specular_intensity_max");
      v183 = vostok::configs::binary_config_value::operator[](v182, "value");
      if ( v183->type == 2 )
        v184 = *(float *)&v183->data.pointer;
      else
        v184 = (float)(int)v183->data.pointer;
      v231.y = v184 - v230;
    }
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float2>(
    (vostok::render::effect_constant_storage *)&v231,
    compiler,
    "specular_intensity_ranges");
  if ( vostok::configs::binary_config_value::value_exists(v185, (int)config, (unsigned int)"constant_specular_color")
    && vostok::configs::binary_config_value::value_exists(
         v186,
         (int)config,
         (unsigned int)"constant_specular_color_multiplier") )
  {
    v187 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color_multiplier");
    v188 = (float **)vostok::configs::binary_config_value::operator[](v187, "value");
    v189 = *v188;
    v232.x = **v188;
    *(_QWORD *)&v232.elements[1] = *(_QWORD *)(v189 + 1);
    v190 = vostok::configs::binary_config_value::operator[](config, "constant_specular_color");
    v191 = vostok::configs::binary_config_value::operator[](v190, "value");
    v192 = (float *)v191->data.pointer;
    v193 = *(float *)v191->data.pointer;
    __libm_sse2_pow(v211, v223);
    *(float *)&v193 = v193;
    v234 = *(float *)&v193;
    v194 = v192[1];
    __libm_sse2_pow(v212, v224);
    *(float *)&v194 = v194;
    v235 = *(float *)&v194;
    v195 = v192[2];
    __libm_sse2_pow(v213, v225);
    v196 = v195;
    v231.x = v234 * v232.x;
    v231.y = v232.y * v235;
    v231.z = v232.z * v196;
    vostok::render::effect_compiler::set_constant<vostok::math::float3>(
      (const vostok::math::float3 *)&v231,
      v197,
      compiler,
      "specular_color_parameter");
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v236,
    (vostok::render::effect_constant_storage *)v186,
    compiler,
    "solid_color_specular");
  vostok::render::effect_material_base::compile_end(v198, compiler);
}
