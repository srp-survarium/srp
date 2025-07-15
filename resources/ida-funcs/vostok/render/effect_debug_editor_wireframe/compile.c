void __thiscall vostok::render::effect_debug_editor_wireframe::compile(
        vostok::render::effect_debug_editor_wireframe *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::configs::binary_config_value *v6; // eax
  vostok::configs::binary_config_value *v7; // eax
  const vostok::configs::binary_config_value *v8; // eax
  float *pointer; // edi
  double v10; // xmm0_8
  double v11; // xmm0_8
  double v12; // xmm0_8
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::command_line::key *v15; // ecx
  vostok::render::effect_constant_storage *v16; // ecx
  vostok::render::effect_constant_storage *v17; // ecx
  vostok::render::effect_material_base *v18; // ecx
  vostok::render::shader_configuration *v19; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v20; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v21; // [esp+4h] [ebp-20h]
  long double v22; // [esp+4h] [ebp-20h]
  long double v23; // [esp+4h] [ebp-20h]
  long double v24; // [esp+4h] [ebp-20h]
  const vostok::configs::binary_config_value *v25; // [esp+8h] [ebp-1Ch]
  long double v26; // [esp+Ch] [ebp-18h]
  long double v27; // [esp+Ch] [ebp-18h]
  long double v28; // [esp+Ch] [ebp-18h]
  unsigned int v29; // [esp+10h] [ebp-14h]
  vostok::math::float4 v30; // [esp+14h] [ebp-10h] BYREF

  v30.x = 0.0;
  *(_QWORD *)&v30.elements[1] = 0x8000000000000LL;
  v30.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "forward_base",
    compiler,
    (const char *)&v30,
    config,
    v19,
    v25);
  vostok::render::effect_compiler::set_depth(v4, (int)compiler, 1, 0, v20);
  vostok::render::effect_compiler::set_alpha_blend(
    v5,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v21);
  v6 = vostok::configs::binary_config_value::operator[](config, "draw_mode");
  HIDWORD(v26) = vostok::configs::binary_config_value::operator[](v6, "value")->data.pointer;
  v7 = vostok::configs::binary_config_value::operator[](config, "draw_color");
  v8 = vostok::configs::binary_config_value::operator[](v7, "value");
  pointer = (float *)v8->data.pointer;
  v10 = *(float *)v8->data.pointer;
  __libm_sse2_pow(v22, v26);
  *(float *)&v10 = v10;
  v30.x = *(float *)&v10;
  v11 = pointer[1];
  __libm_sse2_pow(v23, v27);
  *(float *)&v11 = v11;
  v30.y = *(float *)&v11;
  v12 = pointer[2];
  __libm_sse2_pow(v24, v28);
  *(float *)&v12 = v12;
  v30.z = *(float *)&v12;
  v30.w = pointer[3];
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_particle_lighting",
    "$user$particle_lighting",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( v29 > 1 )
    vostok::render::effect_compiler::set_fill_mode(
      compiler,
      (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
      v15);
  else
    vostok::render::effect_compiler::set_fill_mode(
      compiler,
      (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
      v15);
  vostok::render::effect_compiler::set_constant<float>(v16, &v30.w, compiler, "solid_transparency");
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v30, v17, compiler, "solid_color_specular");
  vostok::render::effect_material_base::compile_end(v18, compiler);
}
