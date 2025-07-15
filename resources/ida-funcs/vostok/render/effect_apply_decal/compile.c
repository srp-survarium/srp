void __thiscall vostok::render::effect_apply_decal::compile(
        vostok::render::effect_apply_decal *this,
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
  vostok::command_line::key *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::command_line::key *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::shader_configuration v36; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v37; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v38; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v39; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v40; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v41; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v42; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v43; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v44; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v45; // [esp+4h] [ebp-20h]
  __int64 v46; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v36.0 = "apply_decal_normals_blend";
  *(unsigned __int64 *)((char *)v36.configuration + 4) = 0;
  HIDWORD(v36.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "apply_decal", 0, v36, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v39);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_decals_smoothness",
    "$user$decals_smoothness",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
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
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_stencil(
    v13,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v40);
  vostok::render::effect_compiler::end_pass(v14, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v15,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v16, (int)compiler);
  *(_DWORD *)&v37.0 = "apply_decal_normals_write";
  *(unsigned __int64 *)((char *)v37.configuration + 4) = 0;
  HIDWORD(v37.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v17, (int)compiler, "apply_decal", 0, v37, 0);
  vostok::render::effect_compiler::set_depth(v18, (int)compiler, 0, 0, v41);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v19);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_decals_normal_result",
    "$user$decals_blend_result",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v21,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v22,
    (const char *)compiler,
    "t_decals_smoothness_result",
    "$user$decals_smoothness_result",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_stencil(
    v23,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v42);
  vostok::render::effect_compiler::end_pass(v24, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v25,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v26, (int)compiler);
  *(_DWORD *)&v38.0 = "apply_decal_diffuse_write";
  v46 = 0x80000;
  *(unsigned __int64 *)((char *)v38.configuration + 4) = 0;
  HIDWORD(v38.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v27, (int)compiler, "apply_decal", 0, v38, 0);
  vostok::render::effect_compiler::set_depth(v28, (int)compiler, 0, 0, v43);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v29);
  vostok::render::effect_compiler::set_texture(
    v30,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_stencil(
    v31,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v44);
  vostok::render::effect_compiler::set_alpha_blend(
    v32,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v45);
  vostok::render::effect_compiler::color_write_enable(
    v33,
    (int)compiler,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v34, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v35,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
