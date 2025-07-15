void __thiscall vostok::render::effect_god_rays::compile(
        vostok::render::effect_god_rays *this,
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
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::shader_configuration v19; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v20; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v21; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v22; // [esp+4h] [ebp-20h]
  __int64 v23; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v19.0 = "god_rays_mask";
  *(unsigned __int64 *)((char *)v19.configuration + 4) = 0;
  HIDWORD(v19.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "god_rays", 0, v19, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v21);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(v7, (int)compiler, 0, D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v8, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v9,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v10, (int)compiler);
  *(_DWORD *)&v20.0 = "god_rays";
  v23 = 0x80000;
  *(unsigned __int64 *)((char *)v20.configuration + 4) = 0;
  HIDWORD(v20.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v11, (int)compiler, "god_rays", 0, v20, 0);
  vostok::render::effect_compiler::set_depth(v12, (int)compiler, 0, 0, v22);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_light_scattering_mask",
    "$user$light_scattering_mask",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v15,
    (const char *)compiler,
    "t_sun_rays",
    "engine/sun_rays",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v16,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
