void __thiscall vostok::render::effect_fill_reflective_shadow_map::compile(
        vostok::render::effect_fill_reflective_shadow_map *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_material_base *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::render::effect_material_base *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_material_base *v9; // ecx
  vostok::render::shader_configuration *v10; // [esp+0h] [ebp-18h]
  vostok::render::shader_configuration *v11; // [esp+0h] [ebp-18h]
  vostok::render::shader_configuration *v12; // [esp+0h] [ebp-18h]
  D3D11_COMPARISON_FUNC v13; // [esp+0h] [ebp-18h]
  const vostok::configs::binary_config_value *v14; // [esp+4h] [ebp-14h]
  const vostok::configs::binary_config_value *v15; // [esp+4h] [ebp-14h]
  const vostok::configs::binary_config_value *v16; // [esp+4h] [ebp-14h]
  _DWORD v17[4]; // [esp+8h] [ebp-10h] BYREF

  v17[2] = 0x80000;
  v17[0] = 0;
  v17[1] = 0;
  v17[3] = 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)"vertex_base_lpv",
    "fill_reflective_shadow_map",
    compiler,
    (const char *)v17,
    config,
    v10,
    v14);
  vostok::render::effect_material_base::compile_end(v4, compiler);
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v5,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "fill_reflective_shadow_map_position",
    compiler,
    (const char *)v17,
    config,
    v11,
    v15);
  vostok::render::effect_material_base::compile_end(v6, compiler);
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v7,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "fill_view_space_depth",
    compiler,
    (const char *)v17,
    config,
    v12,
    v16);
  vostok::render::effect_compiler::set_depth(v8, (int)compiler, 1, 1, v13);
  vostok::render::effect_material_base::compile_end(v9, compiler);
}
