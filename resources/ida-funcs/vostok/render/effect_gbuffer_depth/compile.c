void __thiscall vostok::render::effect_gbuffer_depth::compile(
        vostok::render::effect_gbuffer_depth *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_material_base *v6; // ecx
  vostok::render::shader_configuration *v7; // [esp+0h] [ebp-18h]
  D3D11_COMPARISON_FUNC v8; // [esp+0h] [ebp-18h]
  const vostok::configs::binary_config_value *v9; // [esp+4h] [ebp-14h]
  _DWORD v10[4]; // [esp+8h] [ebp-10h] BYREF

  v10[2] = 0x80000;
  v10[0] = 0;
  v10[1] = 0;
  v10[3] = 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "geometry_depth_pass",
    compiler,
    (const char *)v10,
    config,
    v7,
    v9);
  vostok::render::effect_compiler::set_depth(v4, (int)compiler, 1, 0, v8);
  vostok::render::effect_compiler::color_write_enable(v5, (int)compiler, D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_material_base::compile_end(v6, compiler);
}
