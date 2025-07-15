void __thiscall vostok::render::effect_fstage_default_materials::compile(
        vostok::render::effect_fstage_default_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  unsigned int vertex_input_type; // ecx
  int v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // eax
  char v11; // al
  vostok::configs::binary_config_value *v12; // ecx
  vostok::configs::binary_config_value *v13; // eax
  bool v14; // al
  vostok::configs::binary_config_value *v15; // ecx
  vostok::configs::binary_config_value *v16; // eax
  char v17; // al
  vostok::configs::binary_config_value *v18; // eax
  char v19; // al
  vostok::configs::binary_config_value *draw_to_gbuffer; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::configs::binary_config_value *v22; // ecx
  vostok::render::effect_constant_storage *v23; // ecx
  vostok::configs::binary_config_value *v24; // eax
  const vostok::configs::binary_config_value *v25; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v27; // ecx
  vostok::configs::binary_config_value *v28; // eax
  const vostok::configs::binary_config_value *v29; // eax
  float v30; // xmm0_4
  vostok::configs::binary_config_value *v31; // eax
  const vostok::configs::binary_config_value *v32; // eax
  float v33; // xmm0_4
  vostok::configs::binary_config_value *v34; // eax
  const vostok::configs::binary_config_value *v35; // eax
  float v36; // xmm0_4
  vostok::configs::binary_config_value *v37; // eax
  const vostok::configs::binary_config_value *v38; // eax
  vostok::render::effect_constant_storage *v39; // ecx
  float v40; // xmm0_4
  vostok::configs::binary_config_value *v41; // ecx
  vostok::configs::binary_config_value *v42; // ecx
  vostok::configs::binary_config_value *v43; // ecx
  vostok::configs::binary_config_value *v44; // ecx
  vostok::configs::binary_config_value *v45; // eax
  char **v46; // eax
  vostok::render::effect_compiler *v47; // ecx
  vostok::configs::binary_config_value *v48; // eax
  const vostok::configs::binary_config_value *v49; // eax
  _DWORD *v50; // esi
  vostok::configs::binary_config_value *v51; // eax
  float **v52; // eax
  float *v53; // esi
  vostok::configs::binary_config_value *v54; // eax
  const vostok::configs::binary_config_value *v55; // eax
  float v56; // xmm0_4
  vostok::configs::binary_config_value *v57; // eax
  const vostok::configs::binary_config_value *v58; // eax
  vostok::render::effect_constant_storage *v59; // ecx
  float v60; // xmm0_4
  vostok::render::effect_constant_storage *v61; // ecx
  vostok::render::effect_constant_storage *v62; // ecx
  vostok::configs::binary_config_value *v63; // eax
  char **v64; // eax
  vostok::render::effect_compiler *v65; // ecx
  vostok::configs::binary_config_value *v66; // eax
  const vostok::configs::binary_config_value *v67; // eax
  float v68; // xmm0_4
  vostok::configs::binary_config_value *v69; // eax
  const vostok::configs::binary_config_value *v70; // eax
  float *v71; // esi
  double v72; // xmm0_8
  double v73; // xmm0_8
  double v74; // xmm0_8
  vostok::configs::binary_config_value *v75; // ecx
  vostok::configs::binary_config_value *v76; // eax
  char **v77; // eax
  vostok::render::effect_compiler *v78; // ecx
  vostok::render::effect_constant_storage *v79; // ecx
  vostok::configs::binary_config_value *v80; // eax
  const vostok::configs::binary_config_value *v81; // eax
  float v82; // xmm0_4
  vostok::render::effect_constant_storage *v83; // ecx
  vostok::configs::binary_config_value *v84; // ecx
  vostok::configs::binary_config_value *v85; // ecx
  vostok::configs::binary_config_value *v86; // eax
  const vostok::configs::binary_config_value *v87; // eax
  float v88; // xmm0_4
  vostok::configs::binary_config_value *v89; // eax
  const vostok::configs::binary_config_value *v90; // eax
  float v91; // xmm0_4
  unsigned int *v92; // ecx
  vostok::render::effect_compiler *v93; // ecx
  vostok::render::shader_configuration *v94; // [esp+4h] [ebp-68h]
  long double v95; // [esp+4h] [ebp-68h]
  long double v96; // [esp+4h] [ebp-68h]
  long double v97; // [esp+4h] [ebp-68h]
  const vostok::configs::binary_config_value *v98; // [esp+8h] [ebp-64h]
  long double v99; // [esp+Ch] [ebp-60h] BYREF
  unsigned int num_last_mips_used; // [esp+14h] [ebp-58h]
  __int64 v101; // [esp+18h] [ebp-54h] BYREF
  unsigned int v102; // [esp+20h] [ebp-4Ch]
  unsigned int streaming_priority[2]; // [esp+24h] [ebp-48h] BYREF
  vostok::configs::binary_config_value *v104; // [esp+2Ch] [ebp-40h]
  __int64 v105; // [esp+30h] [ebp-3Ch]
  int v106; // [esp+38h] [ebp-34h]
  vostok::math::float4 v107; // [esp+3Ch] [ebp-30h] BYREF
  int v108; // [esp+4Ch] [ebp-20h] BYREF
  int v109; // [esp+50h] [ebp-1Ch]
  int v110; // [esp+54h] [ebp-18h]
  int v111; // [esp+58h] [ebp-14h]
  vostok::math::float4 v112; // [esp+5Ch] [ebp-10h] BYREF

  vertex_input_type = parameters->vertex_input_type;
  LOBYTE(num_last_mips_used) = parameters->vertex_input_type >= 0xF
                            || (v5 = 1 << vertex_input_type, 1 << vertex_input_type != 2048)
                            && v5 != 128
                            && v5 != 512
                            && v5 != 256;
  v110 = 0x80000;
  v108 = 0;
  v109 = 0;
  v111 = 0;
  streaming_priority[0] = (_BYTE)num_last_mips_used == 0 ? -1 : 5;
  v6 = vostok::configs::binary_config_value::operator[](config, "use_temissive");
  HIBYTE(v109) = ((vostok::configs::binary_config_value::operator[](v6, "value")->data.pointer != 0) + 1) & 3;
  v7 = vostok::configs::binary_config_value::operator[](config, "use_ttransparency");
  LOBYTE(v109) = vostok::configs::binary_config_value::operator[](v7, "value")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v8, (int)config, (unsigned int)"use_soft_edges") )
  {
    v10 = vostok::configs::binary_config_value::operator[](config, "use_soft_edges");
    v11 = vostok::configs::binary_config_value::operator[](v10, "value")->data.pointer != 0;
  }
  else
  {
    v11 = 0;
  }
  LOBYTE(v9) = v111 & 0x7F;
  LOBYTE(v111) = v111 & 0x7F | (v11 << 7);
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)config, (unsigned int)"use_sequence") )
  {
    v13 = vostok::configs::binary_config_value::operator[](config, "use_sequence");
    v14 = vostok::configs::binary_config_value::operator[](v13, "value")->data.pointer != 0;
  }
  else
  {
    v14 = 0;
  }
  LOBYTE(v109) = (v109 ^ (32 * v14)) & 0x20 ^ v109;
  if ( vostok::configs::binary_config_value::value_exists(v12, (int)config, (unsigned int)"use_uv_distortion") )
  {
    v16 = vostok::configs::binary_config_value::operator[](config, "use_uv_distortion");
    v17 = vostok::configs::binary_config_value::operator[](v16, "value")->data.pointer != 0;
  }
  else
  {
    v17 = 0;
  }
  LOBYTE(v15) = BYTE2(v108) & 0x7F;
  BYTE2(v108) = BYTE2(v108) & 0x7F | (v17 << 7);
  if ( vostok::configs::binary_config_value::value_exists(
         v15,
         (int)config,
         (unsigned int)"use_angle_depended_attenuation") )
  {
    v18 = vostok::configs::binary_config_value::operator[](config, "use_angle_depended_attenuation");
    v19 = vostok::configs::binary_config_value::operator[](v18, "value")->data.pointer != 0;
  }
  else
  {
    v19 = 0;
  }
  draw_to_gbuffer = (vostok::configs::binary_config_value *)parameters->draw_to_gbuffer;
  BYTE2(v109) = BYTE2(v109) & 0x3F | (v19 << 6);
  v104 = (const void **)((char *)&draw_to_gbuffer->data.pointer + 1) != 0 ? draw_to_gbuffer : 0;
  HIBYTE(v109) = HIBYTE(v109) & 0x3F | ((v104 != 0) << 6);
  LOBYTE(draw_to_gbuffer) = HIBYTE(v109);
  vostok::render::effect_material_base::compile_begin(
    parameters,
    draw_to_gbuffer,
    (vostok::render::effect_material_base *)"vertex_base_z_shifted",
    "forward_base",
    compiler,
    (const char *)&v108,
    config,
    v94,
    v98);
  vostok::render::effect_compiler::set_depth(v21, (int)compiler, 1, 0, SLODWORD(v95));
  *((float *)&v99 + 1) = s_bm_current_air_resistance;
  if ( vostok::configs::binary_config_value::value_exists(v22, (int)config, (unsigned int)"attenuation_power") )
  {
    v24 = vostok::configs::binary_config_value::operator[](config, "attenuation_power");
    v25 = vostok::configs::binary_config_value::operator[](v24, "value");
    if ( v25->type == 2 )
      pointer = *(float *)&v25->data.pointer;
    else
      pointer = (float)(int)v25->data.pointer;
    *((float *)&v99 + 1) = pointer;
  }
  if ( (v109 & 0xC00000) != 0 )
    vostok::render::effect_compiler::set_constant<float>(v23, (float *)&v99 + 1, compiler, "attenuation_power");
  vostok::render::effect_compiler::set_texture(
    (vostok::render::effect_compiler *)v23,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v109 & 0x20) != 0 )
  {
    v28 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_play_speed");
    v29 = vostok::configs::binary_config_value::operator[](v28, "value");
    if ( v29->type == 2 )
      v30 = *(float *)&v29->data.pointer;
    else
      v30 = (float)(int)v29->data.pointer;
    *((float *)&v101 + 1) = v30;
    v31 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_start_frame_index");
    v32 = vostok::configs::binary_config_value::operator[](v31, "value");
    if ( v32->type == 2 )
      v33 = *(float *)&v32->data.pointer;
    else
      v33 = (float)(int)v32->data.pointer;
    *(float *)&v101 = v33;
    v34 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_array_height");
    v35 = vostok::configs::binary_config_value::operator[](v34, "value");
    if ( v35->type == 2 )
      v36 = *(float *)&v35->data.pointer;
    else
      v36 = (float)(int)v35->data.pointer;
    *((float *)&v99 + 1) = v36;
    v37 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_array_width");
    v38 = vostok::configs::binary_config_value::operator[](v37, "value");
    if ( v38->type == 2 )
      v40 = *(float *)&v38->data.pointer;
    else
      v40 = (float)(int)v38->data.pointer;
    *(_QWORD *)&v107.x = __PAIR64__(HIDWORD(v99), LODWORD(v40));
    *(_QWORD *)&v107.elements[2] = v101;
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v107, v39, compiler, "sequence_parameters");
  }
  if ( (v108 & 0x800000) != 0
    && vostok::configs::binary_config_value::value_exists(v27, (int)config, (unsigned int)"uv_distortion_texture")
    && vostok::configs::binary_config_value::value_exists(v41, (int)config, (unsigned int)"uv_distortion_multiplier")
    && vostok::configs::binary_config_value::value_exists(
         v42,
         (int)config,
         (unsigned int)"distortion_1_moving_direction")
    && vostok::configs::binary_config_value::value_exists(
         v43,
         (int)config,
         (unsigned int)"distortion_2_moving_direction")
    && vostok::configs::binary_config_value::value_exists(v44, (int)config, (unsigned int)"uv_distortion_tile") )
  {
    v45 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_texture");
    v46 = (char **)vostok::configs::binary_config_value::operator[](v45, "value");
    vostok::render::effect_compiler::set_texture(
      v47,
      (const char *)compiler,
      "t_uv_distortion",
      *v46,
      0,
      0xFFFFFFFF,
      0,
      1.0);
    v48 = vostok::configs::binary_config_value::operator[](config, "distortion_1_moving_direction");
    v49 = vostok::configs::binary_config_value::operator[](v48, "value");
    v50 = v49->data.pointer;
    LODWORD(v105) = *(_DWORD *)v49->data.pointer;
    HIDWORD(v105) = *++v50;
    v106 = v50[1];
    v51 = vostok::configs::binary_config_value::operator[](config, "distortion_2_moving_direction");
    v52 = (float **)vostok::configs::binary_config_value::operator[](v51, "value");
    v53 = *v52;
    v107.x = **v52;
    *(_QWORD *)&v107.elements[1] = *(_QWORD *)(v53 + 1);
    v54 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_multiplier");
    v55 = vostok::configs::binary_config_value::operator[](v54, "value");
    if ( v55->type == 2 )
      v56 = *(float *)&v55->data.pointer;
    else
      v56 = (float)(int)v55->data.pointer;
    *((float *)&v101 + 1) = v56;
    v57 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_tile");
    v58 = vostok::configs::binary_config_value::operator[](v57, "value");
    if ( v58->type == 2 )
      v60 = *(float *)&v58->data.pointer;
    else
      v60 = (float)(int)v58->data.pointer;
    *(float *)&v101 = v60;
    *(_QWORD *)&v112.x = v105;
    *(_QWORD *)&v112.elements[2] = *(_QWORD *)&v107.x;
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v112, v59, compiler, "uv_distortion_movement");
    vostok::render::effect_compiler::set_constant<float>(v61, (float *)&v101 + 1, compiler, "uv_distortion_multiplier");
    vostok::render::effect_compiler::set_constant<float>(v62, (float *)&v101, compiler, "uv_distortion_tile");
  }
  if ( (HIBYTE(v109) & 3) == 2 )
  {
    v63 = vostok::configs::binary_config_value::operator[](config, "texture_emissive");
    v64 = (char **)vostok::configs::binary_config_value::operator[](v63, "value");
    vostok::render::effect_compiler::set_texture(
      v65,
      (const char *)compiler,
      "t_base",
      *v64,
      num_last_mips_used,
      streaming_priority[0],
      0,
      1.0);
  }
  v66 = vostok::configs::binary_config_value::operator[](config, "constant_emissive_multiplier");
  v67 = vostok::configs::binary_config_value::operator[](v66, "value");
  if ( v67->type == 2 )
    v68 = *(float *)&v67->data.pointer;
  else
    v68 = (float)(int)v67->data.pointer;
  *((float *)&v99 + 1) = v68;
  v69 = vostok::configs::binary_config_value::operator[](config, "constant_emissive");
  v70 = vostok::configs::binary_config_value::operator[](v69, "value");
  v71 = (float *)v70->data.pointer;
  v72 = *(float *)v70->data.pointer;
  __libm_sse2_pow(v95, v99);
  *(float *)&v72 = v72;
  v112.x = *(float *)&v72;
  v73 = v71[1];
  __libm_sse2_pow(v96, v99);
  *(float *)&v73 = v73;
  v112.y = *(float *)&v73;
  v74 = v71[2];
  __libm_sse2_pow(v97, v99);
  *(float *)&v74 = v74;
  v112.z = *(float *)&v74 * *((float *)&v99 + 1);
  v112.x = v112.x * *((float *)&v99 + 1);
  v112.y = v112.y * *((float *)&v99 + 1);
  v112.w = s_bm_current_air_resistance;
  *(_QWORD *)&v107.x = *(_QWORD *)&v112.x;
  v107.z = *(float *)&v74 * *((float *)&v99 + 1);
  v107.w = s_bm_current_air_resistance;
  if ( (v109 & 1) != 0 )
  {
    v76 = vostok::configs::binary_config_value::operator[](config, "texture_transparency");
    v77 = (char **)vostok::configs::binary_config_value::operator[](v76, "value");
    vostok::render::effect_compiler::set_texture(
      v78,
      (const char *)compiler,
      "t_transparency",
      *v77,
      num_last_mips_used,
      streaming_priority[0],
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v75, (int)config, (unsigned int)"constant_transparency") )
  {
    v80 = vostok::configs::binary_config_value::operator[](config, "constant_transparency");
    v81 = vostok::configs::binary_config_value::operator[](v80, "value");
    if ( v81->type == 2 )
      v82 = *(float *)&v81->data.pointer;
    else
      v82 = (float)(int)v81->data.pointer;
  }
  else
  {
    v82 = s_bm_current_air_resistance;
  }
  *(float *)streaming_priority = v82;
  vostok::render::effect_compiler::set_constant<float>(v79, (float *)streaming_priority, compiler, "solid_transparency");
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v107, v83, compiler, "solid_color_specular");
  if ( vostok::configs::binary_config_value::value_exists(v84, (int)config, (unsigned int)"constant_tile_u")
    && vostok::configs::binary_config_value::value_exists(v85, (int)config, (unsigned int)"constant_tile_v") )
  {
    v86 = vostok::configs::binary_config_value::operator[](config, "constant_tile_v");
    v87 = vostok::configs::binary_config_value::operator[](v86, "value");
    if ( v87->type == 2 )
      v88 = *(float *)&v87->data.pointer;
    else
      v88 = (float)(int)v87->data.pointer;
    *(float *)streaming_priority = v88;
    v89 = vostok::configs::binary_config_value::operator[](config, "constant_tile_u");
    v90 = vostok::configs::binary_config_value::operator[](v89, "value");
    if ( v90->type == 2 )
      v91 = *(float *)&v90->data.pointer;
    else
      v91 = (float)(int)v90->data.pointer;
    *((float *)&v101 + 1) = v91;
    v102 = streaming_priority[0];
    v92 = (unsigned int *)&v101 + 1;
  }
  else
  {
    *(float *)streaming_priority = s_bm_current_air_resistance;
    *(float *)&streaming_priority[1] = s_bm_current_air_resistance;
    v92 = streaming_priority;
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float2>(
    (vostok::render::effect_constant_storage *)v92,
    compiler,
    "constant_tile_uv");
  if ( v104 )
    vostok::render::effect_compiler::color_write_enable(
      v93,
      (int)compiler,
      D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_material_base::compile_end((vostok::render::effect_material_base *)v93, compiler);
}
