void __thiscall vostok::render::effect_fstage_fake_translucency_materials::compile(
        vostok::render::effect_fstage_fake_translucency_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // eax
  char **v5; // eax
  vostok::render::effect_compiler *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::configs::binary_config_value *v9; // eax
  char **v10; // eax
  vostok::render::effect_compiler *v11; // ecx
  vostok::configs::binary_config_value *v12; // ecx
  vostok::configs::binary_config_value *v13; // ecx
  vostok::configs::binary_config_value *v14; // eax
  const vostok::configs::binary_config_value *v15; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v17; // ecx
  vostok::configs::binary_config_value *v18; // eax
  const vostok::configs::binary_config_value *v19; // eax
  float v20; // xmm0_4
  vostok::configs::binary_config_value *v21; // ecx
  vostok::configs::binary_config_value *v22; // eax
  const vostok::configs::binary_config_value *v23; // eax
  float v24; // xmm0_4
  vostok::render::effect_constant_storage *v25; // ecx
  vostok::configs::binary_config_value *v26; // eax
  const vostok::configs::binary_config_value *v27; // eax
  _DWORD *v28; // esi
  double v29; // xmm0_8
  double v30; // xmm0_8
  double v31; // xmm0_8
  vostok::render::effect_constant_storage *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::command_line::key *v35; // ecx
  vostok::render::effect_material_base *v36; // ecx
  vostok::render::shader_configuration *v37; // [esp+4h] [ebp-50h]
  long double v38; // [esp+4h] [ebp-50h]
  long double v39; // [esp+4h] [ebp-50h]
  long double v40; // [esp+4h] [ebp-50h]
  D3D11_BLEND_OP v41; // [esp+4h] [ebp-50h]
  const vostok::configs::binary_config_value *v42; // [esp+8h] [ebp-4Ch]
  long double v43; // [esp+Ch] [ebp-48h]
  long double v44; // [esp+Ch] [ebp-48h]
  long double v45; // [esp+Ch] [ebp-48h]
  vostok::math::float4 v46; // [esp+14h] [ebp-40h] BYREF
  vostok::math::float4 v47; // [esp+24h] [ebp-30h] BYREF
  float v48; // [esp+34h] [ebp-20h]
  float v49; // [esp+38h] [ebp-1Ch]
  float v50; // [esp+3Ch] [ebp-18h]
  unsigned int v51; // [esp+40h] [ebp-14h]
  __int64 v52; // [esp+44h] [ebp-10h]
  int v53; // [esp+4Ch] [ebp-8h]
  unsigned int v54; // [esp+50h] [ebp-4h]

  *(_QWORD *)&v46.elements[2] = 0x80000;
  *(_QWORD *)&v46.x = 0x200000000000000LL;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    (const char *)&stru_812620,
    compiler,
    (const char *)&v46,
    config,
    v37,
    v42);
  v4 = vostok::configs::binary_config_value::operator[](config, "texture_translucency");
  v5 = (char **)vostok::configs::binary_config_value::operator[](v4, "value");
  vostok::render::effect_compiler::set_texture(v6, (const char *)compiler, "t_translucency", *v5, 0, 0xFFFFFFFF, 0, 1.0);
  if ( vostok::configs::binary_config_value::value_exists(v7, (int)config, (unsigned int)"texture_diffuse") )
  {
    v9 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v10 = (char **)vostok::configs::binary_config_value::operator[](v9, "value");
    vostok::render::effect_compiler::set_texture(v11, (const char *)compiler, "t_diffuse", *v10, 0, 0xFFFFFFFF, 0, 1.0);
  }
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_sun_shadow_and_scattering",
    "$user$sun_shadow_and_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  v46.x = s_bm_current_air_resistance;
  *(_QWORD *)&v46.elements[1] = LODWORD(s_bm_current_air_resistance);
  v46.w = 0.0;
  memset(&v47, 0, sizeof(v47));
  if ( vostok::configs::binary_config_value::value_exists(
         v12,
         (int)config,
         (unsigned int)"constant_translucency_multiplier") )
  {
    v14 = vostok::configs::binary_config_value::operator[](config, "constant_translucency_multiplier");
    v15 = vostok::configs::binary_config_value::operator[](v14, "value");
    if ( v15->type == 2 )
      pointer = *(float *)&v15->data.pointer;
    else
      pointer = (float)(int)v15->data.pointer;
    v46.x = pointer;
  }
  if ( vostok::configs::binary_config_value::value_exists(v13, (int)config, (unsigned int)"constant_translucency_power") )
  {
    v18 = vostok::configs::binary_config_value::operator[](config, "constant_translucency_power");
    v19 = vostok::configs::binary_config_value::operator[](v18, "value");
    if ( v19->type == 2 )
      v20 = *(float *)&v19->data.pointer;
    else
      v20 = (float)(int)v19->data.pointer;
    v46.y = v20;
  }
  if ( vostok::configs::binary_config_value::value_exists(
         v17,
         (int)config,
         (unsigned int)"constant_translucency_distortion") )
  {
    v22 = vostok::configs::binary_config_value::operator[](config, "constant_translucency_distortion");
    v23 = vostok::configs::binary_config_value::operator[](v22, "value");
    if ( v23->type == 2 )
      v24 = *(float *)&v23->data.pointer;
    else
      v24 = (float)(int)v23->data.pointer;
    v46.z = v24;
  }
  if ( vostok::configs::binary_config_value::value_exists(v21, (int)config, (unsigned int)"constant_ramp_color") )
  {
    v26 = vostok::configs::binary_config_value::operator[](config, "constant_ramp_color");
    v27 = vostok::configs::binary_config_value::operator[](v26, "value");
    v28 = v27->data.pointer;
    v48 = *(float *)v27->data.pointer;
    v49 = *(float *)++v28;
    v50 = *(float *)++v28;
    v51 = v28[1];
    v29 = v48;
    __libm_sse2_pow(v38, v43);
    *(float *)&v29 = v29;
    LODWORD(v52) = LODWORD(v29);
    v30 = v49;
    __libm_sse2_pow(v39, v44);
    *(float *)&v30 = v30;
    HIDWORD(v52) = LODWORD(v30);
    v31 = v50;
    __libm_sse2_pow(v40, v45);
    *(float *)&v31 = v31;
    v53 = LODWORD(v31);
    v54 = v51;
    *(_QWORD *)&v47.x = v52;
    *(_QWORD *)&v47.elements[2] = __PAIR64__(v51, LODWORD(v31));
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v46, v25, compiler, "translucency_parameters");
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v47, v32, compiler, "translucency_ramp_color");
  vostok::render::effect_compiler::set_depth(v33, (int)compiler, 1, 0, SLODWORD(v38));
  vostok::render::effect_compiler::set_alpha_blend(
    v34,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v41);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v35);
  vostok::render::effect_material_base::compile_end(v36, compiler);
}
