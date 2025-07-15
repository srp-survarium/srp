void __thiscall vostok::render::effect_gstage_terrain_materials::compile(
        vostok::render::effect_gstage_terrain_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // eax
  bool v6; // al
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // eax
  char v9; // al
  vostok::configs::binary_config_value *v10; // ecx
  vostok::configs::binary_config_value *v11; // eax
  bool v12; // al
  vostok::configs::binary_config_value *v13; // ecx
  vostok::configs::binary_config_value *v14; // eax
  const void *pointer; // eax
  vostok::configs::binary_config_value *v16; // ecx
  vostok::configs::binary_config_value *v17; // eax
  vostok::configs::binary_config_value *v18; // ecx
  vostok::configs::binary_config_value *v19; // eax
  vostok::configs::binary_config_value *v20; // ecx
  vostok::configs::binary_config_value *v21; // eax
  vostok::configs::binary_config_value *v22; // ecx
  vostok::configs::binary_config_value *v23; // eax
  char v24; // al
  vostok::configs::binary_config_value *v25; // ecx
  vostok::configs::binary_config_value *v26; // eax
  unsigned int v27; // eax
  vostok::render::effect_compiler *v28; // ecx
  vostok::command_line::key *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::configs::binary_config_value *v32; // eax
  char **v33; // eax
  vostok::render::effect_compiler *v34; // ecx
  vostok::configs::binary_config_value *v35; // eax
  const vostok::configs::binary_config_value *v36; // eax
  float v37; // xmm0_4
  vostok::configs::binary_config_value *v38; // eax
  const vostok::configs::binary_config_value *v39; // eax
  float v40; // xmm0_4
  vostok::configs::binary_config_value *v41; // eax
  const vostok::configs::binary_config_value *v42; // eax
  float v43; // xmm0_4
  vostok::configs::binary_config_value *v44; // eax
  const vostok::configs::binary_config_value *v45; // eax
  float v46; // xmm0_4
  vostok::configs::binary_config_value *v47; // eax
  char **v48; // eax
  vostok::render::effect_compiler *v49; // ecx
  vostok::configs::binary_config_value *v50; // eax
  char **v51; // eax
  vostok::render::effect_compiler *v52; // ecx
  vostok::configs::binary_config_value *v53; // eax
  char **v54; // eax
  vostok::render::effect_compiler *v55; // ecx
  vostok::configs::binary_config_value *v56; // eax
  char **v57; // eax
  vostok::render::effect_compiler *v58; // ecx
  vostok::render::effect_constant_storage *v59; // ecx
  vostok::configs::binary_config_value *v60; // eax
  char **v61; // eax
  vostok::render::effect_compiler *v62; // ecx
  vostok::configs::binary_config_value *v63; // eax
  char **v64; // eax
  vostok::render::effect_compiler *v65; // ecx
  vostok::configs::binary_config_value *v66; // eax
  char **v67; // eax
  vostok::render::effect_compiler *v68; // ecx
  vostok::configs::binary_config_value *v69; // eax
  char **v70; // eax
  vostok::render::effect_compiler *v71; // ecx
  vostok::configs::binary_config_value *v72; // eax
  char **v73; // eax
  vostok::render::effect_compiler *v74; // ecx
  vostok::render::effect_constant_storage *v75; // ecx
  vostok::render::effect_constant_storage *v76; // ecx
  vostok::configs::binary_config_value *v77; // eax
  char **v78; // eax
  vostok::render::effect_compiler *v79; // ecx
  vostok::configs::binary_config_value *v80; // eax
  char **v81; // eax
  vostok::render::effect_compiler *v82; // ecx
  vostok::configs::binary_config_value *v83; // eax
  char **v84; // eax
  vostok::render::effect_compiler *v85; // ecx
  vostok::configs::binary_config_value *v86; // eax
  char **v87; // eax
  vostok::render::effect_compiler *v88; // ecx
  vostok::render::effect_constant_storage *v89; // ecx
  vostok::render::effect_compiler *v90; // ecx
  vostok::render::effect_compiler *v91; // ecx
  vostok::render::effect_compiler *v92; // ecx
  vostok::render::effect_material_base *v93; // ecx
  vostok::configs::binary_config_value *v94; // eax
  const vostok::configs::binary_config_value *v95; // eax
  float v96; // xmm0_4
  vostok::configs::binary_config_value *v97; // eax
  const vostok::configs::binary_config_value *v98; // eax
  float v99; // xmm0_4
  vostok::configs::binary_config_value *v100; // eax
  char **v101; // eax
  vostok::render::effect_compiler *v102; // ecx
  vostok::configs::binary_config_value *v103; // eax
  char **v104; // eax
  vostok::render::effect_compiler *v105; // ecx
  vostok::render::effect_constant_storage *v106; // ecx
  vostok::render::effect_material_base *v107; // ecx
  vostok::configs::binary_config_value *v108; // ecx
  vostok::configs::binary_config_value *v109; // ecx
  vostok::configs::binary_config_value *v110; // eax
  bool v111; // al
  vostok::render::effect_compiler *v112; // ecx
  vostok::render::effect_compiler *v113; // ecx
  vostok::render::effect_constant_storage *v114; // ecx
  vostok::configs::binary_config_value *v115; // eax
  char **v116; // eax
  vostok::render::effect_compiler *v117; // ecx
  vostok::render::effect_material_base *v118; // ecx
  vostok::configs::binary_config_value *v119; // ecx
  vostok::configs::binary_config_value *v120; // ecx
  vostok::render::effect_constant_storage *v121; // ecx
  vostok::configs::binary_config_value *v122; // eax
  bool v123; // al
  vostok::configs::binary_config_value *v124; // eax
  char **v125; // eax
  vostok::render::effect_compiler *v126; // ecx
  vostok::render::effect_material_base *v127; // ecx
  vostok::configs::binary_config_value *v128; // ecx
  vostok::render::effect_compiler *v129; // ecx
  vostok::render::effect_compiler *v130; // ecx
  vostok::render::effect_compiler *v131; // ecx
  vostok::configs::binary_config_value *v132; // eax
  const vostok::configs::binary_config_value *v133; // eax
  float v134; // xmm0_4
  vostok::configs::binary_config_value *v135; // eax
  const vostok::configs::binary_config_value *v136; // eax
  float *v137; // esi
  double v138; // xmm0_8
  double v139; // xmm0_8
  double v140; // xmm0_8
  vostok::render::effect_constant_storage *v141; // ecx
  vostok::render::effect_material_base *v142; // ecx
  vostok::configs::binary_config_value *v143; // eax
  char **v144; // eax
  vostok::render::effect_compiler *v145; // ecx
  vostok::configs::binary_config_value *v146; // ecx
  vostok::configs::binary_config_value *v147; // ecx
  vostok::configs::binary_config_value *v148; // eax
  bool v149; // al
  vostok::configs::binary_config_value *v150; // ecx
  vostok::configs::binary_config_value *v151; // eax
  bool v152; // al
  vostok::render::effect_compiler *v153; // ecx
  vostok::configs::binary_config_value *v154; // ecx
  vostok::configs::binary_config_value *v155; // eax
  char **v156; // eax
  vostok::render::effect_compiler *v157; // ecx
  vostok::configs::binary_config_value *v158; // eax
  const vostok::configs::binary_config_value *v159; // eax
  float v160; // xmm0_4
  vostok::render::effect_material_base *v161; // ecx
  vostok::configs::binary_config_value *v162; // ecx
  vostok::configs::binary_config_value *v163; // ecx
  vostok::configs::binary_config_value *v164; // eax
  bool v165; // al
  vostok::configs::binary_config_value *v166; // ecx
  vostok::configs::binary_config_value *v167; // eax
  bool v168; // al
  vostok::render::effect_compiler *v169; // ecx
  vostok::configs::binary_config_value *v170; // ecx
  vostok::configs::binary_config_value *v171; // eax
  char **v172; // eax
  vostok::render::effect_compiler *v173; // ecx
  vostok::configs::binary_config_value *v174; // eax
  const vostok::configs::binary_config_value *v175; // eax
  float v176; // xmm0_4
  vostok::render::effect_compiler *v177; // ecx
  vostok::render::effect_compiler *v178; // ecx
  vostok::render::effect_material_base *v179; // ecx
  vostok::configs::binary_config_value *v180; // ecx
  vostok::render::effect_compiler *v181; // ecx
  vostok::render::effect_compiler *v182; // ecx
  vostok::render::effect_compiler *v183; // ecx
  vostok::render::effect_material_base *v184; // ecx
  vostok::configs::binary_config_value *v185; // ecx
  vostok::configs::binary_config_value *v186; // ecx
  vostok::configs::binary_config_value *v187; // eax
  bool v188; // al
  vostok::render::effect_compiler *v189; // ecx
  vostok::command_line::key *v190; // ecx
  vostok::render::effect_compiler *v191; // ecx
  vostok::render::effect_material_base *v192; // ecx
  vostok::configs::binary_config_value *v193; // ecx
  vostok::render::effect_compiler *v194; // ecx
  vostok::command_line::key *v195; // ecx
  vostok::render::effect_compiler *v196; // ecx
  vostok::render::effect_material_base *v197; // ecx
  vostok::configs::binary_config_value *v198; // ecx
  vostok::configs::binary_config_value *v199; // ecx
  vostok::configs::binary_config_value *v200; // eax
  bool v201; // al
  vostok::configs::binary_config_value *v202; // ecx
  vostok::configs::binary_config_value *v203; // eax
  char v204; // al
  vostok::configs::binary_config_value *v205; // ecx
  vostok::configs::binary_config_value *v206; // eax
  bool v207; // al
  vostok::configs::binary_config_value *v208; // ecx
  vostok::configs::binary_config_value *v209; // eax
  bool v210; // al
  vostok::render::effect_compiler *v211; // ecx
  vostok::command_line::key *v212; // ecx
  vostok::command_line::key *v213; // ecx
  vostok::render::effect_material_base *v214; // ecx
  vostok::configs::binary_config_value *v215; // ecx
  vostok::render::effect_compiler *v216; // ecx
  vostok::render::effect_compiler *v217; // ecx
  vostok::render::effect_material_base *v218; // ecx
  vostok::render::shader_configuration *v219; // [esp+4h] [ebp-60h]
  D3D11_STENCIL_OP v220; // [esp+4h] [ebp-60h]
  D3D11_COMPARISON_FUNC v221; // [esp+4h] [ebp-60h]
  D3D11_STENCIL_OP v222; // [esp+4h] [ebp-60h]
  vostok::render::shader_configuration *v223; // [esp+4h] [ebp-60h]
  D3D11_COMPARISON_FUNC v224; // [esp+4h] [ebp-60h]
  D3D11_STENCIL_OP v225; // [esp+4h] [ebp-60h]
  vostok::render::shader_configuration *v226; // [esp+4h] [ebp-60h]
  vostok::render::shader_configuration *v227; // [esp+4h] [ebp-60h]
  long double v228; // [esp+4h] [ebp-60h]
  long double v229; // [esp+4h] [ebp-60h]
  long double v230; // [esp+4h] [ebp-60h]
  D3D11_COMPARISON_FUNC v231; // [esp+4h] [ebp-60h]
  vostok::render::shader_configuration *v232; // [esp+4h] [ebp-60h]
  D3D11_COMPARISON_FUNC v233; // [esp+4h] [ebp-60h]
  vostok::render::shader_configuration *v234; // [esp+4h] [ebp-60h]
  D3D11_COMPARISON_FUNC v235; // [esp+4h] [ebp-60h]
  D3D11_STENCIL_OP v236; // [esp+4h] [ebp-60h]
  vostok::render::shader_configuration *v237; // [esp+4h] [ebp-60h]
  D3D11_COMPARISON_FUNC v238; // [esp+4h] [ebp-60h]
  D3D11_BLEND_OP v239; // [esp+4h] [ebp-60h]
  vostok::render::shader_configuration *v240; // [esp+4h] [ebp-60h]
  D3D11_COMPARISON_FUNC v241; // [esp+4h] [ebp-60h]
  vostok::render::shader_configuration *v242; // [esp+4h] [ebp-60h]
  D3D11_COMPARISON_FUNC v243; // [esp+4h] [ebp-60h]
  vostok::render::shader_configuration *v244; // [esp+4h] [ebp-60h]
  D3D11_COMPARISON_FUNC v245; // [esp+4h] [ebp-60h]
  D3D11_STENCIL_OP v246; // [esp+4h] [ebp-60h]
  const vostok::configs::binary_config_value *v247; // [esp+8h] [ebp-5Ch]
  const vostok::configs::binary_config_value *v248; // [esp+8h] [ebp-5Ch]
  const vostok::configs::binary_config_value *v249; // [esp+8h] [ebp-5Ch]
  const vostok::configs::binary_config_value *v250; // [esp+8h] [ebp-5Ch]
  const vostok::configs::binary_config_value *v251; // [esp+8h] [ebp-5Ch]
  const vostok::configs::binary_config_value *v252; // [esp+8h] [ebp-5Ch]
  const vostok::configs::binary_config_value *v253; // [esp+8h] [ebp-5Ch]
  const vostok::configs::binary_config_value *v254; // [esp+8h] [ebp-5Ch]
  const vostok::configs::binary_config_value *v255; // [esp+8h] [ebp-5Ch]
  const vostok::configs::binary_config_value *v256; // [esp+8h] [ebp-5Ch]
  long double v257; // [esp+Ch] [ebp-58h]
  long double v258; // [esp+Ch] [ebp-58h]
  long double v259; // [esp+Ch] [ebp-58h]
  char v260; // [esp+15h] [ebp-4Fh]
  char v261; // [esp+16h] [ebp-4Eh]
  char v262; // [esp+17h] [ebp-4Dh]
  char v263; // [esp+17h] [ebp-4Dh]
  float v264; // [esp+18h] [ebp-4Ch]
  __int64 v265; // [esp+1Ch] [ebp-48h]
  int i; // [esp+20h] [ebp-44h]
  float v267; // [esp+28h] [ebp-3Ch]
  float v268; // [esp+2Ch] [ebp-38h] BYREF
  float v269; // [esp+30h] [ebp-34h] BYREF
  float v270; // [esp+34h] [ebp-30h] BYREF
  float v271; // [esp+38h] [ebp-2Ch]
  __int64 v272; // [esp+3Ch] [ebp-28h]
  vostok::math::float4 v273; // [esp+44h] [ebp-20h] BYREF
  vostok::math::float4 v274; // [esp+54h] [ebp-10h] BYREF

  LODWORD(v268) = 3;
  do
  {
    v272 = 0x80000;
    v270 = 0.0;
    v271 = 0.0;
    v6 = 0;
    if ( vostok::configs::binary_config_value::value_exists(
           (vostok::configs::binary_config_value *)this,
           (int)config,
           (unsigned int)"use_tdetail") )
    {
      v5 = vostok::configs::binary_config_value::operator[](config, "use_tdetail");
      if ( vostok::configs::binary_config_value::operator[](v5, "value")->data.pointer )
        v6 = 1;
    }
    HIBYTE(v270) = 2 * v6;
    v9 = 0;
    if ( vostok::configs::binary_config_value::value_exists(v4, (int)config, (unsigned int)"use_nmap") )
    {
      v8 = vostok::configs::binary_config_value::operator[](config, "use_nmap");
      if ( vostok::configs::binary_config_value::operator[](v8, "value")->data.pointer )
        v9 = 1;
    }
    BYTE2(v270) = (v9 << 7) | 8;
    v12 = 0;
    if ( vostok::configs::binary_config_value::value_exists(v7, (int)config, (unsigned int)"use_specular_intensity_map") )
    {
      v11 = vostok::configs::binary_config_value::operator[](config, "use_specular_intensity_map");
      if ( vostok::configs::binary_config_value::operator[](v11, "value")->data.pointer )
        v12 = 1;
    }
    HIBYTE(v270) ^= (HIBYTE(v270) ^ (8 * v12)) & 8;
    if ( vostok::configs::binary_config_value::value_exists(v10, (int)config, (unsigned int)"terrain_blend_mode") )
    {
      v14 = vostok::configs::binary_config_value::operator[](config, "terrain_blend_mode");
      pointer = vostok::configs::binary_config_value::operator[](v14, "value")->data.pointer;
    }
    else
    {
      LOBYTE(pointer) = 0;
    }
    BYTE4(v272) ^= (BYTE4(v272) ^ (32 * (_BYTE)pointer)) & 0x60;
    if ( !vostok::configs::binary_config_value::value_exists(v13, (int)config, (unsigned int)"use_height_map_0")
      || (v17 = vostok::configs::binary_config_value::operator[](config, "use_height_map_0"),
          v262 = 1,
          !vostok::configs::binary_config_value::operator[](v17, "value")->data.pointer) )
    {
      v262 = 0;
    }
    if ( !vostok::configs::binary_config_value::value_exists(v16, (int)config, (unsigned int)"use_height_map_1")
      || (v19 = vostok::configs::binary_config_value::operator[](config, "use_height_map_1"),
          v260 = 1,
          !vostok::configs::binary_config_value::operator[](v19, "value")->data.pointer) )
    {
      v260 = 0;
    }
    if ( !vostok::configs::binary_config_value::value_exists(v18, (int)config, (unsigned int)"use_height_map_2")
      || (v21 = vostok::configs::binary_config_value::operator[](config, "use_height_map_2"),
          v261 = 1,
          !vostok::configs::binary_config_value::operator[](v21, "value")->data.pointer) )
    {
      v261 = 0;
    }
    LOBYTE(v22) = vostok::configs::binary_config_value::value_exists(v20, (int)config, (unsigned int)"use_height_map_3")
               && (v23 = vostok::configs::binary_config_value::operator[](config, "use_height_map_3"),
                   vostok::configs::binary_config_value::operator[](v23, "value")->data.pointer);
    v24 = v262 || v260 || v261 || (_BYTE)v22;
    BYTE2(v270) ^= (BYTE2(v270) ^ (v24 << 6)) & 0x40;
    if ( v260 )
      BYTE2(v272) = 72;
    if ( v261 )
      BYTE2(v272) |= 0x20u;
    if ( (_BYTE)v22 )
      BYTE2(v272) |= 0x10u;
    if ( vostok::configs::binary_config_value::value_exists(v22, (int)config, (unsigned int)"num_used_terrain_layers") )
    {
      v26 = vostok::configs::binary_config_value::operator[](config, "num_used_terrain_layers");
      v27 = (unsigned int)vostok::configs::binary_config_value::operator[](v26, "value")->data.pointer;
      if ( v27 > 1 )
      {
        if ( v27 > 4 )
          LOBYTE(v27) = 4;
      }
      else
      {
        LOBYTE(v27) = 1;
      }
      BYTE2(v272) ^= (BYTE2(v272) ^ (2 * v27)) & 0xE;
    }
    vostok::render::effect_material_base::compile_begin(
      parameters,
      v25,
      (vostok::render::effect_material_base *)&stru_80E8FC,
      "terrain_gbuffer_pass",
      compiler,
      (const char *)&v270,
      config,
      v219,
      v247);
    vostok::render::effect_compiler::set_stencil(
      v28,
      (int)compiler,
      1,
      0x81u,
      0xFFu,
      255,
      D3D11_COMPARISON_ALWAYS,
      D3D11_STENCIL_OP_REPLACE,
      D3D11_STENCIL_OP_KEEP,
      v220);
    if ( vostok::command_line::key::is_set(v29, (int)&s_z_only_2) )
    {
      vostok::render::effect_compiler::set_depth(v30, (int)compiler, 1, 0, v221);
      vostok::render::effect_compiler::set_stencil(
        v31,
        (int)compiler,
        0,
        0,
        0,
        0,
        D3D11_COMPARISON_ALWAYS,
        D3D11_STENCIL_OP_KEEP,
        D3D11_STENCIL_OP_KEEP,
        v222);
    }
    else
    {
      vostok::render::effect_compiler::set_depth(v30, (int)compiler, 1, 1, v221);
    }
    v32 = vostok::configs::binary_config_value::operator[](config, "texture_mask");
    v33 = (char **)vostok::configs::binary_config_value::operator[](v32, "value");
    vostok::render::effect_compiler::set_texture(
      v34,
      (const char *)compiler,
      "texture_mask",
      *v33,
      1,
      5u,
      5u,
      s_spot_max_distance);
    v35 = vostok::configs::binary_config_value::operator[](config, "constant_tile_3");
    v36 = vostok::configs::binary_config_value::operator[](v35, "value");
    if ( v36->type == 2 )
      v37 = *(float *)&v36->data.pointer;
    else
      v37 = (float)(int)v36->data.pointer;
    *((float *)&v265 + 1) = v37;
    v38 = vostok::configs::binary_config_value::operator[](config, "constant_tile_2");
    v39 = vostok::configs::binary_config_value::operator[](v38, "value");
    if ( v39->type == 2 )
      v40 = *(float *)&v39->data.pointer;
    else
      v40 = (float)(int)v39->data.pointer;
    *(float *)&v265 = v40;
    v41 = vostok::configs::binary_config_value::operator[](config, "constant_tile_1");
    v42 = vostok::configs::binary_config_value::operator[](v41, "value");
    if ( v42->type == 2 )
      v43 = *(float *)&v42->data.pointer;
    else
      v43 = (float)(int)v42->data.pointer;
    v264 = v43;
    v44 = vostok::configs::binary_config_value::operator[](config, "constant_tile_0");
    v45 = vostok::configs::binary_config_value::operator[](v44, "value");
    if ( v45->type == 2 )
      v46 = *(float *)&v45->data.pointer;
    else
      v46 = (float)(int)v45->data.pointer;
    *(_QWORD *)&v273.x = __PAIR64__(LODWORD(v264), LODWORD(v46));
    *(_QWORD *)&v273.elements[2] = v265;
    if ( SBYTE2(v270) < 0 )
    {
      v47 = vostok::configs::binary_config_value::operator[](config, "texture_normal_0");
      v48 = (char **)vostok::configs::binary_config_value::operator[](v47, "value");
      vostok::render::effect_compiler::set_texture(v49, (const char *)compiler, "texture_normal_0", *v48, 1, 5u, 0, v46);
      v50 = vostok::configs::binary_config_value::operator[](config, "texture_normal_1");
      v51 = (char **)vostok::configs::binary_config_value::operator[](v50, "value");
      vostok::render::effect_compiler::set_texture(
        v52,
        (const char *)compiler,
        "texture_normal_1",
        *v51,
        1,
        5u,
        0,
        v264);
      v53 = vostok::configs::binary_config_value::operator[](config, "texture_normal_2");
      v54 = (char **)vostok::configs::binary_config_value::operator[](v53, "value");
      vostok::render::effect_compiler::set_texture(
        v55,
        (const char *)compiler,
        "texture_normal_2",
        *v54,
        1,
        5u,
        0,
        *(float *)&v265);
      v56 = vostok::configs::binary_config_value::operator[](config, "texture_normal_3");
      v57 = (char **)vostok::configs::binary_config_value::operator[](v56, "value");
      vostok::render::effect_compiler::set_texture(
        v58,
        (const char *)compiler,
        "texture_normal_3",
        *v57,
        1,
        5u,
        0,
        *((float *)&v265 + 1));
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v273, v59, compiler, "constant_tiles");
    }
    v60 = vostok::configs::binary_config_value::operator[](config, "texture_specular_intensity");
    v61 = (char **)vostok::configs::binary_config_value::operator[](v60, "value");
    vostok::render::effect_compiler::set_texture(
      v62,
      (const char *)compiler,
      "texture_specular_intensity",
      *v61,
      0,
      0xFFFFFFFF,
      0,
      1.0);
    if ( (BYTE2(v270) & 0x40) != 0 )
    {
      v63 = vostok::configs::binary_config_value::operator[](config, "texture_height_0");
      v64 = (char **)vostok::configs::binary_config_value::operator[](v63, "value");
      vostok::render::effect_compiler::set_texture(v65, (const char *)compiler, "texture_height_0", *v64, 1, 5u, 0, v46);
      v66 = vostok::configs::binary_config_value::operator[](config, "texture_height_1");
      v67 = (char **)vostok::configs::binary_config_value::operator[](v66, "value");
      vostok::render::effect_compiler::set_texture(
        v68,
        (const char *)compiler,
        "texture_height_1",
        *v67,
        1,
        5u,
        0,
        v264);
      v69 = vostok::configs::binary_config_value::operator[](config, "texture_height_2");
      v70 = (char **)vostok::configs::binary_config_value::operator[](v69, "value");
      vostok::render::effect_compiler::set_texture(
        v71,
        (const char *)compiler,
        "texture_height_2",
        *v70,
        1,
        5u,
        0,
        *(float *)&v265);
      v72 = vostok::configs::binary_config_value::operator[](config, "texture_height_3");
      v73 = (char **)vostok::configs::binary_config_value::operator[](v72, "value");
      vostok::render::effect_compiler::set_texture(
        v74,
        (const char *)compiler,
        "texture_height_3",
        *v73,
        1,
        5u,
        0,
        *((float *)&v265 + 1));
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v273, v75, compiler, "constant_tiles");
      v269 = s_bm_current_air_resistance;
      vostok::render::effect_compiler::set_constant<float>(v76, &v269, compiler, "constant_parallax_scale");
    }
    v77 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse_0");
    v78 = (char **)vostok::configs::binary_config_value::operator[](v77, "value");
    vostok::render::effect_compiler::set_texture(v79, (const char *)compiler, "texture_diffuse_0", *v78, 1, 5u, 1u, v46);
    v80 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse_1");
    v81 = (char **)vostok::configs::binary_config_value::operator[](v80, "value");
    vostok::render::effect_compiler::set_texture(
      v82,
      (const char *)compiler,
      "texture_diffuse_1",
      *v81,
      1,
      5u,
      1u,
      v264);
    v83 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse_2");
    v84 = (char **)vostok::configs::binary_config_value::operator[](v83, "value");
    vostok::render::effect_compiler::set_texture(
      v85,
      (const char *)compiler,
      "texture_diffuse_2",
      *v84,
      1,
      5u,
      1u,
      *(float *)&v265);
    v86 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse_3");
    v87 = (char **)vostok::configs::binary_config_value::operator[](v86, "value");
    vostok::render::effect_compiler::set_texture(
      v88,
      (const char *)compiler,
      "texture_diffuse_3",
      *v87,
      1,
      5u,
      1u,
      *((float *)&v265 + 1));
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v273, v89, compiler, "constant_tiles");
    vostok::render::effect_compiler::set_texture(
      v90,
      (const char *)compiler,
      "t_normal",
      "$user$normal",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v91,
      (const char *)compiler,
      "t_parameters",
      "$user$surface_parameters",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v92,
      (const char *)compiler,
      "t_decals_normal",
      "$user$decals_normal",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    if ( (HIBYTE(v270) & 2) != 0 )
    {
      v94 = vostok::configs::binary_config_value::operator[](config, "constant_detail_tile_1");
      v95 = vostok::configs::binary_config_value::operator[](v94, "value");
      if ( v95->type == 2 )
        v96 = *(float *)&v95->data.pointer;
      else
        v96 = (float)(int)v95->data.pointer;
      v267 = v96;
      v97 = vostok::configs::binary_config_value::operator[](config, "constant_detail_tile_0");
      v98 = vostok::configs::binary_config_value::operator[](v97, "value");
      if ( v98->type == 2 )
        v99 = *(float *)&v98->data.pointer;
      else
        v99 = (float)(int)v98->data.pointer;
      *(_QWORD *)&v274.x = __PAIR64__(LODWORD(v267), LODWORD(v99));
      *(_QWORD *)&v274.elements[2] = 0;
      v100 = vostok::configs::binary_config_value::operator[](config, "texture_detail_0");
      v101 = (char **)vostok::configs::binary_config_value::operator[](v100, "value");
      vostok::render::effect_compiler::set_texture(
        v102,
        (const char *)compiler,
        "texture_detail_0",
        *v101,
        1,
        5u,
        1u,
        1.0);
      v103 = vostok::configs::binary_config_value::operator[](config, "texture_detail_1");
      v104 = (char **)vostok::configs::binary_config_value::operator[](v103, "value");
      vostok::render::effect_compiler::set_texture(
        v105,
        (const char *)compiler,
        "texture_detail_1",
        *v104,
        1,
        5u,
        1u,
        1.0);
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        &v274,
        v106,
        compiler,
        "constant_detail_tiles");
    }
    vostok::render::effect_material_base::compile_end(v93, compiler);
    --LODWORD(v268);
  }
  while ( v268 != 0.0 );
  v273.x = 0.0;
  *(_QWORD *)&v273.elements[1] = 0x8000000000000LL;
  v273.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)"vertex_base_lpv",
    "fill_reflective_shadow_map_backed",
    compiler,
    (const char *)&v273,
    config,
    v219,
    v247);
  vostok::render::effect_material_base::compile_end(v107, compiler);
  v272 = 0x80000;
  v270 = 0.0;
  v271 = 0.0;
  v111 = 0;
  if ( vostok::configs::binary_config_value::value_exists(v108, (int)config, (unsigned int)"use_tdetail") )
  {
    v110 = vostok::configs::binary_config_value::operator[](config, "use_tdetail");
    if ( vostok::configs::binary_config_value::operator[](v110, "value")->data.pointer )
      v111 = 1;
  }
  HIBYTE(v270) = 2 * v111;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v109,
    (vostok::render::effect_material_base *)&stru_812848,
    (const char *)&stru_812848,
    compiler,
    (const char *)&v270,
    config,
    v223,
    v248);
  vostok::render::effect_compiler::set_depth(v112, (int)compiler, 0, 0, v224);
  vostok::render::effect_compiler::set_stencil(
    v113,
    (int)compiler,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v225);
  if ( (HIBYTE(v270) & 2) != 0 )
  {
    v115 = vostok::configs::binary_config_value::operator[](config, "texture_detail_0");
    v116 = (char **)vostok::configs::binary_config_value::operator[](v115, "value");
    vostok::render::effect_compiler::set_texture(v117, (const char *)compiler, "t_base", *v116, 0, 0xFFFFFFFF, 0, 1.0);
  }
  v270 = s_bm_current_air_resistance;
  v271 = s_bm_current_air_resistance;
  *(float *)&v272 = s_bm_current_air_resistance;
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(
    (const vostok::math::float3 *)&v270,
    v114,
    compiler,
    "diffuse_color_parameter");
  vostok::render::effect_material_base::compile_end(v118, compiler);
  v272 = 0x80000;
  v270 = 0.0;
  v271 = 0.0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v119,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "fill_reflective_shadow_map",
    compiler,
    (const char *)&v270,
    config,
    v226,
    v249);
  v123 = 0;
  if ( vostok::configs::binary_config_value::value_exists(v120, (int)config, (unsigned int)"use_tdetail") )
  {
    v122 = vostok::configs::binary_config_value::operator[](config, "use_tdetail");
    if ( vostok::configs::binary_config_value::operator[](v122, "value")->data.pointer )
      v123 = 1;
  }
  HIBYTE(v270) ^= (HIBYTE(v270) ^ (2 * v123)) & 2;
  if ( (HIBYTE(v270) & 2) != 0 )
  {
    v124 = vostok::configs::binary_config_value::operator[](config, "texture_detail_0");
    v125 = (char **)vostok::configs::binary_config_value::operator[](v124, "value");
    vostok::render::effect_compiler::set_texture(v126, (const char *)compiler, "t_base", *v125, 0, 0xFFFFFFFF, 0, 1.0);
  }
  v270 = s_bm_current_air_resistance;
  v271 = s_bm_current_air_resistance;
  *(float *)&v272 = s_bm_current_air_resistance;
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(
    (const vostok::math::float3 *)&v270,
    v121,
    compiler,
    "diffuse_color_parameter");
  vostok::render::effect_material_base::compile_end(v127, compiler);
  v273.x = 0.0;
  *(_QWORD *)&v273.elements[1] = 0x8000000000000LL;
  v273.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v128,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "gbuffer_emissive_pass",
    compiler,
    (const char *)&v273,
    config,
    v227,
    v250);
  vostok::render::effect_compiler::set_depth(v129, (int)compiler, 1, 0, SLODWORD(v228));
  vostok::render::effect_compiler::set_stencil(
    v130,
    (int)compiler,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    SLODWORD(v228));
  v263 = HIBYTE(v273.elements[1]) & 3;
  if ( (HIBYTE(v273.elements[1]) & 3) != 0 )
  {
    v132 = vostok::configs::binary_config_value::operator[](config, "constant_emissive_multiplier");
    v133 = vostok::configs::binary_config_value::operator[](v132, "value");
    if ( v133->type == 2 )
      v134 = *(float *)&v133->data.pointer;
    else
      v134 = (float)(int)v133->data.pointer;
    v268 = v134;
    v135 = vostok::configs::binary_config_value::operator[](config, "constant_emissive");
    v136 = vostok::configs::binary_config_value::operator[](v135, "value");
    v137 = (float *)v136->data.pointer;
    v138 = *(float *)v136->data.pointer;
    __libm_sse2_pow(v228, v257);
    *(float *)&v138 = v138;
    v270 = *(float *)&v138;
    v139 = v137[1];
    __libm_sse2_pow(v229, v258);
    *(float *)&v139 = v139;
    v271 = *(float *)&v139;
    v140 = v137[2];
    __libm_sse2_pow(v230, v259);
    *(float *)&v140 = v140;
    LODWORD(v272) = LODWORD(v140);
    *((float *)&v272 + 1) = v137[3];
    v273.w = *((float *)&v272 + 1);
    v273.x = v268 * v270;
    v273.y = v268 * v271;
    v273.z = v268 * *(float *)&v140;
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v273, v141, compiler, "solid_emission_color");
  }
  vostok::render::effect_compiler::set_alpha_blend(
    v131,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    SLODWORD(v228));
  if ( v263 == 2 )
  {
    v143 = vostok::configs::binary_config_value::operator[](config, "texture_emissive");
    v144 = (char **)vostok::configs::binary_config_value::operator[](v143, "value");
    vostok::render::effect_compiler::set_texture(
      v145,
      (const char *)compiler,
      "t_emission",
      *v144,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  vostok::render::effect_material_base::compile_end(v142, compiler);
  v272 = 0x80000;
  v270 = 0.0;
  v271 = 0.0;
  if ( vostok::configs::binary_config_value::value_exists(v146, (int)config, (unsigned int)"use_alpha_test") )
  {
    v148 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
    v149 = vostok::configs::binary_config_value::operator[](v148, "value")->data.pointer != 0;
  }
  else
  {
    v149 = 0;
  }
  BYTE2(v270) = 16 * v149;
  if ( vostok::configs::binary_config_value::value_exists(v147, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v151 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v152 = vostok::configs::binary_config_value::operator[](v151, "value")->data.pointer != 0;
  }
  else
  {
    v152 = 0;
  }
  BYTE2(v270) ^= (BYTE2(v270) ^ (8 * v152)) & 8;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v150,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "motion_vectors_accumulation",
    compiler,
    (const char *)&v270,
    config,
    (vostok::render::shader_configuration *)LODWORD(v228),
    (const vostok::configs::binary_config_value *)HIDWORD(v228));
  vostok::render::effect_compiler::set_depth(v153, (int)compiler, 1, 0, v231);
  v268 = FLOAT_0_25;
  if ( (BYTE2(v270) & 8) != 0 )
  {
    v155 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v156 = (char **)vostok::configs::binary_config_value::operator[](v155, "value");
    vostok::render::effect_compiler::set_texture(v157, (const char *)compiler, "t_base", *v156, 0, 0xFFFFFFFF, 0, 1.0);
  }
  if ( (BYTE2(v270) & 0x10) != 0
    && vostok::configs::binary_config_value::value_exists(v154, (int)config, (unsigned int)"alpha_ref") )
  {
    v158 = vostok::configs::binary_config_value::operator[](config, "alpha_ref");
    v159 = vostok::configs::binary_config_value::operator[](v158, "value");
    if ( v159->type == 2 )
      v160 = *(float *)&v159->data.pointer;
    else
      v160 = (float)(int)v159->data.pointer;
    v268 = v160;
  }
  vostok::render::effect_compiler::set_constant<float>(
    (vostok::render::effect_constant_storage *)v154,
    &v268,
    compiler,
    "alpha_ref_parameter");
  vostok::render::effect_material_base::compile_end(v161, compiler);
  v272 = 0x80000;
  v270 = 0.0;
  v271 = 0.0;
  if ( vostok::configs::binary_config_value::value_exists(v162, (int)config, (unsigned int)"use_alpha_test") )
  {
    v164 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
    v165 = vostok::configs::binary_config_value::operator[](v164, "value")->data.pointer != 0;
  }
  else
  {
    v165 = 0;
  }
  BYTE2(v270) = 16 * v165;
  if ( vostok::configs::binary_config_value::value_exists(v163, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v167 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v168 = vostok::configs::binary_config_value::operator[](v167, "value")->data.pointer != 0;
  }
  else
  {
    v168 = 0;
  }
  BYTE2(v270) ^= (BYTE2(v270) ^ (8 * v168)) & 8;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v166,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "subsurface_scattering",
    compiler,
    (const char *)&v270,
    config,
    v232,
    v251);
  vostok::render::effect_compiler::set_depth(v169, (int)compiler, 1, 0, v233);
  v268 = FLOAT_0_25;
  if ( (BYTE2(v270) & 8) != 0 )
  {
    v171 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v172 = (char **)vostok::configs::binary_config_value::operator[](v171, "value");
    vostok::render::effect_compiler::set_texture(v173, (const char *)compiler, "t_base", *v172, 0, 0xFFFFFFFF, 0, 1.0);
  }
  if ( (BYTE2(v270) & 0x10) != 0
    && vostok::configs::binary_config_value::value_exists(v170, (int)config, (unsigned int)"alpha_ref") )
  {
    v174 = vostok::configs::binary_config_value::operator[](config, "alpha_ref");
    v175 = vostok::configs::binary_config_value::operator[](v174, "value");
    if ( v175->type == 2 )
      v176 = *(float *)&v175->data.pointer;
    else
      v176 = (float)(int)v175->data.pointer;
    v268 = v176;
  }
  vostok::render::effect_compiler::set_constant<float>(
    (vostok::render::effect_constant_storage *)v170,
    &v268,
    compiler,
    "alpha_ref_parameter");
  vostok::render::effect_compiler::set_texture(
    v177,
    (const char *)compiler,
    "t_diffuse_lighting",
    "$user$accum_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v178,
    (const char *)compiler,
    "t_specular_lighting",
    "$user$accum_specular",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_material_base::compile_end(v179, compiler);
  v273.x = 0.0;
  *(_QWORD *)&v273.elements[1] = 0x8000000000000LL;
  v273.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v180,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "z_only",
    compiler,
    (const char *)&v273,
    config,
    v234,
    v252);
  vostok::render::effect_compiler::set_depth(v181, (int)compiler, 1, 1, v235);
  vostok::render::effect_compiler::set_stencil(
    v182,
    (int)compiler,
    1,
    0x81u,
    0xFFu,
    255,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_REPLACE,
    D3D11_STENCIL_OP_KEEP,
    v236);
  vostok::render::effect_compiler::color_write_enable(v183, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_material_base::compile_end(v184, compiler);
  v273.x = 0.0;
  *(_QWORD *)&v273.elements[1] = 0x8000000000000LL;
  v273.w = 0.0;
  if ( vostok::configs::binary_config_value::value_exists(v185, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v187 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v188 = vostok::configs::binary_config_value::operator[](v187, "value")->data.pointer != 0;
  }
  else
  {
    v188 = 0;
  }
  BYTE2(v273.elements[0]) = 8 * v188;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v186,
    (vostok::render::effect_material_base *)&stru_8129B8,
    "bake_decal_accumulate",
    compiler,
    (const char *)&v273,
    config,
    v237,
    v253);
  vostok::render::effect_compiler::set_depth(v189, (int)compiler, 0, 0, v238);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v190);
  vostok::render::effect_compiler::set_alpha_blend(
    v191,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v239);
  vostok::render::effect_material_base::compile_end(v192, compiler);
  v273.x = 0.0;
  *(_QWORD *)&v273.elements[1] = 0x8000000000000LL;
  v273.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v193,
    (vostok::render::effect_material_base *)&stru_8129E4,
    "bake_decal_occlusion",
    compiler,
    (const char *)&v273,
    config,
    v240,
    v254);
  vostok::render::effect_compiler::set_depth(v194, (int)compiler, 1, 1, v241);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v195);
  vostok::render::effect_compiler::color_write_enable(v196, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_material_base::compile_end(v197, compiler);
  v272 = 0x80000;
  v270 = 0.0;
  v271 = 0.0;
  if ( vostok::configs::binary_config_value::value_exists(v198, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v200 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v201 = vostok::configs::binary_config_value::operator[](v200, "value")->data.pointer != 0;
  }
  else
  {
    v201 = 0;
  }
  BYTE2(v270) = 8 * v201;
  if ( vostok::configs::binary_config_value::value_exists(v199, (int)config, (unsigned int)"use_nmap") )
  {
    v203 = vostok::configs::binary_config_value::operator[](config, "use_nmap");
    v204 = vostok::configs::binary_config_value::operator[](v203, "value")->data.pointer != 0;
  }
  else
  {
    v204 = 0;
  }
  LOBYTE(v202) = BYTE2(v270) & 0x7F;
  BYTE2(v270) = BYTE2(v270) & 0x7F | (v204 << 7);
  if ( vostok::configs::binary_config_value::value_exists(v202, (int)config, (unsigned int)"use_tfresnel") )
  {
    v206 = vostok::configs::binary_config_value::operator[](config, "use_tfresnel");
    v207 = vostok::configs::binary_config_value::operator[](v206, "value")->data.pointer != 0;
  }
  else
  {
    v207 = 0;
  }
  HIBYTE(v270) ^= (HIBYTE(v270) ^ (16 * v207)) & 0x10;
  if ( vostok::configs::binary_config_value::value_exists(v205, (int)config, (unsigned int)"use_troughness") )
  {
    v209 = vostok::configs::binary_config_value::operator[](config, "use_troughness");
    v210 = vostok::configs::binary_config_value::operator[](v209, "value")->data.pointer != 0;
  }
  else
  {
    v210 = 0;
  }
  HIBYTE(v270) ^= (HIBYTE(v270) ^ (32 * v210)) & 0x20;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v208,
    (vostok::render::effect_material_base *)&stru_8129B8,
    "bake_decal_composition",
    compiler,
    (const char *)&v270,
    config,
    v242,
    v255);
  vostok::render::effect_compiler::set_depth(v211, (int)compiler, 0, 0, v243);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v212);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v213);
  vostok::render::effect_material_base::compile_end(v214, compiler);
  for ( i = 0; i < 3; ++i )
  {
    LOWORD(v272) = 0;
    v270 = 0.0;
    v271 = 0.0;
    HIBYTE(v272) = 0;
    LOBYTE(v215) = i & 7;
    *(_DWORD *)((char *)&v272 + 3) = i & 7 | (unsigned __int8)(16 * (i == 2));
    BYTE2(v272) = 8;
    vostok::render::effect_material_base::compile_begin(
      parameters,
      v215,
      (vostok::render::effect_material_base *)&stru_80E8FC,
      "editor_accumulate_overdraw",
      compiler,
      (const char *)&v270,
      config,
      v244,
      v256);
    vostok::render::effect_compiler::set_depth(v216, (int)compiler, 1, 1, v245);
    vostok::render::effect_compiler::set_stencil(
      v217,
      (int)compiler,
      1,
      0xFFu,
      0xFFu,
      255,
      D3D11_COMPARISON_ALWAYS,
      D3D11_STENCIL_OP_INCR,
      D3D11_STENCIL_OP_KEEP,
      v246);
    vostok::render::effect_material_base::compile_end(v218, compiler);
  }
}
