void __thiscall vostok::render::effect_sky_sphere_default_materials::compile(
        vostok::render::effect_sky_sphere_default_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::configs::binary_config_value *v5; // eax
  char **v6; // eax
  vostok::render::effect_compiler *v7; // ecx
  vostok::command_line::key *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  __m128i pointer; // xmm0
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::command_line::key *v17; // ecx
  vostok::configs::binary_config_value *v18; // eax
  char **v19; // eax
  vostok::render::effect_compiler *v20; // ecx
  vostok::configs::binary_config_value *v21; // ecx
  vostok::render::effect_constant_storage *v22; // ecx
  vostok::configs::binary_config_value *v23; // eax
  const vostok::configs::binary_config_value *v24; // eax
  vostok::render::effect_constant_storage *v25; // ecx
  vostok::configs::binary_config_value *v26; // ecx
  vostok::configs::binary_config_value *v27; // ecx
  vostok::configs::binary_config_value *v28; // eax
  const vostok::configs::binary_config_value *v29; // eax
  float v30; // xmm0_4
  vostok::configs::binary_config_value *v31; // eax
  const vostok::configs::binary_config_value *v32; // eax
  float v33; // xmm0_4
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::shader_configuration v36; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v37; // [esp-10h] [ebp-34h]
  long double v38; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v39; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v40; // [esp+4h] [ebp-20h]
  float v41; // [esp+10h] [ebp-14h]
  vostok::math::float4 v42; // [esp+14h] [ebp-10h] BYREF

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v36.0 = "sky_sphere_preview";
  *(_QWORD *)&v42.x = 0;
  *(_QWORD *)&v42.elements[2] = 0x80000;
  *(unsigned __int64 *)((char *)v36.configuration + 4) = 0;
  HIDWORD(v36.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, (char *)&stru_80E8FC, 0, v36, 0);
  v5 = vostok::configs::binary_config_value::operator[](config, "sky_texture");
  v6 = (char **)vostok::configs::binary_config_value::operator[](v5, "value");
  vostok::render::effect_compiler::set_texture(v7, (const char *)compiler, "t_sky_sphere", *v6, 0, 0xFFFFFFFF, 0, 1.0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v8);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v11, (int)compiler);
  *(_QWORD *)&v42.x = 0;
  *(unsigned __int64 *)((char *)v37.configuration + 4) = 0;
  *(_QWORD *)&v42.elements[2] = 0x80000;
  pointer = _mm_loadl_epi64((const __m128i *)&v42.elements[2]);
  HIDWORD(v37.configuration[1]) = pointer.m128i_i32[0];
  *(_DWORD *)&v37.0 = "sky_sphere";
  vostok::render::effect_compiler::begin_pass(
    v13,
    (int)compiler,
    "sky_sphere",
    0,
    v37,
    (vostok::render::shader_include_getter *)pointer.m128i_i32[1]);
  vostok::render::effect_compiler::set_depth(v14, (int)compiler, 0, 0, SLODWORD(v38));
  vostok::render::effect_compiler::set_stencil(
    v15,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v39);
  vostok::render::effect_compiler::set_alpha_blend(
    v16,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v40);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v17);
  v18 = vostok::configs::binary_config_value::operator[](config, "sky_texture");
  v19 = (char **)vostok::configs::binary_config_value::operator[](v18, "value");
  vostok::render::effect_compiler::set_texture(v20, (const char *)compiler, "t_sky_sphere", *v19, 0, 0xFFFFFFFF, 0, 1.0);
  if ( vostok::configs::binary_config_value::value_exists(v21, (int)config, (unsigned int)"sky_rotation") )
  {
    v23 = vostok::configs::binary_config_value::operator[](config, "sky_rotation");
    v24 = vostok::configs::binary_config_value::operator[](v23, "value");
    if ( v24->type == 2 )
      pointer = (__m128i)(unsigned int)v24->data.pointer;
    else
      *(float *)pointer.m128i_i32 = (float)(int)v24->data.pointer;
    __libm_sse2_cos(v38);
    v42.x = (float)(*(float *)pointer.m128i_i32 * 0.0055555557) * 3.1415927;
    *(double *)pointer.m128i_i64 = v42.x;
    __libm_sse2_sin(pointer);
    v42.y = v42.x;
    *(_QWORD *)&v42.elements[2] = 0;
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v42, v25, compiler, "sky_cos_sin");
  }
  else
  {
    *(_QWORD *)&v42.x = LODWORD(s_bm_current_air_resistance);
    *(_QWORD *)&v42.elements[2] = 0;
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v42, v22, compiler, "sky_cos_sin");
  }
  if ( vostok::configs::binary_config_value::value_exists(v26, (int)config, (unsigned int)"sky_fog_power")
    && vostok::configs::binary_config_value::value_exists(v27, (int)config, (unsigned int)"sky_fog_up_limit") )
  {
    v28 = vostok::configs::binary_config_value::operator[](config, "sky_fog_power");
    v29 = vostok::configs::binary_config_value::operator[](v28, "value");
    if ( v29->type == 2 )
      v30 = *(float *)&v29->data.pointer;
    else
      v30 = (float)(int)v29->data.pointer;
    v41 = v30;
    v31 = vostok::configs::binary_config_value::operator[](config, "sky_fog_up_limit");
    v32 = vostok::configs::binary_config_value::operator[](v31, "value");
    if ( v32->type == 2 )
      v33 = *(float *)&v32->data.pointer;
    else
      v33 = (float)(int)v32->data.pointer;
    v42.x = v41;
  }
  else
  {
    v42.x = s_bm_current_air_resistance;
    v33 = FLOAT_0_25;
  }
  v42.y = v33;
  *(_QWORD *)&v42.elements[2] = 0;
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    &v42,
    (vostok::render::effect_constant_storage *)v27,
    compiler,
    "fog_power_and_range");
  vostok::render::effect_compiler::end_pass(v34, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v35,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
