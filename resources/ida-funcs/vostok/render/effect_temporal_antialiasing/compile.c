void __thiscall vostok::render::effect_temporal_antialiasing::compile(
        vostok::render::effect_temporal_antialiasing *this,
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
  vostok::render::shader_configuration v13; // [esp-10h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v14; // [esp+4h] [ebp-18h]
  __int64 v15; // [esp+14h] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v13.configuration + 4) = 0;
  v15 = 0x80000;
  HIDWORD(v13.configuration[1]) = 0x80000;
  *(_DWORD *)&v13.0 = "temporal_antialiasing";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "temporal_antialiasing", 0, v13, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v14);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_current_frame_color",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_previous_frame_color",
    "$user$previous_present",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_object_motion_vectors",
    "$user$object_motion_vectors",
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
  vostok::render::effect_compiler::color_write_enable(
    v10,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
