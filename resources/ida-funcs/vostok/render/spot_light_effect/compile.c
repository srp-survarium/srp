void __thiscall vostok::render::spot_light_effect<1>::compile(
        vostok::render::spot_light_effect<1> *this,
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
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::command_line::key *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::render::shader_configuration v37; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v38; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v39; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v40; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v41; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v42; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v43; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v44; // [esp+4h] [ebp-20h]
  __int64 v45; // [esp+1Ch] [ebp-8h]

  v45 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v37.0 = "spot_light_accumulator";
  *(unsigned __int64 *)((char *)v37.configuration + 4) = 0x400000000LL;
  HIDWORD(v37.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "light", 0, v37, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v39);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_INVERT,
    v40);
  vostok::render::effect_compiler::set_alpha_blend(
    v7,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v41);
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
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_material",
    "$user$material",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_target_ex",
    "$user$position_ex",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v15,
    (const char *)compiler,
    "t_emissive",
    "$user$emmisive",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v16,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v17,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v18, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v19,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v20, (int)compiler);
  *(_DWORD *)&v38.0 = "spot_light_accumulator";
  *(unsigned __int64 *)((char *)v38.configuration + 4) = 0x400000000LL;
  HIDWORD(v38.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v21, (int)compiler, "light", 0, v38, 0);
  vostok::render::effect_compiler::set_depth(v22, (int)compiler, 0, 0, v42);
  vostok::render::effect_compiler::set_stencil(
    v23,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v43);
  vostok::render::effect_compiler::set_alpha_blend(
    v24,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v44);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v25);
  vostok::render::effect_compiler::set_texture(
    v26,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v27,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v28,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v29,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v30,
    (const char *)compiler,
    "t_material",
    "$user$material",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v31,
    (const char *)compiler,
    "t_target_ex",
    "$user$position_ex",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v32,
    (const char *)compiler,
    "t_emissive",
    "$user$emmisive",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v33,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v34,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v35, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v36,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::spot_light_effect<0>::compile(
        vostok::render::spot_light_effect<0> *this,
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
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::command_line::key *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::render::shader_configuration v37; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v38; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v39; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v40; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v41; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v42; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v43; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v44; // [esp+4h] [ebp-20h]
  __int64 v45; // [esp+1Ch] [ebp-8h]

  v45 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v37.0 = "spot_light_accumulator";
  *(unsigned __int64 *)((char *)v37.configuration + 4) = 0;
  HIDWORD(v37.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "light", 0, v37, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v39);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_INVERT,
    v40);
  vostok::render::effect_compiler::set_alpha_blend(
    v7,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v41);
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
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_material",
    "$user$material",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_target_ex",
    "$user$position_ex",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v15,
    (const char *)compiler,
    "t_emissive",
    "$user$emmisive",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v16,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v17,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v18, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v19,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v20, (int)compiler);
  *(_DWORD *)&v38.0 = "spot_light_accumulator";
  *(unsigned __int64 *)((char *)v38.configuration + 4) = 0;
  HIDWORD(v38.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v21, (int)compiler, "light", 0, v38, 0);
  vostok::render::effect_compiler::set_depth(v22, (int)compiler, 0, 0, v42);
  vostok::render::effect_compiler::set_stencil(
    v23,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v43);
  vostok::render::effect_compiler::set_alpha_blend(
    v24,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v44);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v25);
  vostok::render::effect_compiler::set_texture(
    v26,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v27,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v28,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v29,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v30,
    (const char *)compiler,
    "t_material",
    "$user$material",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v31,
    (const char *)compiler,
    "t_target_ex",
    "$user$position_ex",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v32,
    (const char *)compiler,
    "t_emissive",
    "$user$emmisive",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v33,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v34,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v35, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v36,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
