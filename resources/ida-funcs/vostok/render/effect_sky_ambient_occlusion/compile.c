void __thiscall vostok::render::effect_sky_ambient_occlusion::compile(
        vostok::render::effect_sky_ambient_occlusion *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::command_line::key *v8; // ecx
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
  vostok::command_line::key *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::shader_configuration v25; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v26; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v27; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v28; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v30; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v31; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v32; // [esp+4h] [ebp-20h]
  __int64 v33; // [esp+1Ch] [ebp-8h]

  v33 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v25.configuration + 4) = 0;
  HIDWORD(v25.configuration[1]) = 0x80000;
  *(_DWORD *)&v25.0 = "sky_ambient_occlusion";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "sky_ambient_occlusion", 0, v25, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v27);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_SRC_COLOR,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v28);
  vostok::render::effect_compiler::set_stencil(
    v7,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_INVERT,
    v29);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v8);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v12, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v13,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v14, (int)compiler);
  *(unsigned __int64 *)((char *)v26.configuration + 4) = 0;
  HIDWORD(v26.configuration[1]) = 0x80000;
  *(_DWORD *)&v26.0 = "sky_ambient_occlusion";
  vostok::render::effect_compiler::begin_pass(v15, (int)compiler, "sky_ambient_occlusion", 0, v26, 0);
  vostok::render::effect_compiler::set_depth(v16, (int)compiler, 0, 0, v30);
  vostok::render::effect_compiler::set_stencil(
    v17,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v31);
  vostok::render::effect_compiler::set_alpha_blend(
    v18,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_SRC_COLOR,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v32);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v19);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v21,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v22,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v23, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v24,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
