void __thiscall vostok::render::effect_fstage_volume_cone_base_materials::compile(
        vostok::render::effect_fstage_volume_cone_base_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  unsigned int vertex_input_type; // ecx
  int v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // eax
  const vostok::configs::binary_config_value *v10; // eax
  float *pointer; // edi
  double v12; // xmm0_8
  double v13; // xmm0_8
  double v14; // xmm0_8
  vostok::configs::binary_config_value *v15; // eax
  const vostok::configs::binary_config_value *v16; // eax
  float v17; // xmm0_4
  vostok::configs::binary_config_value *v18; // eax
  const vostok::configs::binary_config_value *v19; // eax
  _DWORD *v20; // esi
  vostok::configs::binary_config_value *v21; // eax
  const vostok::configs::binary_config_value *v22; // eax
  vostok::render::effect_constant_storage *v23; // ecx
  float v24; // xmm0_4
  vostok::render::effect_constant_storage *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::configs::binary_config_value *v28; // eax
  char **v29; // eax
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::configs::binary_config_value *v32; // ecx
  vostok::configs::binary_config_value *v33; // eax
  char **v34; // eax
  vostok::render::effect_compiler *v35; // ecx
  vostok::configs::binary_config_value *v36; // eax
  const vostok::configs::binary_config_value *v37; // eax
  float v38; // xmm0_4
  vostok::configs::binary_config_value *v39; // eax
  const vostok::configs::binary_config_value *v40; // eax
  vostok::render::effect_constant_storage *v41; // ecx
  float v42; // xmm0_4
  vostok::render::effect_constant_storage *v43; // ecx
  vostok::render::effect_material_base *v44; // ecx
  vostok::render::shader_configuration *v45; // [esp+4h] [ebp-58h]
  long double v46; // [esp+4h] [ebp-58h]
  long double v47; // [esp+4h] [ebp-58h]
  long double v48; // [esp+4h] [ebp-58h]
  const vostok::configs::binary_config_value *v49; // [esp+8h] [ebp-54h]
  long double v50; // [esp+Ch] [ebp-50h]
  long double v51; // [esp+Ch] [ebp-50h]
  long double v52; // [esp+Ch] [ebp-50h]
  float v53; // [esp+14h] [ebp-48h]
  unsigned int num_last_mips_used; // [esp+18h] [ebp-44h] BYREF
  unsigned int streaming_priority; // [esp+1Ch] [ebp-40h] BYREF
  __int64 v56; // [esp+20h] [ebp-3Ch]
  unsigned int v57; // [esp+28h] [ebp-34h]
  int v58; // [esp+2Ch] [ebp-30h] BYREF
  int v59; // [esp+30h] [ebp-2Ch]
  int v60; // [esp+34h] [ebp-28h]
  int v61; // [esp+38h] [ebp-24h]
  float v62; // [esp+3Ch] [ebp-20h]
  float v63; // [esp+40h] [ebp-1Ch]
  float v64; // [esp+44h] [ebp-18h]
  float v65; // [esp+48h] [ebp-14h]
  vostok::math::float4 v66; // [esp+4Ch] [ebp-10h] BYREF

  vertex_input_type = parameters->vertex_input_type;
  LOBYTE(num_last_mips_used) = parameters->vertex_input_type >= 0xF
                            || (v5 = 1 << vertex_input_type, 1 << vertex_input_type != 2048)
                            && v5 != 128
                            && v5 != 512
                            && v5 != 256;
  v60 = 0x80000;
  v58 = 0;
  v59 = 0;
  v61 = 0;
  streaming_priority = (_BYTE)num_last_mips_used == 0 ? -1 : 5;
  v6 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
  BYTE2(v58) = 8 * (vostok::configs::binary_config_value::operator[](v6, "value")->data.pointer != 0);
  v7 = vostok::configs::binary_config_value::operator[](config, "use_ttransparency");
  LOBYTE(v59) = vostok::configs::binary_config_value::operator[](v7, "value")->data.pointer != 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v8,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    (const char *)&stru_8124C8,
    compiler,
    (const char *)&v58,
    config,
    v45,
    v49);
  v9 = vostok::configs::binary_config_value::operator[](config, "constant_volume_color");
  v10 = vostok::configs::binary_config_value::operator[](v9, "value");
  pointer = (float *)v10->data.pointer;
  v12 = *(float *)v10->data.pointer;
  __libm_sse2_pow(v46, v50);
  *(float *)&v12 = v12;
  v62 = *(float *)&v12;
  v13 = pointer[1];
  __libm_sse2_pow(v47, v51);
  *(float *)&v13 = v13;
  v63 = *(float *)&v13;
  v14 = pointer[2];
  __libm_sse2_pow(v48, v52);
  *(float *)&v14 = v14;
  v64 = *(float *)&v14;
  v65 = pointer[3];
  v15 = vostok::configs::binary_config_value::operator[](config, "constant_volume_color_multiplier");
  v16 = vostok::configs::binary_config_value::operator[](v15, "value");
  if ( v16->type == 2 )
    v17 = *(float *)&v16->data.pointer;
  else
    v17 = (float)(int)v16->data.pointer;
  v53 = v17;
  v18 = vostok::configs::binary_config_value::operator[](config, "move_direction");
  v19 = vostok::configs::binary_config_value::operator[](v18, "value");
  v20 = v19->data.pointer;
  LODWORD(v56) = *(_DWORD *)v19->data.pointer;
  HIDWORD(v56) = *++v20;
  v57 = v20[1];
  v21 = vostok::configs::binary_config_value::operator[](config, "uv_tile");
  v22 = vostok::configs::binary_config_value::operator[](v21, "value");
  if ( v22->type == 2 )
    v24 = *(float *)&v22->data.pointer;
  else
    v24 = (float)(int)v22->data.pointer;
  *(_QWORD *)&v66.x = v56;
  *(_QWORD *)&v66.elements[2] = __PAIR64__(LODWORD(v24), v57);
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v66, v23, compiler, "mode_direction_and_uv_tile");
  v66.x = v62 * v53;
  v66.y = v63 * v53;
  v66.z = v64 * v53;
  v66.w = v65;
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v66, v25, compiler, "volume_color");
  vostok::render::effect_compiler::set_texture(
    v26,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v58 & 0x80000) != 0 )
  {
    v28 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v29 = (char **)vostok::configs::binary_config_value::operator[](v28, "value");
    vostok::render::effect_compiler::set_texture(
      v30,
      (const char *)compiler,
      "t_diffuse",
      *v29,
      num_last_mips_used,
      streaming_priority,
      0,
      1.0);
  }
  vostok::render::effect_compiler::set_texture(
    v27,
    (const char *)compiler,
    "t_spot_falloff",
    "fx/spot_falloff",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v31,
    (const char *)compiler,
    "t_sphere_falloff",
    "fx/sphere_falloff",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v59 & 1) != 0 )
  {
    v33 = vostok::configs::binary_config_value::operator[](config, "texture_transparency");
    v34 = (char **)vostok::configs::binary_config_value::operator[](v33, "value");
    vostok::render::effect_compiler::set_texture(
      v35,
      (const char *)compiler,
      "t_transparency",
      *v34,
      num_last_mips_used,
      streaming_priority,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v32, (int)config, (unsigned int)"constant_transparency") )
  {
    v36 = vostok::configs::binary_config_value::operator[](config, "constant_transparency");
    v37 = vostok::configs::binary_config_value::operator[](v36, "value");
    if ( v37->type == 2 )
      v38 = *(float *)&v37->data.pointer;
    else
      v38 = (float)(int)v37->data.pointer;
  }
  else
  {
    v38 = s_bm_current_air_resistance;
  }
  num_last_mips_used = LODWORD(v38);
  v39 = vostok::configs::binary_config_value::operator[](config, "attenuation_scale");
  v40 = vostok::configs::binary_config_value::operator[](v39, "value");
  if ( v40->type == 2 )
    v42 = *(float *)&v40->data.pointer;
  else
    v42 = (float)(int)v40->data.pointer;
  streaming_priority = LODWORD(v42);
  vostok::render::effect_compiler::set_constant<float>(v41, (float *)&streaming_priority, compiler, "attenuation_scale");
  vostok::render::effect_compiler::set_constant<float>(
    v43,
    (float *)&num_last_mips_used,
    compiler,
    "solid_transparency");
  vostok::render::effect_material_base::compile_end(v44, compiler);
}
