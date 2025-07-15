void __thiscall vostok::render::effect_fstage_smoke_custom_lighted_materials::compile(
        vostok::render::effect_fstage_smoke_custom_lighted_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // eax
  char **v8; // eax
  vostok::render::effect_compiler *v9; // ecx
  vostok::configs::binary_config_value *v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v13; // eax
  const vostok::configs::binary_config_value *v14; // eax
  float *v15; // esi
  double v16; // xmm0_8
  double v17; // xmm0_8
  double v18; // xmm0_8
  vostok::configs::binary_config_value *v19; // ecx
  vostok::configs::binary_config_value *v20; // eax
  char **v21; // eax
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::effect_constant_storage *v23; // ecx
  vostok::configs::binary_config_value *v24; // eax
  const vostok::configs::binary_config_value *v25; // eax
  float v26; // xmm0_4
  vostok::render::effect_constant_storage *v27; // ecx
  vostok::render::effect_material_base *v28; // ecx
  vostok::render::shader_configuration *v29; // [esp+4h] [ebp-40h]
  long double v30; // [esp+4h] [ebp-40h]
  long double v31; // [esp+4h] [ebp-40h]
  long double v32; // [esp+4h] [ebp-40h]
  const vostok::configs::binary_config_value *v33; // [esp+8h] [ebp-3Ch]
  long double v34; // [esp+Ch] [ebp-38h] BYREF
  int v35; // [esp+14h] [ebp-30h] BYREF
  int v36; // [esp+18h] [ebp-2Ch]
  int v37; // [esp+1Ch] [ebp-28h]
  int v38; // [esp+20h] [ebp-24h]
  __int64 v39; // [esp+24h] [ebp-20h]
  int v40; // [esp+2Ch] [ebp-18h]
  int v41; // [esp+30h] [ebp-14h]
  vostok::math::float4 v42; // [esp+34h] [ebp-10h] BYREF

  v37 = 0x80000;
  v35 = 0;
  v36 = 0;
  v38 = 0;
  v4 = vostok::configs::binary_config_value::operator[](config, "use_temissive");
  HIBYTE(v36) = ((vostok::configs::binary_config_value::operator[](v4, "value")->data.pointer != 0) + 1) & 3;
  v5 = vostok::configs::binary_config_value::operator[](config, "use_ttransparency");
  LOBYTE(v36) = vostok::configs::binary_config_value::operator[](v5, "value")->data.pointer != 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v6,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "forward_base_smoke_custom_lighted",
    compiler,
    (const char *)&v35,
    config,
    v29,
    v33);
  if ( (HIBYTE(v36) & 3) == 2 )
  {
    v7 = vostok::configs::binary_config_value::operator[](config, "texture_emissive");
    v8 = (char **)vostok::configs::binary_config_value::operator[](v7, "value");
    vostok::render::effect_compiler::set_texture(v9, (const char *)compiler, "t_base", *v8, 0, 0xFFFFFFFF, 0, 1.0);
  }
  v10 = vostok::configs::binary_config_value::operator[](config, "constant_emissive_multiplier");
  v11 = vostok::configs::binary_config_value::operator[](v10, "value");
  if ( v11->type == 2 )
    pointer = *(float *)&v11->data.pointer;
  else
    pointer = (float)(int)v11->data.pointer;
  *((float *)&v34 + 1) = pointer;
  v13 = vostok::configs::binary_config_value::operator[](config, "constant_emissive");
  v14 = vostok::configs::binary_config_value::operator[](v13, "value");
  v15 = (float *)v14->data.pointer;
  v16 = *(float *)v14->data.pointer;
  __libm_sse2_pow(v30, v34);
  *(float *)&v16 = v16;
  v42.x = *(float *)&v16;
  v17 = v15[1];
  __libm_sse2_pow(v31, v34);
  *(float *)&v17 = v17;
  v42.y = *(float *)&v17;
  v18 = v15[2];
  __libm_sse2_pow(v32, v34);
  v39 = *(_QWORD *)&v42.x;
  *(float *)&v18 = v18;
  v40 = LODWORD(v18);
  v41 = HIDWORD(v34);
  *(_QWORD *)&v42.elements[2] = __PAIR64__(HIDWORD(v34), LODWORD(v18));
  if ( (v36 & 1) != 0 )
  {
    v20 = vostok::configs::binary_config_value::operator[](config, "texture_transparency");
    v21 = (char **)vostok::configs::binary_config_value::operator[](v20, "value");
    vostok::render::effect_compiler::set_texture(
      v22,
      (const char *)compiler,
      "t_transparency",
      *v21,
      0,
      0xFFFFFFFF,
      0,
      1.0);
  }
  if ( vostok::configs::binary_config_value::value_exists(v19, (int)config, (unsigned int)"constant_transparency") )
  {
    v24 = vostok::configs::binary_config_value::operator[](config, "constant_transparency");
    v25 = vostok::configs::binary_config_value::operator[](v24, "value");
    if ( v25->type == 2 )
      v26 = *(float *)&v25->data.pointer;
    else
      v26 = (float)(int)v25->data.pointer;
  }
  else
  {
    v26 = s_bm_current_air_resistance;
  }
  *((float *)&v34 + 1) = v26;
  vostok::render::effect_compiler::set_constant<float>(v23, (float *)&v34 + 1, compiler, "solid_transparency");
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v42, v27, compiler, "solid_color_specular");
  vostok::render::effect_material_base::compile_end(v28, compiler);
}
