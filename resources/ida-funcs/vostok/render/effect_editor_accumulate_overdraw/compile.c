void __thiscall vostok::render::effect_editor_accumulate_overdraw::compile(
        vostok::render::effect_editor_accumulate_overdraw *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_material_base *v6; // ecx
  vostok::render::shader_configuration *v7; // [esp+0h] [ebp-18h]
  D3D11_COMPARISON_FUNC v8; // [esp+0h] [ebp-18h]
  D3D11_STENCIL_OP v9; // [esp+0h] [ebp-18h]
  const vostok::configs::binary_config_value *v10; // [esp+4h] [ebp-14h]
  _DWORD v11[4]; // [esp+8h] [ebp-10h] BYREF

  v11[2] = 0x80000;
  v11[0] = 0;
  v11[1] = 0;
  v11[3] = 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "editor_accumulate_overdraw",
    compiler,
    (const char *)v11,
    config,
    v7,
    v10);
  vostok::render::effect_compiler::set_depth(v4, (int)compiler, 1, 1, v8);
  vostok::render::effect_compiler::set_stencil(
    v5,
    (int)compiler,
    1,
    0xFFu,
    0xFFu,
    255,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_INCR,
    D3D11_STENCIL_OP_KEEP,
    v9);
  vostok::render::effect_material_base::compile_end(v6, compiler);
}
