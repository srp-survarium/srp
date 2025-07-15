void __thiscall vostok::render::effect_editor_show_cascaded_shadow_map_depth::compile(
        vostok::render::effect_editor_show_cascaded_shadow_map_depth *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *__formal,
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
  vostok::render::shader_configuration v12; // [esp-10h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v13; // [esp+4h] [ebp-18h]
  __int64 v14; // [esp+14h] [ebp-8h]

  v14 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v12.configuration + 4) = 0;
  HIDWORD(v12.configuration[1]) = 0x80000;
  *(_DWORD *)&v12.0 = "editor_show_cascaded_shadow_map_depth";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "editor_show_cascaded_shadow_map_depth", 0, v12, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v13);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "cascaded_shadow_map0",
    "$user$cascaded_shadow_map0",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "cascaded_shadow_map1",
    "$user$cascaded_shadow_map1",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "cascaded_shadow_map2",
    "$user$cascaded_shadow_map2",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "cascaded_shadow_map3",
    "$user$cascaded_shadow_map3",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v10, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v11,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
