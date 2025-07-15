void __thiscall vostok::render::scr_quad_effect::compile(
        vostok::render::scr_quad_effect *this,
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
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::shader_configuration v17; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v18; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v19; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v20; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v21; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v22; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v23; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v24; // [esp+0h] [ebp-20h]
  __int64 v25; // [esp+18h] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v17.0 = "present";
  *(unsigned __int64 *)((char *)v17.configuration + 4) = 0;
  HIDWORD(v17.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "sa_quad", 0, v17, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v19);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v20);
  vostok::render::effect_compiler::set_stencil(
    v7,
    (int)compiler,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v21);
  vostok::render::effect_compiler::end_pass(v8, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v9,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v10, (int)compiler);
  *(_DWORD *)&v18.0 = "present_2rt";
  v25 = 0x80000;
  *(unsigned __int64 *)((char *)v18.configuration + 4) = 0;
  HIDWORD(v18.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v11, (int)compiler, "sa_quad", 0, v18, 0);
  vostok::render::effect_compiler::set_depth(v12, (int)compiler, 0, 0, v22);
  vostok::render::effect_compiler::set_alpha_blend(
    v13,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v23);
  vostok::render::effect_compiler::set_stencil(
    v14,
    (int)compiler,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v24);
  vostok::render::effect_compiler::end_pass(v15, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v16,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
