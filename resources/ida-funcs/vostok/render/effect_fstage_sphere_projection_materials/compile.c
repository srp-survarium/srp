void __thiscall vostok::render::effect_fstage_sphere_projection_materials::compile(
        vostok::render::effect_fstage_sphere_projection_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // eax
  bool v9; // al
  vostok::configs::binary_config_value *v10; // ecx
  vostok::configs::binary_config_value *v11; // eax
  char v12; // al
  vostok::render::effect_compiler *v13; // ecx
  vostok::configs::binary_config_value *v14; // ecx
  vostok::configs::binary_config_value *v15; // ecx
  vostok::configs::binary_config_value *v16; // eax
  float **v17; // eax
  float *v18; // esi
  vostok::math::float3 *v19; // esi
  vostok::configs::binary_config_value *v20; // ecx
  vostok::configs::binary_config_value *v21; // eax
  const vostok::configs::binary_config_value *v22; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v24; // ecx
  vostok::configs::binary_config_value *v25; // eax
  float **v26; // eax
  float *v27; // esi
  double x; // xmm0_8
  double y; // xmm0_8
  double z; // xmm0_8
  vostok::math::float4 *v31; // esi
  float *p_y; // esi
  vostok::configs::binary_config_value *v33; // ecx
  vostok::configs::binary_config_value *v34; // eax
  const vostok::configs::binary_config_value *v35; // eax
  float v36; // xmm0_4
  vostok::render::effect_constant_storage *v37; // ecx
  vostok::configs::binary_config_value *v38; // eax
  const vostok::configs::binary_config_value *v39; // eax
  float v40; // xmm0_4
  vostok::render::effect_constant_storage *v41; // ecx
  vostok::render::effect_constant_storage *v42; // ecx
  vostok::render::effect_constant_storage *v43; // ecx
  vostok::render::effect_constant_storage *v44; // ecx
  vostok::configs::binary_config_value *v45; // ecx
  vostok::configs::binary_config_value *v46; // eax
  const vostok::configs::binary_config_value *v47; // eax
  float v48; // xmm0_4
  vostok::configs::binary_config_value *v49; // eax
  const vostok::configs::binary_config_value *v50; // eax
  float v51; // xmm0_4
  vostok::configs::binary_config_value *v52; // eax
  const vostok::configs::binary_config_value *v53; // eax
  float v54; // xmm0_4
  vostok::configs::binary_config_value *v55; // eax
  const vostok::configs::binary_config_value *v56; // eax
  vostok::render::effect_constant_storage *v57; // ecx
  float v58; // xmm0_4
  vostok::configs::binary_config_value *v59; // ecx
  vostok::configs::binary_config_value *v60; // ecx
  vostok::configs::binary_config_value *v61; // ecx
  vostok::configs::binary_config_value *v62; // ecx
  vostok::configs::binary_config_value *v63; // eax
  char **v64; // eax
  vostok::render::effect_compiler *v65; // ecx
  vostok::configs::binary_config_value *v66; // eax
  float **v67; // eax
  float *v68; // esi
  vostok::configs::binary_config_value *v69; // eax
  float **v70; // eax
  float *v71; // esi
  vostok::configs::binary_config_value *v72; // eax
  const vostok::configs::binary_config_value *v73; // eax
  float v74; // xmm0_4
  vostok::configs::binary_config_value *v75; // eax
  const vostok::configs::binary_config_value *v76; // eax
  vostok::render::effect_constant_storage *v77; // ecx
  float v78; // xmm0_4
  vostok::render::effect_constant_storage *v79; // ecx
  vostok::render::effect_constant_storage *v80; // ecx
  vostok::configs::binary_config_value *v81; // eax
  char **v82; // eax
  vostok::render::effect_compiler *v83; // ecx
  vostok::configs::binary_config_value *v84; // eax
  const vostok::configs::binary_config_value *v85; // eax
  float v86; // xmm0_4
  vostok::configs::binary_config_value *v87; // eax
  const vostok::configs::binary_config_value *v88; // eax
  float *v89; // esi
  double v90; // xmm0_8
  double v91; // xmm0_8
  double v92; // xmm0_8
  vostok::configs::binary_config_value *v93; // ecx
  vostok::configs::binary_config_value *v94; // eax
  char **v95; // eax
  vostok::render::effect_compiler *v96; // ecx
  vostok::render::effect_constant_storage *v97; // ecx
  vostok::configs::binary_config_value *v98; // eax
  const vostok::configs::binary_config_value *v99; // eax
  float v100; // xmm0_4
  vostok::render::effect_constant_storage *v101; // ecx
  vostok::configs::binary_config_value *v102; // ecx
  vostok::configs::binary_config_value *v103; // ecx
  vostok::configs::binary_config_value *v104; // eax
  const vostok::configs::binary_config_value *v105; // eax
  float v106; // xmm0_4
  vostok::configs::binary_config_value *v107; // eax
  const vostok::configs::binary_config_value *v108; // eax
  float v109; // xmm0_4
  vostok::render::effect_constant_storage *v110; // ecx
  vostok::render::effect_material_base *v111; // ecx
  vostok::render::shader_configuration *v112; // [esp+4h] [ebp-68h]
  long double v113; // [esp+4h] [ebp-68h]
  long double v114; // [esp+4h] [ebp-68h]
  long double v115; // [esp+4h] [ebp-68h]
  long double v116; // [esp+4h] [ebp-68h]
  long double v117; // [esp+4h] [ebp-68h]
  const vostok::configs::binary_config_value *v118; // [esp+8h] [ebp-64h]
  long double v119; // [esp+Ch] [ebp-60h] BYREF
  float v120; // [esp+14h] [ebp-58h] BYREF
  float v121; // [esp+18h] [ebp-54h]
  int v122; // [esp+1Ch] [ebp-50h]
  float w; // [esp+20h] [ebp-4Ch]
  float v124; // [esp+24h] [ebp-48h] BYREF
  float v125; // [esp+28h] [ebp-44h]
  int v126; // [esp+2Ch] [ebp-40h]
  vostok::math::float3 v127; // [esp+30h] [ebp-3Ch] BYREF
  vostok::math::float4 v128; // [esp+3Ch] [ebp-30h] BYREF
  int v129; // [esp+4Ch] [ebp-20h] BYREF
  int v130; // [esp+50h] [ebp-1Ch]
  int v131; // [esp+54h] [ebp-18h]
  int v132; // [esp+58h] [ebp-14h]
  vostok::math::float4 v133; // [esp+5Ch] [ebp-10h] BYREF

  v131 = 0x80000;
  v129 = 0;
  v130 = 0;
  v132 = 0;
  v4 = vostok::configs::binary_config_value::operator[](config, "use_temissive");
  HIBYTE(v130) = ((vostok::configs::binary_config_value::operator[](v4, "value")->data.pointer != 0) + 1) & 3;
  v5 = vostok::configs::binary_config_value::operator[](config, "use_ttransparency");
  LOBYTE(v130) = vostok::configs::binary_config_value::operator[](v5, "value")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v6, (int)config, (unsigned int)"use_sequence") )
  {
    v8 = vostok::configs::binary_config_value::operator[](config, "use_sequence");
    v9 = vostok::configs::binary_config_value::operator[](v8, "value")->data.pointer != 0;
  }
  else
  {
    v9 = 0;
  }
  LOBYTE(v130) = (v130 ^ (32 * v9)) & 0x20 ^ v130;
  if ( vostok::configs::binary_config_value::value_exists(v7, (int)config, (unsigned int)"use_uv_distortion") )
  {
    v11 = vostok::configs::binary_config_value::operator[](config, "use_uv_distortion");
    v12 = vostok::configs::binary_config_value::operator[](v11, "value")->data.pointer != 0;
  }
  else
  {
    v12 = 0;
  }
  LOBYTE(v10) = BYTE2(v129) & 0x7F;
  BYTE2(v129) = BYTE2(v129) & 0x7F | (v12 << 7);
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v10,
    (vostok::render::effect_material_base *)"vertex_base_z_shifted",
    (const char *)&stru_8123FC,
    compiler,
    (const char *)&v129,
    config,
    v112,
    v118);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 1, 0, SLODWORD(v113));
  if ( vostok::configs::binary_config_value::value_exists(v14, (int)config, (unsigned int)"sphere_position") )
  {
    v16 = vostok::configs::binary_config_value::operator[](config, "sphere_position");
    v17 = (float **)vostok::configs::binary_config_value::operator[](v16, "value");
    v18 = *v17;
    v128.x = **v17;
    *(_QWORD *)&v128.elements[1] = *(_QWORD *)(v18 + 1);
    v19 = (vostok::math::float3 *)&v128;
  }
  else
  {
    v124 = 0.0;
    v125 = 0.0;
    v126 = 0;
    v19 = (vostok::math::float3 *)&v124;
  }
  v127 = *v19;
  if ( vostok::configs::binary_config_value::value_exists(v15, (int)config, (unsigned int)"sphere_radius") )
  {
    v21 = vostok::configs::binary_config_value::operator[](config, "sphere_radius");
    v22 = vostok::configs::binary_config_value::operator[](v21, "value");
    if ( v22->type == 2 )
      pointer = *(float *)&v22->data.pointer;
    else
      pointer = (float)(int)v22->data.pointer;
  }
  else
  {
    pointer = s_bm_current_air_resistance;
  }
  v124 = pointer;
  if ( vostok::configs::binary_config_value::value_exists(v20, (int)config, (unsigned int)"sphere_color") )
  {
    v25 = vostok::configs::binary_config_value::operator[](config, "sphere_color");
    v26 = (float **)vostok::configs::binary_config_value::operator[](v25, "value");
    v27 = *v26;
    v128.x = **v26;
    v128.y = *++v27;
    *(_QWORD *)&v128.elements[2] = *(_QWORD *)(v27 + 1);
    x = v128.x;
    __libm_sse2_pow(v113, v119);
    *(float *)&x = x;
    v120 = *(float *)&x;
    y = v128.y;
    __libm_sse2_pow(v114, v119);
    *(float *)&y = y;
    v121 = *(float *)&y;
    z = v128.z;
    __libm_sse2_pow(v115, v119);
    *(float *)&z = z;
    v122 = LODWORD(z);
    w = v128.w;
    v31 = (vostok::math::float4 *)&v120;
  }
  else
  {
    v128.x = s_bm_current_air_resistance;
    v128.y = s_bm_current_air_resistance;
    v128.z = s_bm_current_air_resistance;
    v128.w = s_bm_current_air_resistance;
    v31 = &v128;
  }
  v133.x = v31->x;
  p_y = &v31->y;
  v133.y = *p_y;
  *(_QWORD *)&v133.elements[2] = *(_QWORD *)(p_y + 1);
  if ( vostok::configs::binary_config_value::value_exists(v24, (int)config, (unsigned int)"sphere_blend_down") )
  {
    v34 = vostok::configs::binary_config_value::operator[](config, "sphere_blend_down");
    v35 = vostok::configs::binary_config_value::operator[](v34, "value");
    if ( v35->type == 2 )
      v36 = *(float *)&v35->data.pointer;
    else
      v36 = (float)(int)v35->data.pointer;
  }
  else
  {
    v36 = c_anim_center;
  }
  v120 = v36;
  if ( vostok::configs::binary_config_value::value_exists(v33, (int)config, (unsigned int)"sphere_blend_up") )
  {
    v38 = vostok::configs::binary_config_value::operator[](config, "sphere_blend_up");
    v39 = vostok::configs::binary_config_value::operator[](v38, "value");
    if ( v39->type == 2 )
      v40 = *(float *)&v39->data.pointer;
    else
      v40 = (float)(int)v39->data.pointer;
  }
  else
  {
    v40 = c_anim_center;
  }
  *((float *)&v119 + 1) = v40;
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(&v127, v37, compiler, "sphere_position");
  vostok::render::effect_compiler::set_constant<float>(v41, &v124, compiler, "sphere_radius");
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v133, v42, compiler, "sphere_color");
  vostok::render::effect_compiler::set_constant<float>(v43, &v120, compiler, "sphere_blend_down");
  vostok::render::effect_compiler::set_constant<float>(v44, (float *)&v119 + 1, compiler, "sphere_blend_up");
  if ( (v130 & 0x20) != 0 )
  {
    v46 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_play_speed");
    v47 = vostok::configs::binary_config_value::operator[](v46, "value");
    if ( v47->type == 2 )
      v48 = *(float *)&v47->data.pointer;
    else
      v48 = (float)(int)v47->data.pointer;
    v124 = v48;
    v49 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_start_frame_index");
    v50 = vostok::configs::binary_config_value::operator[](v49, "value");
    if ( v50->type == 2 )
      v51 = *(float *)&v50->data.pointer;
    else
      v51 = (float)(int)v50->data.pointer;
    v120 = v51;
    v52 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_array_height");
    v53 = vostok::configs::binary_config_value::operator[](v52, "value");
    if ( v53->type == 2 )
      v54 = *(float *)&v53->data.pointer;
    else
      v54 = (float)(int)v53->data.pointer;
    *((float *)&v119 + 1) = v54;
    v55 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_array_width");
    v56 = vostok::configs::binary_config_value::operator[](v55, "value");
    if ( v56->type == 2 )
      v58 = *(float *)&v56->data.pointer;
    else
      v58 = (float)(int)v56->data.pointer;
    *(_QWORD *)&v128.x = __PAIR64__(HIDWORD(v119), LODWORD(v58));
    *(_QWORD *)&v128.elements[2] = __PAIR64__(LODWORD(v124), LODWORD(v120));
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v128, v57, compiler, "sequence_parameters");
  }
  if ( (v129 & 0x800000) != 0
    && vostok::configs::binary_config_value::value_exists(v45, (int)config, (unsigned int)"uv_distortion_texture")
    && vostok::configs::binary_config_value::value_exists(v59, (int)config, (unsigned int)"uv_distortion_multiplier")
    && vostok::configs::binary_config_value::value_exists(
         v60,
         (int)config,
         (unsigned int)"distortion_1_moving_direction")
    && vostok::configs::binary_config_value::value_exists(
         v61,
         (int)config,
         (unsigned int)"distortion_2_moving_direction")
    && vostok::configs::binary_config_value::value_exists(v62, (int)config, (unsigned int)"uv_distortion_tile") )
  {
    v63 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_texture");
    v64 = (char **)vostok::configs::binary_config_value::operator[](v63, "value");
    vostok::render::effect_compiler::set_texture(
      v65,
      (const char *)compiler,
      "t_uv_distortion",
      *v64,
      0,
      0xFFFFFFFF,
      0,
      1.0);
    v66 = vostok::configs::binary_config_value::operator[](config, "distortion_1_moving_direction");
    v67 = (float **)vostok::configs::binary_config_value::operator[](v66, "value");
    v68 = *v67;
    v127.x = **v67;
    *(_QWORD *)&v127.elements[1] = *(_QWORD *)(v68 + 1);
    v69 = vostok::configs::binary_config_value::operator[](config, "distortion_2_moving_direction");
    v70 = (float **)vostok::configs::binary_config_value::operator[](v69, "value");
    v71 = *v70;
    v128.x = **v70;
    *(_QWORD *)&v128.elements[1] = *(_QWORD *)(v71 + 1);
    v72 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_multiplier");
    v73 = vostok::configs::binary_config_value::operator[](v72, "value");
    if ( v73->type == 2 )
      v74 = *(float *)&v73->data.pointer;
    else
      v74 = (float)(int)v73->data.pointer;
    v124 = v74;
    v75 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_tile");
    v76 = vostok::configs::binary_config_value::operator[](v75, "value");
    if ( v76->type == 2 )
      v78 = *(float *)&v76->data.pointer;
    else
      v78 = (float)(int)v76->data.pointer;
    v120 = v78;
    *(_QWORD *)&v133.x = *(_QWORD *)&v127.x;
    *(_QWORD *)&v133.elements[2] = *(_QWORD *)&v128.x;
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v133, v77, compiler, "uv_distortion_movement");
    vostok::render::effect_compiler::set_constant<float>(v79, &v124, compiler, "uv_distortion_multiplier");
    vostok::render::effect_compiler::set_constant<float>(v80, &v120, compiler, "uv_distortion_tile");
  }
  if ( (HIBYTE(v130) & 3) == 2 )
  {
    v81 = vostok::configs::binary_config_value::operator[](config, "texture_emissive");
    v82 = (char **)vostok::configs::binary_config_value::operator[](v81, "value");
    vostok::render::effect_compiler::set_texture(v83, (const char *)compiler, "t_base", *v82, 0, 0xFFFFFFFF, 0, 1.0);
  }
  v84 = vostok::configs::binary_config_value::operator[](config, "constant_emissive_multiplier");
  v85 = vostok::configs::binary_config_value::operator[](v84, "value");
  if ( v85->type == 2 )
    v86 = *(float *)&v85->data.pointer;
  else
    v86 = (float)(int)v85->data.pointer;
  *((float *)&v119 + 1) = v86;
  v87 = vostok::configs::binary_config_value::operator[](config, "constant_emissive");
  v88 = vostok::configs::binary_config_value::operator[](v87, "value");
  v89 = (float *)v88->data.pointer;
  v90 = *(float *)v88->data.pointer;
  __libm_sse2_pow(v113, v119);
  *(float *)&v90 = v90;
  v133.x = *(float *)&v90;
  v91 = v89[1];
  __libm_sse2_pow(v116, v119);
  *(float *)&v91 = v91;
  v133.y = *(float *)&v91;
  v92 = v89[2];
  __libm_sse2_pow(v117, v119);
  *(float *)&v92 = v92;
  v133.z = *(float *)&v92 * *((float *)&v119 + 1);
  v133.x = v133.x * *((float *)&v119 + 1);
  v133.y = v133.y * *((float *)&v119 + 1);
  v133.w = s_bm_current_air_resistance;
  *(_QWORD *)&v128.x = *(_QWORD *)&v133.x;
  v128.z = *(float *)&v92 * *((float *)&v119 + 1);
  v128.w = s_bm_current_air_resistance;
  if ( (v130 & 1) != 0 )
  {
    v94 = vostok::configs::binary_config_value::operator[](config, "texture_transparency");
    v95 = (char **)vostok::configs::binary_config_value::operator[](v94, "value");
    vostok::render::effect_compiler::set_texture(
      v96,
      (const char *)compiler,
      "t_transparency",
      *v95,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v93, (int)config, (unsigned int)"constant_transparency") )
  {
    v98 = vostok::configs::binary_config_value::operator[](config, "constant_transparency");
    v99 = vostok::configs::binary_config_value::operator[](v98, "value");
    if ( v99->type == 2 )
      v100 = *(float *)&v99->data.pointer;
    else
      v100 = (float)(int)v99->data.pointer;
  }
  else
  {
    v100 = s_bm_current_air_resistance;
  }
  v124 = v100;
  vostok::render::effect_compiler::set_constant<float>(v97, &v124, compiler, "solid_transparency");
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v128, v101, compiler, "solid_color_specular");
  if ( vostok::configs::binary_config_value::value_exists(v102, (int)config, (unsigned int)"constant_tile_u")
    && vostok::configs::binary_config_value::value_exists(v103, (int)config, (unsigned int)"constant_tile_v") )
  {
    v104 = vostok::configs::binary_config_value::operator[](config, "constant_tile_v");
    v105 = vostok::configs::binary_config_value::operator[](v104, "value");
    if ( v105->type == 2 )
      v106 = *(float *)&v105->data.pointer;
    else
      v106 = (float)(int)v105->data.pointer;
    v124 = v106;
    v107 = vostok::configs::binary_config_value::operator[](config, "constant_tile_u");
    v108 = vostok::configs::binary_config_value::operator[](v107, "value");
    if ( v108->type == 2 )
      v109 = *(float *)&v108->data.pointer;
    else
      v109 = (float)(int)v108->data.pointer;
    v120 = v109;
    v121 = v124;
    v110 = (vostok::render::effect_constant_storage *)&v120;
  }
  else
  {
    v124 = s_bm_current_air_resistance;
    v125 = s_bm_current_air_resistance;
    v110 = (vostok::render::effect_constant_storage *)&v124;
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float2>(v110, compiler, "constant_tile_uv");
  vostok::render::effect_material_base::compile_end(v111, compiler);
}
