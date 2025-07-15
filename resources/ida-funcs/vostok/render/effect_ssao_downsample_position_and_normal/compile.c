void __thiscall vostok::render::effect_ssao_downsample_position_and_normal::compile(
        vostok::render::effect_ssao_downsample_position_and_normal *this,
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
  vostok::render::shader_configuration v19; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v20; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v21; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v22; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v23; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v24; // [esp+4h] [ebp-20h]
  __int64 v25; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v19.0 = "ssao_downsample_depth_and_normals";
  *(unsigned __int64 *)((char *)v19.configuration + 4) = 0;
  HIDWORD(v19.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ssao_downsample_depth_and_normals", 0, v19, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v21);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v22);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v10, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v11,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v12, (int)compiler);
  v25 = 0x80000;
  *(unsigned __int64 *)((char *)v20.configuration + 4) = 0;
  *(_DWORD *)&v20.0 = "ssao_downsample_depth";
  HIDWORD(v20.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v13, (int)compiler, "ssao_downsample_depth_and_normals", 0, v20, 0);
  vostok::render::effect_compiler::set_depth(v14, (int)compiler, 0, 0, v23);
  vostok::render::effect_compiler::set_alpha_blend(
    v15,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v24);
  vostok::render::effect_compiler::set_texture(
    v16,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
