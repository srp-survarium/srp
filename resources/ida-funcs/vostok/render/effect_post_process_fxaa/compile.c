void __thiscall vostok::render::effect_post_process_fxaa::compile(
        vostok::render::effect_post_process_fxaa *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::shader_configuration v9; // [esp-10h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v10; // [esp+4h] [ebp-18h]
  __int64 v11; // [esp+14h] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v9.configuration + 4) = 0;
  v11 = 0x80000;
  HIDWORD(v9.configuration[1]) = 0x80000;
  *(_DWORD *)&v9.0 = "post_process_fxaa";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "post_process_fxaa", 0, v9, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v10);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$generic1",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v7, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
