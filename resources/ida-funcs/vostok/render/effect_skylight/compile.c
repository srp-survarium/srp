void __thiscall vostok::render::effect_skylight::compile(
        vostok::render::effect_skylight *this,
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
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v26; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v27; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v28; // [esp+4h] [ebp-20h]
  __int64 v29; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0;
  HIDWORD(v23.configuration[1]) = 0x80000;
  *(_DWORD *)&v23.0 = "skylight";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "skylight", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v25);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_ssao_accumulator",
    "$user$ssao_accumulator_full_x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_stencil(
    v10,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v26);
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0;
  v29 = 0x80000;
  HIDWORD(v24.configuration[1]) = 0x80000;
  *(_DWORD *)&v24.0 = "skylight";
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "skylight", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v27);
  vostok::render::effect_compiler::set_texture(
    v16,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v17,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v18,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_ssao_accumulator",
    "$user$ssao_accumulator_full_x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_stencil(
    v20,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v28);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
