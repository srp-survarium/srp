void __thiscall vostok::render::effect_ambient_volume::compile(
        vostok::render::effect_ambient_volume *this,
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
  vostok::command_line::key *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::shader_configuration v19; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v20; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v21; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v22; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v23; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v24; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v25; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+0h] [ebp-20h]
  __int64 v27; // [esp+18h] [ebp-8h]

  v27 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v19.configuration + 4) = 0;
  HIDWORD(v19.configuration[1]) = 0x80000;
  *(_DWORD *)&v19.0 = "ambient_volume";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ambient_volume", 0, v19, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v21);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_SRC_COLOR,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v22);
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
    v23);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v8);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v11, (int)compiler);
  *(unsigned __int64 *)((char *)v20.configuration + 4) = 0;
  HIDWORD(v20.configuration[1]) = 0x80000;
  *(_DWORD *)&v20.0 = "ambient_volume";
  vostok::render::effect_compiler::begin_pass(v12, (int)compiler, "ambient_volume", 0, v20, 0);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 0, 0, v24);
  vostok::render::effect_compiler::set_stencil(
    v14,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v25);
  vostok::render::effect_compiler::set_alpha_blend(
    v15,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_SRC_COLOR,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v26);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v16);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
