void __thiscall vostok::render::effect_offscreen_particle_lighting_materials::compile(
        vostok::render::effect_offscreen_particle_lighting_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // esi
  vostok::configs::binary_config_value *v5; // eax
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
  bool v17; // al
  vostok::configs::binary_config_value *v18; // ecx
  vostok::configs::binary_config_value *v19; // eax
  char v20; // al
  vostok::configs::binary_config_value *v21; // eax
  char **v22; // eax
  vostok::render::effect_compiler *v23; // ecx
  vostok::configs::binary_config_value *v24; // eax
  const vostok::configs::binary_config_value *v25; // eax
  float *pointer; // esi
  double v27; // xmm0_8
  double v28; // xmm0_8
  double v29; // xmm0_8
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::configs::binary_config_value *v32; // ecx
  vostok::configs::binary_config_value *v33; // eax
  char **v34; // eax
  vostok::render::effect_compiler *v35; // ecx
  vostok::configs::binary_config_value *v36; // eax
  const vostok::configs::binary_config_value *v37; // eax
  _DWORD *v38; // esi
  vostok::configs::binary_config_value *v39; // eax
  const vostok::configs::binary_config_value *v40; // eax
  _DWORD *v41; // esi
  vostok::configs::binary_config_value *v42; // eax
  const vostok::configs::binary_config_value *v43; // eax
  float v44; // xmm0_4
  vostok::configs::binary_config_value *v45; // eax
  const vostok::configs::binary_config_value *v46; // eax
  vostok::render::effect_constant_storage *v47; // ecx
  float v48; // xmm0_4
  vostok::render::effect_constant_storage *v49; // ecx
  vostok::render::effect_constant_storage *v50; // ecx
  vostok::configs::binary_config_value *v51; // eax
  char **v52; // eax
  vostok::render::effect_compiler *v53; // ecx
  vostok::configs::binary_config_value *v54; // ecx
  vostok::configs::binary_config_value *v55; // eax
  char **v56; // eax
  vostok::render::effect_compiler *v57; // ecx
  vostok::render::effect_constant_storage *v58; // ecx
  vostok::configs::binary_config_value *v59; // eax
  const vostok::configs::binary_config_value *v60; // eax
  float v61; // xmm0_4
  vostok::render::effect_constant_storage *v62; // ecx
  vostok::render::effect_constant_storage *v63; // ecx
  vostok::render::effect_compiler *v64; // ecx
  vostok::render::effect_compiler *v65; // ecx
  vostok::render::effect_compiler *v66; // ecx
  vostok::render::effect_compiler *v67; // ecx
  vostok::render::effect_material_base *v68; // ecx
  vostok::render::shader_configuration *v69; // [esp+4h] [ebp-88h]
  long double v70; // [esp+4h] [ebp-88h]
  long double v71; // [esp+4h] [ebp-88h]
  long double v72; // [esp+4h] [ebp-88h]
  D3D11_COMPARISON_FUNC v73; // [esp+4h] [ebp-88h]
  D3D11_BLEND_OP v74; // [esp+4h] [ebp-88h]
  const vostok::configs::binary_config_value *v75; // [esp+8h] [ebp-84h]
  long double v76; // [esp+Ch] [ebp-80h]
  long double v77; // [esp+Ch] [ebp-80h]
  long double v78; // [esp+Ch] [ebp-80h]
  int v79; // [esp+14h] [ebp-78h]
  float v80; // [esp+18h] [ebp-74h] BYREF
  float v81; // [esp+1Ch] [ebp-70h] BYREF
  float v82; // [esp+20h] [ebp-6Ch] BYREF
  __int64 v83; // [esp+24h] [ebp-68h]
  int v84; // [esp+2Ch] [ebp-60h]
  __int64 v85; // [esp+30h] [ebp-5Ch]
  int v86; // [esp+38h] [ebp-54h]
  int v87; // [esp+3Ch] [ebp-50h] BYREF
  int v88; // [esp+40h] [ebp-4Ch]
  int v89; // [esp+44h] [ebp-48h]
  int v90; // [esp+48h] [ebp-44h]
  __int64 v91; // [esp+4Ch] [ebp-40h]
  int v92; // [esp+54h] [ebp-38h]
  int v93; // [esp+58h] [ebp-34h]
  vostok::math::float4 v94; // [esp+5Ch] [ebp-30h] BYREF
  vostok::math::float4 v95; // [esp+6Ch] [ebp-20h] BYREF
  vostok::math::float4 v96; // [esp+7Ch] [ebp-10h] BYREF

  v4 = config;
  v89 = 0x80000;
  v87 = 0;
  v88 = 0;
  v90 = 0;
  v5 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
  HIBYTE(v76) = vostok::configs::binary_config_value::operator[](v5, "value")->data.pointer != 0;
  v6 = vostok::configs::binary_config_value::operator[](config, "use_nmap");
  BYTE2(v87) = 8
             * (HIBYTE(v76) & 1
              | (16 * (vostok::configs::binary_config_value::operator[](v6, "value")->data.pointer != 0)));
  v7 = vostok::configs::binary_config_value::operator[](config, "use_ttransparency");
  LOBYTE(v88) = vostok::configs::binary_config_value::operator[](v7, "value")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v8, (int)config, (unsigned int)"use_soft_edges") )
  {
    v10 = vostok::configs::binary_config_value::operator[](config, "use_soft_edges");
    v11 = vostok::configs::binary_config_value::operator[](v10, "value")->data.pointer != 0;
  }
  else
  {
    v11 = 0;
  }
  LOBYTE(v9) = v90 & 0x7F;
  LOBYTE(v90) = v90 & 0x7F | (v11 << 7);
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)config, (unsigned int)"use_uv_distortion") )
  {
    v13 = vostok::configs::binary_config_value::operator[](config, "use_uv_distortion");
    v14 = vostok::configs::binary_config_value::operator[](v13, "value")->data.pointer != 0;
  }
  else
  {
    v14 = 0;
  }
  LOBYTE(v88) = (v88 ^ (2 * v14)) & 2 ^ v88;
  if ( vostok::configs::binary_config_value::value_exists(v12, (int)config, (unsigned int)"fresnel_attenuation") )
  {
    v16 = vostok::configs::binary_config_value::operator[](config, "fresnel_attenuation");
    v17 = vostok::configs::binary_config_value::operator[](v16, "value")->data.pointer != 0;
  }
  else
  {
    v17 = 0;
  }
  LOBYTE(v88) = (v88 ^ (8 * v17)) & 8 ^ v88;
  if ( vostok::configs::binary_config_value::value_exists(v15, (int)config, (unsigned int)"is_anisotropic_material") )
  {
    v19 = vostok::configs::binary_config_value::operator[](config, "is_anisotropic_material");
    v20 = vostok::configs::binary_config_value::operator[](v19, "value")->data.pointer != 0;
  }
  else
  {
    v20 = 0;
  }
  memset(&v95, 0, sizeof(v95));
  LOBYTE(v89) = (v89 ^ (v20 << 6)) & 0x40 ^ v89;
  v79 = 0;
  while ( 1 )
  {
    BYTE1(v88) ^= (v79 ^ BYTE1(v88)) & 0xF;
    vostok::render::effect_material_base::compile_begin(
      parameters,
      v18,
      (vostok::render::effect_material_base *)"vertex_base_offscreen_particle_lighting",
      "offscreen_particle_lighting",
      compiler,
      (const char *)&v87,
      v4,
      v69,
      v75);
    if ( (v87 & 0x80000) != 0 )
    {
      v21 = vostok::configs::binary_config_value::operator[](v4, "texture_diffuse");
      v22 = (char **)vostok::configs::binary_config_value::operator[](v21, "value");
      vostok::render::effect_compiler::set_texture(v23, (const char *)compiler, "t_base", *v22, 0, 0xFFFFFFFF, 0, 1.0);
    }
    v24 = vostok::configs::binary_config_value::operator[](v4, "constant_diffuse");
    v25 = vostok::configs::binary_config_value::operator[](v24, "value");
    pointer = (float *)v25->data.pointer;
    v27 = *(float *)v25->data.pointer;
    __libm_sse2_pow(v70, v76);
    *(float *)&v27 = v27;
    LODWORD(v91) = LODWORD(v27);
    v28 = pointer[1];
    __libm_sse2_pow(v71, v77);
    *(float *)&v28 = v28;
    HIDWORD(v91) = LODWORD(v28);
    v29 = pointer[2];
    __libm_sse2_pow(v72, v78);
    *(float *)&v29 = v29;
    v92 = LODWORD(v29);
    v93 = *((_DWORD *)pointer + 3);
    *(_QWORD *)&v96.x = v91;
    *(_QWORD *)&v96.elements[2] = LODWORD(v29);
    vostok::render::effect_compiler::set_depth(v30, (int)compiler, 0, 0, v73);
    vostok::render::effect_compiler::set_alpha_blend(
      v31,
      (int)compiler,
      1,
      D3D11_BLEND_SRC_ALPHA,
      D3D11_BLEND_INV_SRC_ALPHA,
      D3D11_BLEND_OP_ADD,
      D3D11_BLEND_ZERO,
      D3D11_BLEND_INV_SRC_ALPHA,
      v74);
    if ( (v88 & 2) != 0
      && vostok::configs::binary_config_value::value_exists(v32, (int)config, (unsigned int)"uv_distortion_texture")
      && vostok::configs::binary_config_value::value_exists(v32, (int)config, (unsigned int)"uv_distortion_multiplier")
      && vostok::configs::binary_config_value::value_exists(
           v32,
           (int)config,
           (unsigned int)"distortion_1_moving_direction")
      && vostok::configs::binary_config_value::value_exists(
           v32,
           (int)config,
           (unsigned int)"distortion_2_moving_direction")
      && vostok::configs::binary_config_value::value_exists(v32, (int)config, (unsigned int)"uv_distortion_tile") )
    {
      v33 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_texture");
      v34 = (char **)vostok::configs::binary_config_value::operator[](v33, "value");
      vostok::render::effect_compiler::set_texture(
        v35,
        (const char *)compiler,
        "t_uv_distortion",
        *v34,
        0,
        0xFFFFFFFF,
        0,
        1.0);
      v36 = vostok::configs::binary_config_value::operator[](config, "distortion_1_moving_direction");
      v37 = vostok::configs::binary_config_value::operator[](v36, "value");
      v38 = v37->data.pointer;
      LODWORD(v83) = *(_DWORD *)v37->data.pointer;
      HIDWORD(v83) = *++v38;
      v84 = v38[1];
      v39 = vostok::configs::binary_config_value::operator[](config, "distortion_2_moving_direction");
      v40 = vostok::configs::binary_config_value::operator[](v39, "value");
      v41 = v40->data.pointer;
      LODWORD(v85) = *(_DWORD *)v40->data.pointer;
      HIDWORD(v85) = *++v41;
      v86 = v41[1];
      v42 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_multiplier");
      v43 = vostok::configs::binary_config_value::operator[](v42, "value");
      if ( v43->type == 2 )
        v44 = *(float *)&v43->data.pointer;
      else
        v44 = (float)(int)v43->data.pointer;
      v80 = v44;
      v45 = vostok::configs::binary_config_value::operator[](config, "uv_distortion_tile");
      v46 = vostok::configs::binary_config_value::operator[](v45, "value");
      if ( v46->type == 2 )
        v48 = *(float *)&v46->data.pointer;
      else
        v48 = (float)(int)v46->data.pointer;
      v81 = v48;
      *(_QWORD *)&v94.x = v83;
      *(_QWORD *)&v94.elements[2] = v85;
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v94, v47, compiler, "uv_distortion_movement");
      vostok::render::effect_compiler::set_constant<float>(v49, &v80, compiler, "uv_distortion_multiplier");
      vostok::render::effect_compiler::set_constant<float>(v50, &v81, compiler, "uv_distortion_tile");
    }
    if ( (v87 & 0x800000) != 0 )
    {
      v51 = vostok::configs::binary_config_value::operator[](config, "texture_normal");
      v52 = (char **)vostok::configs::binary_config_value::operator[](v51, "value");
      vostok::render::effect_compiler::set_texture(v53, (const char *)compiler, "t_normal", *v52, 0, 0xFFFFFFFF, 0, 1.0);
    }
    vostok::render::effect_compiler::set_texture(
      (vostok::render::effect_compiler *)v32,
      (const char *)compiler,
      "t_position",
      "$user$position",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    if ( (v88 & 1) != 0 )
    {
      v55 = vostok::configs::binary_config_value::operator[](config, "texture_transparency");
      v56 = (char **)vostok::configs::binary_config_value::operator[](v55, "value");
      vostok::render::effect_compiler::set_texture(
        v57,
        (const char *)compiler,
        "t_transparency",
        *v56,
        0,
        0xFFFFFFFF,
        0,
        1.0);
    }
    if ( vostok::configs::binary_config_value::value_exists(v54, (int)config, (unsigned int)"constant_transparency") )
    {
      v59 = vostok::configs::binary_config_value::operator[](config, "constant_transparency");
      v60 = vostok::configs::binary_config_value::operator[](v59, "value");
      v61 = v60->type == 2 ? *(float *)&v60->data.pointer : (float)(int)v60->data.pointer;
    }
    else
    {
      v61 = s_bm_current_air_resistance;
    }
    v82 = v61;
    vostok::render::effect_compiler::set_constant<float>(v58, &v82, compiler, "solid_transparency");
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v96, v62, compiler, "solid_color_specular");
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v95, v63, compiler, "solid_material_params");
    vostok::render::effect_compiler::set_texture(
      v64,
      (const char *)compiler,
      "t_cascaded_shadow_map0",
      "$user$cascaded_shadow_map0",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v65,
      (const char *)compiler,
      "t_cascaded_shadow_map1",
      "$user$cascaded_shadow_map1",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v66,
      (const char *)compiler,
      "t_cascaded_shadow_map2",
      "$user$cascaded_shadow_map2",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v67,
      (const char *)compiler,
      "t_cascaded_shadow_map3",
      "$user$cascaded_shadow_map3",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_material_base::compile_end(v68, compiler);
    if ( (unsigned int)++v79 >= 4 )
      break;
    v4 = config;
  }
}
