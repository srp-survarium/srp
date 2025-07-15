void __thiscall vostok::render::effect_light_mask::compile(
        vostok::render::effect_light_mask *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::command_line::key *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::command_line::key *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::shader_configuration v34; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v35; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v36; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v37; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v38; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v39; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v40; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v41; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v42; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v43; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v44; // [esp+4h] [ebp-20h]
  __int64 v45; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v34.0 = "dumb";
  *(unsigned __int64 *)((char *)v34.configuration + 4) = 0;
  HIDWORD(v34.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "accum_mask", 0, v34, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v37);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_INVERT,
    v38);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v7);
  vostok::render::effect_compiler::color_write_enable(v8, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v11, (int)compiler);
  *(_DWORD *)&v35.0 = "accum_sun_mask";
  *(unsigned __int64 *)((char *)v35.configuration + 4) = 0;
  HIDWORD(v35.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v12, (int)compiler, "stub_notransform_2pos", 0, v35, 0);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 0, 0, v39);
  vostok::render::effect_compiler::set_stencil(
    v14,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v40);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v15);
  vostok::render::effect_compiler::color_write_enable(v16, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v41);
  vostok::render::effect_compiler::set_texture(
    v18,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v23, (int)compiler);
  *(_DWORD *)&v36.0 = "accum_sun_mask";
  v45 = 0x80000;
  *(unsigned __int64 *)((char *)v36.configuration + 4) = 0;
  HIDWORD(v36.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v24, (int)compiler, "stub_notransform_t", 0, v36, 0);
  vostok::render::effect_compiler::set_depth(v25, (int)compiler, 0, 0, v42);
  vostok::render::effect_compiler::set_stencil(
    v26,
    (int)compiler,
    1,
    0x80u,
    0x80u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INCR,
    D3D11_STENCIL_OP_KEEP,
    v43);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v27);
  vostok::render::effect_compiler::color_write_enable(v28, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::set_alpha_blend(
    v29,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v44);
  vostok::render::effect_compiler::set_texture(
    v30,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v31,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v32, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v33,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
