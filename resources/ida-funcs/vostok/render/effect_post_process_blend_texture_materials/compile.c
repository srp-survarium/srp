void __thiscall vostok::render::effect_post_process_blend_texture_materials::compile(
        vostok::render::effect_post_process_blend_texture_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // eax
  const vostok::configs::binary_config_value *v5; // eax
  float *pointer; // esi
  double v7; // xmm0_8
  double v8; // xmm0_8
  double v9; // xmm0_8
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::configs::binary_config_value *v12; // eax
  char **v13; // eax
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_constant_storage *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::shader_configuration v20; // [esp-10h] [ebp-44h]
  long double v21; // [esp+4h] [ebp-30h]
  long double v22; // [esp+4h] [ebp-30h]
  long double v23; // [esp+4h] [ebp-30h]
  D3D11_COMPARISON_FUNC v24; // [esp+4h] [ebp-30h]
  D3D11_BLEND_OP v25; // [esp+4h] [ebp-30h]
  long double v26; // [esp+Ch] [ebp-28h]
  long double v27; // [esp+Ch] [ebp-28h]
  long double v28; // [esp+Ch] [ebp-28h]
  __int64 v29; // [esp+1Ch] [ebp-18h]
  vostok::math::float4 v30; // [esp+24h] [ebp-10h] BYREF

  v4 = vostok::configs::binary_config_value::operator[](config, "constant_modulate_color");
  v5 = vostok::configs::binary_config_value::operator[](v4, "value");
  pointer = (float *)v5->data.pointer;
  v7 = *(float *)v5->data.pointer;
  __libm_sse2_pow(v21, v26);
  *(float *)&v7 = v7;
  v30.x = *(float *)&v7;
  v8 = pointer[1];
  __libm_sse2_pow(v22, v27);
  *(float *)&v8 = v8;
  v30.y = *(float *)&v8;
  v9 = pointer[2];
  __libm_sse2_pow(v23, v28);
  *(float *)&v9 = v9;
  v30.z = *(float *)&v9;
  v30.w = pointer[3];
  vostok::render::effect_compiler::begin_technique(v10, (int)compiler);
  *(_DWORD *)&v20.0 = "blend_texture";
  v29 = 0x80000;
  *(unsigned __int64 *)((char *)v20.configuration + 4) = 0;
  HIDWORD(v20.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v11, (int)compiler, "copy_image", 0, v20, 0);
  v12 = vostok::configs::binary_config_value::operator[](config, "texture_base");
  v13 = (char **)vostok::configs::binary_config_value::operator[](v12, "value");
  vostok::render::effect_compiler::set_texture(v14, (const char *)compiler, "t_base", *v13, 0, 0xFFFFFFFF, 0, 1.0);
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v30, v15, compiler, "modulate_color");
  vostok::render::effect_compiler::set_depth(v16, (int)compiler, 1, 0, v24);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v25);
  vostok::render::effect_compiler::end_pass(v18, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v19,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
