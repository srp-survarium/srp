void __thiscall vostok::render::effect_environment_probe_lighting<1,1>::compile(
        vostok::render::effect_environment_probe_lighting<1,1> *this,
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
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::command_line::key *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::shader_configuration v33; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v34; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v35; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v36; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v37; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v38; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v39; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v40; // [esp+4h] [ebp-20h]
  __int64 v41; // [esp+1Ch] [ebp-8h]

  v41 = 1091043328;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v33.0 = "environment_probe_lighting";
  *(unsigned __int64 *)((char *)v33.configuration + 4) = 0;
  HIDWORD(v33.configuration[1]) = 1091043328;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "light", 0, v33, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v35);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v36);
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
    v37);
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
    "t_diffuse",
    "$user$albedo",
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
    "t_ssao_accumulator",
    "$user$ssao_accumulator_full_x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_probe_indices",
    "$user$probe_indices",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v15,
    (int)compiler,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v16, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v17,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v18, (int)compiler);
  *(_DWORD *)&v34.0 = "environment_probe_lighting";
  *(unsigned __int64 *)((char *)v34.configuration + 4) = 0;
  HIDWORD(v34.configuration[1]) = 1091043328;
  vostok::render::effect_compiler::begin_pass(v19, (int)compiler, "light", 0, v34, 0);
  vostok::render::effect_compiler::set_depth(v20, (int)compiler, 0, 0, v38);
  vostok::render::effect_compiler::set_stencil(
    v21,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v39);
  vostok::render::effect_compiler::set_alpha_blend(
    v22,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v40);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v23);
  vostok::render::effect_compiler::set_texture(
    v24,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v25,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v26,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v27,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v28,
    (const char *)compiler,
    "t_ssao_accumulator",
    "$user$ssao_accumulator_full_x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v29,
    (const char *)compiler,
    "t_probe_indices",
    "$user$probe_indices",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v30,
    (int)compiler,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v31, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v32,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_environment_probe_lighting<1,0>::compile(
        vostok::render::effect_environment_probe_lighting<1,0> *this,
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
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::command_line::key *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::shader_configuration v33; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v34; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v35; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v36; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v37; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v38; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v39; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v40; // [esp+4h] [ebp-20h]
  __int64 v41; // [esp+1Ch] [ebp-8h]

  v41 = 1074266112;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v33.0 = "environment_probe_lighting";
  *(unsigned __int64 *)((char *)v33.configuration + 4) = 0;
  HIDWORD(v33.configuration[1]) = 1074266112;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "light", 0, v33, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v35);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v36);
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
    v37);
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
    "t_diffuse",
    "$user$albedo",
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
    "t_ssao_accumulator",
    "$user$ssao_accumulator_full_x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_probe_indices",
    "$user$probe_indices",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v15,
    (int)compiler,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v16, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v17,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v18, (int)compiler);
  *(_DWORD *)&v34.0 = "environment_probe_lighting";
  *(unsigned __int64 *)((char *)v34.configuration + 4) = 0;
  HIDWORD(v34.configuration[1]) = 1074266112;
  vostok::render::effect_compiler::begin_pass(v19, (int)compiler, "light", 0, v34, 0);
  vostok::render::effect_compiler::set_depth(v20, (int)compiler, 0, 0, v38);
  vostok::render::effect_compiler::set_stencil(
    v21,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v39);
  vostok::render::effect_compiler::set_alpha_blend(
    v22,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v40);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v23);
  vostok::render::effect_compiler::set_texture(
    v24,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v25,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v26,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v27,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v28,
    (const char *)compiler,
    "t_ssao_accumulator",
    "$user$ssao_accumulator_full_x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v29,
    (const char *)compiler,
    "t_probe_indices",
    "$user$probe_indices",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v30,
    (int)compiler,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v31, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v32,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_environment_probe_lighting<0,1>::compile(
        vostok::render::effect_environment_probe_lighting<0,1> *this,
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
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::command_line::key *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::shader_configuration v33; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v34; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v35; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v36; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v37; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v38; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v39; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v40; // [esp+4h] [ebp-20h]
  __int64 v41; // [esp+1Ch] [ebp-8h]

  v41 = 17301504;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v33.0 = "environment_probe_lighting";
  *(unsigned __int64 *)((char *)v33.configuration + 4) = 0;
  HIDWORD(v33.configuration[1]) = 17301504;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "light", 0, v33, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v35);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v36);
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
    v37);
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
    "t_diffuse",
    "$user$albedo",
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
    "t_ssao_accumulator",
    "$user$ssao_accumulator_full_x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_probe_indices",
    "$user$probe_indices",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v15,
    (int)compiler,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v16, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v17,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v18, (int)compiler);
  *(_DWORD *)&v34.0 = "environment_probe_lighting";
  *(unsigned __int64 *)((char *)v34.configuration + 4) = 0;
  HIDWORD(v34.configuration[1]) = 17301504;
  vostok::render::effect_compiler::begin_pass(v19, (int)compiler, "light", 0, v34, 0);
  vostok::render::effect_compiler::set_depth(v20, (int)compiler, 0, 0, v38);
  vostok::render::effect_compiler::set_stencil(
    v21,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v39);
  vostok::render::effect_compiler::set_alpha_blend(
    v22,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v40);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v23);
  vostok::render::effect_compiler::set_texture(
    v24,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v25,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v26,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v27,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v28,
    (const char *)compiler,
    "t_ssao_accumulator",
    "$user$ssao_accumulator_full_x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v29,
    (const char *)compiler,
    "t_probe_indices",
    "$user$probe_indices",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v30,
    (int)compiler,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v31, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v32,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_environment_probe_lighting<0,0>::compile(
        vostok::render::effect_environment_probe_lighting<0,0> *this,
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
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::command_line::key *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::shader_configuration v33; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v34; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v35; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v36; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v37; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v38; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v39; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v40; // [esp+4h] [ebp-20h]
  __int64 v41; // [esp+1Ch] [ebp-8h]

  v41 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v33.0 = "environment_probe_lighting";
  *(unsigned __int64 *)((char *)v33.configuration + 4) = 0;
  HIDWORD(v33.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "light", 0, v33, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v35);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v36);
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
    v37);
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
    "t_diffuse",
    "$user$albedo",
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
    "t_ssao_accumulator",
    "$user$ssao_accumulator_full_x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_probe_indices",
    "$user$probe_indices",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v15,
    (int)compiler,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v16, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v17,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v18, (int)compiler);
  *(_DWORD *)&v34.0 = "environment_probe_lighting";
  *(unsigned __int64 *)((char *)v34.configuration + 4) = 0;
  HIDWORD(v34.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v19, (int)compiler, "light", 0, v34, 0);
  vostok::render::effect_compiler::set_depth(v20, (int)compiler, 0, 0, v38);
  vostok::render::effect_compiler::set_stencil(
    v21,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v39);
  vostok::render::effect_compiler::set_alpha_blend(
    v22,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v40);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v23);
  vostok::render::effect_compiler::set_texture(
    v24,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v25,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v26,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v27,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v28,
    (const char *)compiler,
    "t_ssao_accumulator",
    "$user$ssao_accumulator_full_x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v29,
    (const char *)compiler,
    "t_probe_indices",
    "$user$probe_indices",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v30,
    (int)compiler,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v31, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v32,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
