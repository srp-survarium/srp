void __thiscall vostok::render::effect_apply_ambient_lights::compile(
        vostok::render::effect_apply_ambient_lights *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::shader_configuration v11; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v12; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v13; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v14; // [esp+4h] [ebp-20h]
  __int64 v15; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v11.configuration + 4) = 0;
  v15 = 0x80000;
  HIDWORD(v11.configuration[1]) = 0x80000;
  *(_DWORD *)&v11.0 = "apply_ambient_lights";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "apply_ambient_lights", 0, v11, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v12);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_SRC_COLOR,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v13);
  vostok::render::effect_compiler::set_stencil(
    v7,
    (int)compiler,
    1,
    0,
    0xFFu,
    255,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v14);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_ambient_lights_accumulation",
    "$user$accum_ambient_lights",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
