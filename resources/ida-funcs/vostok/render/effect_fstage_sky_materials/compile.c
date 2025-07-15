void __thiscall vostok::render::effect_fstage_sky_materials::compile(
        vostok::render::effect_fstage_sky_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // eax
  const vostok::configs::binary_config_value *v5; // eax
  float *pointer; // edi
  double v7; // xmm0_8
  double v8; // xmm0_8
  double v9; // xmm0_8
  vostok::configs::binary_config_value *v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  vostok::render::effect_constant_storage *v12; // ecx
  float v13; // xmm1_4
  vostok::configs::binary_config_value *v14; // eax
  char **v15; // eax
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::command_line::key *v20; // ecx
  vostok::configs::binary_config_value *v21; // ecx
  vostok::configs::binary_config_value *v22; // ecx
  vostok::configs::binary_config_value *v23; // eax
  const vostok::configs::binary_config_value *v24; // eax
  float v25; // xmm0_4
  vostok::configs::binary_config_value *v26; // eax
  const vostok::configs::binary_config_value *v27; // eax
  float v28; // xmm0_4
  vostok::render::effect_material_base *v29; // ecx
  vostok::render::shader_configuration *v30; // [esp+4h] [ebp-20h]
  long double v31; // [esp+4h] [ebp-20h]
  long double v32; // [esp+4h] [ebp-20h]
  long double v33; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v34; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v35; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v36; // [esp+4h] [ebp-20h]
  const vostok::configs::binary_config_value *v37; // [esp+8h] [ebp-1Ch]
  long double v38; // [esp+Ch] [ebp-18h]
  long double v39; // [esp+Ch] [ebp-18h]
  long double v40; // [esp+Ch] [ebp-18h]
  float v41; // [esp+10h] [ebp-14h]
  vostok::math::float4 v42; // [esp+14h] [ebp-10h] BYREF

  *(_QWORD *)&v42.elements[2] = 0x80000;
  *(_QWORD *)&v42.x = 0x200000000000000LL;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)&stru_80B4E8,
    (const char *)&stru_80B4E8,
    compiler,
    (const char *)&v42,
    config,
    v30,
    v37);
  v4 = vostok::configs::binary_config_value::operator[](config, "sky_color");
  v5 = vostok::configs::binary_config_value::operator[](v4, "value");
  pointer = (float *)v5->data.pointer;
  v7 = *(float *)v5->data.pointer;
  __libm_sse2_pow(v31, v38);
  *(float *)&v7 = v7;
  v42.x = *(float *)&v7;
  v8 = pointer[1];
  __libm_sse2_pow(v32, v39);
  *(float *)&v8 = v8;
  v42.y = *(float *)&v8;
  v9 = pointer[2];
  __libm_sse2_pow(v33, v40);
  *(float *)&v9 = v9;
  v42.z = *(float *)&v9;
  v42.w = pointer[3];
  v10 = vostok::configs::binary_config_value::operator[](config, "sky_color_multiplier");
  v11 = vostok::configs::binary_config_value::operator[](v10, "value");
  if ( v11->type == 2 )
    v13 = *(float *)&v11->data.pointer;
  else
    v13 = (float)(int)v11->data.pointer;
  v42.x = v42.x * v13;
  v42.y = v42.y * v13;
  v42.z = v42.z * v13;
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v42, v12, compiler, "sky_color");
  v14 = vostok::configs::binary_config_value::operator[](config, "texture_emissive");
  v15 = (char **)vostok::configs::binary_config_value::operator[](v14, "value");
  vostok::render::effect_compiler::set_texture(v16, (const char *)compiler, "t_base", *v15, 0, 0xFFFFFFFF, 0, 1.0);
  vostok::render::effect_compiler::set_depth(v17, (int)compiler, 0, 0, v34);
  vostok::render::effect_compiler::set_alpha_blend(
    v18,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_SRC_COLOR,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v35);
  vostok::render::effect_compiler::set_stencil(
    v19,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v36);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v20);
  if ( vostok::configs::binary_config_value::value_exists(v21, (int)config, (unsigned int)"sky_fog_power")
    && vostok::configs::binary_config_value::value_exists(v22, (int)config, (unsigned int)"sky_fog_up_limit") )
  {
    v23 = vostok::configs::binary_config_value::operator[](config, "sky_fog_power");
    v24 = vostok::configs::binary_config_value::operator[](v23, "value");
    if ( v24->type == 2 )
      v25 = *(float *)&v24->data.pointer;
    else
      v25 = (float)(int)v24->data.pointer;
    v41 = v25;
    v26 = vostok::configs::binary_config_value::operator[](config, "sky_fog_up_limit");
    v27 = vostok::configs::binary_config_value::operator[](v26, "value");
    if ( v27->type == 2 )
      v28 = *(float *)&v27->data.pointer;
    else
      v28 = (float)(int)v27->data.pointer;
    v42.x = v41;
  }
  else
  {
    v42.x = s_bm_current_air_resistance;
    v28 = FLOAT_0_25;
  }
  *(_QWORD *)&v42.elements[1] = LODWORD(v28);
  v42.w = 0.0;
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v42,
    (vostok::render::effect_constant_storage *)v22,
    compiler,
    "fog_power_and_range");
  vostok::render::effect_material_base::compile_end(v29, compiler);
}
