void __thiscall vostok::render::effect_color_grading_lut_blending::compile(
        vostok::render::effect_color_grading_lut_blending *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::shader_configuration v9; // [esp-14h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v10; // [esp+0h] [ebp-18h]
  D3D11_BLEND_OP v11; // [esp+0h] [ebp-18h]
  __int64 v12; // [esp+10h] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v9.configuration + 4) = 0;
  v12 = 0x80000;
  HIDWORD(v9.configuration[1]) = 0x80000;
  *(_DWORD *)&v9.0 = "color_grading_lut_blending";
  vostok::render::effect_compiler::begin_pass(
    v4,
    (int)compiler,
    "color_grading_lut_blending",
    "color_grading_lut_blending",
    v9,
    0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v10);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v11);
  vostok::render::effect_compiler::end_pass(v7, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
