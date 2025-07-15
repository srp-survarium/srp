void __thiscall vostok::render::effect_fill_environment_probe_face::compile(
        vostok::render::effect_fill_environment_probe_face *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx
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
  vostok::command_line::key *v19; // ecx
  vostok::command_line::key *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v25; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v26; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v29; // [esp+4h] [ebp-20h]
  __int64 v30; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0;
  HIDWORD(v24.configuration[1]) = 0x80000;
  *(_DWORD *)&v24.0 = "fill_environment_probe_face";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "fill_environment_probe_face", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v26);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v7);
  vostok::render::effect_compiler::set_alpha_blend(
    v8,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v27);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_probe_face_texture",
    "$user$generic0",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v14, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v15,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v16, (int)compiler);
  *(_DWORD *)&v25.0 = "fill_environment_probe_face_diffuse";
  v30 = 0x80000;
  *(unsigned __int64 *)((char *)v25.configuration + 4) = 0;
  HIDWORD(v25.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v17, (int)compiler, "fill_environment_probe_face", 0, v25, 0);
  vostok::render::effect_compiler::set_depth(v18, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v19);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v20);
  vostok::render::effect_compiler::set_alpha_blend(
    v21,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v29);
  vostok::render::effect_compiler::end_pass(v22, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v23,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
