void __thiscall vostok::render::effect_apply_distortion::compile(
        vostok::render::effect_apply_distortion *this,
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
  vostok::command_line::key *v10; // ecx
  vostok::command_line::key *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::command_line::key *v21; // ecx
  vostok::command_line::key *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::command_line::key *v30; // ecx
  vostok::command_line::key *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::shader_configuration v34; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v35; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v36; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v37; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v38; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v39; // [esp+4h] [ebp-20h]
  __int64 v40; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v34.configuration + 4) = 0;
  HIDWORD(v34.configuration[1]) = 0x80000;
  *(_DWORD *)&v34.0 = "apply_distortion";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "apply_distortion", 0, v34, 0);
  vostok::render::effect_compiler::set_texture(
    v5,
    (const char *)compiler,
    "t_base",
    "$user$generic0",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_distortion",
    "$user$distortion",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_distortion_mask",
    "$user$distortion_mask",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_depth(v9, (int)compiler, 0, 0, v37);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v10);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v11);
  vostok::render::effect_compiler::end_pass(v12, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v13,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v14, (int)compiler);
  *(unsigned __int64 *)((char *)v35.configuration + 4) = 0;
  HIDWORD(v35.configuration[1]) = 0x80000;
  *(_DWORD *)&v35.0 = "apply_distortion";
  vostok::render::effect_compiler::begin_pass(v15, (int)compiler, "apply_distortion", 0, v35, 0);
  vostok::render::effect_compiler::set_texture(
    v16,
    (const char *)compiler,
    "t_base",
    "$user$generic1",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v17,
    (const char *)compiler,
    "t_distortion",
    "$user$distortion",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v18,
    (const char *)compiler,
    "t_distortion_mask",
    "$user$distortion_mask",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_depth(v20, (int)compiler, 0, 0, v38);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v21);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v22);
  vostok::render::effect_compiler::end_pass(v23, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v24,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v25, (int)compiler);
  v40 = 0x80000;
  *(unsigned __int64 *)((char *)v36.configuration + 4) = 0;
  HIDWORD(v36.configuration[1]) = 0x80000;
  *(_DWORD *)&v36.0 = "apply_distortion_copy_result";
  vostok::render::effect_compiler::begin_pass(v26, (int)compiler, "apply_distortion", 0, v36, 0);
  vostok::render::effect_compiler::set_texture(
    v27,
    (const char *)compiler,
    "t_base",
    "$user$generic1",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v28,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_depth(v29, (int)compiler, 0, 0, v39);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v30);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v31);
  vostok::render::effect_compiler::end_pass(v32, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v33,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
