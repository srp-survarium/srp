void __thiscall vostok::render::effect_fstage_simpe_water_materials::compile(
        vostok::render::effect_fstage_simpe_water_materials *this,
        vostok::render::effect_compiler *compiler,
        vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  char *v4; // eax
  vostok::render::effect_compiler *v5; // esi
  vostok::configs::binary_config_value *v6; // eax
  char **v7; // eax
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::configs::binary_config_value *v15; // ecx
  vostok::render::effect_constant_storage *v16; // ecx
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
  vostok::configs::binary_config_value *v27; // ecx
  vostok::configs::binary_config_value *v28; // eax
  const vostok::configs::binary_config_value *v29; // eax
  float v30; // xmm0_4
  vostok::render::effect_constant_storage *v31; // ecx
  vostok::configs::binary_config_value *v32; // eax
  const vostok::configs::binary_config_value *v33; // eax
  float v34; // xmm0_4
  vostok::render::effect_constant_storage *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::render::effect_compiler *v37; // ecx
  vostok::render::effect_compiler *v38; // ecx
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::render::effect_compiler *v45; // ecx
  vostok::render::effect_compiler *v46; // ecx
  vostok::render::effect_compiler *v47; // ecx
  vostok::render::effect_material_base *v48; // ecx
  D3D11_BLEND v49; // [esp-10h] [ebp-74h]
  D3D11_BLEND v50; // [esp-Ch] [ebp-70h]
  long double v51; // [esp+4h] [ebp-60h]
  long double v52; // [esp+4h] [ebp-60h]
  long double v53; // [esp+4h] [ebp-60h]
  D3D11_BLEND_OP v54; // [esp+4h] [ebp-60h]
  long double v55; // [esp+Ch] [ebp-58h]
  long double v56; // [esp+Ch] [ebp-58h]
  long double v57; // [esp+Ch] [ebp-58h]
  unsigned int i; // [esp+14h] [ebp-50h]
  float v59; // [esp+18h] [ebp-4Ch]
  float v60; // [esp+1Ch] [ebp-48h] BYREF
  float v61; // [esp+20h] [ebp-44h] BYREF
  vostok::configs::binary_config_value v62; // [esp+24h] [ebp-40h] BYREF
  float v63; // [esp+3Ch] [ebp-28h]
  float v64; // [esp+40h] [ebp-24h]
  unsigned int v65; // [esp+44h] [ebp-20h]
  int v66; // [esp+48h] [ebp-1Ch]
  int v67; // [esp+4Ch] [ebp-18h]
  float v68; // [esp+50h] [ebp-14h]
  unsigned int v69; // [esp+54h] [ebp-10h]
  int v70; // [esp+58h] [ebp-Ch]

  v62.data.max_storage = 0x800000;
  v62.id.max_storage = 0x80000;
  for ( i = 0; i < 2; ++i )
  {
    v4 = "forward_water";
    if ( i )
      v4 = "forward_water_local_reflections";
    v5 = compiler;
    vostok::render::effect_material_base::compile_begin(
      parameters,
      &v62,
      (vostok::render::effect_material_base *)&stru_80E8FC,
      v4,
      (char *)compiler,
      (vostok::render::effect_compiler *)&v62,
      config,
      (const vostok::configs::binary_config_value *)LODWORD(v51));
    v6 = vostok::configs::binary_config_value::operator[](config, "texture_reflection");
    v7 = (char **)vostok::configs::binary_config_value::operator[](v6, "value");
    vostok::render::effect_compiler::set_texture(v8, (const char *)compiler, "t_reflection", *v7, 1, 2u, 0, 1.0);
    vostok::render::effect_compiler::set_texture(
      v9,
      (const char *)compiler,
      "t_normal_map",
      "engine/water_waves2",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v10,
      (const char *)compiler,
      "t_position",
      "$user$position",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v11,
      (const char *)compiler,
      "t_normal",
      "$user$normal",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v12,
      (const char *)compiler,
      "t_parameters",
      "$user$surface_parameters",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v13,
      (const char *)compiler,
      "t_diffuse",
      "$user$albedo",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v14,
      (const char *)compiler,
      "t_frame_color",
      "$user$generic1",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    *(float *)&v62.id_crc = c_anim_center;
    *(float *)&v62.type = s_bm_current_air_resistance;
    v63 = c_anim_center;
    v64 = s_bm_current_air_resistance;
    if ( vostok::configs::binary_config_value::value_exists(v15, (int)config, (unsigned int)"water_fog_color") )
    {
      v17 = vostok::configs::binary_config_value::operator[](config, "wave_fog_density");
      v18 = vostok::configs::binary_config_value::operator[](v17, "value");
      if ( v18->type == 2 )
        pointer = *(float *)&v18->data.pointer;
      else
        pointer = (float)(int)v18->data.pointer;
      v59 = pointer;
      v20 = vostok::configs::binary_config_value::operator[](config, "water_fog_color");
      v21 = vostok::configs::binary_config_value::operator[](v20, "value");
      v22 = (float *)v21->data.pointer;
      v23 = *(float *)v21->data.pointer;
      __libm_sse2_pow(v51, v55);
      *(float *)&v23 = v23;
      v69 = LODWORD(v23);
      v24 = v22[1];
      __libm_sse2_pow(v52, v56);
      *(float *)&v24 = v24;
      v70 = LODWORD(v24);
      v25 = v22[2];
      __libm_sse2_pow(v53, v57);
      v65 = v69;
      *(float *)&v25 = v25;
      v67 = LODWORD(v25);
      v66 = v70;
      v68 = v59;
      v62.id_crc = v69;
      *(_DWORD *)&v62.type = v70;
      v63 = *(float *)&v25;
      v64 = v59;
      v5 = compiler;
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (const vostok::math::float4 *)&v62.id_crc,
      v16,
      v5,
      "packed_water_parameters_0");
    if ( vostok::configs::binary_config_value::value_exists(v26, (int)config, (unsigned int)"foam_intensity") )
    {
      v28 = vostok::configs::binary_config_value::operator[](config, "foam_intensity");
      v29 = vostok::configs::binary_config_value::operator[](v28, "value");
      if ( v29->type == 2 )
        v30 = *(float *)&v29->data.pointer;
      else
        v30 = (float)(int)v29->data.pointer;
    }
    else
    {
      v30 = s_bm_current_air_resistance;
    }
    v60 = v30;
    if ( vostok::configs::binary_config_value::value_exists(v27, (int)config, (unsigned int)"soft_intersection_factor") )
    {
      v32 = vostok::configs::binary_config_value::operator[](config, "soft_intersection_factor");
      v33 = vostok::configs::binary_config_value::operator[](v32, "value");
      if ( v33->type == 2 )
        v34 = *(float *)&v33->data.pointer;
      else
        v34 = (float)(int)v33->data.pointer;
    }
    else
    {
      v34 = c_anim_center;
    }
    v61 = v34;
    vostok::render::effect_compiler::set_constant<float>(v31, &v60, v5, "foam_intensity");
    vostok::render::effect_compiler::set_constant<float>(v35, &v61, v5, "soft_intersection_factor");
    vostok::render::effect_compiler::set_texture(
      v36,
      (const char *)v5,
      "t_rain_shadow_map",
      "$user$rain_shadow_map",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v37,
      (const char *)v5,
      "t_puddle_rings",
      "engine/rain_puddle_rings",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v38,
      (const char *)v5,
      "t_foam",
      "engine/water_foam",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v39,
      (const char *)v5,
      "t_diffuse_lighting",
      "$user$accum_diffuse",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v40,
      (const char *)v5,
      "t_cascaded_shadow_map0",
      "$user$cascaded_shadow_map0",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v41,
      (const char *)v5,
      "t_cascaded_shadow_map1",
      "$user$cascaded_shadow_map1",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v42,
      (const char *)v5,
      "t_cascaded_shadow_map2",
      "$user$cascaded_shadow_map2",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v43,
      (const char *)v5,
      "t_cascaded_shadow_map3",
      "$user$cascaded_shadow_map3",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    if ( i )
    {
      vostok::render::effect_compiler::set_depth(v44, (int)v5, 0, 0, SLODWORD(v51));
      v50 = D3D11_BLEND_ZERO;
      v49 = D3D11_BLEND_ONE;
    }
    else
    {
      vostok::render::effect_compiler::set_texture(
        v44,
        (const char *)v5,
        "t_local_reflections_result",
        "$user$local_reflection_result",
        0,
        0xFFFFFFFF,
        0,
        1.0);
      vostok::render::effect_compiler::set_texture(
        v45,
        (const char *)v5,
        "t_water_waves",
        "engine/water_waves",
        0,
        0xFFFFFFFF,
        0,
        1.0);
      vostok::render::effect_compiler::set_depth(v46, (int)v5, 1, 0, SLODWORD(v51));
      v50 = D3D11_BLEND_INV_SRC_ALPHA;
      v49 = D3D11_BLEND_SRC_ALPHA;
    }
    vostok::render::effect_compiler::set_alpha_blend(
      v47,
      (int)compiler,
      0,
      v49,
      v50,
      D3D11_BLEND_OP_ADD,
      D3D11_BLEND_ONE,
      D3D11_BLEND_ZERO,
      v54);
    vostok::render::effect_material_base::compile_end(v48, compiler);
  }
}
