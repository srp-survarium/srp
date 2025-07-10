void __thiscall vostok::render::effect_editor_show_batched_geometry::compile(
        vostok::render::effect_editor_show_batched_geometry *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  const char *v7; // [esp+0h] [ebp-18h]
  const char *v8; // [esp+0h] [ebp-18h]
  vostok::render::shader_configuration *v9; // [esp+4h] [ebp-14h]
  vostok::render::shader_configuration *v10; // [esp+4h] [ebp-14h]
  vostok::render::shader_configuration configuration; // [esp+8h] [ebp-10h] BYREF

  *(_DWORD *)&configuration.0 = 0;
  *(unsigned __int64 *)((char *)configuration.configuration + 4) = 0x400000000LL;
  HIDWORD(configuration.configuration[1]) = 0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966A14.m_name.m_string.m_buffer[92],
    (vostok::render::shader_configuration *)&stru_967C04.m_name.m_string.m_buffer[136],
    (const char *)&configuration,
    v7,
    v9);
  vostok::render::effect_compiler::end_pass(
    v3,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v4, (int)compiler);
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_96689C,
    (vostok::render::shader_configuration *)&stru_967C04.m_name.m_string.m_buffer[164],
    (const char *)&configuration,
    v8,
    v10);
  vostok::render::effect_compiler::end_pass(
    v5,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v6, (int)compiler);
}
