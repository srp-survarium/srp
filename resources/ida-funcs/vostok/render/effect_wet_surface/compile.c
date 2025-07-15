void __thiscall vostok::render::effect_wet_surface::compile(
        vostok::render::effect_wet_surface *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
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
  vostok::render::effect_compiler *v23; // ecx
  vostok::command_line::key *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::command_line::key *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::render::effect_compiler *v37; // ecx
  vostok::render::shader_configuration v38; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v39; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v40; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v41; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v42; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v43; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v44; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v45; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v46; // [esp+4h] [ebp-20h]
  __int64 v47; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v38.configuration + 4) = 0;
  HIDWORD(v38.configuration[1]) = 0x80000;
  *(_DWORD *)&v38.0 = "wet_sufrace";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "wet_sufrace", 0, v38, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v41);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
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
    "$user$normal_copy",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_parameters_copy",
    "$user$parameters_copy",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_rain_shadow_map",
    "$user$rain_shadow_map",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_water_flowing_normals",
    "engine/water_flowing_nmap",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_water_flowing_specular",
    "engine/water_flowing_spec",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_puddle_rings",
    "engine/rain_puddle_rings",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v15,
    (const char *)compiler,
    "t_rain_stream",
    "engine/rain_stream",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v16,
    (const char *)compiler,
    "t_rain_puddle",
    "engine/rain_puddle",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v17,
    (const char *)compiler,
    "t_rain_puddle_mask",
    "engine/rain_puddle_mask",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_stencil(
    v18,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v42);
  vostok::render::effect_compiler::end_pass(v19, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v20,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v21, (int)compiler);
  *(_DWORD *)&v39.0 = "wet_sufrace_write_normal";
  *(unsigned __int64 *)((char *)v39.configuration + 4) = 0;
  HIDWORD(v39.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v22, (int)compiler, "wet_sufrace", 0, v39, 0);
  vostok::render::effect_compiler::set_depth(v23, (int)compiler, 1, 0, v43);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v24);
  vostok::render::effect_compiler::set_texture(
    v25,
    (const char *)compiler,
    "t_unpacked_normal",
    "$user$generic1",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_stencil(
    v26,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v44);
  vostok::render::effect_compiler::end_pass(v27, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v28,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v29, (int)compiler);
  *(_DWORD *)&v40.0 = "wet_sufrace_copy";
  v47 = 0x80000;
  *(unsigned __int64 *)((char *)v40.configuration + 4) = 0;
  HIDWORD(v40.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v30, (int)compiler, "wet_sufrace", 0, v40, 0);
  vostok::render::effect_compiler::set_depth(v31, (int)compiler, 0, 0, v45);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v32);
  vostok::render::effect_compiler::set_stencil(
    v33,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v46);
  vostok::render::effect_compiler::set_texture(
    v34,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v35,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v36, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v37,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
