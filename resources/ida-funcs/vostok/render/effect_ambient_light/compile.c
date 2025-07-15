void __thiscall vostok::render::effect_ambient_light<1,1,1>::compile(
        vostok::render::effect_ambient_light<1,1,1> *this,
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
  vostok::command_line::key *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v30; // [esp+4h] [ebp-20h]
  __int64 v31; // [esp+1Ch] [ebp-8h]

  v31 = 17301504;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0x10008000000LL;
  HIDWORD(v23.configuration[1]) = 17301504;
  *(_DWORD *)&v23.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ambient_light", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v25);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v26);
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
    v27);
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
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0x10008000000LL;
  HIDWORD(v24.configuration[1]) = 17301504;
  *(_DWORD *)&v24.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "ambient_light", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_stencil(
    v16,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v29);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v30);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v18);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_ambient_light<1,1,0>::compile(
        vostok::render::effect_ambient_light<1,1,0> *this,
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
  vostok::command_line::key *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v30; // [esp+4h] [ebp-20h]
  __int64 v31; // [esp+1Ch] [ebp-8h]

  v31 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0x10008000000LL;
  HIDWORD(v23.configuration[1]) = 0x80000;
  *(_DWORD *)&v23.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ambient_light", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v25);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v26);
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
    v27);
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
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0x10008000000LL;
  HIDWORD(v24.configuration[1]) = 0x80000;
  *(_DWORD *)&v24.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "ambient_light", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_stencil(
    v16,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v29);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v30);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v18);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_ambient_light<1,0,1>::compile(
        vostok::render::effect_ambient_light<1,0,1> *this,
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
  vostok::command_line::key *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v30; // [esp+4h] [ebp-20h]
  __int64 v31; // [esp+1Ch] [ebp-8h]

  v31 = 17301504;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0x10000000000LL;
  HIDWORD(v23.configuration[1]) = 17301504;
  *(_DWORD *)&v23.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ambient_light", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v25);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v26);
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
    v27);
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
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0x10000000000LL;
  HIDWORD(v24.configuration[1]) = 17301504;
  *(_DWORD *)&v24.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "ambient_light", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_stencil(
    v16,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v29);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v30);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v18);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_ambient_light<1,0,0>::compile(
        vostok::render::effect_ambient_light<1,0,0> *this,
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
  vostok::command_line::key *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v30; // [esp+4h] [ebp-20h]
  __int64 v31; // [esp+1Ch] [ebp-8h]

  v31 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0x10000000000LL;
  HIDWORD(v23.configuration[1]) = 0x80000;
  *(_DWORD *)&v23.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ambient_light", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v25);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v26);
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
    v27);
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
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0x10000000000LL;
  HIDWORD(v24.configuration[1]) = 0x80000;
  *(_DWORD *)&v24.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "ambient_light", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_stencil(
    v16,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v29);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v30);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v18);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_ambient_light<2,1,1>::compile(
        vostok::render::effect_ambient_light<2,1,1> *this,
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
  vostok::command_line::key *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v30; // [esp+4h] [ebp-20h]
  __int64 v31; // [esp+1Ch] [ebp-8h]

  v31 = 17301504;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0x20008000000LL;
  HIDWORD(v23.configuration[1]) = 17301504;
  *(_DWORD *)&v23.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ambient_light", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v25);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v26);
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
    v27);
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
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0x20008000000LL;
  HIDWORD(v24.configuration[1]) = 17301504;
  *(_DWORD *)&v24.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "ambient_light", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_stencil(
    v16,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v29);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v30);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v18);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_ambient_light<2,1,0>::compile(
        vostok::render::effect_ambient_light<2,1,0> *this,
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
  vostok::command_line::key *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v30; // [esp+4h] [ebp-20h]
  __int64 v31; // [esp+1Ch] [ebp-8h]

  v31 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0x20008000000LL;
  HIDWORD(v23.configuration[1]) = 0x80000;
  *(_DWORD *)&v23.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ambient_light", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v25);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v26);
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
    v27);
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
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0x20008000000LL;
  HIDWORD(v24.configuration[1]) = 0x80000;
  *(_DWORD *)&v24.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "ambient_light", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_stencil(
    v16,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v29);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v30);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v18);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_ambient_light<2,0,1>::compile(
        vostok::render::effect_ambient_light<2,0,1> *this,
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
  vostok::command_line::key *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v30; // [esp+4h] [ebp-20h]
  __int64 v31; // [esp+1Ch] [ebp-8h]

  v31 = 17301504;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0x20000000000LL;
  HIDWORD(v23.configuration[1]) = 17301504;
  *(_DWORD *)&v23.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ambient_light", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v25);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v26);
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
    v27);
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
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0x20000000000LL;
  HIDWORD(v24.configuration[1]) = 17301504;
  *(_DWORD *)&v24.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "ambient_light", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_stencil(
    v16,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v29);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v30);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v18);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_ambient_light<2,0,0>::compile(
        vostok::render::effect_ambient_light<2,0,0> *this,
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
  vostok::command_line::key *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v30; // [esp+4h] [ebp-20h]
  __int64 v31; // [esp+1Ch] [ebp-8h]

  v31 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0x20000000000LL;
  HIDWORD(v23.configuration[1]) = 0x80000;
  *(_DWORD *)&v23.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ambient_light", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v25);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v26);
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
    v27);
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
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0x20000000000LL;
  HIDWORD(v24.configuration[1]) = 0x80000;
  *(_DWORD *)&v24.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "ambient_light", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_stencil(
    v16,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v29);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v30);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v18);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_ambient_light<0,1,1>::compile(
        vostok::render::effect_ambient_light<0,1,1> *this,
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
  vostok::command_line::key *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v30; // [esp+4h] [ebp-20h]
  __int64 v31; // [esp+1Ch] [ebp-8h]

  v31 = 17301504;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0x8000000;
  HIDWORD(v23.configuration[1]) = 17301504;
  *(_DWORD *)&v23.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ambient_light", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v25);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v26);
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
    v27);
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
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0x8000000;
  HIDWORD(v24.configuration[1]) = 17301504;
  *(_DWORD *)&v24.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "ambient_light", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_stencil(
    v16,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v29);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v30);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v18);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_ambient_light<0,1,0>::compile(
        vostok::render::effect_ambient_light<0,1,0> *this,
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
  vostok::command_line::key *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v30; // [esp+4h] [ebp-20h]
  __int64 v31; // [esp+1Ch] [ebp-8h]

  v31 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0x8000000;
  HIDWORD(v23.configuration[1]) = 0x80000;
  *(_DWORD *)&v23.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ambient_light", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v25);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v26);
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
    v27);
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
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0x8000000;
  HIDWORD(v24.configuration[1]) = 0x80000;
  *(_DWORD *)&v24.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "ambient_light", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_stencil(
    v16,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v29);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v30);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v18);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_ambient_light<0,0,1>::compile(
        vostok::render::effect_ambient_light<0,0,1> *this,
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
  vostok::command_line::key *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v30; // [esp+4h] [ebp-20h]
  __int64 v31; // [esp+1Ch] [ebp-8h]

  v31 = 17301504;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0;
  HIDWORD(v23.configuration[1]) = 17301504;
  *(_DWORD *)&v23.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ambient_light", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v25);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v26);
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
    v27);
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
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0;
  HIDWORD(v24.configuration[1]) = 17301504;
  *(_DWORD *)&v24.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "ambient_light", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_stencil(
    v16,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v29);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v30);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v18);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_ambient_light<0,0,0>::compile(
        vostok::render::effect_ambient_light<0,0,0> *this,
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
  vostok::command_line::key *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v26; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v30; // [esp+4h] [ebp-20h]
  __int64 v31; // [esp+1Ch] [ebp-8h]

  v31 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0;
  HIDWORD(v23.configuration[1]) = 0x80000;
  *(_DWORD *)&v23.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "ambient_light", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v25);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v26);
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
    v27);
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
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0;
  HIDWORD(v24.configuration[1]) = 0x80000;
  *(_DWORD *)&v24.0 = "ambient_light";
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "ambient_light", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_stencil(
    v16,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v29);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v30);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v18);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
