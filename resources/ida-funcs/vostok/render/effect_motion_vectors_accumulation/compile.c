void __thiscall vostok::render::effect_motion_vectors_accumulation::compile(
        vostok::render::effect_motion_vectors_accumulation *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // eax
  bool v6; // al
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // eax
  bool v9; // al
  vostok::render::effect_compiler *v10; // ecx
  vostok::configs::binary_config_value *v11; // ecx
  vostok::configs::binary_config_value *v12; // eax
  char **v13; // eax
  vostok::render::effect_compiler *v14; // ecx
  vostok::configs::binary_config_value *v15; // eax
  const vostok::configs::binary_config_value *v16; // eax
  float pointer; // xmm0_4
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_material_base *v19; // ecx
  vostok::render::shader_configuration *v20; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v21; // [esp+4h] [ebp-20h]
  const vostok::configs::binary_config_value *v22; // [esp+8h] [ebp-1Ch]
  float v23; // [esp+10h] [ebp-14h] BYREF
  _DWORD v24[4]; // [esp+14h] [ebp-10h] BYREF

  v24[2] = 0x80000;
  v24[0] = 0;
  v24[1] = 0;
  v24[3] = 0;
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)this,
         (int)config,
         (unsigned int)"use_alpha_test") )
  {
    v5 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
    v6 = vostok::configs::binary_config_value::operator[](v5, "value")->data.pointer != 0;
  }
  else
  {
    v6 = 0;
  }
  BYTE2(v24[0]) = 16 * v6;
  if ( vostok::configs::binary_config_value::value_exists(v4, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v8 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v9 = vostok::configs::binary_config_value::operator[](v8, "value")->data.pointer != 0;
  }
  else
  {
    v9 = 0;
  }
  BYTE2(v24[0]) ^= (BYTE2(v24[0]) ^ (8 * v9)) & 8;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v7,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "motion_vectors_accumulation",
    compiler,
    (const char *)v24,
    config,
    v20,
    v22);
  vostok::render::effect_compiler::set_depth(v10, (int)compiler, 1, 0, v21);
  v23 = FLOAT_0_25;
  if ( (v24[0] & 0x80000) != 0 )
  {
    v12 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v13 = (char **)vostok::configs::binary_config_value::operator[](v12, "value");
    vostok::render::effect_compiler::set_texture(v14, (const char *)compiler, "t_base", *v13, 0, 0xFFFFFFFF, 0, 1.0);
  }
  if ( (v24[0] & 0x100000) != 0
    && vostok::configs::binary_config_value::value_exists(v11, (int)config, (unsigned int)"alpha_ref") )
  {
    v15 = vostok::configs::binary_config_value::operator[](config, "alpha_ref");
    v16 = vostok::configs::binary_config_value::operator[](v15, "value");
    if ( v16->type == 2 )
      pointer = *(float *)&v16->data.pointer;
    else
      pointer = (float)(int)v16->data.pointer;
    v23 = pointer;
  }
  vostok::render::effect_compiler::set_constant<float>(
    (vostok::render::effect_constant_storage *)v11,
    &v23,
    compiler,
    "alpha_ref_parameter");
  vostok::render::effect_compiler::color_write_enable(
    v18,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_material_base::compile_end(v19, compiler);
}
