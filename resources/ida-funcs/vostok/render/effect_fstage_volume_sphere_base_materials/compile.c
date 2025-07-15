void __thiscall vostok::render::effect_fstage_volume_sphere_base_materials::compile(
        vostok::render::effect_fstage_volume_sphere_base_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // eax
  const vostok::configs::binary_config_value *v8; // eax
  float *pointer; // edi
  double v10; // xmm0_8
  double v11; // xmm0_8
  double v12; // xmm0_8
  vostok::configs::binary_config_value *v13; // eax
  const vostok::configs::binary_config_value *v14; // eax
  float v15; // xmm0_4
  vostok::configs::binary_config_value *v16; // eax
  const vostok::configs::binary_config_value *v17; // eax
  _DWORD *v18; // esi
  vostok::configs::binary_config_value *v19; // eax
  const vostok::configs::binary_config_value *v20; // eax
  vostok::render::effect_constant_storage *v21; // ecx
  float v22; // xmm0_4
  vostok::render::effect_constant_storage *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::configs::binary_config_value *v26; // eax
  char **v27; // eax
  vostok::render::effect_compiler *v28; // ecx
  vostok::configs::binary_config_value *v29; // ecx
  vostok::configs::binary_config_value *v30; // eax
  char **v31; // eax
  vostok::render::effect_compiler *v32; // ecx
  vostok::configs::binary_config_value *v33; // eax
  const vostok::configs::binary_config_value *v34; // eax
  float v35; // xmm0_4
  vostok::configs::binary_config_value *v36; // eax
  const vostok::configs::binary_config_value *v37; // eax
  vostok::render::effect_constant_storage *v38; // ecx
  float v39; // xmm0_4
  vostok::render::effect_constant_storage *v40; // ecx
  vostok::render::effect_material_base *v41; // ecx
  vostok::render::shader_configuration *v42; // [esp+4h] [ebp-50h]
  long double v43; // [esp+4h] [ebp-50h]
  long double v44; // [esp+4h] [ebp-50h]
  long double v45; // [esp+4h] [ebp-50h]
  const vostok::configs::binary_config_value *v46; // [esp+8h] [ebp-4Ch]
  long double v47; // [esp+Ch] [ebp-48h] BYREF
  float v48; // [esp+14h] [ebp-40h] BYREF
  __int64 v49; // [esp+18h] [ebp-3Ch]
  unsigned int v50; // [esp+20h] [ebp-34h]
  int v51; // [esp+24h] [ebp-30h] BYREF
  int v52; // [esp+28h] [ebp-2Ch]
  int v53; // [esp+2Ch] [ebp-28h]
  int v54; // [esp+30h] [ebp-24h]
  float v55; // [esp+34h] [ebp-20h]
  float v56; // [esp+38h] [ebp-1Ch]
  float v57; // [esp+3Ch] [ebp-18h]
  float v58; // [esp+40h] [ebp-14h]
  vostok::math::float4 v59; // [esp+44h] [ebp-10h] BYREF

  v53 = 0x80000;
  v51 = 0;
  v52 = 0;
  v54 = 0;
  v4 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
  BYTE2(v51) = 8 * (vostok::configs::binary_config_value::operator[](v4, "value")->data.pointer != 0);
  v5 = vostok::configs::binary_config_value::operator[](config, "use_ttransparency");
  LOBYTE(v52) = vostok::configs::binary_config_value::operator[](v5, "value")->data.pointer != 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v6,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    (const char *)&stru_8124AC,
    compiler,
    (const char *)&v51,
    config,
    v42,
    v46);
  v7 = vostok::configs::binary_config_value::operator[](config, "constant_volume_color");
  v8 = vostok::configs::binary_config_value::operator[](v7, "value");
  pointer = (float *)v8->data.pointer;
  v10 = *(float *)v8->data.pointer;
  __libm_sse2_pow(v43, v47);
  *(float *)&v10 = v10;
  v55 = *(float *)&v10;
  v11 = pointer[1];
  __libm_sse2_pow(v44, v47);
  *(float *)&v11 = v11;
  v56 = *(float *)&v11;
  v12 = pointer[2];
  __libm_sse2_pow(v45, v47);
  *(float *)&v12 = v12;
  v57 = *(float *)&v12;
  v58 = pointer[3];
  v13 = vostok::configs::binary_config_value::operator[](config, "constant_volume_color_multiplier");
  v14 = vostok::configs::binary_config_value::operator[](v13, "value");
  if ( v14->type == 2 )
    v15 = *(float *)&v14->data.pointer;
  else
    v15 = (float)(int)v14->data.pointer;
  *((float *)&v47 + 1) = v15;
  v16 = vostok::configs::binary_config_value::operator[](config, "move_direction");
  v17 = vostok::configs::binary_config_value::operator[](v16, "value");
  v18 = v17->data.pointer;
  LODWORD(v49) = *(_DWORD *)v17->data.pointer;
  HIDWORD(v49) = *++v18;
  v50 = v18[1];
  v19 = vostok::configs::binary_config_value::operator[](config, "uv_tile");
  v20 = vostok::configs::binary_config_value::operator[](v19, "value");
  if ( v20->type == 2 )
    v22 = *(float *)&v20->data.pointer;
  else
    v22 = (float)(int)v20->data.pointer;
  *(_QWORD *)&v59.x = v49;
  *(_QWORD *)&v59.elements[2] = __PAIR64__(LODWORD(v22), v50);
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v59, v21, compiler, "mode_direction_and_uv_tile");
  v59.x = v55 * *((float *)&v47 + 1);
  v59.y = v56 * *((float *)&v47 + 1);
  v59.z = v57 * *((float *)&v47 + 1);
  v59.w = v58;
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v59, v23, compiler, "volume_color");
  vostok::render::effect_compiler::set_texture(
    v24,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v51 & 0x80000) != 0 )
  {
    v26 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v27 = (char **)vostok::configs::binary_config_value::operator[](v26, "value");
    vostok::render::effect_compiler::set_texture(v28, (const char *)compiler, "t_diffuse", *v27, 0, 0xFFFFFFFF, 0, 1.0);
  }
  vostok::render::effect_compiler::set_texture(
    v25,
    (const char *)compiler,
    "t_sphere_falloff",
    "fx/sphere_falloff",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v52 & 1) != 0 )
  {
    v30 = vostok::configs::binary_config_value::operator[](config, "texture_transparency");
    v31 = (char **)vostok::configs::binary_config_value::operator[](v30, "value");
    vostok::render::effect_compiler::set_texture(
      v32,
      (const char *)compiler,
      "t_transparency",
      *v31,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v29, (int)config, (unsigned int)"constant_transparency") )
  {
    v33 = vostok::configs::binary_config_value::operator[](config, "constant_transparency");
    v34 = vostok::configs::binary_config_value::operator[](v33, "value");
    if ( v34->type == 2 )
      v35 = *(float *)&v34->data.pointer;
    else
      v35 = (float)(int)v34->data.pointer;
  }
  else
  {
    v35 = s_bm_current_air_resistance;
  }
  v48 = v35;
  v36 = vostok::configs::binary_config_value::operator[](config, "attenuation_scale");
  v37 = vostok::configs::binary_config_value::operator[](v36, "value");
  if ( v37->type == 2 )
    v39 = *(float *)&v37->data.pointer;
  else
    v39 = (float)(int)v37->data.pointer;
  *((float *)&v47 + 1) = v39;
  vostok::render::effect_compiler::set_constant<float>(v38, (float *)&v47 + 1, compiler, "attenuation_scale");
  vostok::render::effect_compiler::set_constant<float>(v40, &v48, compiler, "solid_transparency");
  vostok::render::effect_material_base::compile_end(v41, compiler);
}
