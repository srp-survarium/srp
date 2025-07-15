void __thiscall vostok::render::effect_rain::compile(
        vostok::render::effect_rain *this,
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
  vostok::render::shader_configuration v21; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v22; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v23; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v24; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v25; // [esp+4h] [ebp-20h]
  __int64 v26; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v21.configuration + 4) = 0;
  HIDWORD(v21.configuration[1]) = 0x80000;
  *(_DWORD *)&v21.0 = "rain";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "rain", 0, v21, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v23);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_alpha_blend(
    v7,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v24);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_scroll_rain",
    "engine/scroll_rain_0",
    0,
    0xFFFFFFFF,
    0,
    1.0);
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
    "t_rain_shadow_map",
    "$user$rain_shadow_map",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_frame_color",
    "$user$generic1",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_diffuse_lighting",
    "$user$accum_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v13, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v14,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v15, (int)compiler);
  *(unsigned __int64 *)((char *)v22.configuration + 4) = 0;
  v26 = 0x80000;
  HIDWORD(v22.configuration[1]) = 0x80000;
  *(_DWORD *)&v22.0 = "rain_resolve";
  vostok::render::effect_compiler::begin_pass(v16, (int)compiler, "rain_resolve", 0, v22, 0);
  vostok::render::effect_compiler::set_alpha_blend(
    v17,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v25);
  vostok::render::effect_compiler::set_texture(
    v18,
    (const char *)compiler,
    "t_rain",
    "$user$rain_result",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v19, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v20,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
