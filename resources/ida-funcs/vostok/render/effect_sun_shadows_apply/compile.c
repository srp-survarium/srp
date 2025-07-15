void __thiscall vostok::render::effect_sun_shadows_apply<1,1>::compile(
        vostok::render::effect_sun_shadows_apply<1,1> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::command_line::key *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::shader_configuration v13; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v14; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v15; // [esp+4h] [ebp-20h]
  __int64 v16; // [esp+1Ch] [ebp-8h]

  v16 = 17301504;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v13.configuration + 4) = 0x80000;
  HIDWORD(v13.configuration[1]) = 17301504;
  *(_DWORD *)&v13.0 = "sun_shadow";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "sun_shadow", 0, v13, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v14);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    1,
    0xFFu,
    0xFFu,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v15);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v7);
  vostok::render::effect_compiler::set_fill_mode(
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
}


void __thiscall vostok::render::effect_sun_shadows_apply<1,2>::compile(
        vostok::render::effect_sun_shadows_apply<1,2> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::command_line::key *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::shader_configuration v13; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v14; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v15; // [esp+4h] [ebp-20h]
  __int64 v16; // [esp+1Ch] [ebp-8h]

  v16 = 34078720;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v13.configuration + 4) = 0x80000;
  HIDWORD(v13.configuration[1]) = 34078720;
  *(_DWORD *)&v13.0 = "sun_shadow";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "sun_shadow", 0, v13, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v14);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    1,
    0xFFu,
    0xFFu,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v15);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v7);
  vostok::render::effect_compiler::set_fill_mode(
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
}


void __thiscall vostok::render::effect_sun_shadows_apply<1,3>::compile(
        vostok::render::effect_sun_shadows_apply<1,3> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::command_line::key *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::shader_configuration v13; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v14; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v15; // [esp+4h] [ebp-20h]
  __int64 v16; // [esp+1Ch] [ebp-8h]

  v16 = 50855936;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v13.configuration + 4) = 0x80000;
  HIDWORD(v13.configuration[1]) = 50855936;
  *(_DWORD *)&v13.0 = "sun_shadow";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "sun_shadow", 0, v13, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v14);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    1,
    0xFFu,
    0xFFu,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v15);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v7);
  vostok::render::effect_compiler::set_fill_mode(
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
}


void __thiscall vostok::render::effect_sun_shadows_apply<1,0>::compile(
        vostok::render::effect_sun_shadows_apply<1,0> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::command_line::key *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::shader_configuration v13; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v14; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v15; // [esp+4h] [ebp-20h]
  __int64 v16; // [esp+1Ch] [ebp-8h]

  v16 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v13.configuration + 4) = 0x80000;
  HIDWORD(v13.configuration[1]) = 0x80000;
  *(_DWORD *)&v13.0 = "sun_shadow";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "sun_shadow", 0, v13, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v14);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    1,
    0xFFu,
    0xFFu,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v15);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v7);
  vostok::render::effect_compiler::set_fill_mode(
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
}


void __thiscall vostok::render::effect_sun_shadows_apply<0,1>::compile(
        vostok::render::effect_sun_shadows_apply<0,1> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::command_line::key *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::shader_configuration v13; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v14; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v15; // [esp+4h] [ebp-20h]
  __int64 v16; // [esp+1Ch] [ebp-8h]

  v16 = 17301504;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v13.configuration + 4) = 0;
  HIDWORD(v13.configuration[1]) = 17301504;
  *(_DWORD *)&v13.0 = "sun_shadow";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "sun_shadow", 0, v13, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v14);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    1,
    0xFFu,
    0xFFu,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v15);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v7);
  vostok::render::effect_compiler::set_fill_mode(
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
}


void __thiscall vostok::render::effect_sun_shadows_apply<0,2>::compile(
        vostok::render::effect_sun_shadows_apply<0,2> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::command_line::key *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::shader_configuration v13; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v14; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v15; // [esp+4h] [ebp-20h]
  __int64 v16; // [esp+1Ch] [ebp-8h]

  v16 = 34078720;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v13.configuration + 4) = 0;
  HIDWORD(v13.configuration[1]) = 34078720;
  *(_DWORD *)&v13.0 = "sun_shadow";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "sun_shadow", 0, v13, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v14);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    1,
    0xFFu,
    0xFFu,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v15);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v7);
  vostok::render::effect_compiler::set_fill_mode(
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
}


void __thiscall vostok::render::effect_sun_shadows_apply<0,3>::compile(
        vostok::render::effect_sun_shadows_apply<0,3> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::command_line::key *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::shader_configuration v13; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v14; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v15; // [esp+4h] [ebp-20h]
  __int64 v16; // [esp+1Ch] [ebp-8h]

  v16 = 50855936;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v13.configuration + 4) = 0;
  HIDWORD(v13.configuration[1]) = 50855936;
  *(_DWORD *)&v13.0 = "sun_shadow";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "sun_shadow", 0, v13, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v14);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    1,
    0xFFu,
    0xFFu,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v15);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v7);
  vostok::render::effect_compiler::set_fill_mode(
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
}


void __thiscall vostok::render::effect_sun_shadows_apply<0,0>::compile(
        vostok::render::effect_sun_shadows_apply<0,0> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::command_line::key *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::shader_configuration v13; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v14; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v15; // [esp+4h] [ebp-20h]
  __int64 v16; // [esp+1Ch] [ebp-8h]

  v16 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v13.configuration + 4) = 0;
  HIDWORD(v13.configuration[1]) = 0x80000;
  *(_DWORD *)&v13.0 = "sun_shadow";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "sun_shadow", 0, v13, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v14);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    1,
    0xFFu,
    0xFFu,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v15);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v7);
  vostok::render::effect_compiler::set_fill_mode(
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
}
