void __thiscall vostok::render::effect_editor_texture_density::compile(
        vostok::render::effect_editor_texture_density *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::command_line::key *v5; // ecx
  vostok::render::effect_material_base *v6; // ecx
  vostok::render::shader_configuration *v7; // [esp+0h] [ebp-18h]
  D3D11_COMPARISON_FUNC v8; // [esp+0h] [ebp-18h]
  const vostok::configs::binary_config_value *v9; // [esp+4h] [ebp-14h]
  _DWORD v10[4]; // [esp+8h] [ebp-10h] BYREF

  v10[2] = 0x80000;
  v10[0] = 0;
  v10[1] = 0;
  v10[3] = 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "editor_texture_density",
    compiler,
    (const char *)v10,
    config,
    v7,
    v9);
  vostok::render::effect_compiler::set_depth(v4, (int)compiler, 1, 1, v8);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v5);
  vostok::render::effect_material_base::compile_end(v6, compiler);
}
