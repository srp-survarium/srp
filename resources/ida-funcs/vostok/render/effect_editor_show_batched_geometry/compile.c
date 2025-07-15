void __thiscall vostok::render::effect_editor_show_batched_geometry::compile(
        vostok::render::effect_editor_show_batched_geometry *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_material_base *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::render::effect_material_base *v6; // ecx
  vostok::render::shader_configuration *v7; // [esp+0h] [ebp-18h]
  vostok::render::shader_configuration *v8; // [esp+0h] [ebp-18h]
  const vostok::configs::binary_config_value *v9; // [esp+4h] [ebp-14h]
  const vostok::configs::binary_config_value *v10; // [esp+4h] [ebp-14h]
  _DWORD v11[4]; // [esp+8h] [ebp-10h] BYREF

  v11[2] = 0x80000;
  v11[0] = 0;
  v11[1] = 0;
  v11[3] = 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)"vertex_base_lpv",
    "editor_show_lpv_geometry",
    compiler,
    (const char *)v11,
    config,
    v7,
    v9);
  vostok::render::effect_material_base::compile_end(v4, compiler);
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v5,
    (vostok::render::effect_material_base *)&stru_812A9C,
    "editor_show_shadow_geometry",
    compiler,
    (const char *)v11,
    config,
    v8,
    v10);
  vostok::render::effect_material_base::compile_end(v6, compiler);
}
