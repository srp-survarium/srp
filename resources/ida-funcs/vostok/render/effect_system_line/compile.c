void __thiscall vostok::render::effect_system_line::compile(
        vostok::render::effect_system_line *this,
        vostok::render::effect_compiler *c,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // eax
  vostok::render::effect_compiler *v5; // eax
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // eax
  vostok::render::effect_compiler *v8; // eax
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // eax
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // eax
  vostok::render::effect_compiler *v13; // eax
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // eax
  vostok::render::effect_compiler *v16; // eax
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // eax
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::shader_configuration v20; // [esp-3Ch] [ebp-5Ch]
  vostok::render::shader_configuration v21; // [esp-3Ch] [ebp-5Ch]
  vostok::render::effect_compiler *v22; // [esp-20h] [ebp-40h]
  vostok::render::effect_compiler *v23; // [esp-20h] [ebp-40h]
  D3D11_STENCIL_OP v24; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v25; // [esp+0h] [ebp-20h]

  *(_DWORD *)&v20.0 = "system_line";
  *(unsigned __int64 *)((char *)v20.configuration + 4) = 0;
  HIDWORD(v20.configuration[1]) = 0x80000;
  v4 = vostok::render::effect_compiler::begin_technique(0, (int)c);
  v5 = vostok::render::effect_compiler::begin_pass(0, (int)v4, "system_line", 0, v20, 0);
  v7 = vostok::render::effect_compiler::set_depth(v6, (int)v5, 1, 1, (D3D11_COMPARISON_FUNC)0);
  v8 = vostok::render::effect_compiler::set_stencil(
         v22,
         (int)v7,
         1,
         0x20u,
         0,
         255,
         D3D11_COMPARISON_ALWAYS,
         D3D11_STENCIL_OP_REPLACE,
         D3D11_STENCIL_OP_KEEP,
         v24);
  v10 = vostok::render::effect_compiler::end_pass(v9, (int)v8);
  vostok::render::effect_compiler::end_technique(
    v11,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v10);
  *(_DWORD *)&v21.0 = "system_line";
  *(unsigned __int64 *)((char *)v21.configuration + 4) = 0;
  HIDWORD(v21.configuration[1]) = 0x80000;
  v12 = vostok::render::effect_compiler::begin_technique(0, (int)c);
  v13 = vostok::render::effect_compiler::begin_pass(0, (int)v12, "system_line_top", 0, v21, 0);
  v15 = vostok::render::effect_compiler::set_depth(v14, (int)v13, 1, 1, (D3D11_COMPARISON_FUNC)0);
  v16 = vostok::render::effect_compiler::set_stencil(
          v23,
          (int)v15,
          1,
          0x20u,
          0,
          255,
          D3D11_COMPARISON_ALWAYS,
          D3D11_STENCIL_OP_REPLACE,
          D3D11_STENCIL_OP_KEEP,
          v25);
  v18 = vostok::render::effect_compiler::end_pass(v17, (int)v16);
  vostok::render::effect_compiler::end_technique(
    v19,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v18);
}
