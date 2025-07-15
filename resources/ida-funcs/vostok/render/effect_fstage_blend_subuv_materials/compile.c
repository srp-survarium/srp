void __thiscall vostok::render::effect_fstage_blend_subuv_materials::compile(
        vostok::render::effect_fstage_blend_subuv_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // eax
  char v10; // al
  vostok::render::effect_compiler *v11; // ecx
  vostok::configs::binary_config_value *v12; // eax
  vostok::render::effect_compiler *v13; // ecx
  vostok::configs::binary_config_value *v14; // eax
  char **v15; // eax
  vostok::render::effect_compiler *v16; // ecx
  vostok::configs::binary_config_value *v17; // eax
  const vostok::configs::binary_config_value *v18; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v20; // eax
  const vostok::configs::binary_config_value *v21; // eax
  float *v22; // esi
  double v23; // xmm0_8
  double v24; // xmm0_8
  double v25; // xmm0_8
  vostok::configs::binary_config_value *v26; // ecx
  vostok::configs::binary_config_value *v27; // eax
  char **v28; // eax
  vostok::render::effect_compiler *v29; // ecx
  vostok::configs::binary_config_value *v30; // ecx
  vostok::configs::binary_config_value *v31; // eax
  const vostok::configs::binary_config_value *v32; // eax
  float v33; // xmm0_4
  vostok::configs::binary_config_value *v34; // eax
  char **v35; // eax
  vostok::render::effect_compiler *v36; // ecx
  vostok::configs::binary_config_value *v37; // eax
  const vostok::configs::binary_config_value *v38; // eax
  float *v39; // esi
  vostok::configs::binary_config_value *v40; // eax
  const vostok::configs::binary_config_value *v41; // eax
  _DWORD *v42; // esi
  vostok::configs::binary_config_value *v43; // eax
  const vostok::configs::binary_config_value *v44; // eax
  float v45; // xmm0_4
  vostok::configs::binary_config_value *v46; // eax
  const vostok::configs::binary_config_value *v47; // eax
  vostok::render::effect_constant_storage *v48; // ecx
  float v49; // xmm0_4
  vostok::render::effect_constant_storage *v50; // ecx
  vostok::render::effect_constant_storage *v51; // ecx
  vostok::render::effect_constant_storage *v52; // ecx
  vostok::render::effect_material_base *v53; // ecx
  vostok::render::shader_configuration *v54; // [esp+4h] [ebp-58h]
  long double v55; // [esp+4h] [ebp-58h]
  long double v56; // [esp+4h] [ebp-58h]
  long double v57; // [esp+4h] [ebp-58h]
  const vostok::configs::binary_config_value *v58; // [esp+8h] [ebp-54h]
  long double v59; // [esp+Ch] [ebp-50h] BYREF
  float v60; // [esp+14h] [ebp-48h] BYREF
  float v61; // [esp+18h] [ebp-44h] BYREF
  __int64 v62; // [esp+1Ch] [ebp-40h]
  float v63; // [esp+24h] [ebp-38h]
  float v64; // [esp+28h] [ebp-34h]
  __int64 v65; // [esp+2Ch] [ebp-30h] BYREF
  int v66; // [esp+34h] [ebp-28h]
  int v67; // [esp+38h] [ebp-24h]
  vostok::math::float4 v68; // [esp+3Ch] [ebp-20h] BYREF
  vostok::math::float4 v69; // [esp+4Ch] [ebp-10h] BYREF

  v66 = 0x80000;
  v65 = 0;
  v67 = 0;
  v4 = vostok::configs::binary_config_value::operator[](config, "use_temissive");
  HIBYTE(v65) = ((vostok::configs::binary_config_value::operator[](v4, "value")->data.pointer != 0) + 1) & 3;
  v5 = vostok::configs::binary_config_value::operator[](config, "use_ttransparency");
  BYTE4(v65) = vostok::configs::binary_config_value::operator[](v5, "value")->data.pointer != 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v6,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "forward_base_subuv",
    compiler,
    (const char *)&v65,
    config,
    v54,
    v58);
  if ( vostok::configs::binary_config_value::value_exists(v7, (int)config, (unsigned int)"use_uv_distortion") )
  {
    v9 = vostok::configs::binary_config_value::operator[](config, "use_uv_distortion");
    v10 = vostok::configs::binary_config_value::operator[](v9, "value")->data.pointer != 0;
  }
  else
  {
    v10 = 0;
  }
  LOBYTE(v8) = BYTE2(v65) & 0x7F;
  BYTE2(v65) = BYTE2(v65) & 0x7F | (v10 << 7);
  if ( vostok::configs::binary_config_value::value_exists(v8, (int)config, (unsigned int)"use_soft_edges") )
  {
    v12 = vostok::configs::binary_config_value::operator[](config, "use_soft_edges");
    vostok::configs::binary_config_value::operator[](v12, "value");
  }
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_particle_lighting",
    "$user$particle_lighting",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (HIBYTE(v65) & 3) == 2 )
  {
    v14 = vostok::configs::binary_config_value::operator[](config, "texture_emissive");
    v15 = (char **)vostok::configs::binary_config_value::operator[](v14, "value");
    vostok::render::effect_compiler::set_texture(v16, (const char *)compiler, "t_base", *v15, 0, 0xFFFFFFFF, 0, 1.0);
  }
  v17 = vostok::configs::binary_config_value::operator[](config, "constant_emissive_multiplier");
  v18 = vostok::configs::binary_config_value::operator[](v17, "value");
  if ( v18->type == 2 )
    pointer = *(float *)&v18->data.pointer;
  else
    pointer = (float)(int)v18->data.pointer;
  *((float *)&v59 + 1) = pointer;
  v20 = vostok::configs::binary_config_value::operator[](config, "constant_emissive");
  v21 = vostok::configs::binary_config_value::operator[](v20, "value");
  v22 = (float *)v21->data.pointer;
  v23 = *(float *)v21->data.pointer;
  __libm_sse2_pow(v55, v59);
  *(float *)&v23 = v23;
  v68.x = *(float *)&v23;
  v24 = v22[1];
  __libm_sse2_pow(v56, v59);
  *(float *)&v24 = v24;
  v68.y = *(float *)&v24;
  v25 = v22[2];
  __libm_sse2_pow(v57, v59);
  *(float *)&v25 = v25;
  v63 = *(float *)&v25 * *((float *)&v59 + 1);
  *(float *)&v62 = v68.x * *((float *)&v59 + 1);
  *((float *)&v62 + 1) = v68.y * *((float *)&v59 + 1);
  v64 = s_bm_current_air_resistance;
  v69.x = v68.x * *((float *)&v59 + 1);
  v69.y = v68.y * *((float *)&v59 + 1);
  v69.z = *(float *)&v25 * *((float *)&v59 + 1);
  v69.w = s_bm_current_air_resistance;
  if ( (v65 & 0x100000000LL) != 0 )
  {
    v27 = vostok::configs::binary_config_value::operator[](config, "texture_transparency");
    v28 = (char **)vostok::configs::binary_config_value::operator[](v27, "value");
    vostok::render::effect_compiler::set_texture(
      v29,
      (const char *)compiler,
      "t_transparency",
      *v28,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v26, (int)config, (unsigned int)"constant_transparency") )
  {
    v31 = vostok::configs::binary_config_value::operator[](config, "constant_transparency");
    v32 = vostok::configs::binary_config_value::operator[](v31, "value");
    if ( v32->type == 2 )
      v33 = *(float *)&v32->data.pointer;
    else
      v33 = (float)(int)v32->data.pointer;
  }
  else
  {
    v33 = s_bm_current_air_resistance;
  }
  v61 = v33;
  if ( (v65 & 0x800000) != 0
    && vostok::configs::binary_config_value::value_exists(v30, (int)config, (unsigned int)"uv_distortion_texture")
    && vostok::configs::binary_config_value::value_exists(v30, (int)config, (unsigned int)"uv_distortion_multiplier")
    && vostok::configs::binary_config_value::value_exists(
         v30,
         (int)config,
         (unsigned int)"distortion_1_moving_direction")
    && vostok::configs::binary_config_value::value_exists(
         v30,
         (int)config,
         (unsigned int)"distortion_2_moving_direction")
    && vostok::configs::binary_config_value::value_exists(v30, (int)config, (unsigned int)"uv_distortion_tile") )
  {
    v34 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_texture");
    v35 = (char **)vostok::configs::binary_config_value::operator[](v34, "value");
    vostok::render::effect_compiler::set_texture(
      v36,
      (const char *)compiler,
      "t_uv_distortion",
      *v35,
      0,
      0xFFFFFFFF,
      0,
      1.0);
    v37 = vostok::configs::binary_config_value::operator[](config, "distortion_1_moving_direction");
    v38 = vostok::configs::binary_config_value::operator[](v37, "value");
    v39 = (float *)v38->data.pointer;
    LODWORD(v62) = *(_DWORD *)v38->data.pointer;
    *((float *)&v62 + 1) = *++v39;
    v63 = v39[1];
    v40 = vostok::configs::binary_config_value::operator[](config, "distortion_2_moving_direction");
    v41 = vostok::configs::binary_config_value::operator[](v40, "value");
    v42 = v41->data.pointer;
    LODWORD(v65) = *(_DWORD *)v41->data.pointer;
    HIDWORD(v65) = *++v42;
    v66 = v42[1];
    v43 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_multiplier");
    v44 = vostok::configs::binary_config_value::operator[](v43, "value");
    if ( v44->type == 2 )
      v45 = *(float *)&v44->data.pointer;
    else
      v45 = (float)(int)v44->data.pointer;
    *((float *)&v59 + 1) = v45;
    v46 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_tile");
    v47 = vostok::configs::binary_config_value::operator[](v46, "value");
    if ( v47->type == 2 )
      v49 = *(float *)&v47->data.pointer;
    else
      v49 = (float)(int)v47->data.pointer;
    v60 = v49;
    *(_QWORD *)&v68.x = v62;
    *(_QWORD *)&v68.elements[2] = v65;
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v68, v48, compiler, "uv_distortion_movement");
    vostok::render::effect_compiler::set_constant<float>(v50, (float *)&v59 + 1, compiler, "uv_distortion_multiplier");
    vostok::render::effect_compiler::set_constant<float>(v51, &v60, compiler, "uv_distortion_tile");
  }
  vostok::render::effect_compiler::set_constant<float>(
    (vostok::render::effect_constant_storage *)v30,
    &v61,
    compiler,
    "solid_transparency");
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v69, v52, compiler, "solid_color_specular");
  vostok::render::effect_material_base::compile_end(v53, compiler);
}
