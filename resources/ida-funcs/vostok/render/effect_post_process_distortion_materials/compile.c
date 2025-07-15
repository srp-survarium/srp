void __thiscall vostok::render::effect_post_process_distortion_materials::compile(
        vostok::render::effect_post_process_distortion_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // eax
  const vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // ecx
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v8; // eax
  char **v9; // eax
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_constant_storage *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_material_base *v14; // ecx
  vostok::render::shader_configuration *v15; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v16; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v17; // [esp+4h] [ebp-20h]
  const vostok::configs::binary_config_value *v18; // [esp+8h] [ebp-1Ch]
  float v19; // [esp+10h] [ebp-14h] BYREF
  _DWORD v20[4]; // [esp+14h] [ebp-10h] BYREF

  v4 = vostok::configs::binary_config_value::operator[](config, "constant_distortion_scale");
  v5 = vostok::configs::binary_config_value::operator[](v4, "value");
  if ( v5->type == 2 )
    pointer = *(float *)&v5->data.pointer;
  else
    pointer = (float)(int)v5->data.pointer;
  v20[2] = 0x80000;
  v19 = pointer;
  v20[0] = 0;
  v20[1] = 0;
  v20[3] = 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v6,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    (const char *)&stru_812598,
    compiler,
    (const char *)v20,
    config,
    v15,
    v18);
  v8 = vostok::configs::binary_config_value::operator[](config, "texture_base");
  v9 = (char **)vostok::configs::binary_config_value::operator[](v8, "value");
  vostok::render::effect_compiler::set_texture(v10, (const char *)compiler, "t_base", *v9, 0, 0xFFFFFFFF, 0, 1.0);
  vostok::render::effect_compiler::set_constant<float>(v11, &v19, compiler, "distortion_scale");
  vostok::render::effect_compiler::set_depth(v12, (int)compiler, 1, 0, v16);
  vostok::render::effect_compiler::set_alpha_blend(
    v13,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v17);
  vostok::render::effect_material_base::compile_end(v14, compiler);
}
