void __thiscall vostok::render::effect_fstage_fire_fresnel_materials::compile(
        vostok::render::effect_fstage_fire_fresnel_materials *this,
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
  char v14; // al
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::configs::binary_config_value *v17; // eax
  char **v18; // eax
  vostok::render::effect_compiler *v19; // ecx
  vostok::configs::binary_config_value *v20; // eax
  const vostok::configs::binary_config_value *v21; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v23; // eax
  const vostok::configs::binary_config_value *v24; // eax
  float *v25; // esi
  double v26; // xmm0_8
  double v27; // xmm0_8
  double v28; // xmm0_8
  vostok::configs::binary_config_value *v29; // ecx
  vostok::configs::binary_config_value *v30; // eax
  char **v31; // eax
  vostok::render::effect_compiler *v32; // ecx
  vostok::configs::binary_config_value *v33; // ecx
  vostok::configs::binary_config_value *v34; // eax
  const vostok::configs::binary_config_value *v35; // eax
  float v36; // xmm0_4
  vostok::configs::binary_config_value *v37; // eax
  char **v38; // eax
  vostok::render::effect_compiler *v39; // ecx
  vostok::configs::binary_config_value *v40; // eax
  const vostok::configs::binary_config_value *v41; // eax
  _DWORD *v42; // esi
  vostok::configs::binary_config_value *v43; // eax
  const vostok::configs::binary_config_value *v44; // eax
  _DWORD *v45; // esi
  vostok::configs::binary_config_value *v46; // eax
  const vostok::configs::binary_config_value *v47; // eax
  float v48; // xmm0_4
  vostok::configs::binary_config_value *v49; // eax
  const vostok::configs::binary_config_value *v50; // eax
  vostok::render::effect_constant_storage *v51; // ecx
  float v52; // xmm0_4
  vostok::render::effect_constant_storage *v53; // ecx
  vostok::render::effect_constant_storage *v54; // ecx
  vostok::render::effect_constant_storage *v55; // ecx
  vostok::render::effect_material_base *v56; // ecx
  vostok::render::shader_configuration *v57; // [esp+4h] [ebp-58h]
  long double v58; // [esp+4h] [ebp-58h]
  long double v59; // [esp+4h] [ebp-58h]
  long double v60; // [esp+4h] [ebp-58h]
  const vostok::configs::binary_config_value *v61; // [esp+8h] [ebp-54h]
  long double v62; // [esp+Ch] [ebp-50h] BYREF
  float v63; // [esp+14h] [ebp-48h] BYREF
  unsigned int streaming_priority; // [esp+18h] [ebp-44h] BYREF
  __int64 v65; // [esp+1Ch] [ebp-40h]
  int v66; // [esp+24h] [ebp-38h]
  float v67; // [esp+28h] [ebp-34h]
  __int64 v68; // [esp+2Ch] [ebp-30h] BYREF
  int v69; // [esp+34h] [ebp-28h]
  int v70; // [esp+38h] [ebp-24h]
  vostok::math::float4 v71; // [esp+3Ch] [ebp-20h] BYREF
  vostok::math::float4 v72; // [esp+4Ch] [ebp-10h] BYREF

  vertex_input_type = parameters->vertex_input_type;
  BYTE4(v62) = parameters->vertex_input_type >= 0xF
            || (v5 = 1 << vertex_input_type, 1 << vertex_input_type != 2048) && v5 != 128 && v5 != 512 && v5 != 256;
  v69 = 0x80000;
  v68 = 0;
  v70 = 0;
  streaming_priority = BYTE4(v62) == 0 ? -1 : 5;
  v6 = vostok::configs::binary_config_value::operator[](config, "use_temissive");
  HIBYTE(v68) = ((vostok::configs::binary_config_value::operator[](v6, "value")->data.pointer != 0) + 1) & 3;
  v7 = vostok::configs::binary_config_value::operator[](config, "use_ttransparency");
  BYTE4(v68) = vostok::configs::binary_config_value::operator[](v7, "value")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v8, (int)config, (unsigned int)"use_uv_distortion") )
  {
    v10 = vostok::configs::binary_config_value::operator[](config, "use_uv_distortion");
    v11 = vostok::configs::binary_config_value::operator[](v10, "value")->data.pointer != 0;
  }
  else
  {
    v11 = 0;
  }
  LOBYTE(v9) = BYTE2(v68) & 0x7F;
  BYTE2(v68) = BYTE2(v68) & 0x7F | (v11 << 7);
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)config, (unsigned int)"use_soft_edges") )
  {
    v13 = vostok::configs::binary_config_value::operator[](config, "use_soft_edges");
    v14 = vostok::configs::binary_config_value::operator[](v13, "value")->data.pointer != 0;
  }
  else
  {
    v14 = 0;
  }
  LOBYTE(v12) = v70 & 0x7F;
  LOBYTE(v70) = v70 & 0x7F | (v14 << 7);
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v12,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "forward_base_fire_subuv",
    compiler,
    (const char *)&v68,
    config,
    v57,
    v61);
  vostok::render::effect_compiler::set_texture(
    v15,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v16,
    (const char *)compiler,
    "t_particle_lighting",
    "$user$particle_lighting",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (HIBYTE(v68) & 3) == 2 )
  {
    v17 = vostok::configs::binary_config_value::operator[](config, "texture_emissive");
    v18 = (char **)vostok::configs::binary_config_value::operator[](v17, "value");
    vostok::render::effect_compiler::set_texture(
      v19,
      (const char *)compiler,
      "t_base",
      *v18,
      SBYTE4(v62),
      streaming_priority,
      0,
      1.0);
  }
  v20 = vostok::configs::binary_config_value::operator[](config, "constant_emissive_multiplier");
  v21 = vostok::configs::binary_config_value::operator[](v20, "value");
  if ( v21->type == 2 )
    pointer = *(float *)&v21->data.pointer;
  else
    pointer = (float)(int)v21->data.pointer;
  v63 = pointer;
  v23 = vostok::configs::binary_config_value::operator[](config, "constant_emissive");
  v24 = vostok::configs::binary_config_value::operator[](v23, "value");
  v25 = (float *)v24->data.pointer;
  v26 = *(float *)v24->data.pointer;
  __libm_sse2_pow(v58, v62);
  *(float *)&v26 = v26;
  v71.x = *(float *)&v26;
  v27 = v25[1];
  __libm_sse2_pow(v59, v62);
  *(float *)&v27 = v27;
  v71.y = *(float *)&v27;
  v28 = v25[2];
  __libm_sse2_pow(v60, v62);
  v65 = *(_QWORD *)&v71.x;
  *(float *)&v28 = v28;
  v66 = LODWORD(v28);
  v67 = v63;
  *(_QWORD *)&v72.x = *(_QWORD *)&v71.x;
  *(_QWORD *)&v72.elements[2] = __PAIR64__(LODWORD(v63), LODWORD(v28));
  if ( (v68 & 0x100000000LL) != 0 )
  {
    v30 = vostok::configs::binary_config_value::operator[](config, "texture_transparency");
    v31 = (char **)vostok::configs::binary_config_value::operator[](v30, "value");
    vostok::render::effect_compiler::set_texture(
      v32,
      (const char *)compiler,
      "t_transparency",
      *v31,
      SBYTE4(v62),
      streaming_priority,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v29, (int)config, (unsigned int)"constant_transparency") )
  {
    v34 = vostok::configs::binary_config_value::operator[](config, "constant_transparency");
    v35 = vostok::configs::binary_config_value::operator[](v34, "value");
    if ( v35->type == 2 )
      v36 = *(float *)&v35->data.pointer;
    else
      v36 = (float)(int)v35->data.pointer;
  }
  else
  {
    v36 = s_bm_current_air_resistance;
  }
  *((float *)&v62 + 1) = v36;
  if ( (v68 & 0x800000) != 0
    && vostok::configs::binary_config_value::value_exists(v33, (int)config, (unsigned int)"uv_distortion_texture")
    && vostok::configs::binary_config_value::value_exists(v33, (int)config, (unsigned int)"uv_distortion_multiplier")
    && vostok::configs::binary_config_value::value_exists(
         v33,
         (int)config,
         (unsigned int)"distortion_1_moving_direction")
    && vostok::configs::binary_config_value::value_exists(
         v33,
         (int)config,
         (unsigned int)"distortion_2_moving_direction")
    && vostok::configs::binary_config_value::value_exists(v33, (int)config, (unsigned int)"uv_distortion_tile") )
  {
    v37 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_texture");
    v38 = (char **)vostok::configs::binary_config_value::operator[](v37, "value");
    vostok::render::effect_compiler::set_texture(
      v39,
      (const char *)compiler,
      "t_uv_distortion",
      *v38,
      0,
      0xFFFFFFFF,
      0,
      1.0);
    v40 = vostok::configs::binary_config_value::operator[](config, "distortion_1_moving_direction");
    v41 = vostok::configs::binary_config_value::operator[](v40, "value");
    v42 = v41->data.pointer;
    LODWORD(v65) = *(_DWORD *)v41->data.pointer;
    HIDWORD(v65) = *++v42;
    v66 = v42[1];
    v43 = vostok::configs::binary_config_value::operator[](config, "distortion_2_moving_direction");
    v44 = vostok::configs::binary_config_value::operator[](v43, "value");
    v45 = v44->data.pointer;
    LODWORD(v68) = *(_DWORD *)v44->data.pointer;
    HIDWORD(v68) = *++v45;
    v69 = v45[1];
    v46 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_multiplier");
    v47 = vostok::configs::binary_config_value::operator[](v46, "value");
    if ( v47->type == 2 )
      v48 = *(float *)&v47->data.pointer;
    else
      v48 = (float)(int)v47->data.pointer;
    streaming_priority = LODWORD(v48);
    v49 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_tile");
    v50 = vostok::configs::binary_config_value::operator[](v49, "value");
    if ( v50->type == 2 )
      v52 = *(float *)&v50->data.pointer;
    else
      v52 = (float)(int)v50->data.pointer;
    v63 = v52;
    *(_QWORD *)&v71.x = v65;
    *(_QWORD *)&v71.elements[2] = v68;
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v71, v51, compiler, "uv_distortion_movement");
    vostok::render::effect_compiler::set_constant<float>(
      v53,
      (float *)&streaming_priority,
      compiler,
      "uv_distortion_multiplier");
    vostok::render::effect_compiler::set_constant<float>(v54, &v63, compiler, "uv_distortion_tile");
  }
  vostok::render::effect_compiler::set_constant<float>(
    (vostok::render::effect_constant_storage *)v33,
    (float *)&v62 + 1,
    compiler,
    "solid_transparency");
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v72, v55, compiler, "solid_color_specular");
  vostok::render::effect_material_base::compile_end(v56, compiler);
}
